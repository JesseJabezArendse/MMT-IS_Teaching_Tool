//********************************************************************
//*                      Mech Educational Board                      *
//*                     7 Segment Display Library                    *
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

#define STEPPER_HALF_MODE 0
#define STEPPER_WAVE_MODE 1
#define STEPPER_FULL_MODE 2

#define STEPPER_STEPS_FOR_FULL_REVOLUTION 4092

extern TIM_HandleTypeDef htim4;

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

void Stepper_setSpeed(uint16_t millirRPM);
void init_StepperMotor(short mode);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
