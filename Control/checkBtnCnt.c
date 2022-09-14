/*
 * checkBtnCnt.c
 *
 * Created: 2020-10-11 오후 9:12:43
 *  Author: rjsdn
 */ 
#include "checkBtnCnt.h"


void checkBtnCnt()
{
	if (getBtn3cnt() != 0)
	{
		setStateExcute(WASH);
	}
	else if(getBtn3cnt() == 0)
	{
		if (getBtn4cnt() != 0)
		{
			setStateExcute(RINSE);
		}
		else if (getBtn4cnt() == 0)
		{
			if (getBtn5cnt() != 0)
			{
				setStateExcute(SPINDRY);
			}
			else if(getBtn5cnt() == 0)
			{
				//readyWashing();
				setStateExcute(FINISH);
			}	
		}
	}
	
}