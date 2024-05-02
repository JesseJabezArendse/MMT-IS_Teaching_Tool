
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include "simstruc.h"
#include <chrono>
#include <thread>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_1_width 4
#define y_width 8

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#define ONE_SECOND 1000000 // microseconds


// Mapping Input Pins
#define CONTROLLINO_A0 0 
#define CONTROLLINO_A1 1
#define CONTROLLINO_A2 2
#define CONTROLLINO_A3 3
#define CONTROLLINO_A4 4
#define CONTROLLINO_A5 5
#define CONTROLLINO_A6 6
#define CONTROLLINO_A7 7

#define CONTROLLINO_P0 0 
#define CONTROLLINO_P1 1
#define CONTROLLINO_P2 2
#define CONTROLLINO_P3 3

// Mapping states
#define LOW 0
#define HIGH 1

// Mapping Output Pins
#define CONTROLLINO_D0 0 
#define CONTROLLINO_D1 1
#define CONTROLLINO_D2 2
#define CONTROLLINO_D3 3
#define CONTROLLINO_D4 4
#define CONTROLLINO_D5 5
#define CONTROLLINO_D6 6
#define CONTROLLINO_D7 7


static std::chrono::high_resolution_clock::time_point start_time;

void startTimer() {
    start_time = std::chrono::high_resolution_clock::now();
}

bool isTimerExpired() {
    auto current_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time);
    return duration.count() >= ONE_SECOND;
}

void delay(int seconds){
    for (int i = 0 ; i < seconds; i++){
     startTimer();
     while (!isTimerExpired()){}
    }

}

bool digitalRead(const boolean_T *Buttons, int Controllino_Pin){
    return Buttons[Controllino_Pin];
}

int analogRead(const real_T *Pots, int Controllino_Pin){
    return Pots[Controllino_Pin];
}

void digitalWrite(boolean_T *LEDs, int Controllino_Pin , bool state){
    LEDs[Controllino_Pin] = state;
}

int iValue;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void T208_Outputs_wrapper(const boolean_T *Buttons,
			const real_T *Pots,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Read analog value                //1 mark for reading in value
    iValue = (analogRead (Pots, CONTROLLINO_P0 )) * 255 / 4095;
    
    // iValue > 25
                                //2 marks for if-statement, and correct logical comparison against value
    if ( iValue > 25 )
        digitalWrite (LEDs, CONTROLLINO_D0, HIGH);
      else
        digitalWrite (LEDs, CONTROLLINO_D0, LOW);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


