#define MOTION_DRIVER_TARGET_MSP430 1
#define BMX055	1
#include "contiki.h"
#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>

#include "window.h"
#include "bmx055_def.h"

#define ZEROMOTION 0
#include "accl.h"


/* Starting sampling rate. */
#define SLEEP_MPU_HZ  (10)
#define DEFAULT_MPU_HZ  (50)
#define GESTURE_MPU_HZ  (150)

void gyro_dev_shutdown(void);
void mag_dev_init(void);
#if ZEROMOTION
static uint8_t zeromotion; // 1 - hang on the changes.
static unsigned long stop_seconds;
#endif

#define BMM_MAX_RETRY_WAKEUP (5)

void gyro_dev_shutdown();
void mag_dev_init();

const static uint8_t ACC_init_data[] =
{	
//  	BMX_ACC_PUM_LPW, BMX_ACC_PMU_NORMAL,   	
  	BMX_ACC_PUM_LPW, BMX_ACC_PMU_LPW_EN | BMX_ACC_PMU_SLEEP_25_MS,   		
	BMX_ACC_PUM_LOW_POWER, BMX_ACC_PMU_LPM2 | BMX_ACC_PMU_EST,
  	BMX_ACC_PMU_RANGE, BMX_ACC_PMU_RANGE_2G, 								//set acc sensitivity to 2G

  	BMX_ACC_PUM_BW, BMX_ACC_BW_62_5HZ,									////set sampling to 62.5 Hz
  	BMX_ACC_FIFO_CONFIG_1, BMX_ACC_FIFO_MODE_FIFO | BMX_ACC_FIFO_SELECT_XYZ, // enable fifo for accel x, y, z  	
};

void delay_ms(unsigned long num_ms)
{
  BUSYWAIT_UNTIL(0, num_ms * RTIMER_SECOND / 1000);
}

int bmx055_selftest()
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
/*	
    	// configure INT pin
  	MPU_INT_SEL &= ~MPU_INT_BIT;  // = 0 - I/O
  	MPU_INT_DIR &= ~MPU_INT_BIT;  // = 0 - Input
  	MPU_INT_IFG &= ~MPU_INT_BIT;  // no IRQ pending
  	MPU_INT_IES &= ~MPU_INT_BIT;  // IRQ on 0->1 transition
  	MPU_INT_IE  |=  MPU_INT_BIT;  // enable IRQ for P1.6	
*/
#if ZEROMOTION
  	zeromotion = 0;
  	stop_seconds = 0;
#endif
  	
  	// initialize I2C bus
  	I2C_addr(BMX_ACCL_ADDR);
  	
  	I2C_write(BMX_ACC_BGW_SREST, BMX_ACC_SRSET);
  	delay_ms(100);
  	for(int i = 0; i < sizeof(ACC_init_data); i+=2)
  	{
    		I2C_writebytes(ACC_init_data[i], &ACC_init_data[i+1], 1);
  	}
  	I2C_done();

	gyro_dev_shutdown();
	mag_dev_init();	
	
  	return;  	
  	
}

