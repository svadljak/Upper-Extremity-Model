/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.h
 *
 * Code generation for function 'computeGradLag'
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
void b_computeGradLag(const emlrtStack *sp, real_T workspace[299], int32_T nVar,
                      const real_T grad[13], const real_T AeqTrans[26],
                      const int32_T finiteLB[13], int32_T mLB,
                      const int32_T finiteUB[13], const real_T lambda[23]);

void computeGradLag(const emlrtStack *sp, real_T workspace[13], int32_T nVar,
                    const real_T grad[13], const real_T AeqTrans[26],
                    const int32_T finiteLB[13], int32_T mLB,
                    const int32_T finiteUB[13], const real_T lambda[23]);

/* End of code generation (computeGradLag.h) */
