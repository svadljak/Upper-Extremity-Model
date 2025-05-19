/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixamax.c
 *
 * Code generation for function 'ixamax'
 *
 */

/* Include files */
#include "ixamax.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T b_ixamax(const emlrtStack *sp, int32_T n, const real_T x[529])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idxmax;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      smax = muDoubleScalarAbs(x[0]);
      b_st.site = &w_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 2; k <= n; k++) {
        real_T s;
        s = muDoubleScalarAbs(x[(k - 1) * 24]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }
  return idxmax;
}

int32_T ixamax(const emlrtStack *sp, int32_T n, const real_T x[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idxmax;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      smax = muDoubleScalarAbs(x[0]);
      b_st.site = &w_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 2; k <= n; k++) {
        real_T s;
        s = muDoubleScalarAbs(x[k - 1]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }
  return idxmax;
}

/* End of code generation (ixamax.c) */