void accl_dev_shutdown(void)
{
//  	MPU_INT_IE  &=  ~MPU_INT_BIT;  // enable IRQ for P1.6
  	I2C_addr(BMX_ACCL_ADDR);
  	I2C_write(BMX_ACC_PUM_LPW, BMX_ACC_PMU_DEEP_SUSPEND);
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

static int accl_read_fifo_all(unsigned short *length, unsigned char *data, unsigned char *more)
{
    	unsigned char tmp[2];
    	unsigned short fifo_count;	
    	
    	I2C_addr(BMX_ACCL_ADDR);
//    	printf("Accl read FIFO \n");
    	if (I2C_readbytes(BMX_ACC_FIFO_STATUS, tmp, 1))
        	return -1;
        fifo_count = tmp[0] &0x7f;	
        fifo_count = fifo_count *3;
//        printf("FIFO cnt : %x\n", fifo_count);
        if (fifo_count > (32 >> 1))
        {
        	/* FIFO is 50% full, better check overflow bit. */
        	if (I2C_readbytes(BMX_ACC_INT_STATUS_1, tmp, 1))
            		return -1;
        	if (tmp[0] & BMX_ACC_FIFO_FULL_INT) 
        	{
            		return -2;
        	}        	
        }	

    	if (*length >= fifo_count)
      		*length = fifo_count;
    	else
      		*more = 1;        
      		
	if (I2C_readbytes(BMX_ACC_FIFO_DATA, data, *length))
      		return -1;

    	return 0;      		
}

int accl_dev_readall(unsigned short *length, unsigned char *data, unsigned char *more)
{
  	int result = accl_read_fifo_all(length, data, more);

  	if (result == 0)
  	{
    		for (int index = 0; index < *length; index += 2)
//    		for (int index = 1; index < *length; index += 2)
    		{
//  			data[index] >>= 4;
        		*(int16_t*)&data[index] &= 0xfff0;
    		}
  	}
/*  	
  	for (int i = 0; i < *length; i++)
  		printf("%x\n", data[i]);
*/
  	return result;	
}

int accl_read_raw(unsigned char *data)
{
	if (I2C_readbytes(BMX_GYRO_X_LSB, data, 6))
      		return -1;

    	return 0;      			
}

/* d is mode
   0: pedometer
   1: Gensture
   2: sleep track
   */
void accl_dev_switch(int d)
{
	I2C_addr(BMX_ACCL_ADDR);
  	switch(d)
  	{
    	case 1:    	
      		I2C_write(BMX_ACC_PMU_RANGE, BMX_ACC_PMU_RANGE_4G);
      		I2C_write(BMX_ACC_PUM_BW, BMX_ACC_BW_125HZ);
      		break;
    	
    	
    	case 0:    	
      		I2C_write(BMX_ACC_PMU_RANGE, BMX_ACC_PMU_RANGE_2G);
      		I2C_write(BMX_ACC_PUM_BW, BMX_ACC_BW_62_5HZ);
      		break;
    	
    	
    	case 2:    	
      		I2C_write(BMX_ACC_PMU_RANGE, BMX_ACC_PMU_RANGE_2G);
      		I2C_write(BMX_ACC_PUM_BW, BMX_ACC_BW_7_81_HZ);
    	
  }
  I2C_write(BMX_ACC_FIFO_CONFIG_1, BMX_ACC_FIFO_MODE_FIFO | BMX_ACC_FIFO_SELECT_XYZ);
  I2C_done();	
	
}


//Gyroscope
void gyro_dev_shutdown()
{
	int try_times = BMM_MAX_RETRY_WAKEUP;
	uint8_t ret = 0;
	//Gyro goto deepsuppend mode
	printf("Gyro shutdown ! \n");	
	I2C_addr(BMX_GYRO_ADDR);
	while (try_times) 
  	{
  		ret = I2C_write(BMX_GYRO_LPM1, BMX_GYRO_PMU_DEEP_SUSPEND);
		if(ret==0)
		{
			printf("Gyro into Deepsuspend ! \n");	
			break;	
		}
		else 
		{	
			printf("Gyro still in Normal retry again %x\n",try_times);	
			try_times--;	
		}
		delay_ms(100);
	}	
	
	I2C_done();
}
#if 0
void gyro_dev_init()
{

}


static int gyro_read_fifo_all(unsigned short *length, unsigned char *data, unsigned char *more)
{
    	unsigned char tmp[2];
    	unsigned short fifo_count;	
    	
    	if (I2C_readbytes(BMX_GYRO_FIFO_STATUS, tmp, 1))
        	return -1;
        fifo_count = tmp[0] &0x7f;	
        if (fifo_count > (100 >> 1))
        {
        	/* FIFO is 50% full, better check overflow bit. */
        	if (I2C_readbytes(BMX_ACC_INT_STATUS_1, tmp, 1))
            		return -1;
        	if (tmp[0] & BMX_GYRO_FIFO_FULL_INT) 
        	{
            		return -2;
        	}        	
        }	

    	if (*length >= fifo_count)
      		*length = fifo_count;
    	else
      		*more = 1;        
      		
	if (I2C_readbytes(BMX_GYRO_FIFO_DATA, data, *length))
      		return -1;

    	return 0;      			
}

int gyro_dev_readall(unsigned short *length, unsigned char *data, unsigned char *more)
{
	int result = gyro_read_fifo_all(length, data, more);
	return result;	
}
#endif

//Magnetrometer
//Gyroscope
int mag_get_REG_value(uint8_t reg, uint8_t *data)
{	
	uint8_t ret;
	I2C_addr(BMX_MAG_ADDR);
	if(I2C_readbytes(reg, data, 1))
		return -1;
	
	return 0;
}



void mag_dev_init()
{	

	uint8_t ret = 0;
	int try_times = BMM_MAX_RETRY_WAKEUP;
	printf("Wakeup Mag \n");
  	I2C_addr(BMX_MAG_ADDR);  	
  	
  	while (try_times) 
  	{
  		ret = I2C_write(BMX_MAG_CTRL_0, 0x01);	//From Suspend mode to sleep mode 
		if(ret==0)
		{
			printf("Mag Wakeup! \n");	
			break;	
		}
		else 
		{	
			printf("Mag in suspend retry again %x\n",try_times);	
			try_times--;	
		}
		delay_ms(100);
	}	
	//Write init config setting to register
	I2C_write(BMX_MAG_CTRL_1, BMX_MAG_DATA_RATE_8HZ);	//From Suspend mode to sleep mode 	
  	I2C_done();		
  	
}

void mag_dev_Enter_Sleep()
{	
	uint8_t data;
	I2C_addr(BMX_MAG_ADDR);
	if(mag_get_REG_value(BMX_MAG_CTRL_1, &data) )
  		return ;
	I2C_write(BMX_MAG_CTRL_1, data | 0x06);	//To enter sleep mode
	I2C_done();		
}

void mag_dev_Exit_Sleep()
{
	uint8_t data;
	I2C_addr(BMX_MAG_ADDR);
	if(mag_get_REG_value(BMX_MAG_CTRL_1, &data) )
  		return ;  	
	I2C_write(BMX_MAG_CTRL_1, (data&0xf9));		//To exit sleep mode
	
	I2C_readbytes(BMX_MAG_ID, &data, 1);
	printf("MAG ID = %x\n", data);
}

int mag_get_raw(unsigned char *data)
{
	I2C_addr(BMX_MAG_ADDR);
	if (I2C_readbytes(BMX_MAG_X_LSB, data, 8))
      		return -1;

    	return 0;      				
}