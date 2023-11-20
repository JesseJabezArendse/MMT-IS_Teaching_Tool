//********************************************************************
//*                      Mech Educational Board                      *
//*                         Neo Pixels Library                       *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "NeoPixels.h"

extern TIM_HandleTypeDef htim2; //to reference htim2 from main.c

void send_PWM(void)
{
    pBuff = dmaBuffer;
    for (int i = 0; i < NUM_NEOPIXELS; i++)
    {
       for (int j = 23; j >= 0; j--)
       {
         if ((pixel[i].data >> j) & 0x01)
         {
           *pBuff = NEOPIXEL_ONE;
         }
         else
         {
           *pBuff = NEOPIXEL_ZERO;
         }
         pBuff++;
     }
    }
    dmaBuffer[DMA_BUFF_SIZE - 1] = 0; // last element must be 0!


    HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_3, dmaBuffer, DMA_BUFF_SIZE);
}



void set_RGB(uint8_t r, uint8_t g, uint8_t b,uint8_t i)
{
		pixel[i].color.r = r*NEOPIXEL_MAX_BRIGHTNESS/255;
		pixel[i].color.g = g*NEOPIXEL_MAX_BRIGHTNESS/255;
		pixel[i].color.b = b*NEOPIXEL_MAX_BRIGHTNESS/255;
	
    send_PWM();
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_3);
}