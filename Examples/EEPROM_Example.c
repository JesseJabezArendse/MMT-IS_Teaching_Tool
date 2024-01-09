#include "EEPROM.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_I2C2_Init();

  WriteToMemory(1001,10);

  uint16_t ExampleMemory = ReadFromMemory(10); //exampleMemory will be = 1001 


  while (1)
  {

  }
}