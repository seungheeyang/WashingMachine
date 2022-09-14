/*
 * stateSpinDry.h
 *
 * Created: 2020-10-09 오후 6:48:17
 *  Author: kccistc
 */ 


#ifndef STATESPINDRY_H_
#define STATESPINDRY_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../Device/DCmotor.h"
#include "../Device/servo.h"
#include "../timeTick.h"
#include "checkBtnCnt.h"
#include "manualMode.h"
#include "stateController.h"

void spinDry();
void spinDryPross();



#endif /* STATESPINDRY_H_ */