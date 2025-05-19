/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: maxConstraintViolation.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "maxConstraintViolation.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *obj
 *                const double x[13]
 * Return Type  : double
 */
double maxConstraintViolation(e_struct_T *obj, const double x[13])
{
  double v;
  int i;
  int ia;
  int idxLB;
  if (obj->probType == 2) {
    __m128d r;
    double c;
    r = _mm_loadu_pd(&obj->beq[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    for (idxLB = 0; idxLB <= 13; idxLB += 13) {
      c = 0.0;
      i = idxLB + 8;
      for (ia = idxLB + 1; ia <= i; ia++) {
        c += obj->Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 13);
      obj->maxConstrWorkspace[i] += c;
    }
    c = (obj->maxConstrWorkspace[0] - x[8]) + x[10];
    obj->maxConstrWorkspace[0] = c;
    v = fmax(0.0, fabs(c));
    c = (obj->maxConstrWorkspace[1] - x[9]) + x[11];
    obj->maxConstrWorkspace[1] = c;
    v = fmax(v, fabs(c));
  } else {
    __m128d r;
    r = _mm_loadu_pd(&obj->beq[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    for (idxLB = 0; idxLB <= 13; idxLB += 13) {
      double c;
      c = 0.0;
      i = idxLB + obj->nVar;
      for (ia = idxLB + 1; ia <= i; ia++) {
        c += obj->Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 13);
      obj->maxConstrWorkspace[i] += c;
    }
    v = fmax(fmax(0.0, fabs(obj->maxConstrWorkspace[0])),
             fabs(obj->maxConstrWorkspace[1]));
  }
  i = (unsigned char)obj->sizes[3];
  for (ia = 0; ia < i; ia++) {
    idxLB = obj->indexLB[ia] - 1;
    v = fmax(v, -x[idxLB] - obj->lb[idxLB]);
  }
  for (ia = 0; ia < 8; ia++) {
    idxLB = obj->indexUB[ia] - 1;
    v = fmax(v, x[idxLB] - obj->ub[idxLB]);
  }
  return v;
}

/*
 * File trailer for maxConstraintViolation.c
 *
 * [EOF]
 */
