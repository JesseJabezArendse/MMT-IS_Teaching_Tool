//********************************************************************
//*                      Mech Educational Board                      *
//*                         Neo Pixels Library                       *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*

#include "main.h"

extern UART_HandleTypeDef huart4;

uint8_t rxBuffer[13]; // Receive buffer

// sends a string through UART USB
void send_USB(char _out[]) {
	HAL_UART_Transmit(&huart4, (uint8_t*) _out, strlen(_out), 60);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(&huart4, (uint8_t*) newline, 2, 10);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == UART4) {
        HAL_UART_Receive_IT(huart, rxBuffer, 13);
    }
}