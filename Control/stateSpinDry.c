/*
* stateSpinDry.c
*
* Created: 2020-10-09 오후 6:48:00
*  Author: kccistc
*/

#include "stateSpinDry.h"

uint32_t spinDryFlag = 0;
extern uint8_t button5count;

void spinDry()
{
	//pause();
	spinDryPross();
	//	setBtn5cnt(getBtn5cnt()-1);
}

void spinDryPross()
{
	static uint32_t delayTime3 = 500;
	static uint32_t DCflagsetTime3 = 5500;
	static uint32_t DCsetTime3 = 10500;
	
	uint32_t curTime = 0;
	curTime = getTimeTick();
	
	if ((curTime >= delayTime3) && (curTime < DCflagsetTime3))
	{
		DCmotorRun();
		revolveRight();
		OCR3A = 39999;
	}
	
	else if ((curTime >= DCflagsetTime3) && (curTime < DCsetTime3))
	{
		DCmotorRun();
		revolveLeft();
		OCR3A = 39999;
	}
	
	else if (curTime >= DCsetTime3)
	{
		DCmotorStop();
		spinDryFlag = 1;
		setBtn5cnt(getBtn5cnt()-1);
		setStateExcute(COMMON);
	}
}