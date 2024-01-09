#include "7SegDisplay.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_TIM7_Init();

  init_7SegDisplay(); //Display displays "HI"

  HAL_Delay(500);

  int i = 0;


  while (1)
  {
    setNumber(i);
    i++;
    HAL_Delay(200);
  }

  //Display counts up from 0 very fast
}