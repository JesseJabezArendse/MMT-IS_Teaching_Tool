//********************************************************************
//*                      Mech Educational Board                      *
//*                         EEPROM Library                           *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      26-10-2023                                           *
//*==================================================================*
#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define EEPROM_ADDRESS 0b1010000

extern I2C_HandleTypeDef hi2c2;

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void WriteToMemory(uint16_t Value , uint8_t RegisterAddress );
uint16_t ReadFromMemory(uint8_t RegisterAddress);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
