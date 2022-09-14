/*
 * timeTick.h
 *
 * Created: 2020-09-25 오전 10:34:18
 *  Author: kccistc
 */ 


#ifndef TIMETICK_H_
#define TIMETICK_H_
#include <avr/io.h>

#include "./Control/stateController.h"

void timeTickInit();
uint32_t getTimeTick();
void incTimeTick();


#endif /* TIMETICK_H_ */