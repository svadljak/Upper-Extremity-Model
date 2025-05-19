/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemv.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xgemv.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int m
 *                const double A[26]
 *                const double x[299]
 *                double y[23]
 * Return Type  : void
 */
void xgemv(int m, const double A[26], const double x[299], double y[23])
{
  __m128d r;
  int ia;
  int iac;
  r = _mm_loadu_pd(&y[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  for (iac = 0; iac <= 13; iac += 13) {
    double c;
    int i;
    c = 0.0;
    i = iac + m;
    for (ia = iac + 1; ia <= i; ia++) {
      c += A[ia - 1] * x[(ia - iac) + 22];
    }
    i = div_nde_s32_floor(iac, 13);
    y[i] += c;
  }
}

/*
 * File trailer for xgemv.c
 *
 * [EOF]
 */
