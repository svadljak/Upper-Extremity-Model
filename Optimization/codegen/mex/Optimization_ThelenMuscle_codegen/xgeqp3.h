/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.h
 *
 * Code generation for function 'xgeqp3'
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
void xgeqp3(const emlrtStack *sp, real_T A[529], int32_T m, int32_T n,
            int32_T jpvt[23], real_T tau[23]);

/* End of code generation (xgeqp3.h) */
