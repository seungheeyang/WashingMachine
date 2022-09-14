/*
* lcd.c
*
* Created: 2019-09-10 오후 2:14:48
*  Author: 6층교수실PC
*/

#include "I2C_LCD.h"

uint8_t I2C_Data = 0;

void LCD_Data(uint8_t data)
{
	LCD_DATA_PORT = data;
}

void LCD_Data4bit(uint8_t data)
{
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	LCD_EnablePin();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((data & 0x0f) << 4); // 하위 4bit 출력
	LCD_EnablePin();
}

void LCD_Data4bitInit(uint8_t data)
{
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	LCD_EnablePin();
}


void LCD_WriteMode()
{
	LCD_RW_PORT &= ~(1<<LCD_RW);
}


void LCD_EnablePin()
{
	LCD_E_PORT &= ~(1<<LCD_E);
	I2C_TxByte(SLA_W, I2C_Data);
	LCD_E_PORT |= (1<<LCD_E);
	I2C_TxByte(SLA_W, I2C_Data);
	LCD_E_PORT &= ~(1<<LCD_E);
	I2C_TxByte(SLA_W, I2C_Data);
	_delay_us(1600);
}

void LCD_WriteCommand(uint8_t commadData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bit(commadData);
}

void LCD_WriteCommandInit(uint8_t commadData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bitInit(commadData);
}

void LCD_WriteData(uint8_t charData)
{
	LCD_RS_PORT |= (1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bit(charData);
}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	
	uint8_t address = (0x40 * row) + col;
	uint8_t command = 0x80 + address;
	LCD_WriteCommand(command);
}

void LCD_WriteString(char *string)
{
	for (uint8_t i=0; string[i]; i++)
	{
		LCD_WriteData(string[i]);
	}
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row, col);
	LCD_WriteString(string);
}

void LCD_BackLightOn()
{
	I2C_Data |= (1<<LCD_BACKLIGHT);
	I2C_TxByte(SLA_W, I2C_Data);
	
}

void LCD_BackLightOff()
{
	I2C_Data &= ~(1<<LCD_BACKLIGHT);
	I2C_TxByte(SLA_W, I2C_Data);
	
}

void LCD_Init()
{
	I2C_Init();
	_delay_ms(20);
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	LCD_WriteCommand(0x03);
	_delay_ms(1);
	LCD_WriteCommand(0x03);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(COMMAND_4_BIT_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	
	LCD_BackLightOn();
}
