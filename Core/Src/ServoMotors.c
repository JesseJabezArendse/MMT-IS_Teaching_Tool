//********************************************************************
//*                      Mech Educational Board                      *
//*                       Servo Motor Library                        *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      20-11-2023                                           *
//*==================================================================*

#include "main.h"
#include "ServoMotors.h"

extern TIM_HandleTypeDef htim3;

int mainARR = 20000;
int maxAngle = 200;
int mainStartingTime = 0;

int angleToCCR(int angle) {
    int outCCR = angle*1000/maxAngle + mainStartingTime;
    if (outCCR < mainStartingTime ){return mainStartingTime;}
    else if (outCCR > (mainStartingTime + 1000)){return (mainStartingTime + 1000);}
    else return outCCR;
}

void init_ServoMotor( int servoNumber , int frequency , int angleRange , int startingTime){
    if (frequency == SERVO_FREQUENCY_50  ){ //if suitable servo frequency, not accomodated for yet, only use 50

        maxAngle = angleRange;
        mainStartingTime = startingTime*10;

        if (servoNumber == SERVO_M1){HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);}
        if (servoNumber == SERVO_M2){HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);}
        if (servoNumber == SERVO_M3){HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);}
        if (servoNumber == SERVO_M4){HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);}


    }
    
}

void setServoAngle(int servoNumber , int angle){
    if (servoNumber == SERVO_M1){
        TIM3 -> CCR1 = angleToCCR(angle);
    }
    if (servoNumber == SERVO_M2){
        TIM3 -> CCR2 = angleToCCR(angle);
    }
    if (servoNumber == SERVO_M3){
        TIM3 -> CCR3 = angleToCCR(angle);
    }
    if (servoNumber == SERVO_M4){
        TIM3 -> CCR4 = angleToCCR(angle);
    }
    
}