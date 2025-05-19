/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation.h
 *
 * Code generation for function 'maxConstraintViolation'
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
real_T b_maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                                const real_T x[299]);

real_T c_maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                                const real_T x[13]);

real_T maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                              const real_T x[299]);

/* End of code generation (maxConstraintViolation.h) */
