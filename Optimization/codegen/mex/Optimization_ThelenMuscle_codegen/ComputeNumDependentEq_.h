/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ComputeNumDependentEq_.h
 *
 * Code generation for function 'ComputeNumDependentEq_'
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
int32_T ComputeNumDependentEq_(const emlrtStack *sp, h_struct_T *qrmanager,
                               const real_T beqf[23], int32_T mConstr,
                               int32_T nVar);

/* End of code generation (ComputeNumDependentEq_.h) */
