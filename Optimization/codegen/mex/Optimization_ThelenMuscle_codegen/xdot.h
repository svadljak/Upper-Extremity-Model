/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdot.h
 *
 * Code generation for function 'xdot'
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
real_T b_xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
              const real_T y[12]);

real_T c_xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
              const real_T y[13]);

real_T xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
            const real_T y[299]);

/* End of code generation (xdot.h) */
