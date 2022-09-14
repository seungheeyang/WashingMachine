/*
 * DCmotor.h
 *
 * Created: 2020-10-09 오후 5:18:31
 *  Author: kccistc
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_


#include <avr/io.h>


#define MOTOR_DDR	DDRE
#define MOTOR_PORT	PORTE
#define MOTOR_PIN	3

void DCmotorInit();
void DCmotorStop();
void DCmotorRun();
void revolveRight();
void revolveLeft();


#endif /* DCMOTOR_H_ */