
#ifndef UNUSED
#define UNUSED(x) 									( (void)(x) )
#endif

#define ENABLE_GPIO_EMULATE
// #define ENABLE_SPI

#if defined (ENABLE_GPIO_EMULATE)
#define set_LEDGPIO(x)							(P00 = x)
#define LEDGPIO									(P00)
#endif

//debug purpose
// #define ENABLE_DEBUG_WS2812_PROTOCOL

#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
#define LED_NUM 								(1)
#else
#define LED_NUM 								(24)
#endif

#define LED_DATA_LEN 							(LED_NUM * 3)

#define MS_LED_LATCH							(450)		//(2000ul)
#define DEMO_MS									(500ul)		//(5000ul)
#define MS_1MS									(1500)

#define HEARTBEAT_STEPS							(128)		//(16)
#define COLORTALBE_NUM							(766)

#define ENABLE_EXTRA_DEMO

//#define PACK_RGB(r,g,b)							((g<<16)+(r<<8)+b)
//#define UNPACK_R(data)							(unsigned char)((data>>8)&0xFF)
//#define UNPACK_G(data)							(unsigned char)((data>>16)&0xFF)
//#define UNPACK_B(data)							(unsigned char)((data)&0xFF)

/*

	T1H 1 HIGH 580ns~1É s		target : 0.750 us
	T1L 1 LOW 220ns~420ns		target : 0.375 us
	
	T0H 0 HIGH 220ns~380ns		target : 0.375 us
	T0L 0 LOW 580ns~1É s			target : 0.750 us

	if SPI freq : 7M	(clock bit : 143 ns)
		- TH1 : 143 * 6
		- TL1 : 143 * 2
 	_____   
	|     |___|   1111 1100  high level (0xFC)
 	___         
	|   |_____|   1100 0000  low level (0xC0)

	if SPI freq : 8M	(clock bit : 125 ns)
		- TH1 : 125 * 5
		- TL1 : 125 * 3

		1111 1000  high level	(0xF8)		
		1110 0000  low level	(0xE0)	
*/
#define WS_SPI_HIGH 								(0xFC)
#define WS_SPI_LOW	 								(0xC0)

// #define WS_SPI_HIGH 								(0xF8)
// #define WS_SPI_LOW	 								(0xE0)

#define WS_RES_POS_FRONT							(0) 
#define WS_RES_POS_BACK 							(1) 

enum
{
	state_Default = 0,

	state_Rainbow,
	state_RainbowCycle ,	
	state_TheaterChase,	
	state_TheaterChaseRainbow ,
	state_RGBSequence,
	state_AlternateColors,	
	state_FullEmpty,
	state_PatternMove,
#if defined (ENABLE_EXTRA_DEMO)	
	state_ColorWheel,
	state_AllColors = 49,		//a
#endif	
	state_HeartBeat = 50,		//b
	state_CircularRing = 51,	//c
	state_FromAToB = 52,		//d

	state_Max,
};


extern bit trans_finish_flag;
extern xdata unsigned char DataBuffer[LED_DATA_LEN];
extern unsigned char DemoState;

void setLED_delayus(unsigned int dly);

void setLED_delayms(unsigned int ms);

void WS2812C_DATA1(void);

void WS2812C_DATA0(void);

void WS2812C_Send_1Byte(unsigned char Data);

// void WS2812C_Send_1bit(unsigned char Data);

void setLED_ResetPulse(unsigned char pos);

void setLED_Display(unsigned int DataCount);

void setLED_BufferClear(void);

void setLED_Color(unsigned char DeviceNumber ,unsigned char RED, unsigned char GREEN, unsigned char BLUE);

void setLED_ColorWipe(unsigned char RED, unsigned char GREEN, unsigned char BLUE);

void setLED_ColorIdxChange(void);

void _stripEffect_Rainbow(unsigned char* RED, unsigned char* GREEN, unsigned char* BLUE);

unsigned char _stripEffect_Wheel(unsigned char WheelPos , unsigned char* RED, unsigned char* GREEN, unsigned char* BLUE);

void getFromAToB(unsigned int time, unsigned int steps, 
		unsigned char redA,	unsigned char greenA, unsigned char blueA, 
		unsigned char redB, unsigned char greenB, unsigned char blueB);

void getCircularRing(unsigned int time, unsigned char red, unsigned char green,unsigned char blue);

void getHeartBeat(unsigned int time, unsigned char red, unsigned char green,unsigned char blue);

#if defined (ENABLE_EXTRA_DEMO)
void getAllColors(unsigned int time);

void getColorWheel(unsigned int time);
#endif /*ENABLE_EXTRA_DEMO*/

void getPatternMove(unsigned int time, unsigned int parts, unsigned char red,unsigned char green, unsigned char blue);

void getFullEmpty(unsigned int time, unsigned char red, unsigned char green,unsigned char blue);

void getAlternateColors(unsigned int time, unsigned int steps,
		unsigned char redA, unsigned char greenA, unsigned char blueA, 
		unsigned char redB, unsigned char greenB, unsigned char blueB);

void getRGBSequence(unsigned int time);

void getTheaterChaseRainbow(unsigned int time);

void getTheaterChase(unsigned int time ,unsigned char RED, unsigned char GREEN, unsigned char BLUE);

void getRainbowCycle(unsigned char cycle , unsigned int time);

void getRainbow(unsigned int time);

void getBreathing(unsigned int time);

void StateMachine(void);

