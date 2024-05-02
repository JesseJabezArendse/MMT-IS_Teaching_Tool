//********************************************************************
//*                      Mech Educational Board                      *
//*                     7 DISPment Display Library                    *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*
#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include "stm32f4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================

#define STEPPER_HALF_MODE 3
#define STEPPER_WAVE_MODE 2
#define STEPPER_FULL_MODE 1

#define WITH_LEDS         0
#define WITHOUT_LEDS      1



extern TIM_HandleTypeDef htim4;

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void setStepperSpeed(int16_t millirRPM);
void init_StepperMotor(short mode,int NoStepsForFullRevolution,short display);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
