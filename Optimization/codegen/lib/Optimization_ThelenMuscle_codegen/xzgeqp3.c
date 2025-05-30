/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzgeqp3.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xzgeqp3.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double A[529]
 *                int m
 *                int n
 *                int nfxd
 *                double tau[23]
 * Return Type  : void
 */
void qrf(double A[529], int m, int n, int nfxd, double tau[23])
{
  double work[23];
  double atmp;
  int b_i;
  int i;
  memset(&tau[0], 0, 23U * sizeof(double));
  memset(&work[0], 0, 23U * sizeof(double));
  i = (unsigned char)nfxd;
  for (b_i = 0; b_i < i; b_i++) {
    double d;
    int ii;
    int mmi;
    ii = b_i * 23 + b_i;
    mmi = m - b_i;
    if (b_i + 1 < m) {
      atmp = A[ii];
      d = xzlarfg(mmi, &atmp, A, ii + 2);
      tau[b_i] = d;
      A[ii] = atmp;
    } else {
      d = 0.0;
      tau[b_i] = 0.0;
    }
    if (b_i + 1 < n) {
      atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - b_i) - 1, ii + 1, d, A, ii + 24, work);
      A[ii] = atmp;
    }
  }
}

/*
 * File trailer for xzgeqp3.c
 *
 * [EOF]
 */
