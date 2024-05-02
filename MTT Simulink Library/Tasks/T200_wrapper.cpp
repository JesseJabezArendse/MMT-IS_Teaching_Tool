
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
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
/* extern double func(double a); */
#define ONE_SECOND 1000000 // microseconds

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
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void T200_Outputs_wrapper(const boolean_T *Buttons,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//Alarm Reset
 if ((Buttons[0] || Buttons[1] || Buttons[2]) == 1){
    for (int i = 0 ; i < 8 ; i++){
        LEDs[i] = 1;
    }
 }
 if (Buttons[3] == 1){
    for (int i = 0 ; i < 8 ; i++){
        LEDs[i] = 0;
    }
 }

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


