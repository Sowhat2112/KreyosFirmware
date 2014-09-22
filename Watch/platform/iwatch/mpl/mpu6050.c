#define MOTION_DRIVER_TARGET_MSP430 1
#define MPU6050 1

#include "contiki.h"
#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>

#include "window.h"
#include "mpu6050_def.h"

#define ZEROMOTION 0
#include "accl.h"

#define MPU6050_ADDR 0x69

#define MPU_INT_SEL P1SEL
#define MPU_INT_DIR P1DIR
#define MPU_INT_IFG P1IFG
#define MPU_INT_IES P1IES
#define MPU_INT_IE  P1IE
#define MPU_INT_BIT BIT6

/* Starting sampling rate. */
#define SLEEP_MPU_HZ  (10)
#define DEFAULT_MPU_HZ  (50)
#define GESTURE_MPU_HZ  (150)

#if ZEROMOTION
static uint8_t zeromotion; // 1 - hang on the changes.
static unsigned long stop_seconds;
#endif

const static uint8_t init_data[] =
{
  MPU6050_RA_PWR_MGMT_1, 0x04, // wake up sensor
  MPU6050_RA_PWR_MGMT_2, MPU6050_PWR2_STBY_XG_BIT | MPU6050_PWR2_STBY_YG_BIT | MPU6050_PWR2_STBY_ZG_BIT, // wake up sensor
  MPU6050_RA_ACCEL_CONFIG, MPU6050_ACCEL_FS_2G, //set acc sensitivity to 2G
  MPU6050_RA_CONFIG, 0x01, //set DLPF to 21 Hz
  MPU6050_RA_SMPLRT_DIV, (uint8_t)(1000/DEFAULT_MPU_HZ - 1), ////set sampling to 62.5 Hz
  MPU6050_RA_FIFO_EN, 0x08, // enable fifo for accel x, y, z
  MPU6050_RA_USER_CTRL, 0x40, // enable fifo

#if ZEROMOTION
  MPU6050_RA_INT_ENABLE, MPU6050_INTERRUPT_ZMOT_BIT, // enable zero motion detection interrupt
  MPU6050_RA_ZRMOT_THR, 16,
  MPU6050_RA_ZRMOT_DUR, 100,
#endif
};

void delay_ms(unsigned long num_ms)
{
  BUSYWAIT_UNTIL(0, num_ms * RTIMER_SECOND / 1000);
}

int mpu6050_selftest()
{
 #if 0
  long gyro[3], accel[3];
  int r = 0;// mpu_run_self_test(gyro, accel);
  printf("self test result %x\n", r);

  if (r != 0x03)
  {
    return -1;
  }

  printf("accel bias: %ld, %ld, %ld\n", accel[0], accel[1], accel[2]);
#endif
  return 0;
}

void accl_dev_init()
{
    // configure INT pin
  MPU_INT_SEL &= ~MPU_INT_BIT;  // = 0 - I/O
  MPU_INT_DIR &= ~MPU_INT_BIT;  // = 0 - Input
  MPU_INT_IFG &= ~MPU_INT_BIT;  // no IRQ pending
  MPU_INT_IES &= ~MPU_INT_BIT;  // IRQ on 0->1 transition
  MPU_INT_IE  |=  MPU_INT_BIT;  // enable IRQ for P1.6

#if ZEROMOTION
  zeromotion = 0;
  stop_seconds = 0;
#endif

  // initialize I2C bus
  I2C_addr(MPU6050_ADDR);

  I2C_write(MPU6050_RA_PWR_MGMT_1, 0x80);
  delay_ms(100);
  for(int i = 0; i < sizeof(init_data); i+=2)
  {
    I2C_writebytes(init_data[i], &init_data[i+1], 1);
  }
  I2C_done();

  return;
}

void accl_dev_shutdown(void)
{
  MPU_INT_IE  &=  ~MPU_INT_BIT;  // enable IRQ for P1.6
  I2C_addr(MPU6050_ADDR);
  I2C_write(MPU6050_RA_PWR_MGMT_1, BIT6);
  I2C_done();
}

