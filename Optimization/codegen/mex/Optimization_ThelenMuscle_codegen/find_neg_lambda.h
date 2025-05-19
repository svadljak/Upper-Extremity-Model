/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find_neg_lambda.h
 *
 * Code generation for function 'find_neg_lambda'
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
int32_T find_neg_lambda(const emlrtStack *sp, const real_T solution_lambda[23],
                        int32_T workingset_nActiveConstr,
                        const int32_T workingset_nWConstr[5]);

/* End of code generation (find_neg_lambda.h) */
