/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computePrimalFeasError.h
 *
 * Code generation for function 'computePrimalFeasError'
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
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[8],
                              const real_T cEq[2], const int32_T finiteLB[13],
                              int32_T mLB, const int32_T finiteUB[13]);

/* End of code generation (computePrimalFeasError.h) */
