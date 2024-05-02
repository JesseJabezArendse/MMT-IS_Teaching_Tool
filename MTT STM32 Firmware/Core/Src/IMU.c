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
extern I2C_HandleTypeDef hi2c1;
extern volatile float IMU_Accel[3];
extern volatile float IMU_Gyro[3];

uint8_t checking = 0;

float accel_x = 0;
float accel_y = 0;
float accel_z = 0;
float gyro_x  = 0;
float gyro_y  = 0;
float gyro_z  = 0;

uint16_t accelMem[3];
uint16_t gyroMem[3];

short IMUCounter = 0;
void pollIMU(void){

    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_WAKE_ADDRESS, 1,(uint8_t*) 0x0, 1, 1000); 

    HAL_I2C_Mem_Read(&hi2c1, (IMU_ADDRESS<<1)+1, IMU_ACCEL_DATA_ADDRESS, 1, accelMem, sizeof(accelMem), HAL_MAX_DELAY);
    for (int i = 0 ; i < 3 ; i++){
        IMU_Accel[i] = signNumber16(accelMem[i])*10/16384.0f;
    }
    HAL_I2C_Mem_Read(&hi2c1, (IMU_ADDRESS<<1)+1, IMU_GYRO_DATA_ADDRESS, 1, gyroMem, sizeof(gyroMem), HAL_MAX_DELAY);
    for (int i = 0 ; i < 3 ; i++){
        IMU_Gyro[i] = signNumber16(gyroMem[i])/131.0f;
    }
}

static void WriteMem(uint8_t devAddress, uint8_t RegisterAddress, uint16_t Value)
{
	uint8_t addr[2];
	addr[0] = (Value >> 8) & 0xff;  // upper byte
	addr[1] = (Value >> 0) & 0xff; // lower byte
	HAL_I2C_Mem_Write(&hi2c1, (devAddress<<1)+0, RegisterAddress, 1, (uint8_t*)addr, 2, HAL_MAX_DELAY);
}

static uint16_t ReadMem(uint8_t devAddress, uint8_t RegisterAddress)
{
	uint8_t Value[2];

	HAL_I2C_Mem_Read(&hi2c1, (devAddress<<1)+1, RegisterAddress, 1, Value, 2, HAL_MAX_DELAY);

	return ((Value[0] << 8) | Value[1]);
}

float readAccel(short axis){
    accel_x =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS  ))*10/16384.0f; //because full range sensitivity, converts to m/s^2
    accel_y =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+2))*10/16384.0f;
    accel_z =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+4))*10/16384.0f;

    if (axis == IMU_X_AXIS){
        return accel_x;
    }
    if (axis == IMU_Y_AXIS){
        return accel_y;
    }
    if (axis == IMU_Z_AXIS){
        return accel_z;
    }
}

float readGyro(short axis){
    gyro_x = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS  ))/131.0f; //because full range sensitivity
    gyro_y = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+2))/131.0f;
    gyro_z = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+4))/131.0f;

    if (axis == IMU_X_AXIS){
        return gyro_x;
    }
    if (axis == IMU_Y_AXIS){
        return gyro_y;
    }
    if (axis == IMU_Z_AXIS){
        return gyro_z;
    }
}


void refreshIMUValues(){  // this is an interrupt, makes board run slow, dividing the interrupts task to make board more responsive
    IMU_Accel[0] =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS  ))*10/16384.0f; //because full range sensitivity, converts to m/s^2
    IMU_Accel[1] =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+2))*10/16384.0f;
    IMU_Accel[2] =  signNumber16(ReadMem(IMU_ADDRESS,IMU_ACCEL_DATA_ADDRESS+4))*10/16384.0f;

    IMU_Gyro[0] = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS  ))/131.0f; 
    IMU_Gyro[1] = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+2))/131.0f;
    IMU_Gyro[2] = signNumber16(ReadMem(IMU_ADDRESS,IMU_GYRO_DATA_ADDRESS+4))/131.0f;
}

void init_IMU(){
    HAL_TIM_RegisterCallback(&htim6,HAL_TIM_PERIOD_ELAPSED_CB_ID,refreshIMUValues);
    HAL_TIM_Base_Start_IT(&htim6); //timer set to 1Hz to prevent exceeding IMU max reading rate which locks I2C


    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_WAKE_ADDRESS, 1,(uint8_t*) 0x0, 1                     , 1000); 
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_OUTPUT_RATE_ADDRESS, 1, (uint8_t*) IMU_OUTPUT_RATE, 1 , 1000); // sets data output rate to 1 kHz
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_ACCEL_CONFIG_ADDRESS, 1,(uint8_t*) 0x0, 1             , 1000);  // full range: +-2g
    HAL_I2C_Mem_Write(&hi2c1, (IMU_ADDRESS<<1)+0, IMU_GYRO_CONFIG_ADDRESS, 1,(uint8_t*) 0x0, 1              , 1000);  // full range: +-250 deg/s


}
