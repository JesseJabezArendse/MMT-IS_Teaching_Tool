#include "USB.h"

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_UART4_Init();

  while (1)
  {
    send_USB("Hello From MMT Teaching Tool!"); //spams this over COMx port with 9600 baud rate
    HAL_Delay(500);
  }
}