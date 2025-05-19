/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.h
 *
 * Code generation for function 'xgemv'
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
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[299],
             const real_T x[13], real_T y[299]);

void c_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[299], real_T y[23]);

void d_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[299], real_T y[23]);

void e_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[13], real_T y[23]);

void f_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[529],
             int32_T ia0, const real_T x[299], real_T y[13]);

void g_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[529],
             int32_T ia0, const real_T x[13], real_T y[299]);

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[64],
           int32_T lda, const real_T x[13], real_T y[12]);

/* End of code generation (xgemv.h) */
