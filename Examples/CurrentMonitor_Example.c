#include "CurrentMonitor.h"
#include "7SegDisplay.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_I2C1_Init();

  init_7SegDisplay();
  init_currentMonitor(BARREL_SENSE_ADDRESS);

  while (1)
  {
    setNumber(getCurrent());
    HAL_Delay(200);
  }
  // displays current flowing through barrel jack
}