
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
void T202_Outputs_wrapper(const boolean_T *Buttons,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    // if both buttons, do nothing
    if (Buttons[1] && Buttons[2] == 1){
        LEDs[2] = 0;
        LEDs[3] = 0;
    }
    else{
        //Stage Up
         if ((Buttons[0] && Buttons[1] && !Buttons[2] && !Buttons[3]) == 1){
            LEDs[2] = 1;
         }
         else {
            LEDs[2] = 0;
         }
        
        //Stage Down
         if ((Buttons[0] && !Buttons[1] && Buttons[2] && !Buttons[4]) == 1){
            LEDs[3] = 1;
         }
         else {
            LEDs[3] = 0;
         }
    }

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

