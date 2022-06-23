/*_____ I N C L U D E S ____________________________________________________*/
#include "ML51.h"

#include "project_config.h"
#include "LED_stripe.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
// xdata volatile uint8_t u8TH0_Tmp = 0;
// xdata volatile uint8_t u8TL0_Tmp = 0;

#define TH0_INIT        						(HIBYTE(TIMER_DIV12_VALUE_1ms_FOSC_240000)) 
#define TL0_INIT        						(LOBYTE(TIMER_DIV12_VALUE_1ms_FOSC_240000))

//UART 0
bit BIT_UART;
bit uart0_receive_flag=0;
unsigned char uart0_receive_data;


uint16_t counter = 0;
/*_____ D E F I N I T I O N S ______________________________________________*/
volatile uint32_t BitFlag = 0;
volatile uint32_t counter_tick = 0;

/*_____ M A C R O S ________________________________________________________*/
#define SYS_CLOCK 								(24000000ul)


/*_____ F U N C T I O N S __________________________________________________*/


void tick_counter(void)
{
	counter_tick++;
}

uint32_t get_tick(void)
{
	return (counter_tick);
}

void set_tick(uint32_t t)
{
	counter_tick = t;
}

//void compare_buffer(uint8_t *src, uint8_t *des, int nBytes)
//{
//    uint16_t i = 0;	
//	
//    for (i = 0; i < nBytes; i++)
//    {
//        if (src[i] != des[i])
//        {
//            printf("error idx : %4d : 0x%2X , 0x%2X\r\n", i , src[i],des[i]);
//			set_flag(flag_error , Enable);
//        }
//    }

//	if (!is_flag_set(flag_error))
//	{
//    	printf("compare_buffer finish \r\n");	
//		set_flag(flag_error , Disable);
//	}

//}

//void reset_buffer(void *dest, unsigned int val, unsigned int size)
//{
//    uint8_t *pu8Dest;
////    unsigned int i;
//    
//    pu8Dest = (uint8_t *)dest;

//	#if 1
//	while (size-- > 0)
//		*pu8Dest++ = val;
//	#else
//	memset(pu8Dest, val, size * (sizeof(pu8Dest[0]) ));
//	#endif
//	
//}

//void copy_buffer(void *dest, void *src, unsigned int size)
//{
//    uint8_t *pu8Src, *pu8Dest;
//    unsigned int i;
//    
//    pu8Dest = (uint8_t *)dest;
//    pu8Src  = (uint8_t *)src;


//	#if 0
//	  while (size--)
//	    *pu8Dest++ = *pu8Src++;
//	#else
//    for (i = 0; i < size; i++)
//        pu8Dest[i] = pu8Src[i];
//	#endif
//}

//void dump_buffer(uint8_t *pucBuff, int nBytes)
//{
//    uint16_t i = 0;
//    
//    printf("dump_buffer : %2d\r\n" , nBytes);    
//    for (i = 0 ; i < nBytes ; i++)
//    {
//        printf("0x%2X," , pucBuff[i]);
//        if ((i+1)%8 ==0)
//        {
//            printf("\r\n");
//        }            
//    }
//    printf("\r\n\r\n");
//}

//void  dump_buffer_hex(uint8_t *pucBuff, int nBytes)
//{
//    int     nIdx, i;

//    nIdx = 0;
//    while (nBytes > 0)
//    {
//        printf("0x%04X  ", nIdx);
//        for (i = 0; i < 16; i++)
//            printf("%02X ", pucBuff[nIdx + i]);
//        printf("  ");
//        for (i = 0; i < 16; i++)
//        {
//            if ((pucBuff[nIdx + i] >= 0x20) && (pucBuff[nIdx + i] < 127))
//                printf("%c", pucBuff[nIdx + i]);
//            else
//                printf(".");
//            nBytes--;
//        }
//        nIdx += 16;
//        printf("\n");
//    }
//    printf("\n");
//}

void delay(uint16_t dly)
{
/*
	delay(100) : 14.84 us
	delay(200) : 29.37 us
	delay(300) : 43.97 us
	delay(400) : 58.5 us	
	delay(500) : 73.13 us	
	
	delay(1500) : 0.218 ms (218 us)
	delay(2000) : 0.291 ms (291 us)	
*/

	while( dly--);
}


//void send_UARTString(uint8_t* Data)
//{
//	#if 1
//	uint16_t i = 0;

//	while (Data[i] != '\0')
//	{
//		#if 1
//		SBUF = Data[i++];
//		#else
//		UART_Send_Data(UART0,Data[i++]);		
//		#endif
//	}

//	#endif

//	#if 0
//	uint16_t i = 0;
//	
//	for(i = 0;i< (strlen(Data)) ;i++ )
//	{
//		UART_Send_Data(UART0,Data[i]);
//	}
//	#endif

//	#if 0
//    while(*Data)  
//    {  
//        UART_Send_Data(UART0, (unsigned char) *Data++);  
//    } 
//	#endif
//}

//void send_UARTASCII(uint16_t Temp)
//{
//    uint8_t print_buf[16];
//    uint16_t i = 15, j;

//    *(print_buf + i) = '\0';
//    j = (uint16_t)Temp >> 31;
//    if(j)
//        (uint16_t) Temp = ~(uint16_t)Temp + 1;
//    do
//    {
//        i--;
//        *(print_buf + i) = '0' + (uint16_t)Temp % 10;
//        (uint16_t)Temp = (uint16_t)Temp / 10;
//    }
//    while((uint16_t)Temp != 0);
//    if(j)
//    {
//        i--;
//        *(print_buf + i) = '-';
//    }
//    send_UARTString(print_buf + i);
//}

