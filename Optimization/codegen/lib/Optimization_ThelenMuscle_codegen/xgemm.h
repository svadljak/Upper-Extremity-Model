/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemm.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef XGEMM_H
#define XGEMM_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xgemm(int m, int n, int k, const double A[529], int ia0,
             const double B[299], double C[529]);

void xgemm(int m, int n, int k, const double A[64], int lda,
           const double B[529], int ib0, double C[299]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xgemm.h
 *
 * [EOF]
 */
