/*
* timeTick.c
*
* Created: 2021-09-26 오전 14:32:31
*  Author: Seunghee Yang
*/

#include "timeTick.h"

uint32_t timeTick = 0;
uint8_t sec=0;
uint8_t min=0;
uint8_t second=0;
uint8_t minute=0;

extern uint8_t washingFlag;
extern uint8_t rinsingFlag;
extern uint8_t spinDryFlag;
extern uint8_t ManualWashingTimeFlag;
extern uint8_t autoWashingTimeFlag;

void timeTickInit()
{
	//TCNT0, 1ms간격으로 Timer- Interrupt 발생
	//64분주 CS02:1, CS01:0 CS00:0
	TCCR0 |= (1<<CS02);
	//CTC mode WGM01 : 1, WGM00 : 0
	TCCR0 |=(1<<WGM01);
	OCR0 = 250-1;	//1ms 간격으로 인터럽트 발생
	//비교일치 0 인터럽트 발생 마스크 SET
	TIMSK |= (1<<OCIE0);
}

uint32_t getTimeTick()
{
	return timeTick;
}

void incTimeTick()
{
	timeTick++;

	if (washingFlag == 1)
	{
		timeTick=0;
		washingFlag = 0;
	}
	
	if (rinsingFlag ==1)
	{
		timeTick=0;
		rinsingFlag = 0;
	}
	
	if (spinDryFlag ==1)
	{
		timeTick=0;
		spinDryFlag = 0;
	}
	if (ManualWashingTimeFlag ==1)
	{
		timeTick=0;
		ManualWashingTimeFlag = 0;
	}
	if (autoWashingTimeFlag ==1)
	{
		timeTick=0;
		autoWashingTimeFlag = 0;
	}
}

