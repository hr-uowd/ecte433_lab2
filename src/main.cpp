/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "mbed.h"
#include "uowd_include.h"
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"

TS_StateTypeDef  TS_State;


int main( ){
	uowd_init();//custom initialization and setup by UOWD. Should be first in main
	DigitalOut myled(PI_1);
	DigitalIn myswitch(PI_11);
	Serial computer(STDIO_UART_TX,STDIO_UART_RX);

	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	uint8_t no_of_touches;

	while(1){
		no_of_touches = TS_State.touchDetected;
		if(TS_State.touchDetected){
		computer.printf("the number of touches : %d\n\r", no_of_touches);
		}

	}
}







