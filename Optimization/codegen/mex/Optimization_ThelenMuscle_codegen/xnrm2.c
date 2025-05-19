/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "xnrm2.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI = {
    23,      /* lineNo */
    "xnrm2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2."
    "m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    38,      /* lineNo */
    "xnrm2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xnrm2.m" /* pathName */
};

/* Function Definitions */
real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[0]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      b_st.site = &nb_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k < n; k++) {
        real_T absxk;
        absxk = muDoubleScalarAbs(x[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * muDoubleScalarSqrt(y);
    }
  }
  return y;
}

/* End of code generation (xnrm2.c) */
