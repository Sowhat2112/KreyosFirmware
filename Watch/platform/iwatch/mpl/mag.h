#ifndef _MAG_H
#define _MAG_H

extern void mag_dev_Enter_Sleep();
extern void mag_dev_Exit_Sleep();
extern int mag_get_raw(unsigned char *data);


void start_magnetometer();
void shutdown_magnetometer();
int Get_compass_azimuthangle();

#endif