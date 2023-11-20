//********************************************************************
//*                      Mech Educational Board                      *
//*                         ADC Pots Library                         *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "Pots.h"


extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern uint16_t POTS[ADC_CHANNEL_NUM]; //POT0 - POT3, 0 - 4095

uint8_t withNeoPixels = 0;

void init_POTs(int mode){
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)POTS, ADC_CHANNEL_NUM);
    withNeoPixels = mode;
}


// called when ADC value refreshes is done
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
  if (withNeoPixels == 1){
    set_RGB(POTS[0]*255/4095,0,0,0);
    set_RGB(0,POTS[1]*255/4095,0,1);
    set_RGB(0,0,POTS[2]*255/4095,2);
    set_RGB(POTS[3]*255/4095,POTS[3]*255/4095,POTS[3]*255/4095,3);
    setNumber(POTS[3]*255/4095);
  }
  TIM4->ARR = POTS[3]+1; //minimum of 1
}