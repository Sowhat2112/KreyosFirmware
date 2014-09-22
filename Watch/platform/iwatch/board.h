#define P1DIR_V BIT0 // only define unused 
#define P2DIR_V BIT3|BIT4|BIT5
#define P3DIR_V BIT2
#define P4DIR_V BIT0|BIT7
#define P5DIR_V BIT0|BIT1|BIT2|BIT3
#define P6DIR_V BIT0|BIT1|BIT3|BIT5
#define P7DIR_V BIT2|BIT3|BIT4|BIT6
#define P8DIR_V BIT0|BIT1|BIT3|BIT4|BIT5|BIT6
#define P9DIR_V BIT0|BIT1|BIT3|BIT6
#define P10DIR_V  BIT0|BIT1|BIT2|BIT3|BIT4|BIT6
#define P11DIR_V BIT1










#define LIGHTDIR P4DIR
#define LIGHTOUT P4OUT
#define LIGHTSEL P4SEL
#define LIGHT    BIT2
#define LIGHTCONTROL TB0CCTL2
#define LIGHTLEVEL TB0CCR2

#define MOTORDIR P4DIR
#define MOTOROUT P4OUT
#define MOTORSEL P4SEL
#define MOTOR    BIT1
#define MOTORCONTROL TB0CCTL1
#define MOTORLEVEL TB0CCR1

#define BATINDIR P6DIR
#define BATINSEL P6SEL
#define BATININ  P6IN
#define BATINPIN BIT7
#define BATLEVEL BIT4

#define BATOUTDIR P7DIR
#define BATOUTREN P7REN
#define BATOUTOUT P7OUT
#define BATOUTPIN BIT5


#define CLKDIR P3DIR
#define CLKSEL P3SEL
#define CLKOUT P3OUT
#define CLKPIN BIT6

#define SPIDIR P5DIR
#define SPISEL P5SEL
#define SPIOUT P5OUT
#define SIPIN  BIT6
#define SOPIN  BIT7
#define CSPIN  BIT5

#define LCDSPIOUT  P3OUT
#define LCDSPIDIR  P3DIR
#define LCDSPISEL  P3SEL

#define V5VOUT  P6OUT
#define V5VDIR  P6DIR
#define V5BIT   BIT6

#define LCD_SCLK BIT3          // SPI clock
#define LCD_SDATA  BIT1          // SPI data (sent to display)
#define LCD_SCS  BIT0          // SPI chip select

#define LCDEXTCOMMDIR P4DIR
#define LCDEXTCOMMSEL P4SEL
#define LCDEXTCOMMOUT P4OUT
#define LCDEXTCOMMPIN BIT3

#define LCDENDIR P8DIR
#define LCDENOUT P8OUT
#define LCDENPIN BIT2

#define AUDOUT P10OUT
#define AUDDIR P10DIR
#define AUDBIT BIT6

#define SMCLKSEL P11SEL
#define SMCLKDIR P11DIR
#define SMCLKBIT BIT2

#define BT_ACLK_SEL   P11SEL
#define BT_ACLK_DIR   P11DIR
#define BT_ACLK_BIT   BIT0    // P11.0 ACLK 32Khz -> BT

#define BT_SHUTDOWN_SEL P10SEL
#define BT_SHUTDOWN_DIR P10DIR
#define BT_SHUTDOWN_OUT P10OUT
#define BT_SHUTDOWN_BIT BIT7    // P10.7 nShutdown

// TXD P3.4
#define BT_TXD_OUT      P3OUT
#define BT_TXD_SEL      P3SEL
#define BT_TXD_DIR      P3DIR
#define BT_TXD_BIT      BIT4

// RXD P3.5
#define BT_RXD_OUT      P3OUT
#define BT_RXD_SEL      P3SEL
#define BT_RXD_DIR      P3DIR
#define BT_RXD_BIT      BIT5

// RTS P1.4
#define BT_RTS_OUT      P1OUT
#define BT_RTS_SEL      P1SEL
#define BT_RTS_DIR      P1DIR
#define BT_RTS_BIT      BIT4

// CTS P1.3
#define BT_CTS_OUT      P1OUT
#define BT_CTS_SEL      P1SEL
#define BT_CTS_DIR      P1DIR
#define BT_CTS_IFG      P1IFG
#define BT_CTS_IES      P1IES
#define BT_CTS_IE       P1IE
#define BT_CTS_IN       P1IN
#define BT_CTS_BIT      BIT3

//P9.7 nOE SLOW clk
#define OECLKDIR    P9DIR
#define OECLKOUT    P9OUT
#define OECLKBIT    BIT7

//P9.2 nOE HCI 
#define OEHCIDIR    P9DIR
#define OEHCIOUT    P9OUT
#define OEHCIBIT    BIT2

//P8.7 nOE CODEC
#define PCODECDIR P8DIR
#define PCODECOUT P8OUT
#define PCODECBIT BIT7


//P6.2 1.8v 
#define BTPOWERDIR    P6DIR
#define BTPOWEROUT    P6OUT
#define BTPOWERBIT    BIT2

#define UARTOUT P1OUT
#define UARTSEL P1SEL
#define UARTDIR P1DIR
#define UARTIES P1IES
#define UARTIE  P1IE
#define UARTIFG P1IFG
#define UARTIN  P1IN

#define UARTTXBIT BIT1
#define UARTRXBIT BIT2