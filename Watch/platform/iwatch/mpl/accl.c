#include "contiki.h"
#include "accl.h"

#include "sys/etimer.h"
#include "dev/watchdog.h"
#include <stdio.h>
#include <stdlib.h>

#include "window.h"

#include "pedometer/pedometer.h"
#include "pedometer/sleepalgo.h"

PROCESS(mpu6050_process, "Accl Driver");

extern void ped_init();
extern void ped_step_detect_run();
extern void gesture_processdata(int16_t *input);

static uint16_t read_interval;
static struct etimer timer;
void accl_switchmode(int mode);
void accl_initialize()
{
	printf("\nAccl Initialize.......\n");	
  	accl_dev_init();
  	printf("Done!!\n");
	read_interval = NORMAL_INTERVAL;
  	process_start(&mpu6050_process, NULL);
  	

  	printf("\n$$OK MPU6050\n");

}

void accl_shutdown()
{
	accl_dev_shutdown();
}

static int CheckForShake(int16_t *last, int16_t *now, uint16_t threshold)
{
  uint16_t deltaX = abs(last[0] - now[0]);
  uint16_t deltaY = abs(last[1] - now[1]);
  uint16_t deltaZ = abs(last[2] - now[2]);

  return (deltaX > threshold && deltaY > threshold) ||
                    (deltaX > threshold && deltaZ > threshold) ||
                    (deltaY > threshold && deltaZ > threshold);
}

static int8_t _shakeCount;
static int8_t _shaking;
#define ShakeThreshold 180

PROCESS_THREAD(mpu6050_process, ev, data)
{
  PROCESS_BEGIN();
  _shakeCount = 0;
  _shaking = 0;

  etimer_set(&timer, read_interval);
  process_post(ui_process, EVENT_MPU_STATUS, (void*)BIT0);
  while(1)
  {
    PROCESS_WAIT_EVENT();
    // initialize I2C bus

    if (ev == PROCESS_EVENT_TIMER || (ev == PROCESS_EVENT_POLL))
    {
        unsigned char more = 0;
        do
        {
          int16_t accel[3];
          int16_t last[3];
          unsigned short data[512];
          unsigned short length = sizeof(data);
#if 0          
          // Do get magnetometer data
          start_magnetometer();
          delay_ms(3);
          int ret = Get_compass_azimuthangle();
          shutdown_magnetometer();
          // Do get magnetometer data
          delay_ms(1);
#endif          
          
          int result = accl_dev_readall(&length, (unsigned char*)data, &more);

          if (result == 0)
          {
          	
            for (int index = 0; index < length; index += 6)
            {
              accel[0] = data[index];
              accel[1] = data[index + 2];
              accel[2] = data[index + 4];
		
              if (read_interval == NORMAL_INTERVAL)
              {
                accel[0] >>= 6;
                accel[1] >>= 6;
                accel[2] >>= 6;
		
                if (index > 0)
                {
                  if (!_shaking && _shakeCount >= 1 && CheckForShake(last, accel, ShakeThreshold))
                  {
                    //We are shaking
                    _shaking = 1;
                    _shakeCount = 0;
                    process_post(ui_process, EVENT_KEY_PRESSED, (void*)KEY_TAP);
                  }
                  else if (CheckForShake(last, accel, ShakeThreshold))
                  {
                    _shakeCount++;
                  }
                  else if (!CheckForShake(last, accel, 50))
                  {
                    _shakeCount = 0;
                    _shaking = 0;
                  }
                }
                last[0] = accel[0];
                last[1] = accel[1];
                last[2] = accel[2];

                if (ped_update_sample(accel) == 1)
                {
                  ped_step_detect_run();
                }
              }
              else if (read_interval == GESTURE_INTERVAL)
              {
                gesture_processdata(accel);
              }
              else if (read_interval == SLEEP_INTERVAL)
              {
                static int count = 3;
                count--;
                if (count)
                  continue;
                count = 3;
                signed char data[3];
                data[0] = accel[0] >> 8;
                data[1] = accel[1] >> 8;
                data[2] = accel[2] >> 8;

                if (slp_sample_update(data))
                {
                  slp_status_cal();
                }
              }
            }
            continue;
          }
          else if (result == -1)
          {
            printf("Eror when read fifo\n");
            break;
          }
          else if (result == -2)
          {
            // TODO: reset fifo
            // I2C_write(MPU6050_RA_USER_CTRL, MPU6050_USERCTRL_FIFO_RESET_BIT | MPU6050_USERCTRL_FIFO_EN_BIT);
            printf("fifo overflow\n");
            more = 0;
            break;
          }

      }while(more);

#if ZEROMOTION
      if (!zeromotion)
#endif
        etimer_set(&timer, read_interval);
    }
  }

  PROCESS_END();
}

void accl_switchmode(int mode)
{
  accl_dev_switch(mode);
  switch(mode)
  {
    case 1:
    {
      read_interval = GESTURE_INTERVAL; // every 1/8 sec
      break;
    }
    case 0:
    {
      read_interval = NORMAL_INTERVAL;
      break;
    }
    case 2:
    {
      read_interval = SLEEP_INTERVAL;
    }
  }
  etimer_set(&timer, read_interval);
}
