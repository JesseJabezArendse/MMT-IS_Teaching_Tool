//********************************************************************
//*                      Mech Educational Board                      *
//*                          IMU Library                             *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "IMU.h"

extern TIM_HandleTypeDef htim2; //to reference htim2 from main.c

uint8_t checking = 0;

float accel_x = 0;
float accel_y = 0;
float accel_z = 0;
float gyro_x  = 0;
float gyro_y  = 0;
float gyro_z  = 0;

void init_IMU(){
    HAL_TIM_Base_Start_IT(&htim6); //timer set to 1Hz to prevent exceeding IMU max reading rate which locks I2C

    HAL_I2C_Mem_Read(&hi2c1, (IMU_ADDRESS<<1)+1,0x75,1, &checking, 1, 1000); // check
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_WAKE_ADDRESS, 1,(uint8_t*) 0x0, 1, 1000); 

    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_OUTPUT_RATE_ADDRESS, 1, (uint8_t*) IMU_OUTPUT_RATE, 1, 1000); // sets data output rate to 1 kHz
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_ACCEL_CONFIG_ADDRESS, 1,(uint8_t*) 0x0, 1, 1000);  // full range: +-2g
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_ACCEL_CONFIG_ADDRESS, 1,(uint8_t*) 0x0, 1, 1000);  // full range: +-250 deg/s

}


void readAccel(){
    accel_x =  signNumber(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS  ))*10/16384.0f; //because full range sensitivity, converts to m/s^2
    accel_y =  signNumber(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+2))*10/16384.0f;
    accel_z =  signNumber(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+4))*10/16384.0f;

    setFloatNumber(accel_x);
}

void readGyro(){
    gyro_x = signNumber(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS  ))/131.0f; //because full range sensitivity
    gyro_y = signNumber(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+2))/131.0f;
    gyro_z = signNumber(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+4))/131.0f;
}

