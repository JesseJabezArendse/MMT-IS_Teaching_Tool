//********************************************************************
//*                      Mech Educational Board                      *
//*                         Relay Library                            *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*

#include "main.h"
#include "Relays.h"


void toggleRelay(int relayNumber){
    if (relayNumber == RELAY_1){
        HAL_GPIO_TogglePin(Relay1_GPIO_Port , Relay1_Pin);
    }
    if (relayNumber == RELAY_2){
        HAL_GPIO_TogglePin(Relay2_GPIO_Port , Relay2_Pin);
    }
}

void setRelay(int relayNumber,int relayMode){
    if (relayNumber == RELAY_1){
        if (relayMode == RELAY_OPEN){
            HAL_GPIO_WritePin(Relay1_GPIO_Port , Relay1_Pin , 0);
        }
        if (relayMode == RELAY_CLOSE){
            HAL_GPIO_WritePin(Relay1_GPIO_Port , Relay1_Pin , 1);
        }
        else{}                                                  //if you don't use the relay.h defines
    }
    if (relayNumber == RELAY_2){
        if (relayMode == RELAY_OPEN){
            HAL_GPIO_WritePin(Relay2_GPIO_Port , Relay2_Pin , 0);
        }
        if (relayMode == RELAY_CLOSE){
            HAL_GPIO_WritePin(Relay2_GPIO_Port , Relay2_Pin , 1);
        }
        else{}                                                  //if you don't use the relay.h defines
    }
}