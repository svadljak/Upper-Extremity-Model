/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen.h
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Optimization_ThelenMuscle_codegen(const emlrtStack *sp, const real_T Q[16],
                                       const real_T b[2], const real_T Fl[8],
                                       const real_T Fpe[8], const real_T VM[8],
                                       const real_T LM0[8], const real_T a0[8],
                                       const real_T alpha0[8],
                                       const real_T FM0[8],
                                       real_T activation[8]);

/* End of code generation (Optimization_ThelenMuscle_codegen.h) */
