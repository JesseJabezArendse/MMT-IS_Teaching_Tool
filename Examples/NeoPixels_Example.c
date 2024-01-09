#include "NeoPixels.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_TIM2_Init();

  while (1)
  {
    for (int r = 10 ; r < 40 ; r++){
      for (int g = 10 ; g < 40 ; g++){
        for (int b = 10 ; b < 40 ; b++){
          set_RGB(r*5,g*5,b*5,3);      
          HAL_Delay(1);     
        }
      }
    }
  }
  // goes through some weird colours
}