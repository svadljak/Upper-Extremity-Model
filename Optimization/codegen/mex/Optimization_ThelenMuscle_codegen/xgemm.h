/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemm.h
 *
 * Code generation for function 'xgemm'
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
void b_xgemm(int32_T m, int32_T k, const real_T A[529], const real_T B[299],
             real_T C[299]);

void c_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[64], int32_T lda,
             const real_T B[529], int32_T ib0, real_T C[299]);

void d_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[529], int32_T ia0,
             const real_T B[299], real_T C[529]);

void xgemm(int32_T m, int32_T k, const real_T A[529], const real_T B[299],
           real_T C[299]);

/* End of code generation (xgemm.h) */
