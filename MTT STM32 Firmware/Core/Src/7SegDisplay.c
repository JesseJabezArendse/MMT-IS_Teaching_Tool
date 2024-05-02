//********************************************************************
//*                      Mech Educational Board                      *
//*                     7 Segment Display Library                    *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*


#include <stdio.h>
#include "main.h"

extern TIM_HandleTypeDef htim7;

uint8_t counter = 0;
char displayStr[16];

uint8_t floated = 0;

// illuminates next segment in a circle buffer indexed by counter
void refreshDisplay(void) {
    display_char(displayStr[counter],counter-floated);
    counter++;
    if (displayStr[counter] == '.'){
      HAL_GPIO_WritePin(GPIOG, SEG_DP_Pin,1);
      floated = 1;
    }

    if (counter == 3+floated) {
      counter = 0;
      floated = 0;
    }
}

void init_7SegDisplay(void){
  HAL_TIM_RegisterCallback(&htim7, HAL_TIM_PERIOD_ELAPSED_CB_ID, refreshDisplay);
  HAL_TIM_Base_Start_IT(&htim7);

  displayStr[0] = 'H';
  displayStr[1] = 'I';
}

// updates displayStr with 3 chars
void setString(char str0,char str1,char str2){
  displayStr[0] = str0;
  displayStr[1] = str1;
  displayStr[2] = str2;
}
// updates displayStr with 3 digits
void setNumber(int number){
  sprintf(displayStr,"%3d",number);
}

void setFloatNumber(float value) {
    int intPart = (int)value;  // Extract the integer part
    int decimalPart = (int)((value - intPart) * 100);  // Extract the first decimal place

    if (decimalPart < 0){
      decimalPart = -1*decimalPart;
    }    

    // Format the string with one decimal place
    sprintf(displayStr, "%d.%d", intPart, decimalPart);
}

void display_char(char character , uint8_t gridNumber){
  GPIOG->ODR = 0;
  

  if (gridNumber == 0){
    HAL_GPIO_WritePin(GPIOG,SEG_G0_Pin,1);
    HAL_GPIO_WritePin(GPIOG,SEG_G1_Pin,0);
    HAL_GPIO_WritePin(GPIOG,SEG_G2_Pin,0);

  }
  if (gridNumber == 1){
    HAL_GPIO_WritePin(GPIOG,SEG_G0_Pin,0);
    HAL_GPIO_WritePin(GPIOG,SEG_G1_Pin,1);
    HAL_GPIO_WritePin(GPIOG,SEG_G2_Pin,0);
  }
  if (gridNumber == 2){
    HAL_GPIO_WritePin(GPIOG,SEG_G0_Pin,0);
    HAL_GPIO_WritePin(GPIOG,SEG_G1_Pin,0);
    HAL_GPIO_WritePin(GPIOG,SEG_G2_Pin,1);
  }

  switch (character) {
    case '-':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '0':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case '1':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case '2':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '3':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '4':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '5':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '6':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '7':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case '8':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case '9':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'A':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'B':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'C':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'D':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'E':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'F':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'G':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case 'H':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'I':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case 'r':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    case 'U':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 0);
      break;
    case 'S':
      HAL_GPIO_WritePin(GPIOG, SEG_A_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_B_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_C_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_D_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_E_Pin, 0);
      HAL_GPIO_WritePin(GPIOG, SEG_F_Pin, 1);
      HAL_GPIO_WritePin(GPIOG, SEG_G_Pin, 1);
      break;
    default:
      // Handle unsupported characters or display nothing
      break;
  }
 
}


