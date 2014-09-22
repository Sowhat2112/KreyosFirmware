#ifndef _MPU_H
#define _MPU_H

// Export functions
void accl_initialize();
void accl_switchmode(int mode);
void accl_shutdown();

// device specific functions
void accl_dev_init();
void accl_dev_switch();
void accl_dev_shutdown(void);

void delay_ms(unsigned long num_ms);

void start_magnetometer();
void shutdown_magnetometer();
int Get_compass_azimuthangle();

int accl_dev_readall(unsigned short *length, unsigned char *data, unsigned char *more);


#define GESTURE_INTERVAL (CLOCK_SECOND >> 3)
#define NORMAL_INTERVAL (CLOCK_SECOND)
#define SLEEP_INTERVAL (CLOCK_SECOND * 5)

#endif