int port1_pin6()
{
#if ZEROMOTION
  zeromotion = 1 - zeromotion;
  process_poll(&mpu6050_process);
#endif
  return 1;
}

static int read_fifo_all(unsigned short *length, unsigned char *data, unsigned char *more)
{
    unsigned char tmp[2];
    unsigned short fifo_count;

    if (I2C_readbytes(MPU6050_RA_FIFO_COUNTH, tmp, 2))
        return -1;
    fifo_count = (tmp[0] << 8) | tmp[1];
    if (fifo_count > (1024 >> 1)) {
        /* FIFO is 50% full, better check overflow bit. */
        if (I2C_readbytes(MPU6050_RA_INT_STATUS, tmp, 1))
            return -1;
        if (tmp[0] & MPU6050_INTERRUPT_FIFO_OFLOW_BIT) {
            return -2;
        }
    }

    if (*length >= fifo_count)
      *length = fifo_count;
    else
      *more = 1;

    //printf("there is %d\n", fifo_count);

    if (I2C_readbytes(MPU6050_RA_FIFO_R_W, data, *length))
      return -1;

    return 0;
}


int accl_dev_readall(unsigned short *length, unsigned char *data, unsigned char *more)
{
  int result = read_fifo_all(length, data, more);

  if (result == 0)
  {
    for (int index = 0; index < *length; index += 2)
    {
        *(int*)&data[index] = __swap_bytes(*(int*)&data[index]);
    }
  }

  return result;
}

/* d is mode
   0: pedometer
   1: Gensture
   2: sleep track
   */
void accl_dev_switch(int d)
{
  I2C_addr(MPU6050_ADDR);
  switch(d)
  {
    case 1:
    {
      I2C_write(MPU6050_RA_ACCEL_CONFIG, MPU6050_ACCEL_FS_4G);
      I2C_write(MPU6050_RA_SMPLRT_DIV, (uint8_t)(1000/GESTURE_MPU_HZ - 1));
      break;
    }
    case 0:
    {
      I2C_write(MPU6050_RA_ACCEL_CONFIG, MPU6050_ACCEL_FS_2G);
      I2C_write(MPU6050_RA_SMPLRT_DIV, (uint8_t)(1000/DEFAULT_MPU_HZ - 1));
      break;
    }
    case 2:
    {
      I2C_write(MPU6050_RA_ACCEL_CONFIG, MPU6050_ACCEL_FS_2G);
      I2C_write(MPU6050_RA_SMPLRT_DIV, (uint8_t)(1000/SLEEP_MPU_HZ - 1));
    }
  }
  I2C_write(MPU6050_RA_USER_CTRL, MPU6050_USERCTRL_FIFO_RESET_BIT | MPU6050_USERCTRL_FIFO_EN_BIT);
  I2C_done();
}

#if 0
#include "grlib/grlib.h"
#include "Template_Driver.h"
tContext context;
static void mpu_test()
{
  static int init = 0;
  static uint16_t saved_cnt = -1;

  if (!init)
  {
      memlcd_DriverInit();
      GrContextInit(&context, &g_memlcd_Driver);
      init = 1;
      GrContextForegroundSet(&context, ClrBlack);
      tRectangle rect = {0, 0, LCD_X_SIZE, LCD_Y_SIZE};
      GrRectFill(&context, &rect);
      GrContextForegroundSet(&context, ClrWhite);
  }

  if (step_cnt == saved_cnt)
  {
    return;
  }
  saved_cnt = step_cnt;

  GrContextFontSet(&context, &g_sFontNova28);
  char buf[32];
  sprintf(buf, "steps: %d   ", step_cnt);
  GrStringDrawCentered(&context, buf, -1, LCD_X_SIZE/2, LCD_Y_SIZE/2, 1);

  GrFlush(&context);
}
#endif

