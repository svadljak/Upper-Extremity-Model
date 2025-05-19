/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeGrad_StoreHx.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "computeGrad_StoreHx.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : i_struct_T *obj
 *                const double H[64]
 *                const double f[13]
 *                const double x[13]
 * Return Type  : void
 */
void computeGrad_StoreHx(i_struct_T *obj, const double H[64],
                         const double f[13], const double x[13])
{
  int ia;
  int iac;
  int ixlast;
  int k;
  switch (obj->objtype) {
  case 5: {
    int i;
    i = obj->nvar;
    if (i - 2 >= 0) {
      memset(&obj->grad[0], 0, (unsigned int)(i - 1) * sizeof(double));
    }
    obj->grad[obj->nvar - 1] = obj->gammaScalar;
  } break;
  case 3: {
    int i;
    int ix;
    int lda;
    ixlast = obj->nvar - 1;
    lda = obj->nvar;
    if (obj->nvar != 0) {
      if (ixlast >= 0) {
        memset(&obj->Hx[0], 0, (unsigned int)(ixlast + 1) * sizeof(double));
      }
      ix = 0;
      i = obj->nvar * ixlast + 1;
      for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        int i1;
        i1 = iac + ixlast;
        for (ia = iac; ia <= i1; ia++) {
          k = ia - iac;
          obj->Hx[k] += H[ia - 1] * x[ix];
        }
        ix++;
      }
    }
    i = obj->nvar;
    if (i - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], (unsigned int)i * sizeof(double));
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      lda = (ixlast / 2) << 1;
      ix = lda - 2;
      for (k = 0; k <= ix; k += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = lda; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
  } break;
  case 4: {
    __m128d r;
    int i;
    int i1;
    int ix;
    int lda;
    ixlast = obj->nvar - 1;
    lda = obj->nvar;
    if (obj->nvar != 0) {
      if (ixlast >= 0) {
        memset(&obj->Hx[0], 0, (unsigned int)(ixlast + 1) * sizeof(double));
      }
      ix = 0;
      i = obj->nvar * (obj->nvar - 1) + 1;
      for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        i1 = iac + ixlast;
        for (ia = iac; ia <= i1; ia++) {
          k = ia - iac;
          obj->Hx[k] += H[ia - 1] * x[ix];
        }
        ix++;
      }
    }
    i = obj->nvar + 1;
    lda = (((13 - i) / 2) << 1) + i;
    ix = lda - 2;
    for (ixlast = i; ixlast <= ix; ixlast += 2) {
      _mm_storeu_pd(
          &obj->Hx[ixlast - 1],
          _mm_mul_pd(_mm_set1_pd(obj->beta), _mm_loadu_pd(&x[ixlast - 1])));
    }
    for (ixlast = lda; ixlast < 13; ixlast++) {
      obj->Hx[ixlast - 1] = obj->beta * x[ixlast - 1];
    }
    memcpy(&obj->grad[0], &obj->Hx[0], 12U * sizeof(double));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      lda = (ixlast / 2) << 1;
      ix = lda - 2;
      for (k = 0; k <= ix; k += 2) {
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = lda; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
    if (12 - obj->nvar >= 1) {
      ixlast = obj->nvar;
      i = 11 - obj->nvar;
      lda = ((i + 1) / 2) << 1;
      ix = lda - 2;
      for (k = 0; k <= ix; k += 2) {
        i1 = ixlast + k;
        r = _mm_loadu_pd(&obj->grad[i1]);
        _mm_storeu_pd(&obj->grad[i1], _mm_add_pd(r, _mm_set1_pd(obj->rho)));
      }
      for (k = lda; k <= i; k++) {
        i1 = ixlast + k;
        obj->grad[i1] += obj->rho;
      }
    }
  } break;
  }
}

/*
 * File trailer for computeGrad_StoreHx.c
 *
 * [EOF]
 */
