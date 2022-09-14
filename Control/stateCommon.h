/*
 * stateCommon.h
 *
 * Created: 2020-10-09 오후 6:46:55
 *  Author: kccistc
 */ 


#ifndef STATECOMMON_H_
#define STATECOMMON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "checkCard.h"
#include "selectMode.h"
#include "../Device/buzzer.h"

#define  INITIAL	0
#define  INVALID	1
#define  VALID		2
#define  MODE		3
#define	BTNCUNT		4

void Common();
void readyWashing();

#endif /* STATECOMMON_H_ */