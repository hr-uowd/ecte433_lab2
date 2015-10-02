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
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"

TS_StateTypeDef  TS_State;


int main( ){
	uowd_init();//custom initialization and setup by UOWD. Should be first in main
	DigitalOut myled(PI_1);
	DigitalIn myswitch(PI_11);
	Serial computer(STDIO_UART_TX,STDIO_UART_RX);
	LCD_Config();

	BSP_LCD_Clear(LCD_COLOR_BLUE);
	//char mymesg[28];

	BSP_LCD_Clear(LCD_COLOR_WHITE);
	//BSP_LCD_DisplayStringAtLine(0, (uint8_t *) "SWITCH RELEASED" );


	BSP_LCD_Clear(LCD_COLOR_WHITE);
	myled = 1;

	//Touchscreen_demo();

	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());


	uint16_t x, y;
	uint8_t touch_weight;


	while(1){

		BSP_TS_GetState(&TS_State);

		if(TS_State.touchDetected){
		touch_weight = TS_State.touchWeight[0];
		computer.printf("the touch weight is : %d\n\r", touch_weight);
		}



		//x = TS_State.touchDetected;
		//computer.printf("no of touches : %d\n\r", x);




		//if(TS_State.touchDetected)
		      //{
		    	  //myled = 1;
		    	  x = TS_State.touchX[0];
		    	  y = TS_State.touchY[0];
		    	  //computer.printf(" touch [%d , %d]\n\r", x, y);

		      //}
		      //else myled = 0;




		//if(myswitch){
			//BSP_LCD_Clear(LCD_COLOR_BLACK);
			//BSP_LCD_DisplayStringAtLine(0, (uint8_t *) "SWITCH PRESSED" );
			//while(myswitch);
			//BSP_LCD_Clear(LCD_COLOR_BLACK);
			//BSP_LCD_DisplayStringAtLine(0, (uint8_t *) "SWITCH RELEASED" );
		//}




	}
}







