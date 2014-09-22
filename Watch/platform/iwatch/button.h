#ifndef _BUTTON_H
#define _BUTTON_H
#if defined(PRODUCT_W004)  
#define BUTTON_UP       2
#define BUTTON_DOWN     3
#define BUTTON_BACK     4
#define BUTTON_ENTER    1
#else
#define BUTTON_UP       1
#define BUTTON_DOWN     2
#define BUTTON_BACK     3
#define BUTTON_ENTER    4
#endif
void button_init();
int button_snapshot();

#endif