#include "contiki.h"

#include "window.h"
#include <stdio.h>
#include "icons.h"
#include "grlib/grlib.h"
#include "memlcd.h"
#include "memory.h"

#include "stlv.h"
#include "stlv_client.h"
#include "ble_handler.h"

#include "cfs/cfs.h"
#include "btstack/include/btstack/utils.h"
#include "status.h"

char* location; 
uint8_t unit_type;	//1 be Fahrenheit and 0 be Celsius 
int     temperature;
int	max_temp;
int	min_temp;
uint8_t	weather_type;

static void onDraw(tContext *pContext)
{	
	uint8_t	width;
	char buf[30];
	
	GrContextForegroundSet(pContext, ClrWhite);
	tRectangle rect = {0, 0, 143 , 70 };
 	GrRectFill(pContext, &rect);
 	
 	GrContextBackgroundSet(pContext, ClrWhite);
 	GrContextForegroundSet(pContext, ClrBlack);
 	GrContextFontSet(pContext, (tFont*)&g_sFontExIcon64);
	GrStringDraw(pContext, (char *)&weather_type, 1, 40, 8, 0);
 	
 	GrContextForegroundSet(pContext, ClrWhite);
 	sprintf(buf, "%d", temperature); 	
 	GrContextFontSet(pContext, &g_sFontRonda28); 	
 	width = GrStringWidthGet(pContext, buf, -1);
 	GrStringDraw(pContext, buf, -1, 14 , 85, 0);
 	
 	GrCircleDraw(pContext, 22 + width, 99 , 4);
  	GrCircleDraw(pContext, 22 + width, 99 , 3);
  	
  	GrContextFontSet(pContext, &g_sFontRonda16); 	
  	if(unit_type==1)
  		buf[0] = 'F';
  	else
  		buf[0] = 'C';	  		
  	GrStringDraw(pContext, buf, 1, 30+ width , 90, 0);	
 	
 	GrContextFontSet(pContext, &g_sFontRonda16); 	
 	sprintf(buf, "%d", max_temp); 	 	
 	GrStringDraw(pContext, buf, -1, 109 , 88, 0);
 	width = GrStringWidthGet(pContext, buf, -1); 	 	 	
 	GrCircleDraw(pContext, 112 + width, 96 , 2);
 	
 	
 	sprintf(buf, "%d", min_temp); 	 	
 	GrStringDraw(pContext, buf, -1, 109 , 108, 0);
 	width = GrStringWidthGet(pContext, buf, -1); 	 	 	
 	GrCircleDraw(pContext, 112 + width, 116 , 2);
 	
 	GrLineDrawH(pContext, 100, 105, 94); 	
 	GrLineDrawH(pContext, 101, 104, 97);
 	GrLineDrawH(pContext, 100, 105, 98); 	
 	GrLineDrawV(pContext, 102, 96, 107);
 	GrLineDrawV(pContext, 103, 96, 107);
 	
 	GrLineDrawH(pContext, 100, 105, 127); 	
 	GrLineDrawH(pContext, 101, 104, 124);
 	GrLineDrawH(pContext, 100, 105, 123); 	
 	GrLineDrawV(pContext, 102, 114, 125);
 	GrLineDrawV(pContext, 103, 114, 125); 	
 	
 	 	
 	GrContextFontSet(pContext, &g_sFontHelvetic20); 	
 	sprintf(buf, "%s", location); 	
 	GrStringDraw(pContext, buf, -1, 13 , 145, 0);
    	
}

uint8_t weather_process(uint8_t ev, uint16_t lparam, void* rparam)
{
  	switch(ev)
  	{
  	case EVENT_WINDOW_CREATED:
		location = "Shanghai";		
		unit_type =1;
		temperature = 100;
		max_temp = 123;
		min_temp = 90;
		weather_type = 'w';
		    	
  		break;
  		
  	case EVENT_WINDOW_PAINT:
  	{	
  		tContext *pContext = (tContext*)rparam;
    		GrContextForegroundSet(pContext, ClrBlack);
    		GrRectFill(pContext, &fullscreen_clip);
    		onDraw(pContext);
	}    		
    		break;
    		
    	case EVENT_KEY_PRESSED:
    		if (lparam == KEY_EXIT)
  		{
    			window_close();
    			return 1;
  		}
    		break;	

  	default:
    		return 0;
  	}
  	return 1;	
}