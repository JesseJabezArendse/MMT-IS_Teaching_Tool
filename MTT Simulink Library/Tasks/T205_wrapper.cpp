
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

void digitalWrite(boolean_T *LEDs, int Controllino_Pin , bool state){
    LEDs[Controllino_Pin] = state;
}

bool bFilling;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void T205_Outputs_wrapper(const boolean_T *Buttons,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    // push button on
    if ( digitalRead (Buttons,  CONTROLLINO_A0 ) == HIGH )
        bFilling = true;
    
    // push button Off
    if ( digitalRead (Buttons,  CONTROLLINO_A1 ) == LOW )
        bFilling = false;


    // Start Pump1 till 100%
	if ( bFilling && digitalRead(Buttons, CONTROLLINO_A7) == LOW) //2 marks – 1 for each argument
      {
        digitalWrite (LEDs, CONTROLLINO_D0, HIGH);		//1 mark for writing to D0
      }
    else
      {
        digitalWrite (LEDs,  CONTROLLINO_D0, LOW);
        bFilling=false; 					//1 mark for resetting bFilling
      }


    // Start Pump2 til 80%
	if ( bFilling && digitalRead (Buttons, CONTROLLINO_A6)==LOW) //2 marks – 1 for each argument
      {
        digitalWrite (LEDs,  CONTROLLINO_D1, HIGH); 		//1 mark for writing to D1
      }
    else
      {
        digitalWrite (LEDs,  CONTROLLINO_D1, LOW);
      }


    // Signaling <10%
	if ( digitalRead (Buttons, CONTROLLINO_A5)==LOW) 			//1 mark for checking A5=LOW
      {
        digitalWrite (LEDs,  CONTROLLINO_D3, HIGH); 		//1 mark for writing to D3
      }
    else
      {
        digitalWrite (LEDs,  CONTROLLINO_D3, LOW);
      }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


