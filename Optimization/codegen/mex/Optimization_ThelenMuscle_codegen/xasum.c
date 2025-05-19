/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xasum.c
 *
 * Code generation for function 'xasum'
 *
 */

/* Include files */
#include "xasum.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kf_emlrtRSI = {
    23,      /* lineNo */
    "xasum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xasum.m" /* pathName */
};

/* Function Definitions */
real_T xasum(const emlrtStack *sp, int32_T n, const real_T x[13], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    int32_T kend;
    kend = (ix0 + n) - 1;
    b_st.site = &kf_emlrtRSI;
    if ((ix0 <= kend) && (kend > 2147483646)) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = ix0; k <= kend; k++) {
      y += muDoubleScalarAbs(x[k - 1]);
    }
  }
  return y;
}

/* End of code generation (xasum.c) */
