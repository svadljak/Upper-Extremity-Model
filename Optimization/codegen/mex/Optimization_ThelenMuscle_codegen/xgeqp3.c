/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = {
    63,       /* lineNo */
    "xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    158,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    154,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    148,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    143,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    141,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    138,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    98,             /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, real_T A[529], int32_T m, int32_T n,
            int32_T jpvt[23], real_T tau[23])
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'q', 'p', '3'};
  ptrdiff_t jpvt_t[23];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n < 1) {
    memset(&tau[0], 0, 23U * sizeof(real_T));
    b_st.site = &lb_emlrtRSI;
    i = (n / 4) << 2;
    j = i - 4;
    for (k = 0; k <= j; k += 4) {
      _mm_storeu_si128(
          (__m128i *)&jpvt[k],
          _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1)));
    }
    for (k = i; k < n; k++) {
      jpvt[k] = k + 1;
    }
  } else {
    ptrdiff_t info_t;
    boolean_T overflow;
    for (i = 0; i < 23; i++) {
      jpvt_t[i] = (ptrdiff_t)jpvt[i];
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &A[0],
                            (ptrdiff_t)23, &jpvt_t[0], &tau[0]);
    b_st.site = &kb_emlrtRSI;
    if ((int32_T)info_t != 0) {
      overflow = true;
      if ((int32_T)info_t != -4) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      b_st.site = &jb_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      overflow = (m > 2147483646);
      for (j = 0; j < n; j++) {
        b_st.site = &ib_emlrtRSI;
        if (overflow) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (i = 0; i < m; i++) {
          A[j * 23 + i] = rtNaN;
        }
      }
      i = muIntScalarMin_sint32(m, n) - 1;
      b_st.site = &hb_emlrtRSI;
      for (k = 0; k <= i; k++) {
        tau[k] = rtNaN;
      }
      i += 2;
      for (k = i; k < 24; k++) {
        tau[k - 1] = 0.0;
      }
      b_st.site = &gb_emlrtRSI;
      i = (n / 4) << 2;
      j = i - 4;
      for (k = 0; k <= j; k += 4) {
        _mm_storeu_si128(
            (__m128i *)&jpvt[k],
            _mm_add_epi32(
                _mm_add_epi32(_mm_set1_epi32(k),
                              _mm_loadu_si128((const __m128i *)&iv[0])),
                _mm_set1_epi32(1)));
      }
      for (k = i; k < n; k++) {
        jpvt[k] = k + 1;
      }
    } else {
      b_st.site = &fb_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k < n; k++) {
        jpvt[k] = (int32_T)jpvt_t[k];
      }
    }
  }
}

/* End of code generation (xgeqp3.c) */
