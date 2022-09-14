/*
* automatic.c
*
* Created: 2020-10-11 오후 8:00:34
*  Author: rjsdn
*/

#include "automaticMode.h"

uint8_t autoWashingTimeFlag=0;

void atuomaticMode()
{
	LCD_WriteStringXY(0,0,"<AUTO>    wash:1");
	LCD_WriteStringXY(1,0,"rinse:1   dry:1");
	
	setBtn3cnt(1);
	setBtn4cnt(1);
	setBtn5cnt(1);
	
	autoWashingTimeFlag = 1;
	_delay_ms(10);
	setSelectMode(MOVE);
	
	if ((getBtn3cnt()==0) && (getBtn4cnt()==0) && (getBtn5cnt()==0))
	{
		setSelectMode(AUTOMATIC);
	}

	if (getButtonReset())
	{
		setBtn3cnt(0);
		setBtn4cnt(0);
		setBtn5cnt(0);
		LCD_Init();
		setSelectMode(USUAL);
	}
}
