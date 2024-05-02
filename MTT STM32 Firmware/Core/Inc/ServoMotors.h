//********************************************************************
//*                      Mech Educational Board                      *
//*                       Servo Motor Library                        *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      20-11-2023                                           *
//*==================================================================*
#ifndef SERVO_MOTORS_H
#define SERVO_MOTORS_H

#include "stm32f4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define SERVO_M1 1
#define SERVO_M2 2
#define SERVO_M3 3
#define SERVO_M4 4

#define SERVO_FREQUENCY_50 50
#define SERVO_FREQUENCY_60 60
#define SERVO_FREQUENCY_490 490

#define ANGLE_RANGE 200


//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void setServoAngle(int servoNumber , int angle);
void init_ServoMotor( int servoNumber , int frequency , int angleRange , int startingTime);
//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
