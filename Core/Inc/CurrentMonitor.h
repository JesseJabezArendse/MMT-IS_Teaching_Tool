//********************************************************************
//*                      Mech Educational Board                      *
//*                     Current Monitors Library                     *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*
#ifndef CURRENT_MONITOR_H
#define CURRENT_MONITOR_H

#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================

// INA219's I2C bus addresses (last 3 bits dependent on A0-A2)
#define SERVO_SENSE_ADDRESS     0b1000001  											     
#define STEPPER_SENSE_ADDRESS   0b1000000
#define BARREL_SENSE_ADDRESS    0b1000100
#define OTHER_ADDRESS           0b1000                                             


// INA219's memory addresses
#define SENSOR_CONFIGURATION_MEM_ADDR   0x00
#define SENSOR_VSHUNT_MEM_ADDR          0x01
#define SENSOR_VBUS_MEM_ADDR            0x02
#define SENSOR_POWER_MEM_ADDR           0x03
#define SENSOR_CURRENT_MEM_ADDR         0x03
#define SENSOR_CALBRATION_MEM_ADDR      0x05

// Hardcoded calibration values
#define SENSOR_CONFIGURATION_RESET      0x8000
#define SENSOR_CALIBRATION 0b1111111111111111
#define SENSOR_AVERAGING_NUMBER 6
#define ACCURATE_SHUNT_RESISTOR_VALUE 102.75 											//change this to yours, in milli ohms





//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void calibrate(uint8_t devAddress , uint16_t calRegister);
int16_t getCurrent();
int16_t getPower();
void init_currentMonitor(uint8_t INA219_Address);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
