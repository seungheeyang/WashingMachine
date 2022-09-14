/*
 * button.c
 *
 * Created: 2020-09-25 오전 9:57:46
 *  Author: kccistc
 */ 
#include "button.h"
         


void buttonInit()
{
	BUTTON_DDR &= ~((1<<BUTTON1) | (1<<BUTTON2) | (1<<BUTTON3) | (1<<BUTTON4) | (1<<BUTTON5) | (1<<BUTTON_RESET));
	BUTTON_PIN |= ((1<<BUTTON1) | (1<<BUTTON2) | (1<<BUTTON3) | (1<<BUTTON4) | (1<<BUTTON5) | (1<<BUTTON_RESET));	//내부 풀업상태
	BUTTON_DDR &= (1<<BUTTON_PAUSE);
	BUTTON_PIN |= (1<<BUTTON_PAUSE);
} 

uint8_t readButton(uint8_t button)
{
	return BUTTON_PIN & (1<<button);
}


uint8_t getButtonPause()
{
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON_PAUSE);
	
	if (curButtonState == PUSHED)
	{
		return 1;
	}
		return 0;
}

uint8_t getButton1State()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON1);
	
	if (curButtonState == PUSHED && prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}

uint8_t getButton2State()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON2);
	
	if (curButtonState == PUSHED &&prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}

uint8_t getButton3State()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON3);
	
	if (curButtonState == PUSHED &&prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}

uint8_t getButton4State()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON4);
	
	if (curButtonState == PUSHED &&prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}

uint8_t getButton5State()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON5);
	
	if (curButtonState == PUSHED &&prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}

uint8_t getButtonReset()
{
	static uint8_t prevButtonState = RELEASED;
	uint8_t curButtonState;
	curButtonState = readButton(BUTTON_RESET);
	
	if (curButtonState == PUSHED &&prevButtonState == RELEASED)
	{
		prevButtonState = PUSHED;
		_delay_ms(100);
		return 0;
	}
	else if (curButtonState != PUSHED && prevButtonState ==PUSHED)
	{
		prevButtonState = RELEASED;
		_delay_ms(100);
		return 1;
	}
	return 0;
}