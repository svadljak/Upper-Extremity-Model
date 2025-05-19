/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: factorQR.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "factorQR.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : g_struct_T *obj
 *                const double A[299]
 *                int mrows
 *                int ncols
 * Return Type  : void
 */
void factorQR(g_struct_T *obj, const double A[299], int mrows, int ncols)
{
  int idx;
  int ix0;
  int k;
  int scalarLB;
  boolean_T guard1;
  scalarLB = mrows * ncols;
  guard1 = false;
  if (scalarLB > 0) {
    for (idx = 0; idx < ncols; idx++) {
      int iy0;
      ix0 = 13 * idx;
      iy0 = 23 * idx;
      scalarLB = (unsigned char)mrows;
      for (k = 0; k < scalarLB; k++) {
        obj->QR[iy0 + k] = A[ix0 + k];
      }
    }
    guard1 = true;
  } else if (scalarLB == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    scalarLB = (ncols / 4) << 2;
    ix0 = scalarLB - 4;
    for (idx = 0; idx <= ix0; idx += 4) {
      _mm_storeu_si128(
          (__m128i *)&obj->jpvt[idx],
          _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(idx),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1)));
    }
    for (idx = scalarLB; idx < ncols; idx++) {
      obj->jpvt[idx] = idx + 1;
    }
    if (mrows <= ncols) {
      scalarLB = mrows;
    } else {
      scalarLB = ncols;
    }
    obj->minRowCol = scalarLB;
    memset(&obj->tau[0], 0, 23U * sizeof(double));
    if (scalarLB >= 1) {
      qrf(obj->QR, mrows, ncols, scalarLB, obj->tau);
    }
  }
}

/*
 * File trailer for factorQR.c
 *
 * [EOF]
 */
