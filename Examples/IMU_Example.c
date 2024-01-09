#include "IMU.h"
#include "7SegDisplay.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_TIM2_Init();
  MX_I2C1_Init();
  
  init_7SegDisplay();
  init_IMU();

  while (1)
  {
    setFloatNumber(readAccel(IMU_Y_AXIS));
    HAL_Delay(200);
  }
  //displays measured gravity
}