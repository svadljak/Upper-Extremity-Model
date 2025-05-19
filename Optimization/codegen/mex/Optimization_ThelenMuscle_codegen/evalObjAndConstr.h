/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstr.h
 *
 * Code generation for function 'evalObjAndConstr'
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
real_T evalObjAndConstr(const emlrtStack *sp,
                        const real_T c_obj_next_next_next_next_next_[16],
                        const real_T d_obj_next_next_next_next_next_[2],
                        const real_T e_obj_next_next_next_next_next_[8],
                        const real_T f_obj_next_next_next_next_next_[8],
                        const real_T g_obj_next_next_next_next_next_[8],
                        const real_T h_obj_next_next_next_next_next_[8],
                        const real_T i_obj_next_next_next_next_next_[8],
                        const real_T j_obj_next_next_next_next_next_[8],
                        const real_T x[8], real_T Ceq_workspace[2],
                        int32_T *status);

/* End of code generation (evalObjAndConstr.h) */
