
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
void T103_Outputs_wrapper(const boolean_T *Buttons,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
    //Switch On Delay
    if (Buttons[0] == 1){
        delay(2);
        LEDs[0] = 1;
    }
    else {
    LEDs[0] = 0;
    }

    // Switch Off Delay
    if (Buttons[3] == 1){   
        LEDs[1] = 1;
    }
    else {
        delay(2);
        LEDs[1] = 0;
    }

    // Swtich On-Off Delay
    if (Buttons[5] == 1){  
        delay(1);
        LEDs[2] = 1;
    }
    else {
        delay(3);
        LEDs[2] = 0;
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


