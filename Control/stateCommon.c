/*
* stateCommon.c
*
* Created: 2020-10-09 오후 6:46:45
*  Author: kccistc
*/

#include "stateCommon.h"


void readyWashing()
{
	switch(getCardState())
	{
		case INITIAL:
		checkCard();
		LCD_GotoXY(0,0);
		LCD_WriteString("  Tag the card   ");
		break;
		
		case INVALID:
		LCD_GotoXY(0,0);
		LCD_WriteString("  Invalid card  ");
		_delay_ms(500);
		setCardState(INITIAL);
		break;
		
		case VALID:
		powerONbuzzer();
		LCD_GotoXY(0,0);
		LCD_WriteString("   valid card   ");
		_delay_ms(1000);
		LCD_Init();
		setCardState(MODE);
		break;
		
		case MODE:
		selectModeState();
		break;
	}
}