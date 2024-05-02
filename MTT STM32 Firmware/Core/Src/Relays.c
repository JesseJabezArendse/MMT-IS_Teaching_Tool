//********************************************************************
//*                      Mech Educational Board                      *
//*                         Relay Library                            *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "Relays.h"

// toggles Relay from current state
void toggleRelay(int relayNumber){
    if (relayNumber == RELAY_1){
        HAL_GPIO_TogglePin(Relay_1_GPIO_Port , Relay_1_Pin);
    }
    if (relayNumber == RELAY_2){
        HAL_GPIO_TogglePin(Relay_2_GPIO_Port , Relay_2_Pin);
    }
}

// updates Relay's state
void setRelay(int relayNumber,int relayMode){
    if (relayNumber == RELAY_1){
        if (relayMode == RELAY_OPEN){
            HAL_GPIO_WritePin(Relay_1_GPIO_Port , Relay_1_Pin , 0);
        }
        if (relayMode == RELAY_CLOSE){
            HAL_GPIO_WritePin(Relay_1_GPIO_Port , Relay_1_Pin , 1);
        }                                                 
    }
    if (relayNumber == RELAY_2){
        if (relayMode == RELAY_OPEN){
            HAL_GPIO_WritePin(Relay_2_GPIO_Port , Relay_2_Pin , 0);
        }
        if (relayMode == RELAY_CLOSE){
            HAL_GPIO_WritePin(Relay_2_GPIO_Port , Relay_2_Pin , 1);
        }   
    }
}