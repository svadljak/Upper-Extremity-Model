/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factor1.h
 *
 * Code generation for function 'factor1'
 *
 */

#pragma once

/* Include files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_factor(const emlrtStack *sp, i_struct_T *obj, const real_T A[64],
              int32_T ndims, int32_T ldA);

/* End of code generation (factor1.h) */
