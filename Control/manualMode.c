/*
* manual.c
*
* Created: 2020-10-11 오후 8:00:50
*  Author: rjsdn
*/

#include "manualMode.h"

 uint8_t button3count = 0;
 uint8_t button4count = 0;
 uint8_t button5count = 0;
uint8_t ManualWashingTimeFlag = 0;

char washbuff[10];
char rinsebuff[10];
char drybuff[10];

uint8_t getBtn3cnt()
{
	return button3count;
}

void setBtn3cnt(uint8_t data)
{
	button3count = data;
}

uint8_t getBtn4cnt()
{
	return button4count;
}

void setBtn4cnt(uint8_t data)
{
	button4count = data;
}

uint8_t getBtn5cnt()
{
	return button5count;
}

void setBtn5cnt(uint8_t data)
{
	button5count = data;
}

void manualMode()
{
	LCD_WriteStringXY(0,0,"<Manual>  wash:");
	sprintf(washbuff,"%d",getBtn3cnt());
	LCD_WriteStringXY(0,15,washbuff);
	
	LCD_WriteStringXY(1,0,"rinse:");
	sprintf(rinsebuff,"%d",getBtn4cnt());
	LCD_WriteStringXY(1,6,rinsebuff);
	
	LCD_WriteStringXY(1,10,"dry:");
	sprintf(drybuff,"%d",getBtn5cnt());
	LCD_WriteStringXY(1,14,drybuff);
	
	if (getButton3State())
	{
 		button3count++;
 	}
	
	if (getButton4State())
	{
		button4count++;
	}
	
	if (getButton5State())
	{
		button5count++;
	}
	
	if (getButton2State())	//확인버튼
	{
		ManualWashingTimeFlag = 1;
		_delay_ms(10);
		setSelectMode(MOVE);
		
		if ((getBtn3cnt()==0) && (getBtn3cnt()==0) && (getBtn3cnt()==0))
		{
			setSelectMode(MANUAL);
		}
	}
	
	if (getButtonReset())
	{
		setBtn3cnt(0);
		setBtn4cnt(0);
		setBtn5cnt(0);
		LCD_Init();
		setSelectMode(USUAL);
		//setStateExcute(RESET);
	}
}

