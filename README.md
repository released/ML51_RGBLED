# ML51_RGBLED
 ML51_RGBLED

update @ 2022/06/23

1. initial P0.0 to drive WS2812 LED , also use P0.2 for debug or monito SPI clk

2. enable #define ENABLE_GPIO_EMULATE or ENABLE_SPI , for 2 methods to drive LED

3. enable #define ENABLE_DEBUG_WS2812_PROTOCOL , to check single LED and monitor BIT1 , BIT0 width

4. under terminal , press digit 1~ 9 , 0 , or letter a ~ d , to check LED pattern

5. below is terminal log message

![image](https://github.com/released/ML51_RGBLED/blob/main/log.jpg)

LA capture when enable #define ENABLE_DEBUG_WS2812_PROTOCOL 

![image](https://github.com/released/ML51_RGBLED/blob/main/GPIO_EMULATE_ONE_LED_LA.jpg)

scope capture BIT1 , high period / low period , total period

![image](https://github.com/released/ML51_RGBLED/blob/main/GPIO_EMULATE_ONE_LED_high.jpg)

scope capture BIT0 , high period / low period , total period

![image](https://github.com/released/ML51_RGBLED/blob/main/GPIO_EMULATE_ONE_LED_low.jpg)

