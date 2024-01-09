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
extern TIM_HandleTypeDef htim5;

extern uint16_t POTS[ADC_CHANNEL_NUM]; //POT0 - POT3, 0 - 4095

short potToDisplay = 0;

void refreshPixels(){
      set_RGB(POTS[0]*255/4095,0,0,0);
      set_RGB(0,POTS[1]*255/4095,0,1);
      set_RGB(0,0,POTS[2]*255/4095,2);
      set_RGB(POTS[0]*255/4095,POTS[1]*255/4095,POTS[2]*255/4095,3);
}

void displayPot(){
  setNumber(POTS[potToDisplay]*100/4095);
}

void doBoth(){
  refreshPixels();
  displayPot();
}

void init_POTs(int mode){
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)POTS, ADC_CHANNEL_NUM);

    if (mode == WITH_NEOPIXELS){
      HAL_TIM_Base_Stop_IT(&htim5);
      HAL_TIM_RegisterCallback(&htim5, HAL_TIM_PERIOD_ELAPSED_CB_ID, refreshPixels);
      HAL_TIM_Base_Start_IT(&htim5);
    }
    if (mode == WITH_DISPLAY){
      HAL_TIM_Base_Stop_IT(&htim5);
      HAL_TIM_RegisterCallback(&htim5, HAL_TIM_PERIOD_ELAPSED_CB_ID, displayPot);
      HAL_TIM_Base_Start_IT(&htim5);
    }
    if (mode == WITH_NEOPIXELS_AND_DISPLAY){
      HAL_TIM_Base_Stop_IT(&htim5);
      HAL_TIM_RegisterCallback(&htim5, HAL_TIM_PERIOD_ELAPSED_CB_ID, doBoth);
      HAL_TIM_Base_Start_IT(&htim5);
    }
}

void setPotToDisplay(int potNumber){
  potToDisplay = potNumber;
}

