#include "Relays.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  toggleRelay(RELAY_1);
  HAL_Delay(500);

  while (1)
  {
    toggleRelay(RELAY_1);
    HAL_Delay(500);
    toggleRelay(RELAY_2);
    HAL_Delay(500);
  }

  //Relays toggle out of sync
}