//********************************************************************
//*                      Mech Educational Board                      *
//*                     7 Segment Display Library                    *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      23-10-2023                                           *
//*==================================================================*
#ifndef SEVEN_SEGMENT_DISPLAY_H
#define SEVEN_SEGMENT_DISPLAY_H

#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================


//====================================================================
// FUNCTION DECLARATIONS
//====================================================================

// Function to initialize the 7-segment display
void init_7SegDisplay(void);

// Functions for setting display content
void setString(char str0, char str1, char str2);
void setNumber(int number);
void setFloatNumber(float value);

// Function to display a character on a specific grid
void display_char(char character, uint8_t gridNumber);


//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
