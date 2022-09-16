/*
 * timeTick.h
 *
 * Created: 2021-09-25 오전 14:38:31
 *  Author: Seunghee Yang
 */ 


#ifndef TIMETICK_H_
#define TIMETICK_H_
#include <avr/io.h>

#include "./Control/stateController.h"

void timeTickInit();
uint32_t getTimeTick();
void incTimeTick();


#endif /* TIMETICK_H_ */
