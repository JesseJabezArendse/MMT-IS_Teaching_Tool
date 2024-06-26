//********************************************************************
//*                      Mech Educational Board                      *
//*                         EEPROM Library                           *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      26-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "EEPROM.h"

extern I2C_HandleTypeDef hi2c2;

// write to EEPROM
void WriteToMemory(uint16_t Value , uint8_t RegisterAddress )
{
	uint8_t addr[2];
	addr[0] = (Value >> 8) & 0xff;  // upper byte
	addr[1] = (Value >> 0) & 0xff; // lower byte

	HAL_I2C_Mem_Write(&hi2c2, (EEPROM_ADDRESS<<1)+0, RegisterAddress, 2, addr, 2, HAL_MAX_DELAY);
}

// read from EEPROM
uint16_t ReadFromMemory(uint8_t RegisterAddress)
{
	uint8_t Value[2];
	HAL_I2C_Mem_Read(&hi2c2, (EEPROM_ADDRESS<<1)+1, RegisterAddress, 2, Value, 2, HAL_MAX_DELAY);
	
	return ((Value[0] << 8) | Value[1]);
}
