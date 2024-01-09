#include "ServoMotors.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_TIM3_Init();

  init_servo(SERVO_M1,SERVO_FREQUENCY_50,90,100);

  while (1)
  {
  for(int i  = 0 ; i < 90 ; i++){
      setServoAngle(SERVO_M1,i);
      HAL_Delay(10);
    }
  for(int i  = 0 ; i < 45 ; i++){
      setServoAngle(SERVO_M1,40-i);
      HAL_Delay(20);
    }
  }
  // servo motor waves to you
}