/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Optimization_ThelenMuscle_codegen_rtwutil.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
int div_nde_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / denominator;
  return quotient;
}

/*
 * File trailer for Optimization_ThelenMuscle_codegen_rtwutil.c
 *
 * [EOF]
 */
