/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fullColLDL2_.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "fullColLDL2_.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : h_struct_T *obj
 *                int NColsRemain
 * Return Type  : void
 */
void fullColLDL2_(h_struct_T *obj, int NColsRemain)
{
  int ijA;
  int j;
  int jA;
  int k;
  for (k = 0; k < NColsRemain; k++) {
    __m128d r;
    double alpha1;
    double y;
    int LD_diagOffset;
    int i;
    int offset1;
    int scalarLB;
    int subMatrixDim;
    int vectorUB;
    LD_diagOffset = 24 * k;
    alpha1 = -1.0 / obj->FMat[LD_diagOffset];
    subMatrixDim = (NColsRemain - k) - 2;
    offset1 = LD_diagOffset + 2;
    y = obj->workspace_;
    for (jA = 0; jA <= subMatrixDim; jA++) {
      y = obj->FMat[(LD_diagOffset + jA) + 1];
    }
    obj->workspace_ = y;
    if (!(alpha1 == 0.0)) {
      jA = LD_diagOffset;
      for (j = 0; j <= subMatrixDim; j++) {
        if (y != 0.0) {
          double temp;
          int i1;
          temp = y * alpha1;
          i = jA + 25;
          i1 = subMatrixDim + jA;
          scalarLB = ((i1 - i) + 26) / 2 * 2 + i;
          vectorUB = scalarLB - 2;
          for (ijA = i; ijA <= vectorUB; ijA += 2) {
            r = _mm_loadu_pd(&obj->FMat[ijA - 1]);
            r = _mm_add_pd(r, _mm_set1_pd(y * temp));
            _mm_storeu_pd(&obj->FMat[ijA - 1], r);
          }
          for (ijA = scalarLB; ijA <= i1 + 25; ijA++) {
            obj->FMat[ijA - 1] += y * temp;
          }
        }
        jA += 23;
      }
    }
    alpha1 = 1.0 / obj->FMat[LD_diagOffset];
    i = LD_diagOffset + subMatrixDim;
    scalarLB = ((i - offset1) + 3) / 2 * 2 + offset1;
    vectorUB = scalarLB - 2;
    for (jA = offset1; jA <= vectorUB; jA += 2) {
      r = _mm_loadu_pd(&obj->FMat[jA - 1]);
      r = _mm_mul_pd(_mm_set1_pd(alpha1), r);
      _mm_storeu_pd(&obj->FMat[jA - 1], r);
    }
    for (jA = scalarLB; jA <= i + 2; jA++) {
      obj->FMat[jA - 1] *= alpha1;
    }
  }
}

/*
 * File trailer for fullColLDL2_.c
 *
 * [EOF]
 */
