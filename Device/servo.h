/*
 * servo.h
 *
 * Created: 2020-09-21 오후 12:47:07
 *  Author: kccistc
 */ 



#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#define DUTY_OCR	OCR3B


void setDutyRate (uint16_t duty);
void servoRun(uint8_t degree);
void servoInit();





#endif /* SERVO_H_ */