/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * BFGSUpdate.c
 *
 * Code generation for function 'BFGSUpdate'
 *
 */

/* Include files */
#include "BFGSUpdate.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xdot.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo dg_emlrtRSI = {
    1,            /* lineNo */
    "BFGSUpdate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\BFGSUpdate.p" /* pathName */
};

/* Function Definitions */
boolean_T BFGSUpdate(const emlrtStack *sp, int32_T nvar, real_T Bk[64],
                     const real_T sk[13], real_T yk[13], real_T workspace[299])
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T curvatureS;
  real_T dotSY;
  real_T theta;
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T success;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  dotSY = c_xdot(&st, nvar, sk, yk);
  st.site = &dg_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &tb_emlrtRSI;
  if (nvar > 2147483646) {
    d_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  i = (uint8_T)nvar;
  memset(&workspace[0], 0, (uint32_T)i * sizeof(real_T));
  ix = 0;
  scalarLB = ((nvar - 1) << 3) + 1;
  for (iac = 1; iac <= scalarLB; iac += 8) {
    b = (iac + nvar) - 1;
    c_st.site = &t_emlrtRSI;
    if ((iac <= b) && (b > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac; ia <= b; ia++) {
      vectorUB = ia - iac;
      workspace[vectorUB] += Bk[ia - 1] * sk[ix];
    }
    ix++;
  }
  st.site = &dg_emlrtRSI;
  curvatureS = xdot(&st, nvar, sk, workspace);
  if (dotSY < 0.2 * curvatureS) {
    theta = 0.8 * curvatureS / (curvatureS - dotSY);
    st.site = &dg_emlrtRSI;
    b_st.site = &ob_emlrtRSI;
    c_st.site = &pb_emlrtRSI;
    scalarLB = ((uint8_T)nvar >> 1) << 1;
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
    st.site = &dg_emlrtRSI;
    dotSY = c_xdot(&st, nvar, sk, yk);
  }
  if ((curvatureS > 2.2204460492503131E-16) &&
      (dotSY > 2.2204460492503131E-16)) {
    success = true;
  } else {
    success = false;
  }
  if (success) {
    curvatureS = -1.0 / curvatureS;
    st.site = &dg_emlrtRSI;
    b_st.site = &dc_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      d_st.site = &wb_emlrtRSI;
      for (iac = 0; iac < i; iac++) {
        theta = workspace[iac];
        if (theta != 0.0) {
          theta *= curvatureS;
          b = (nvar + ix) - 1;
          d_st.site = &xb_emlrtRSI;
          if ((ix <= b) && (b > 2147483646)) {
            e_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          scalarLB = ((b - ix) + 1) / 2 * 2 + ix;
          vectorUB = scalarLB - 2;
          for (ia = ix; ia <= vectorUB; ia += 2) {
            r = _mm_loadu_pd(&workspace[ia - ix]);
            r = _mm_mul_pd(r, _mm_set1_pd(theta));
            r1 = _mm_loadu_pd(&Bk[ia - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&Bk[ia - 1], r);
          }
          for (ia = scalarLB; ia <= b; ia++) {
            Bk[ia - 1] += workspace[ia - ix] * theta;
          }
        }
        ix += 8;
      }
    }
    curvatureS = 1.0 / dotSY;
    st.site = &dg_emlrtRSI;
    b_st.site = &dc_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      d_st.site = &wb_emlrtRSI;
      for (iac = 0; iac < i; iac++) {
        theta = yk[iac];
        if (theta != 0.0) {
          theta *= curvatureS;
          b = (nvar + ix) - 1;
          d_st.site = &xb_emlrtRSI;
          if ((ix <= b) && (b > 2147483646)) {
            e_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          scalarLB = ((b - ix) + 1) / 2 * 2 + ix;
          vectorUB = scalarLB - 2;
          for (ia = ix; ia <= vectorUB; ia += 2) {
            r = _mm_loadu_pd(&yk[ia - ix]);
            r = _mm_mul_pd(r, _mm_set1_pd(theta));
            r1 = _mm_loadu_pd(&Bk[ia - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&Bk[ia - 1], r);
          }
          for (ia = scalarLB; ia <= b; ia++) {
            Bk[ia - 1] += yk[ia - ix] * theta;
          }
        }
        ix += 8;
      }
    }
  }
  return success;
}

/* End of code generation (BFGSUpdate.c) */
