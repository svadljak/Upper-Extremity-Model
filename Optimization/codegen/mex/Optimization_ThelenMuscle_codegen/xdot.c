/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdot.c
 *
 * Code generation for function 'xdot'
 *
 */

/* Include files */
#include "xdot.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qd_emlrtRSI = {
    32,      /* lineNo */
    "xdotx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" /* pathName */
};

/* Function Definitions */
real_T b_xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
              const real_T y[12])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sc_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    c_st.site = &qd_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      d += x[k] * y[k];
    }
  }
  return d;
}

real_T c_xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
              const real_T y[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sc_emlrtRSI;
  d = 0.0;
  c_st.site = &qd_emlrtRSI;
  if (n > 2147483646) {
    d_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  i = (uint8_T)n;
  for (k = 0; k < i; k++) {
    d += x[k] * y[k];
  }
  return d;
}

real_T xdot(const emlrtStack *sp, int32_T n, const real_T x[13],
            const real_T y[299])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sc_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    c_st.site = &qd_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      d += x[k] * y[k];
    }
  }
  return d;
}

/* End of code generation (xdot.c) */
