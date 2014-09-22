#include "contiki.h"

#include "window.h"
#include "grlib/grlib.h"
#include "memlcd.h"


void window_drawtime(tContext *pContext, long y, uint8_t times[3], uint8_t selected)
{
  char data[3];
  data[0] = data[1] = '0';
  data[2] = ':';
  #define SPACING 3
  uint8_t height = GrStringHeightGet(pContext);
  
  uint8_t width_all = GrStringWidthGet(pContext, data, 3) + 10;
  uint8_t width_digit = GrStringWidthGet(pContext, data, 2) + 4;

  long startx = (LCD_WIDTH - width_all - width_all - width_digit) / 2;
  if (startx < 0) startx = 0;

  for(int i = 0; i < 3; i++)
  {
    data[0] = '0' + times[i] / 10;
    data[1] = '0' + times[i] % 10;

    GrContextForegroundSet(pContext, ClrWhite);
    GrContextBackgroundSet(pContext, ClrBlack);

    if (selected & (1 << i))
      window_selecttext(pContext, data, 2, startx + SPACING + i * width_all, y);
    else
      GrStringDraw(pContext, data, 2, startx + SPACING + i * width_all, y, 0);

    if (i != 2)
    {
      GrContextForegroundSet(pContext, ClrWhite);
      GrContextBackgroundSet(pContext, ClrBlack);
      GrStringDraw(pContext, ":", 1, startx + SPACING + width_digit + i * width_all, y, 0);
    }
  }
}

void window_progress(tContext *pContext, long lY, uint8_t step)
{
  tRectangle rect = {18, lY, 127, lY + 8};
  GrContextForegroundSet(pContext, ClrWhite);
  GrRectFillRound(pContext, &rect, 3);
  GrContextForegroundSet(pContext, ClrBlack);

  if (step > 100)
    step = 100;

  rect.sXMin += 4;
  rect.sYMin += 2;
  rect.sYMax -= 2;
  rect.sXMax = rect.sXMin + step;
  GrRectFill(pContext, &rect);
}
#if defined(PRODUCT_W002) || defined(PRODUCT_W004)  
void window_volume(tContext *pContext, long lX, long lY, int total, int current)
{
  	for (int i = 0; i <= total; i++)
  	{
  		tRectangle rect = {lX , lY - i * 12, lX + 37 , lY + 7 - i*12};
    		if (i <= current)
    		{
      			// solid
      			GrRectFill(pContext, &rect);
    		}
    		else
    		{
      			GrRectDraw(pContext, &rect);
    		}
  	}
}
#else
void window_volume(tContext *pContext, long lX, long lY, int total, int current)
{
  for (int i = 0; i <= total; i++)
  {
    tRectangle rect = {lX + i * 10, lY - 3 - i * 3, lX + 7 + i * 10, lY};
    if (i <= current)
    {
      // solid
      GrRectFill(pContext, &rect);
    }
    else
    {
      GrRectDraw(pContext, &rect);
    }
  }
}
#endif
#if defined(PRODUCT_W002)      
static const tRectangle button_rect[] = 
{
	{131, 76, 143, 88},	//KEY_ENTER
	{1, 19, 13, 31},	//KEY_EXIT
	{131, 19, 143, 31},	//KEY_UP
	{131, 153, 143, 165},	//KEY_DOWN

};
#elif defined(PRODUCT_W004)
static const tRectangle button_rect[] = 
{
	{131, 19, 143, 31},	//KEY_UP
 	{131, 76, 143, 88},	//KEY_ENTER
 	{131, 153, 143, 165},	//KEY_DOWN
 	{1, 19, 13, 31},		//KEY_EXIT
};
#else
static const tRectangle button_rect[] = 
{
 	{11, 145, 68, 161},
 	{11, 28, 68, 44},
 	{77, 28, 131, 44},
 	{77, 145, 131, 161},
};
#endif
/*
* Draw the button text for the keys
* If text is NULL, draw a empty box
*/
#if defined(PRODUCT_W002) || defined(PRODUCT_W004)  
void window_button(tContext *pContext, uint8_t key, uint8_t icon_type, const char* text)
{
	int width;
	int i;
  	long forecolor, backcolor;
	uint8_t upshift = 0;
	
  	if (key & 0x80)
  	{
    		forecolor = ClrBlack;
    		backcolor = ClrWhite;
    		key &= ~(0x80);
  	}
  	else
  	{
    		forecolor = ClrWhite;
    		backcolor = ClrBlack;
  	}
	const tRectangle *rect= &button_rect[key];
	if((icon_type&0x80) == 0x80)
		upshift = 13;
	//Draw button text
	GrContextFontSet(pContext, &g_sFontBaby16);
	if (text)
	{
		GrContextForegroundSet(pContext, backcolor);
		if(key == KEY_EXIT)
			GrStringDraw(pContext, text, -1, rect->sXMax+3, rect->sYMin - upshift  , 0);		
		else
		{
			width = GrStringWidthGet(pContext, text, -1);		
			if(icon_type == BUTTON_NO_ICON)
				GrStringDraw(pContext, text, -1, (rect->sXMax - width ), rect->sYMin- upshift  , 0);					
			else	
				GrStringDraw(pContext, text, -1, (rect->sXMin - width - 3), rect->sYMin- upshift  , 0);					

		}	
	}	
	
	//Draw button icon image
	switch(icon_type&0x0f)
	{
	case TRIANGLE_UP:
		for(i=0; i<7;i++)
		{
			GrLineDrawH(pContext, rect->sXMin+i, rect->sXMax-i, rect->sYMax - 2 - upshift - i);
		}
		break;	
	case TRIANGLE_DOWN:
		for(i=0; i<7;i++)
		{
			GrLineDrawH(pContext, rect->sXMin+i, rect->sXMax-i, rect->sYMin + 2 - upshift + i);
		}
		break;
	case TRIANGLE_RIGHT:
		for(i=0; i<7;i++)
		{
			GrLineDrawV(pContext, rect->sXMin+i, rect->sYMin - upshift +i , rect->sYMax - upshift -i);
		}
		break;
		
	case TRIANGLE_LEFT:
		for(i=0; i<7;i++)
		{
			GrLineDrawV(pContext, rect->sXMax-i, rect->sYMin - upshift +i , rect->sYMax - upshift -i);
		}		
		break;
		
	case MUSIC_PAUSE:
		{
			tRectangle rect1 = {rect->sXMin, rect->sYMin - upshift , rect->sXMin + 3 , rect->sYMax - upshift};
			GrRectFill(pContext,  &rect1);
			
			tRectangle rect2 = {rect->sXMin+6 , rect->sYMin - upshift , rect->sXMin + 9 , rect->sYMax - upshift};
			GrRectFill(pContext,  &rect2);
		}
		break;
	case MUSIC_NEXT:
		for(i=0; i<7;i++)
		{
			GrLineDrawV(pContext, rect->sXMin+i, rect->sYMin - upshift + i , rect->sYMax - upshift - i);
		}
		
		GrLineDrawV(pContext, rect->sXMax+2, rect->sYMin - upshift , rect->sYMax - upshift );
		break;
		
	case MUSIC_PREVIOUS:
		for(i=0; i<7;i++)
		{
			GrLineDrawV(pContext, rect->sXMax-i, rect->sYMin- upshift + i , rect->sYMax - upshift -i);
		}				
		
		GrLineDrawV(pContext, rect->sXMin-2, rect->sYMin - upshift , rect->sYMax - upshift);
		break;
	case BUTTON_NO_ICON:
	default:		
		break;
	}
}

