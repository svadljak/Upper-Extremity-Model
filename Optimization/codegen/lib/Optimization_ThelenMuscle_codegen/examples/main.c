/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "Optimization_ThelenMuscle_codegen.h"
#include "Optimization_ThelenMuscle_codegen_terminate.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void argInit_2x1_real_T(double result[2]);

static void argInit_2x8_real_T(double result[16]);

static void argInit_8x1_real_T(double result[8]);

static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : double result[2]
 * Return Type  : void
 */
static void argInit_2x1_real_T(double result[2])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[16]
 * Return Type  : void
 */
static void argInit_2x8_real_T(double result[16])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 16; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[8]
 * Return Type  : void
 */
static void argInit_8x1_real_T(double result[8])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 8; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Optimization_ThelenMuscle_codegen();
  /* Terminate the application.
You do not need to do this more than one time. */
  Optimization_ThelenMuscle_codegen_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Optimization_ThelenMuscle_codegen(void)
{
  double dv[16];
  double Fl_tmp[8];
  double activation[8];
  double dv1[2];
  /* Initialize function 'Optimization_ThelenMuscle_codegen' input arguments. */
  /* Initialize function input argument 'Q'. */
  /* Initialize function input argument 'b'. */
  /* Initialize function input argument 'Fl'. */
  argInit_8x1_real_T(Fl_tmp);
  /* Initialize function input argument 'Fpe'. */
  /* Initialize function input argument 'VM'. */
  /* Initialize function input argument 'LM0'. */
  /* Initialize function input argument 'a0'. */
  /* Initialize function input argument 'alpha0'. */
  /* Initialize function input argument 'FM0'. */
  /* Call the entry-point 'Optimization_ThelenMuscle_codegen'. */
  argInit_2x8_real_T(dv);
  argInit_2x1_real_T(dv1);
  Optimization_ThelenMuscle_codegen(dv, dv1, Fl_tmp, Fl_tmp, Fl_tmp, Fl_tmp,
                                    Fl_tmp, Fl_tmp, Fl_tmp, activation);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
