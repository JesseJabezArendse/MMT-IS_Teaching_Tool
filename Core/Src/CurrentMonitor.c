//********************************************************************
//*                      Mech Educational Board                      *
//*                     Current Monitors Library                     *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "CurrentMonitor.h"

extern I2C_HandleTypeDef hi2c1; 														//change this to whichever one you're using

uint16_t vbus, vshunt, current, power;

//custom since INA219 Mem is 2x 8-bit
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

	HAL_I2C_Mem_Read(&hi2c1, (devAddress<<1)+1, RegisterAddress, 1, Value, 2, 1000);

	return ((Value[0] << 8) | Value[1]);
}


void calibrate(uint8_t devAddress , uint16_t calRegister){                              //this is for current register calibration, not configuring
    WriteMem(devAddress, SENSOR_CALBRATION_MEM_ADDR, calRegister);                      
}

int16_t signNumber(uint16_t unsignedValue){
	int16_t signedValue;

	if (unsignedValue <= INT16_MAX) {
        signedValue = (int16_t)unsignedValue; // No change needed, it fits in the signed range.
    } else {
        signedValue = -((int16_t)(UINT16_MAX - unsignedValue + 1));
    }

	return signedValue;
}

int16_t toBusVoltage(uint16_t regValue)
{
	return ((regValue >> 3  ) * 4);

}

int16_t toCurrent_raw(uint16_t regValue)
{
	return (regValue-30*25);
}

int16_t toCurrent(uint16_t regValue)
{
	int16_t result = toCurrent_raw(regValue);

	return (result /25 );
}

int16_t toShuntVolage(uint16_t regValue)
{

	return (signNumber(regValue) );
}

//all milli values
uint16_t vbus = 0;           
uint16_t vshunt = 0;         
uint16_t current = 0;        
uint16_t power = 0;          

int16_t getCurrent(){
	int16_t rollingCurrent = 0;
		
		for (int i = 0 ; i < SENSOR_AVERAGING_NUMBER ; i++){
				vshunt = toShuntVolage(ReadMem(BARREL_SENSE_ADDRESS,SENSOR_VSHUNT_MEM_ADDR));
				vbus = toBusVoltage(ReadMem(BARREL_SENSE_ADDRESS,SENSOR_VBUS_MEM_ADDR));
		HAL_Delay(10);
		current = ((vshunt)*1000/ACCURATE_SHUNT_RESISTOR_VALUE);                                                     //manually using vshunt and a more accurate shunt resistor value to get current instead of current register
		rollingCurrent = rollingCurrent + current;
		}

	return rollingCurrent/SENSOR_AVERAGING_NUMBER;

}

int16_t getPower(){
	return current*vshunt;
}


void init_currentMonitor(uint8_t INA219_Address){

    WriteMem(INA219_Address,SENSOR_CONFIGURATION_MEM_ADDR,SENSOR_CONFIGURATION_RESET);                    		 	//reset's config register, assuming you don't need to modify it
	calibrate(INA219_Address,SENSOR_CALIBRATION);

}

