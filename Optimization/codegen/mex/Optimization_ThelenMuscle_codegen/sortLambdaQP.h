/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortLambdaQP.h
 *
 * Code generation for function 'sortLambdaQP'
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
void sortLambdaQP(const emlrtStack *sp, real_T lambda[23],
                  int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const int32_T WorkingSet_Wid[23],
                  const int32_T WorkingSet_Wlocalidx[23],
                  real_T workspace[299]);

/* End of code generation (sortLambdaQP.h) */
