/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGrad_StoreHx.c
 *
 * Code generation for function 'computeGrad_StoreHx'
 *
 */

/* Include files */
#include "computeGrad_StoreHx.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo od_emlrtRSI = {
    1,                     /* lineNo */
    "computeGrad_StoreHx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p" /* pathName */
};

static emlrtBCInfo ic_emlrtBCI = {
    1,                     /* iFirst */
    13,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    1,                     /* iFirst */
    12,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    1,                     /* iFirst */
    12,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
void computeGrad_StoreHx(const emlrtStack *sp, j_struct_T *obj,
                         const real_T H[64], const real_T f[13],
                         const real_T x[13])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T ixlast;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
  case 5:
    ixlast = obj->nvar;
    st.site = &od_emlrtRSI;
    if (obj->nvar - 1 > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = 0; b_i <= ixlast - 2; b_i++) {
      if ((b_i + 1 < 1) || (b_i + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 13, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->grad[b_i] = 0.0;
    }
    if ((obj->nvar < 1) || (obj->nvar > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 13, &ic_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;
  case 3: {
    st.site = &od_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ixlast = obj->nvar;
    st.site = &od_emlrtRSI;
    if (obj->nvar > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = 0; b_i < ixlast; b_i++) {
      if ((b_i + 1 < 1) || (b_i + 1 > 12)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 12, &kc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->grad[b_i] = obj->Hx[b_i];
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      int32_T scalarLB;
      int32_T vectorUB;
      scalarLB = (ixlast / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
  } break;
  case 4: {
    __m128d r;
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    st.site = &od_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    i = obj->nvar + 1;
    st.site = &od_emlrtRSI;
    scalarLB = (((13 - i) / 2) << 1) + i;
    vectorUB = scalarLB - 2;
    for (ixlast = i; ixlast <= vectorUB; ixlast += 2) {
      if ((ixlast < 1) || (ixlast > 12)) {
        emlrtDynamicBoundsCheckR2012b(ixlast, 1, 12, &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      _mm_storeu_pd(
          &obj->Hx[ixlast - 1],
          _mm_mul_pd(_mm_set1_pd(obj->beta), _mm_loadu_pd(&x[ixlast - 1])));
    }
    for (ixlast = scalarLB; ixlast < 13; ixlast++) {
      if (ixlast < 1) {
        emlrtDynamicBoundsCheckR2012b(ixlast, 1, 12, &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->Hx[ixlast - 1] = obj->beta * x[ixlast - 1];
    }
    st.site = &od_emlrtRSI;
    memcpy(&obj->grad[0], &obj->Hx[0], 12U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      scalarLB = (ixlast / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
    if (12 - obj->nvar >= 1) {
      ixlast = obj->nvar;
      i = 11 - obj->nvar;
      scalarLB = ((i + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        b_i = ixlast + k;
        r = _mm_loadu_pd(&obj->grad[b_i]);
        _mm_storeu_pd(&obj->grad[b_i], _mm_add_pd(r, _mm_set1_pd(obj->rho)));
      }
      for (k = scalarLB; k <= i; k++) {
        b_i = ixlast + k;
        obj->grad[b_i] += obj->rho;
      }
    }
  } break;
  }
}

/* End of code generation (computeGrad_StoreHx.c) */
