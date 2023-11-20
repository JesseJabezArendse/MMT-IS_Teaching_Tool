//********************************************************************
//*                      Mech Educational Board                      *
//*                          IMU Library                             *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*
#ifndef IMU_H
#define IMU_H

#include "stm32f4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================

#define IMU_ADDRESS 0b1101000+1 //left floating, works with AD0 = 1

#define IMU_DEVICE_CHECK 0x75 // read this, returns 104 if working
#define IMU_WAKE_ADDRESS 0x6B
#define IMU_OUTPUT_RATE_ADDRESS 0x19
#define IMU_ACCEL_CONFIG_ADDRESS 0x1C
#define IMU_GYRO_CONFIG_ADDRESS 0x1B
#define IMU_ACCEL_DATA_ADDRESS 0x3B
#define IMU_GYRO_DATA_ADDRESS 0x43

#define IMU_OUTPUT_RATE 0x07

extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim6;

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void init_IMU();
void readAccel();

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
