#include "contiki.h"
#include "mag.h"
#include "dev/watchdog.h"
#include <stdio.h>
#include <stdlib.h>
#include "WATCH1/cordic.h"
#include "window.h"

static const int atantable[16] = {  0x4000,   //atan(2^0) = 45 degrees
                                0x25C8,   //atan(2^-1) = 26.5651
                                0x13F6,   //atan(2^-2) = 14.0362
                                0x0A22,   //7.12502
                                0x0516,   //3.57633
                                0x028B,   //1.78981
                                0x0145,   //0.895174
                                0x00A2,   //0.447614
                                0x0051,   //0.223808
                                0x0029,   //0.111904
                                0x0014,   //0.05595
                                0x000A,   //0.0279765
                                0x0005,   //0.0139882
                                0x0003,   //0.0069941
                                0x0002,   //0.0035013
                                0x0001    //0.0017485
};

long cordic_arctan(int x, int y)
{
	int i = 0;
	int x_new, y_new;
	long angleSum = 0;
	
	x *= 4;
	y *= 4;
	
	for(i=0;i<16;i++)
	{
		if(y>0)
		{
			x_new = x + ( y >> i );
			y_new = y - ( x >> i );
			x = x_new;
			y = y_new;
			angleSum += atantable[i];
		}
		else
		{
			x_new = x - ( y >> i );
			y_new = y + ( x >> i );
			x = x_new;
			y = y_new;
			angleSum -= atantable[i];			
		}		
		printf("Debug : i=%d angleSum = %ld, angle = %d\n", i, angleSum, atantable[i]);
	}
	return angleSum;
}

void start_magnetometer()
{	
	printf("Wakeup Magnetometer....\n");	
	mag_dev_Exit_Sleep();
}

void shutdown_magnetometer()
{
	printf("Magnetometer go sleep...\n");	
	mag_dev_Enter_Sleep();
}

int Calculate_compass_azimuthangle(int x, int y)
{
	long temp_angle;
	int Haeding = 0;
	
	printf("Haeding = ");
	if(x==0)
	{
		if(y>0)
		{
			Haeding = 270;
			printf("[%d]\n", Haeding);
		}
		else
		{
			Haeding = 90;
			printf("[%d]\n", Haeding);
		}		
	}	
	else if( x<0)
	{
		if(y>0)
		{
			temp_angle = (cordic_arctan(abs(x), abs(y))*180)>>16;
			//temp_angle = (cordic_arctan(x, y)*180)>>16;
			//temp_angle = cordic_arctan(x, y)*180/3.14;
			Haeding = 180 + temp_angle;
			printf("(180) [%d] [%d]\n", Haeding, temp_angle);			
		}
		else
		{		
			temp_angle = (cordic_arctan(abs(x), abs(y))*180)>>16;
			//temp_angle = (cordic_arctan(x, y)*180)>>16;
			//temp_angle = cordic_arctan(x, y)*180/3.14;
			Haeding = 90 + temp_angle;
			printf("(90) [%d] [%d]\n", Haeding, temp_angle);
		}	
		
	}
	else
	{
		
		if(y>0)
		{
			temp_angle = (cordic_arctan(abs(x), abs(y))*180)>>16;
			//temp_angle = (cordic_arctan(x, y)*180)/65536;
			//temp_angle = cordic_arctan(x, y)*180/3.14;
			Haeding = 270 + temp_angle;
			printf("(270) [%d] [%d]\n", Haeding, temp_angle);
		}
		else
		{
			temp_angle = (cordic_arctan(abs(x), abs(y))*180)>>16;
			//temp_angle = (cordic_arctan(x, y)*180)/65536;
			//temp_angle = cordic_arctan(x, y)*180/3.14;
			Haeding = temp_angle;
			printf("(0) [%d] [%d]\n", Haeding, temp_angle);
		}		
	}		
}

int Get_compass_azimuthangle()
{
	int i;
	unsigned char data[8] = {0,0,0,0,0,0,0,0};	
	printf("Read MAG RAW = ");
	mag_get_raw(data);
	for(i=0;i<8;i++)
		printf("[%02x]", data[i]);
	printf("\n");	
	for (i= 0; i < 4 ; i += 2)
	{
		*(int16_t*)&data[i] &= 0xFFF8;
		printf("[%d]", *(int16_t*)&data[i]);	
	}
	*(int16_t*)&data[4] &= 0xFFFE;
	printf("[%d]", *(int16_t*)&data[4]);	
	
	*(int16_t*)&data[6] &= 0xFFFC;
	printf("[%d]", *(int16_t*)&data[6]);	
		
	printf("\nRead done\n");	
	
	Calculate_compass_azimuthangle(*(int16_t*)&data[0], *(int16_t*)&data[2]);
	
	return 0;
}