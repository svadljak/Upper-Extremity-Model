/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemm.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xgemm.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[529]
 *                int ia0
 *                const double B[299]
 *                double C[529]
 * Return Type  : void
 */
void b_xgemm(int m, int n, int k, const double A[529], int ia0,
             const double B[299], double C[529])
{
  int cr;
  int ic;
  int w;
  if ((m != 0) && (n != 0)) {
    int br;
    int i;
    int i1;
    int lastColC;
    lastColC = 23 * (n - 1);
    for (cr = 0; cr <= lastColC; cr += 23) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, (unsigned int)((i1 - i) + 1) * sizeof(double));
      }
    }
    br = -1;
    for (cr = 0; cr <= lastColC; cr += 23) {
      int ar;
      ar = ia0;
      i = cr + 1;
      i1 = cr + m;
      for (ic = i; ic <= i1; ic++) {
        double temp;
        temp = 0.0;
        for (w = 0; w < k; w++) {
          temp += A[(w + ar) - 1] * B[(w + br) + 1];
        }
        C[ic - 1] += temp;
        ar += 23;
      }
      br += 23;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[64]
 *                int lda
 *                const double B[529]
 *                int ib0
 *                double C[299]
 * Return Type  : void
 */
void xgemm(int m, int n, int k, const double A[64], int lda,
           const double B[529], int ib0, double C[299])
{
  int cr;
  int ib;
  int ic;
  if ((m != 0) && (n != 0)) {
    int br;
    int i;
    int i1;
    int lastColC;
    br = ib0;
    lastColC = 23 * (n - 1);
    for (cr = 0; cr <= lastColC; cr += 23) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, (unsigned int)((i1 - i) + 1) * sizeof(double));
      }
    }
    for (cr = 0; cr <= lastColC; cr += 23) {
      int ar;
      ar = -1;
      i = br + k;
      for (ib = br; ib < i; ib++) {
        int i2;
        int scalarLB;
        int vectorUB;
        i1 = cr + 1;
        i2 = cr + m;
        scalarLB = ((i2 - i1) + 1) / 2 * 2 + i1;
        vectorUB = scalarLB - 2;
        for (ic = i1; ic <= vectorUB; ic += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&A[(ar + ic) - cr]);
          r = _mm_mul_pd(_mm_set1_pd(B[ib - 1]), r);
          r1 = _mm_loadu_pd(&C[ic - 1]);
          r = _mm_add_pd(r1, r);
          _mm_storeu_pd(&C[ic - 1], r);
        }
        for (ic = scalarLB; ic <= i2; ic++) {
          C[ic - 1] += B[ib - 1] * A[(ar + ic) - cr];
        }
        ar += lda;
      }
      br += 23;
    }
  }
}

/*
 * File trailer for xgemm.c
 *
 * [EOF]
 */
