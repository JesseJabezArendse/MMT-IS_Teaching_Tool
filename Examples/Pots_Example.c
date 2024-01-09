#include "7SegDisplay.h"
#include "NeoPixels.h"
#include "Pots.h"

uint16_t POTS[ADC_CHANNEL_NUM];

int main(void)
{
// Defaults, copy and paste these 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM7_Init();
  MX_TIM5_Init();

  init_7SegDisplay();
  init_POTs(WITH_NEOPIXELS_AND_DISPLAY); 
  setPotToDisplay(3);

 // turn the pots and have fun
    while (1)
        {

        }

}