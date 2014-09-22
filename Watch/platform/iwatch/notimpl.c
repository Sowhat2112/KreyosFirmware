#include "contiki.h"
#include "rtc.h"
#include "battery.h"
#include "ant/ant.h"
#include <stdio.h>
#include <string.h>

#include "btstack/utils.h"


void mpu_switchmode(int d)
{}


void codec_setvolume(uint8_t level)
{}

uint8_t codec_changevolume(int8_t diff)
{
	return 5;
}

uint8_t codec_getvolume()
{
	return 4;
}