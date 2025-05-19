/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.h
 *
 * Code generation for function 'finDiffEvalAndChkErr'
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
boolean_T finDiffEvalAndChkErr(const real_T obj_nonlin_workspace_Q[16],
                               const real_T obj_nonlin_workspace_b[2],
                               const real_T obj_nonlin_workspace_Fl[8],
                               const real_T obj_nonlin_workspace_Fpe[8],
                               const real_T obj_nonlin_workspace_VM[8],
                               const real_T obj_nonlin_workspace_LM0[8],
                               const real_T obj_nonlin_workspace_alpha0[8],
                               const real_T obj_nonlin_workspace_FM0[8],
                               real_T cEqPlus[2], int32_T dim, real_T delta,
                               real_T xk[8], real_T *fplus);

/* End of code generation (finDiffEvalAndChkErr.h) */