#else

void window_button(tContext *pContext, uint8_t key, const char* text)
{
  	long forecolor, backcolor;

  	if (key & 0x80)
  	{
    		forecolor = ClrBlack;
    		backcolor = ClrWhite;
    		key &= ~(0x80);
  	}
  	else
  	{
    		forecolor = ClrWhite;
    		backcolor = ClrBlack;

  	}
  	
  	GrContextFontSet(pContext, &g_sFontGothic18);


  // draw black box
  	if (text)
  	{
    		const tRectangle *rect = &button_rect[key];

    		GrContextForegroundSet(pContext, forecolor);
    		GrRectFill(pContext, rect);
    		// draw triagle
    		for(int i = 0; i <= (rect->sYMax - rect->sYMin) /2 ; i++)
    		{
      			if (rect->sXMin < 20)
      			{
			        GrLineDrawH(pContext, rect->sXMin - i, rect->sXMin, rect->sYMin + i);
			        GrLineDrawH(pContext, rect->sXMin - i, rect->sXMin, rect->sYMax - i);
      			}
      			else
      			{
        			GrLineDrawH(pContext, rect->sXMax, rect->sXMax + i, rect->sYMin + i);
        			GrLineDrawH(pContext, rect->sXMax, rect->sXMax + i, rect->sYMax - i);
      			}
    		}

    		GrContextForegroundSet(pContext, backcolor);
    		GrStringDrawCentered(pContext, text, -1, (rect->sXMin + rect->sXMax) /2, (rect->sYMin + rect->sYMax) /2, 0);
  	}
  	else
  	{
    		GrContextForegroundSet(pContext, backcolor);
    		GrRectFill(pContext, &button_rect[key]);
  	}
}
#endif
void window_selecttext(tContext *pContext, const char* pcString, long lLength, long lX, long lY)
{
  int height = GrStringHeightGet(pContext);

  int width, textwidth;

  if (lLength == -1)
  {
    width = GrStringWidthGet(pContext, pcString, lLength);
    textwidth = width;
  }
  else
  {
    char data = '8';
    width = GrStringWidthGet(pContext, &data, 1) * lLength;
    textwidth = GrStringWidthGet(pContext, pcString, lLength);
  }

	
  tRectangle rect = {lX - 2, lY - 2, lX + width + 2, lY + height + 2};
  GrContextForegroundSet(pContext, ClrWhite);
#if defined(PRODUCT_W002) || defined(PRODUCT_W004)  
	GrRectFillRound(pContext, &rect, 0);
#else  
  GrRectFillRound(pContext, &rect, 3);
#endif  
  GrContextForegroundSet(pContext, ClrBlack);

  GrStringDraw(pContext, pcString, lLength, lX + (width - textwidth)/2, lY, 0);

  GrContextForegroundSet(pContext, ClrWhite);
#if defined(PRODUCT_W002) || defined(PRODUCT_W004)  

#else
  // there is something more
  long x = lX + width/2;
  long y0 = lY - 5 - 6;
  long y1 = lY + height + 5 + 6;
  for(int i = 0; i < 6; i++)
  {
    GrLineDrawH(pContext, x - i, x + i,  y1 - i);
    GrLineDrawH(pContext, x - i, x + i,  y0 + i);
  }
#endif  
}
