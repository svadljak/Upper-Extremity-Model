/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.h
 *
 * Code generation for function 'soc'
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
boolean_T soc(const emlrtStack *sp, const real_T Hessian[64],
              const real_T grad[13], d_struct_T *TrialState,
              c_struct_T *memspace, f_struct_T *WorkingSet,
              h_struct_T *QRManager, i_struct_T *CholManager,
              j_struct_T *QPObjective, const k_struct_T *qpoptions);

/* End of code generation (soc.h) */
