/*
* washingMachine.c
*
* Created: 2020-10-08 오후 5:59:40
* Author : kccistc
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "./Control/stateController.h"
#include "./Device/buzzer.h"
#include "./Device/DCmotor.h"
#include "./Device/servo.h"
#include "timeTick.h"
#include "./Device/I2C_LCD.h"
#include "./Device/spi.h"
#include "./Device/mfrc522.h"
#include "./Device/button.h"

#include "./Control/stateCommon.h"

ISR(TIMER0_COMP_vect)
{
	incTimeTick();		//1ms
}

int main(void)
{
	DDRA = 0xff;
	
	sei();
	
	buttonInit();
	servoInit();
	DCmotorInit();
	timeTickInit();
	LCD_Init();

	spi_init();
	mfrc522_init();

	buzzerInit();
	
	servoRun(0);
	_delay_ms(200);
	
	while (1)
	{
// 		if (getButtonPause()==1)	//1이 눌린거
// 		{
// 			PORTA |= (1<<2) | (1<<3);
// 		}
// 		else
// 		{
// 			PORTA &= ~((1<<2) | (1<<3));
// 		}
		readyWashing();
	}
}

