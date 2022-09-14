/*
* modeSelect.c
*
* Created: 2020-10-11 오후 6:26:53
*  Author: rjsdn
*/

#include "selectMode.h"

char washbuff[10];
char rinsebuff[10];
char drybuff[10];

static uint8_t button1Count = 0;
uint8_t selectMode = USUAL;

uint8_t getSelectMode()
{
	return selectMode;
}

void setSelectMode(uint8_t data)
{
	selectMode = data;
}

void selectModeState()
{
	switch (getSelectMode())
	{
		case USUAL:
		usualMode();
		break;
		
		case MANUAL:
		manualMode();
		break;
		
		case AUTOMATIC:
		atuomaticMode();
		break;
		
		case MOVE:
		LCD_WriteStringXY(0,0,"<Manual>  wash:");
		sprintf(washbuff,"%d",getBtn3cnt());
		LCD_WriteStringXY(0,15,washbuff);
		
		LCD_WriteStringXY(1,0,"rinse:");
		sprintf(rinsebuff,"%d",getBtn4cnt());
		LCD_WriteStringXY(1,6,rinsebuff);
		
		LCD_WriteStringXY(1,10,"dry:");
		sprintf(drybuff,"%d",getBtn5cnt());
		LCD_WriteStringXY(1,14,drybuff);		
		stateExcute();
		break;
		
// 		case PAUSE:
// 		pause();
// 		break;
	}
}
// 
// void pause()
// {
// 	DCmotorStop();
// }

void usualMode()
{
	LCD_GotoXY(0,0);
	LCD_WriteString("   select Mode  ");
	
	if (getButton1State())
	{
		button1Count++;
		if (button1Count%2 == 0)
		{
			//자동
			LCD_GotoXY(1,0);
			LCD_WriteString("    Automatic    ");
		}
		
		else if (button1Count%2 == 1)
		{
			//수동
			LCD_GotoXY(1,0);
			LCD_WriteString("     Manual      ");
		}
	}
	
	if (getButton2State() && (button1Count != 0))
	{
		if (button1Count%2 == 0)
		{
			//set 자동
			setSelectMode(AUTOMATIC);
		}
		
		else if (button1Count%2 == 1)
		{
			//set 수동
			setSelectMode(MANUAL);
			_delay_ms(500);
			LCD_Init();
		}
	}
}