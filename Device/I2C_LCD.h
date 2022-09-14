/*
 * lcd.h
 *
 * Created: 2019-09-10 오후 2:14:58
 *  Author: 6층교수실PC
 */ 

#ifndef I2C_LCD_H
#define I2C_LCD_H

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

#define SLA		0X27
#define  WRITE	0
#define READ	1
#define SLA_W	(SLA<<1 | WRITE)
#define  SLA_R	(SLA<<1 | READ)

#define LCD_DATA_DDR	DDRD
#define LCD_DATA_PORT	I2C_Data
#define LCD_DATA_PIN	PIND	
#define LCD_RS_DDR		DDRD
#define LCD_RW_DDR		DDRD
#define LCD_E_DDR		DDRD
#define LCD_RS_PORT		I2C_Data
#define LCD_RW_PORT		I2C_Data
#define LCD_E_PORT		I2C_Data
#define LCD_RS			0
#define LCD_RW			1
#define LCD_E			2
#define LCD_BACKLIGHT	3

#define COMMAND_DISPLAY_CLEAR	0X01
#define COMMAND_DISPLAY_ON		0X0C
#define COMMAND_DISPLAY_OFF		0X08
#define COMMAND_8_BIT_MODE		0X38
#define COMMAND_4_BIT_MODE		0X28
#define COMMAND_ENTRY_MODE		0X06


void LCD_Data(uint8_t data);
void LCD_Data4bit(uint8_t data);
void LCD_WriteMode();
void LCD_ReadPin();
void LCD_EnablePin();
void LCD_WriteCommand(uint8_t commadData);
void LCD_WriteData(uint8_t charData);
void LCD_GotoXY(uint8_t row, uint8_t col);
void LCD_WriteString(char *string);
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string);
void LCD_Init();
void LCD_BackLightOn();
void LCD_BackLightOff();

#endif /* LCD_H_ */