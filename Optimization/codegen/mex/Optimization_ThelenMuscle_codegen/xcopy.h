/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcopy.h
 *
 * Code generation for function 'xcopy'
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
void b_xcopy(const emlrtStack *sp, int32_T n, real_T y[23]);

void c_xcopy(const emlrtStack *sp, int32_T n, const real_T x[299], int32_T ix0,
             real_T y[529], int32_T iy0);

void d_xcopy(const emlrtStack *sp, int32_T n, const real_T x[23],
             real_T y[299]);

void e_xcopy(const emlrtStack *sp, int32_T n, const real_T x[8], real_T y[13]);

void f_xcopy(const emlrtStack *sp, int32_T n, const real_T x[13], real_T y[13]);

void g_xcopy(const emlrtStack *sp, int32_T n, const real_T x[64], int32_T ix0,
             real_T y[529], int32_T iy0);

void h_xcopy(const emlrtStack *sp, int32_T n, real_T y[13]);

void i_xcopy(const emlrtStack *sp, int32_T n, real_T y[64], int32_T iy0);

void j_xcopy(const real_T x[2], real_T y[2]);

void xcopy(const emlrtStack *sp, int32_T n, const real_T x[23], real_T y[23]);

/* End of code generation (xcopy.h) */
