/*
* stateWashing.c
*
* Created: 2020-10-09 오후 5:13:13
*  Author: kccistc
*/

#include "stateWashing.h"

extern uint8_t button3count;
uint8_t washingFlag=0;

void washing()
{
	//pause();
	washingPross();
}


void washingPross()
{
	 uint32_t delayTime1 = 500;
	 uint32_t servoSetTime = 2500;
	 uint32_t DCflagTime1 = 4500;
	 uint32_t DCsetTime1 = 6500;
	
	uint32_t curTime = 0;
	curTime = getTimeTick();
	

		

	if ((curTime >= delayTime1) && (curTime < servoSetTime))
	{
		DCmotorStop();
		servoRun(90);
		_delay_ms(200);
	}

	else if ((curTime >= servoSetTime) && (curTime < DCflagTime1))
	{
		servoRun(0);
		_delay_ms(200);  
		DCmotorRun();
		revolveRight();
		OCR3A = 39999;
	}
	
	else if ((curTime >= DCflagTime1) && (curTime < DCsetTime1))
	{
		DCmotorRun();
		revolveLeft();
		OCR3A = 39999;
	}
	
	else if (curTime >= DCsetTime1)
	{
		DCmotorStop();
		washingFlag=1;
		setBtn3cnt(getBtn3cnt()-1);
		setStateExcute(COMMON);
	}
	
	
}