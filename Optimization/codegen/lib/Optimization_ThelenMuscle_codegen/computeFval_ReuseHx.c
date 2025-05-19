/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeFval_ReuseHx.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "computeFval_ReuseHx.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const i_struct_T *obj
 *                double workspace[299]
 *                const double f[13]
 *                const double x[13]
 * Return Type  : double
 */
double computeFval_ReuseHx(const i_struct_T *obj, double workspace[299],
                           const double f[13], const double x[13])
{
  double val;
  int b_i;
  int ixlast;
  int k;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * x[obj->nvar - 1];
    break;
  case 3: {
    if (obj->hasLinear) {
      int i;
      i = obj->nvar;
      ixlast = (i / 2) << 1;
      k = ixlast - 2;
      for (b_i = 0; b_i <= k; b_i += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj->Hx[b_i]);
        _mm_storeu_pd(
            &workspace[b_i],
            _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5), r), _mm_loadu_pd(&f[b_i])));
      }
      for (b_i = ixlast; b_i < i; b_i++) {
        workspace[b_i] = 0.5 * obj->Hx[b_i] + f[b_i];
      }
      if (obj->nvar >= 1) {
        ixlast = obj->nvar;
        for (k = 0; k < ixlast; k++) {
          val += x[k] * workspace[k];
        }
      }
    } else {
      if (obj->nvar >= 1) {
        ixlast = obj->nvar;
        for (k = 0; k < ixlast; k++) {
          val += x[k] * obj->Hx[k];
        }
      }
      val *= 0.5;
    }
  } break;
  case 4: {
    if (obj->hasLinear) {
      int i;
      i = obj->nvar;
      if (i - 1 >= 0) {
        memcpy(&workspace[0], &f[0], (unsigned int)i * sizeof(double));
      }
      i = 12 - obj->nvar;
      for (b_i = 0; b_i < i; b_i++) {
        workspace[obj->nvar + b_i] = obj->rho;
      }
      for (b_i = 0; b_i < 12; b_i++) {
        double d;
        d = workspace[b_i] + 0.5 * obj->Hx[b_i];
        workspace[b_i] = d;
        val += x[b_i] * d;
      }
    } else {
      int i;
      for (k = 0; k < 12; k++) {
        val += x[k] * obj->Hx[k];
      }
      val *= 0.5;
      i = obj->nvar + 1;
      for (ixlast = i; ixlast < 13; ixlast++) {
        val += x[ixlast - 1] * obj->rho;
      }
    }
  } break;
  }
  return val;
}

/*
 * File trailer for computeFval_ReuseHx.c
 *
 * [EOF]
 */
