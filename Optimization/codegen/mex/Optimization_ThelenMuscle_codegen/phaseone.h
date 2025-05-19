/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * phaseone.h
 *
 * Code generation for function 'phaseone'
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
void phaseone(const emlrtStack *sp, const real_T H[64], const real_T f[13],
              d_struct_T *solution, c_struct_T *memspace,
              f_struct_T *workingset, h_struct_T *qrmanager,
              i_struct_T *cholmanager, j_struct_T *objective,
              const char_T options_SolverName[7],
              const k_struct_T *runTimeOptions);

/* End of code generation (phaseone.h) */
