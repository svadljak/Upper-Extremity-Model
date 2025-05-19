/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rank.c
 *
 * Code generation for function 'rank'
 *
 */

/* Include files */
#include "rank.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T rank(const real_T qrmanager_QR[529], int32_T qrmanager_mrows,
             int32_T qrmanager_ncols)
{
  int32_T minmn;
  int32_T r;
  r = 0;
  minmn = muIntScalarMin_sint32(qrmanager_mrows, qrmanager_ncols);
  if (minmn > 0) {
    real_T tol;
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 *
                                (real_T)muIntScalarMax_sint32(
                                    qrmanager_mrows, qrmanager_ncols)) *
          muDoubleScalarAbs(qrmanager_QR[0]);
    while ((r < minmn) &&
           (!(muDoubleScalarAbs(qrmanager_QR[r + 23 * r]) <= tol))) {
      r++;
    }
  }
  return r;
}

/* End of code generation (rank.c) */
