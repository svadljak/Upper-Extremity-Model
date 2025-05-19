/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcopy.c
 *
 * Code generation for function 'xcopy'
 *
 */

/* Include files */
#include "xcopy.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_xcopy(const emlrtStack *sp, int32_T n, real_T y[23])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (n - 1 >= 0) {
    memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
  }
}

void c_xcopy(const emlrtStack *sp, int32_T n, const real_T x[299], int32_T ix0,
             real_T y[529], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  for (k = 0; k < i; k++) {
    y[(iy0 + k) - 1] = x[(ix0 + k) - 1];
  }
}

void d_xcopy(const emlrtStack *sp, int32_T n, const real_T x[23], real_T y[299])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  memcpy(&y[0], &x[0], (uint32_T)i * sizeof(real_T));
}

void e_xcopy(const emlrtStack *sp, int32_T n, const real_T x[8], real_T y[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  memcpy(&y[0], &x[0], (uint32_T)i * sizeof(real_T));
}

void f_xcopy(const emlrtStack *sp, int32_T n, const real_T x[13], real_T y[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (n - 1 >= 0) {
    memcpy(&y[0], &x[0], (uint32_T)n * sizeof(real_T));
  }
}

void g_xcopy(const emlrtStack *sp, int32_T n, const real_T x[64], int32_T ix0,
             real_T y[529], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < n; k++) {
    y[(iy0 + k) - 1] = x[(ix0 + k) - 1];
  }
}

void h_xcopy(const emlrtStack *sp, int32_T n, real_T y[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
}

void i_xcopy(const emlrtStack *sp, int32_T n, real_T y[64], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  if (i - 1 >= 0) {
    memset(&y[iy0 + -1], 0, (uint32_T)i * sizeof(real_T));
  }
}

void j_xcopy(const real_T x[2], real_T y[2])
{
  y[0] = x[0];
  y[1] = x[1];
}

void xcopy(const emlrtStack *sp, int32_T n, const real_T x[23], real_T y[23])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &q_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  memcpy(&y[0], &x[0], (uint32_T)i * sizeof(real_T));
}

/* End of code generation (xcopy.c) */
