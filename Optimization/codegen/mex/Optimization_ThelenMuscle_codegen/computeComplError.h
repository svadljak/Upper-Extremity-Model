/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.h
 *
 * Code generation for function 'computeComplError'
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
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[8],
                         const int32_T finiteLB[13], int32_T mLB,
                         const int32_T finiteUB[13], const real_T lambda[23]);

/* End of code generation (computeComplError.h) */
