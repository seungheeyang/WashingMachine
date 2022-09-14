/*
* stateRinse.c
*
* Created: 2020-10-09 오후 6:47:31
*  Author: kccistc
*/

#include "stateRinse.h"

uint8_t rinsingFlag=0;
extern uint8_t button4count;

void rinsing()
{
	//pause();
	rinsingPross();
	//setBtn4cnt(getBtn4cnt()-1);
}

void rinsingPross()
{
	static uint32_t delayTime2 = 500;
	static uint32_t InwaterSetTime = 3500;
	static uint32_t OutwaterSetTime = 16500;
	static uint32_t DCflagTime2 = 8500;
	static uint32_t DCsetTime2 = 13500;
	
	uint32_t curTime = 0;
	curTime = getTimeTick();

	if ((curTime >= delayTime2) && (curTime < 1100))
	{
		DCmotorStop();
		LED_PORT |= (1<<2);
	}
	
	else if ((curTime >= 1100) && (curTime < 1700))
	{
		DCmotorStop();
		LED_PORT |= (1<<2) | (1<<3);
	}
	
	else if ((curTime >= 1700) && (curTime < 2300))
	{
		DCmotorStop();
		LED_PORT |= (1<<2) | (1<<3) | (1<<4);
	}
	
	else if ((curTime >= 2300) && (curTime < 2900))
	{
		DCmotorStop();
		LED_PORT |= (1<<2) | (1<<3) | (1<<4) | (1<<5);
	}
	
	else if ((curTime >= 2900) && (curTime < InwaterSetTime))
	{
		DCmotorStop();
		LED_PORT |= (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6);
	}

	else if ((curTime >= InwaterSetTime) && (curTime < DCflagTime2))
	{
		//LED_PORT &= ~((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
		DCmotorRun();
		LED_PORT |= (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6);//DCmotorRun();
		revolveRight();
		OCR3A = 39999;
	}
	
	else if ((curTime >= DCflagTime2) && (curTime < DCsetTime2))
	{
		LED_PORT |= (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6);
		DCmotorRun();
		revolveLeft();
		OCR3A = 39999;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	else if ((curTime >= DCsetTime2) && (curTime < 14100))
	{
		DCmotorStop();
		LED_PORT |= (1<<2) | (1<<3) | (1<<4) | (1<<5);
		LED_PORT &= ~(1<<6);
		//LED_PORT |= ((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
	}
	
	else if ((curTime >= 14100) && (curTime < 14700))
	{
		DCmotorStop();
		LED_PORT &= ~(1<<5);
		LED_PORT |= (1<<2) | (1<<3) | (1<<4);
		//LED_PORT |= ((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
	}
	
	else if ((curTime >= 14700) && (curTime < 15300))
	{
		DCmotorStop();
		
		LED_PORT |= (1<<2) | (1<<3);
		LED_PORT &= ~(1<<4);
		//LED_PORT |= ((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
	}
	
	else if ((curTime >= 15300) && (curTime < 15900))
	{
		DCmotorStop();
		LED_PORT |= (1<<2);
		LED_PORT &= ~(1<<3);
		//LED_PORT |= ((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
	}
	
	else if ((curTime >= 15900) && (curTime < OutwaterSetTime))
	{
		DCmotorStop();
		LED_PORT &= ~(1<<2);
		//LED_PORT |= ((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
	}
	
	else if (curTime >= OutwaterSetTime)
	{
		//LED_PORT &= ~((1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6));
		rinsingFlag = 1;
		setBtn4cnt(getBtn4cnt()-1);
		setStateExcute(COMMON);
	}
}
