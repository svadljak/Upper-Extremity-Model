/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BFGSUpdate.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "BFGSUpdate.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int nvar
 *                double Bk[64]
 *                const double sk[13]
 *                double yk[13]
 *                double workspace[299]
 * Return Type  : boolean_T
 */
boolean_T BFGSUpdate(int nvar, double Bk[64], const double sk[13],
                     double yk[13], double workspace[299])
{
  __m128d r;
  __m128d r1;
  double curvatureS;
  double dotSY;
  double theta;
  int i;
  int i1;
  int ia;
  int iac;
  int ix;
  int scalarLB;
  int vectorUB;
  boolean_T success;
  dotSY = 0.0;
  i = (unsigned char)nvar;
  for (ix = 0; ix < i; ix++) {
    dotSY += sk[ix] * yk[ix];
    workspace[ix] = 0.0;
  }
  ix = 0;
  i1 = ((nvar - 1) << 3) + 1;
  for (iac = 1; iac <= i1; iac += 8) {
    scalarLB = iac + nvar;
    for (ia = iac; ia < scalarLB; ia++) {
      vectorUB = ia - iac;
      workspace[vectorUB] += Bk[ia - 1] * sk[ix];
    }
    ix++;
  }
  curvatureS = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      curvatureS += sk[ix] * workspace[ix];
    }
  }
  if (dotSY < 0.2 * curvatureS) {
    theta = 0.8 * curvatureS / (curvatureS - dotSY);
    scalarLB = ((unsigned char)nvar >> 1) << 1;
    vectorUB = scalarLB - 2;
    for (ix = 0; ix <= vectorUB; ix += 2) {
      r = _mm_loadu_pd(&yk[ix]);
      _mm_storeu_pd(&yk[ix], _mm_mul_pd(_mm_set1_pd(theta), r));
    }
    for (ix = scalarLB; ix < i; ix++) {
      yk[ix] *= theta;
    }
    if (!(1.0 - theta == 0.0)) {
      scalarLB = nvar / 2 * 2;
      vectorUB = scalarLB - 2;
      for (ix = 0; ix <= vectorUB; ix += 2) {
        r = _mm_loadu_pd(&workspace[ix]);
        r = _mm_mul_pd(_mm_set1_pd(1.0 - theta), r);
        r1 = _mm_loadu_pd(&yk[ix]);
        r = _mm_add_pd(r1, r);
        _mm_storeu_pd(&yk[ix], r);
      }
      for (ix = scalarLB; ix < nvar; ix++) {
        yk[ix] += (1.0 - theta) * workspace[ix];
      }
    }
    dotSY = 0.0;
    for (ix = 0; ix < i; ix++) {
      dotSY += sk[ix] * yk[ix];
    }
  }
  if ((curvatureS > 2.2204460492503131E-16) &&
      (dotSY > 2.2204460492503131E-16)) {
    success = true;
  } else {
    success = false;
  }
  if (success) {
    curvatureS = -1.0 / curvatureS;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      for (iac = 0; iac < i; iac++) {
        theta = workspace[iac];
        if (theta != 0.0) {
          theta *= curvatureS;
          i1 = nvar + ix;
          scalarLB = (i1 - ix) / 2 * 2 + ix;
          vectorUB = scalarLB - 2;
          for (ia = ix; ia <= vectorUB; ia += 2) {
            r = _mm_loadu_pd(&workspace[ia - ix]);
            r = _mm_mul_pd(r, _mm_set1_pd(theta));
            r1 = _mm_loadu_pd(&Bk[ia - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&Bk[ia - 1], r);
          }
          for (ia = scalarLB; ia < i1; ia++) {
            Bk[ia - 1] += workspace[ia - ix] * theta;
          }
        }
        ix += 8;
      }
    }
    curvatureS = 1.0 / dotSY;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      for (iac = 0; iac < i; iac++) {
        theta = yk[iac];
        if (theta != 0.0) {
          theta *= curvatureS;
          i1 = nvar + ix;
          scalarLB = (i1 - ix) / 2 * 2 + ix;
          vectorUB = scalarLB - 2;
          for (ia = ix; ia <= vectorUB; ia += 2) {
            r = _mm_loadu_pd(&yk[ia - ix]);
            r = _mm_mul_pd(r, _mm_set1_pd(theta));
            r1 = _mm_loadu_pd(&Bk[ia - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&Bk[ia - 1], r);
          }
          for (ia = scalarLB; ia < i1; ia++) {
            Bk[ia - 1] += yk[ia - ix] * theta;
          }
        }
        ix += 8;
      }
    }
  }
  return success;
}

/*
 * File trailer for BFGSUpdate.c
 *
 * [EOF]
 */
