//********************************************************************
//*                      Mech Educational Board                      *
//*                         Neo Pixels Library                       *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*
#ifndef NEO_PIXELS_H
#define NEO_PIXELS_H

#include "stm32f4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================



#define NUM_NEOPIXELS 4
#define NEOPIXEL_MAX_BRIGHTNESS 30

#define NEOPIXEL_ZERO 	32 	// (ARR+)(0.32) = (100*0.32) = 32
#define NEOPIXEL_ONE	68	// (ARR+)(0.68) = (100*0.68) = 68


#define DMA_BUFF_SIZE (NUM_NEOPIXELS * 24)+1

typedef union
{
  struct
  {
    uint8_t b;
    uint8_t r;
    uint8_t g;
  } color;
  uint32_t data;
} PixelRGB_t;

uint8_t LED_Data[NUM_NEOPIXELS][4];

PixelRGB_t pixel[NUM_NEOPIXELS] = {0};
uint32_t dmaBuffer[DMA_BUFF_SIZE] = {0};
uint32_t *pBuff;

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
void send_PWM(void);
void set_RGB(uint8_t r, uint8_t g, uint8_t b,uint8_t i);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
