#include "StepperMotor.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_TIM4_Init();

  init_StepperMotor(STEPPER_WAVE_MODE,1024,WITH_LEDS);

  while (1)
  {
    for (int i = 0 ; i < 5 ; i++){
      setStepperSpeed(i*200);
      HAL_Delay(500);
    }
  }
  // stepper ramps up speed
}