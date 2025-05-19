/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQR.h
 *
 * Code generation for function 'factorQR'
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
void factorQR(const emlrtStack *sp, h_struct_T *obj, const real_T A[299],
              int32_T mrows, int32_T ncols);

/* End of code generation (factorQR.h) */