void WS2812C_Init(void)
{
	#if defined (ENABLE_SPI)

	#if 1
    /* Set LED output */
    P00 = 1;
    P00_INPUT_MODE;
    ENABLE_P00_PULLDOWN;
	#endif


    MFP_P00_SPI0_MOSI;
    // P00_QUASI_MODE;

    MFP_P02_SPI0_CLK;       /*define  SPI0 CLK pin */
    P02_QUASI_MODE;	
	#if 0
    MFP_P01_SPI0_MISO;      /*define  SPI0 MISO pin */
    P01_QUASI_MODE;

    MFP_P03_GPIO;           /*define  SPI0 SS pin as normal GPIO*/
    P03_PUSHPULL_MODE;
	#endif

    set_SPI0SR_DISMODF;                                	// SS General purpose I/O ( No Mode Fault )
    clr_SPI0CR0_SSOE;

    clr_SPI0CR0_LSBFE;                                  // MSB first

    clr_SPI0CR0_CPOL;                                   // The SPI clock is low in idle mode
    clr_SPI0CR0_CPHA;                                   // The data is sample on the second edge of SPI clock

    set_SPI0CR0_MSTR;                                   // SPI in Master mode
    SPI0_CLOCK_DIV_3;                                	// Select SPI clock
    set_SPI0CR0_SPIEN;                                  // Enable SPI function
    clr_SPI0SR_SPIF;

	#elif defined (ENABLE_GPIO_EMULATE)
	P00_PUSHPULL_MODE;
	P02_PUSHPULL_MODE;	// for debug
	#endif
}


void loop(void)
{
	static uint8_t flag_first_pwr_on = 1;

	if (is_flag_set(flag_1000ms))
	{
		set_flag(flag_1000ms , FALSE);
		P32 ^= 1;		
		SFRS = 0;printf("log :%d\r\n" , counter++);		
	}

    if (RI)
    {   
		clr_SCON_RI;                                         // Clear RI (Receive Interrupt).

		if (flag_first_pwr_on)
		{
			DemoState = state_Rainbow;
			flag_first_pwr_on = 0;
		}
		else
		{
			DemoState = SBUF - 0x30;
		}

		SFRS = 0;printf("DemoState = %bu,%bc\r\n" , DemoState, SBUF);
    }

	if (!trans_finish_flag)
	{
		#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
		setLED_ColorWipe(0xFF, 0x00, 0x00);
		setLED_delayms(1);
		#else

		StateMachine();
		#endif
	}	
}


void GPIO_Init(void)
{
    MFP_P32_GPIO;
    P32_PUSHPULL_MODE;	
		

//	P30_PUSHPULL_MODE;	
}

void Timer0_IRQHandler(void)
{
	tick_counter();

	if ((get_tick() % 1000) == 0)
	{
		set_flag(flag_1000ms , TRUE);
	}

	if ((get_tick() % 50) == 0)
	{

	}		

}

void Timer0_ISR(void) interrupt 1        // Vector @  0x0B
{
	_push_(SFRS);	
	SFRS = 0;

	clr_TCON_TF0;		
	TH0 = TH0_INIT;
	TL0 = TL0_INIT;

	Timer0_IRQHandler();
	_pop_(SFRS);	
}

void Timer0_Init(void)
{
	ENABLE_TIMER0_MODE1;
	TIMER0_FSYS_DIV12;

	TH0 = TH0_INIT;
	TL0 = TL0_INIT;
	clr_TCON_TF0;

	set_TCON_TR0;                                  //Timer0 run
	
	ENABLE_TIMER0_INTERRUPT;                       //enable Timer0 interrupt
	ENABLE_GLOBAL_INTERRUPT;                       //enable interrupts	
}


// void Serial_ISR (void) interrupt 4 
// {
//     _push_(SFRS);

//     if (RI)
//     {   
//       uart0_receive_flag = 1;
//       uart0_receive_data = SBUF;
//       clr_SCON_RI;                                         // Clear RI (Receive Interrupt).
//     }
//     if  (TI)
//     {
// 		clr_SCON_TI;
// 		//      if(!BIT_UART)
// 		//      {
// 		//          TI = 0;
// 		//      }
//     }

//     _pop_(SFRS);	
// }


void UART0_Init(void)
{
	MFP_P31_UART0_TXD;                              
	P31_QUASI_MODE;                                 
	MFP_P30_UART0_RXD;
	P30_QUASI_MODE;	

	SFRS = 0x00;
	SCON = 0x50;            	/*UART0 Mode1,REN=1,TI=1*/
	set_PCON_SMOD;          	/*UART0 Double Rate Enable*/
	T3CON &= 0xF8;           	/*T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)*/
	set_T3CON_BRCK;          	/*UART0 baud rate clock source = Timer3*/
	RH3    = 0xFF;   					/* HIBYTE(65536 - 13)*/
	RL3    = 0xF3;   					/* LOBYTE(65536 - 13); */
	set_T3CON_TR3;          	/*Trigger Timer3*/

	set_SCON_RI;
	set_SCON_TI;
	BIT_UART = 1;

	// ENABLE_UART0_INTERRUPT;                                   /* Enable UART0 interrupt */
	// ENABLE_GLOBAL_INTERRUPT;                                  /* Global interrupt enable */

	SFRS = 0;printf("\r\n\r\n\r\n\r\nUART0_Init\r\n");
}

void SYS_Init(void)
{
//	FsysSelect(FSYS_HIRC);

    ALL_GPIO_QUASI_MODE;
//    ENABLE_GLOBAL_INTERRUPT;                // global enable bit	
}

void main (void) 
{
	SYS_Init();

	UART0_Init();
	GPIO_Init();

    WS2812C_Init();
	// setLED_ColorWipe(0, 0, 0);

	Timer0_Init();

	while(1)
	{
		loop();

	}
}



