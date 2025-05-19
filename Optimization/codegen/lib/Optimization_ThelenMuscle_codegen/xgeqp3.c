/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgeqp3.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xgeqp3.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzgeqp3.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double A[529]
 *                int m
 *                int n
 *                int jpvt[23]
 *                double tau[23]
 * Return Type  : void
 */
void xgeqp3(double A[529], int m, int n, int jpvt[23], double tau[23])
{
  double vn1[23];
  double vn2[23];
  double work[23];
  double temp;
  int b_i;
  int k;
  int minmn_tmp;
  int pvt;
  if (m <= n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = n;
  }
  memset(&tau[0], 0, 23U * sizeof(double));
  if (minmn_tmp < 1) {
    int iy;
    int nfxd;
    iy = (n / 4) << 2;
    nfxd = iy - 4;
    for (pvt = 0; pvt <= nfxd; pvt += 4) {
      _mm_storeu_si128(
          (__m128i *)&jpvt[pvt],
          _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(pvt),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1)));
    }
    for (pvt = iy; pvt < n; pvt++) {
      jpvt[pvt] = pvt + 1;
    }
  } else {
    int i;
    int ix;
    int iy;
    int nfxd;
    int temp_tmp;
    nfxd = 0;
    for (pvt = 0; pvt < n; pvt++) {
      if (jpvt[pvt] != 0) {
        nfxd++;
        if (pvt + 1 != nfxd) {
          ix = pvt * 23;
          iy = (nfxd - 1) * 23;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = A[temp_tmp];
            i = iy + k;
            A[temp_tmp] = A[i];
            A[i] = temp;
          }
          jpvt[pvt] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = pvt + 1;
        } else {
          jpvt[pvt] = pvt + 1;
        }
      } else {
        jpvt[pvt] = pvt + 1;
      }
    }
    if (nfxd > minmn_tmp) {
      nfxd = minmn_tmp;
    }
    qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      double d;
      memset(&work[0], 0, 23U * sizeof(double));
      memset(&vn1[0], 0, 23U * sizeof(double));
      memset(&vn2[0], 0, 23U * sizeof(double));
      i = nfxd + 1;
      for (pvt = i; pvt <= n; pvt++) {
        d = xnrm2(m - nfxd, A, (nfxd + (pvt - 1) * 23) + 1);
        vn1[pvt - 1] = d;
        vn2[pvt - 1] = d;
      }
      for (b_i = i; b_i <= minmn_tmp; b_i++) {
        double s;
        int ii;
        int ip1;
        int mmi;
        int nmi;
        ip1 = b_i + 1;
        iy = (b_i - 1) * 23;
        ii = (iy + b_i) - 1;
        nmi = (n - b_i) + 1;
        mmi = m - b_i;
        if (nmi < 1) {
          nfxd = -2;
        } else {
          nfxd = -1;
          if (nmi > 1) {
            temp = fabs(vn1[b_i - 1]);
            for (k = 2; k <= nmi; k++) {
              s = fabs(vn1[(b_i + k) - 2]);
              if (s > temp) {
                nfxd = k - 2;
                temp = s;
              }
            }
          }
        }
        pvt = b_i + nfxd;
        if (pvt + 1 != b_i) {
          ix = pvt * 23;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = A[temp_tmp];
            nfxd = iy + k;
            A[temp_tmp] = A[nfxd];
            A[nfxd] = temp;
          }
          nfxd = jpvt[pvt];
          jpvt[pvt] = jpvt[b_i - 1];
          jpvt[b_i - 1] = nfxd;
          vn1[pvt] = vn1[b_i - 1];
          vn2[pvt] = vn2[b_i - 1];
        }
        if (b_i < m) {
          temp = A[ii];
          d = xzlarfg(mmi + 1, &temp, A, ii + 2);
          tau[b_i - 1] = d;
          A[ii] = temp;
        } else {
          d = 0.0;
          tau[b_i - 1] = 0.0;
        }
        if (b_i < n) {
          temp = A[ii];
          A[ii] = 1.0;
          xzlarf(mmi + 1, nmi - 1, ii + 1, d, A, ii + 24, work);
          A[ii] = temp;
        }
        for (pvt = ip1; pvt <= n; pvt++) {
          iy = b_i + (pvt - 1) * 23;
          d = vn1[pvt - 1];
          if (d != 0.0) {
            temp = fabs(A[iy - 1]) / d;
            temp = 1.0 - temp * temp;
            if (temp < 0.0) {
              temp = 0.0;
            }
            s = d / vn2[pvt - 1];
            s = temp * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if (b_i < m) {
                d = xnrm2(mmi, A, iy + 1);
                vn1[pvt - 1] = d;
                vn2[pvt - 1] = d;
              } else {
                vn1[pvt - 1] = 0.0;
                vn2[pvt - 1] = 0.0;
              }
            } else {
              vn1[pvt - 1] = d * sqrt(temp);
            }
          }
        }
      }
    }
  }
}

/*
 * File trailer for xgeqp3.c
 *
 * [EOF]
 */
