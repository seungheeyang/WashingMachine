/*
* stateController.c
*
* Created: 2020-10-09 오후 4:48:16
*  Author: kccistc
*/

#include "stateController.h"

uint8_t state=COMMON;

uint8_t getStateExcute()
{
	return state;
}

void setStateExcute(uint8_t data)
{
	state = data;
}

void stateExcute()
{
	switch(getStateExcute())
	{
		case COMMON:
		checkBtnCnt();
		
		break;
		
		case WASH:
		washing();
		if (getButtonReset())
		{
			setBtn3cnt(0);
			setBtn4cnt(0);
			setBtn5cnt(0);
			LCD_Init();
			setStateExcute(COMMON);
			setSelectMode(USUAL);
			setCardState(INITIAL);
			MOTOR_DDR &= ~(1<<MOTOR_PIN);
			DDRA &= ~((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
			//setStateExcute(RESET);
		}
		break;
		
		case RINSE:
		rinsing();
		if (getButtonReset())
		{
			setBtn3cnt(0);
			setBtn4cnt(0);
			setBtn5cnt(0);
			LCD_Init();
			setStateExcute(COMMON);
			setSelectMode(USUAL);
			setCardState(INITIAL);
			MOTOR_DDR &= ~(1<<MOTOR_PIN);
			DDRA &= ~((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
			//setStateExcute(RESET);
		}
		break;
		
		case SPINDRY:
		spinDry();
		if (getButtonReset())
		{
			setBtn3cnt(0);
			setBtn4cnt(0);
			setBtn5cnt(0);
			LCD_Init();
			setStateExcute(COMMON);
			setSelectMode(USUAL);
			setCardState(INITIAL);
			MOTOR_DDR &= ~(1<<MOTOR_PIN);
			DDRA &= ~((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
			//setStateExcute(RESET);
		}
		break;
		
		case FINISH:
		finish();
		if (getButtonReset())
		{
			setBtn3cnt(0);
			setBtn4cnt(0);
			setBtn5cnt(0);
			LCD_Init();
			setSelectMode(USUAL);
			//setStateExcute(RESET);
		}
		break;
	}
}

void finish()
{
	LCD_Init();
	LCD_WriteStringXY(0,0,"     FINISH     ");
	_delay_ms(3000);
	setStateExcute(COMMON);
	setSelectMode(USUAL);
	setCardState(INITIAL);
}

void pause()
{
	if(getButtonPause()==0)
	{
		MOTOR_DDR &= ~(1<<MOTOR_PIN);
		DDRA &= ~((1<<0) | (1<<1));
		TIMSK &= ~(1<<OCIE0);
	}
	else if(getButtonPause()==1)
	{
		DCmotorRun();
		DDRA |= (1<<0) | (1<<1);
		PORTA &= ~((1<<2) | (1<<3));
		TIMSK |= (1<<OCIE0);
	}
}
