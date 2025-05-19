/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[299],
             const real_T x[13], real_T y[299])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_tmp;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_tmp = 13 * (n - 1) + 1;
  b_st.site = &sb_emlrtRSI;
  if (b_tmp > 2147483634) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (iac = 1; iac <= b_tmp; iac += 13) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = (iac + m) - 1;
    b_st.site = &rb_emlrtRSI;
    if ((iac <= b) && (b > 2147483646)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac; ia <= b; ia++) {
      c += A[ia - 1] * x[ia - iac];
    }
    b = div_nde_s32_floor(iac - 1, 13);
    y[b] -= c;
  }
}

void c_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[299], real_T y[23])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jd_emlrtRSI;
  r = _mm_loadu_pd(&y[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  b_st.site = &sb_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = iac + m;
    b_st.site = &rb_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += A[ia - 1] * x[(ia - iac) - 1];
    }
    b = div_nde_s32_floor(iac, 13);
    y[b] += c;
  }
}

void d_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[299], real_T y[23])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jd_emlrtRSI;
  r = _mm_loadu_pd(&y[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  b_st.site = &sb_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = iac + m;
    b_st.site = &rb_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += A[ia - 1] * x[(ia - iac) + 22];
    }
    b = div_nde_s32_floor(iac, 13);
    y[b] += c;
  }
}

void e_xgemv(const emlrtStack *sp, int32_T m, const real_T A[26],
             const real_T x[13], real_T y[23])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jd_emlrtRSI;
  r = _mm_loadu_pd(&y[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  b_st.site = &sb_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = iac + m;
    b_st.site = &rb_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += A[ia - 1] * x[(ia - iac) - 1];
    }
    b = div_nde_s32_floor(iac, 13);
    y[b] += c;
  }
}

void f_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[529],
             int32_T ia0, const real_T x[299], real_T y[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    int32_T b;
    int32_T ix;
    b_st.site = &tb_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    memset(&y[0], 0, (uint32_T)m * sizeof(real_T));
    ix = 0;
    b = ia0 + 23 * (n - 1);
    b_st.site = &u_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483624)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = ia0; iac <= b; iac += 23) {
      int32_T b_b;
      b_b = (iac + m) - 1;
      b_st.site = &t_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b_b; ia++) {
        int32_T i;
        i = ia - iac;
        y[i] += A[ia - 1] * x[ix];
      }
      ix++;
    }
  }
}

void g_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[529],
             int32_T ia0, const real_T x[13], real_T y[299])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    int32_T b;
    b_st.site = &tb_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    b = ia0 + 23 * (n - 1);
    b_st.site = &sb_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483624)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = ia0; iac <= b; iac += 23) {
      real_T c;
      int32_T b_b;
      c = 0.0;
      b_b = (iac + m) - 1;
      b_st.site = &rb_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b_b; ia++) {
        c += A[ia - 1] * x[ia - iac];
      }
      b_b = div_nde_s32_floor(iac - ia0, 23);
      y[b_b] -= c;
    }
  }
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[64],
           int32_T lda, const real_T x[13], real_T y[12])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    int32_T b_tmp;
    int32_T ix;
    boolean_T overflow;
    b_st.site = &tb_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    if (m - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)m * sizeof(real_T));
    }
    ix = 0;
    b_tmp = lda * (n - 1) + 1;
    b_st.site = &u_emlrtRSI;
    if ((lda == 0) || ((lda > 0) && (b_tmp < 1)) ||
        ((lda < 0) && (b_tmp > 1))) {
      overflow = false;
    } else if (lda > 0) {
      overflow = (b_tmp > MAX_int32_T - lda);
    } else {
      overflow = (b_tmp < MIN_int32_T - lda);
    }
    if (lda == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = 1; lda < 0 ? iac >= b_tmp : iac <= b_tmp; iac += lda) {
      int32_T b;
      b = (iac + m) - 1;
      b_st.site = &t_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        int32_T i;
        i = ia - iac;
        y[i] += A[ia - 1] * x[ix];
      }
      ix++;
    }
  }
}

/* End of code generation (xgemv.c) */
