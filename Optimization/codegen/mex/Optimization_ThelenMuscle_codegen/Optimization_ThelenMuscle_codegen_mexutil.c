/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen_mexutil.c
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen_mexutil'
 *
 */

/* Include files */
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / denominator;
  return quotient;
}

/* End of code generation (Optimization_ThelenMuscle_codegen_mexutil.c) */
