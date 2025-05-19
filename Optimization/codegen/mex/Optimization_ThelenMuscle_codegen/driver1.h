/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.h
 *
 * Code generation for function 'driver1'
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
void b_driver(const emlrtStack *sp, d_struct_T *TrialState,
              g_struct_T *MeritFunction,
              const h_coder_internal_stickyStruct *FcnEvaluator,
              e_struct_T *FiniteDifferences, c_struct_T *memspace,
              f_struct_T *WorkingSet, real_T Hessian[64], h_struct_T *QRManager,
              i_struct_T *CholManager, j_struct_T *QPObjective);

/* End of code generation (driver1.h) */
