//********************************************************************
//*                      Mech Educational Board                      *
//*                     Current Monitors Library                     *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      06-11-2023                                           *
//*==================================================================*

#include "main.h"
#include "StepperMotor.h"

extern TIM_HandleTypeDef htim4;

uint8_t stepperIndex = 0;
uint8_t tempARR = 0;
short withLEDs = 0;

int fullRevolution = 4096;

void setStepperSpeed(uint16_t millirRPM){
    if (millirRPM == 0){
        HAL_TIM_Base_Stop_IT(&htim4);
    }
    else if (millirRPM >= 8400){
        millirRPM = 8400;
    }

    tempARR = 84000000/fullRevolution; 
    TIM4->ARR = tempARR*1000/millirRPM;


}


void HalfModeSequence(void){
    GPIOD -> ODR = 0;
    switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,1);
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,0);
        break;
    case 1:
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,0);
        break;
    case 3:
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,1);
        break;
    case 4:
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,0);
        break;
    case 5:
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,1);
        break;
    case 6:
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,0);
        break;
    case 7:
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,1);
        break;
    
    default:
        break;
    }

if (withLEDs == 1){
        switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,1);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,0);
        break;
    case 1:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,0);
        break;
    case 3:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,1);
        break;
    case 4:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,0);
        break;
    case 5:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,1);
        break;
    case 6:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,0);
        break;
    case 7:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,1);
        break;
    
    default:
        break;
    }
}

    stepperIndex++;
    if (stepperIndex == 8){
        stepperIndex = 0;
    }
}

void WaveModeSequence(void){
    GPIOD -> ODR = 0;
    switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,0);
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,1);
        break;
    case 1:
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,0);
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,0);
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,1);
        break;
    case 3:
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,0);
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,1);
        break;
    
    default:
        break;
    }

if (withLEDs == 1){
        switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,1);
        break;
    case 1:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,1);
        break;
    case 3:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,1);
        break;
    
    default:
        break;
    }
}
    
    stepperIndex++;
    if (stepperIndex == 4){
        stepperIndex = 0;
    }
}

void FullModeSequence(void){
    GPIOD -> ODR = 0;
    switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,0);
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,1);
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,1);
        break;
    case 1:
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,0);
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,1);
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(Stepper_1_GPIO_Port,Stepper_1_Pin,0);
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,1);
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,1);
        break;
    case 3:
        HAL_GPIO_WritePin(Stepper_2_GPIO_Port,Stepper_2_Pin,0);
        HAL_GPIO_WritePin(Stepper_3_GPIO_Port,Stepper_3_Pin,1);
        HAL_GPIO_WritePin(Stepper_0_GPIO_Port,Stepper_0_Pin,1);
        break;
    
    default:
        break;
    }

    if (withLEDs == 1){
            switch (stepperIndex)
    {
    case 0:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,1);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,1);
        break;
    case 1:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,1);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,1);
        break;
    case 2:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED1_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,1);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,1);
        break;
    case 3:
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED2_Pin,0);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED3_Pin,1);
        HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,1);
        break;
    
    default:
        break;
    }
    }
    stepperIndex++;
    if (stepperIndex == 4){
        stepperIndex = 0;
    }
}

void init_StepperMotor(short mode,int NoStepsForFullRevolution,short display){
    fullRevolution = NoStepsForFullRevolution;

    if (display == WITH_LEDS){withLEDs = 1;}
    
    if (mode == STEPPER_HALF_MODE){
        GPIOB->ODR = 0;
        HAL_TIM_RegisterCallback(&htim4, HAL_TIM_PERIOD_ELAPSED_CB_ID, HalfModeSequence);
    }
    if (mode == STEPPER_WAVE_MODE){
        GPIOB->ODR = 0;
        HAL_TIM_RegisterCallback(&htim4, HAL_TIM_PERIOD_ELAPSED_CB_ID, WaveModeSequence);
    }
    if (mode == STEPPER_FULL_MODE){
        GPIOB->ODR = 0;
        HAL_TIM_RegisterCallback(&htim4, HAL_TIM_PERIOD_ELAPSED_CB_ID, FullModeSequence);
    }
    
    HAL_TIM_Base_Start_IT(&htim4);
    
}

