
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 8

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void T101_Outputs_wrapper(const boolean_T *Buttons,
			boolean_T *LEDs,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//NAND
    LEDs[0] = !(Buttons[0] && Buttons[1]);

    //NOR
    LEDs[1] = !(Buttons[2] || Buttons[3]);

    //XOR
    if ((Buttons[4] == 1 && Buttons[5] == 0) || (Buttons[4] == 0 && Buttons[5] == 1))
        LEDs[2] = 1;
    else
        LEDs[2] = 0;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


