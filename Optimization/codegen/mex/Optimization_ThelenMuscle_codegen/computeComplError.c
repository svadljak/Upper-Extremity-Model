/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.c
 *
 * Code generation for function 'computeComplError'
 *
 */

/* Include files */
#include "computeComplError.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = {
    1,                   /* lineNo */
    "computeComplError", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p" /* pathName */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p", /* pName */
    0                                /* checkKind */
};

/* Function Definitions */
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[8],
                         const int32_T finiteLB[13], int32_T mLB,
                         const int32_T finiteUB[13], const real_T lambda[23])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T nlpComplError;
  real_T nlpComplError_tmp;
  real_T ubLambda;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nlpComplError = 0.0;
  st.site = &ab_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    int32_T i1;
    i1 = finiteLB[idx];
    if ((i1 < 1) || (i1 > 8)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 8, &g_emlrtBCI, (emlrtConstCTX)sp);
    }
    nlpComplError_tmp = xCurrent[i1 - 1];
    ubLambda = lambda[idx + 2];
    nlpComplError = muDoubleScalarMax(
        nlpComplError,
        muDoubleScalarMin(
            muDoubleScalarAbs(nlpComplError_tmp * ubLambda),
            muDoubleScalarMin(muDoubleScalarAbs(nlpComplError_tmp), ubLambda)));
  }
  st.site = &ab_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    i = finiteUB[idx];
    if ((i < 1) || (i > 8)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 8, &g_emlrtBCI, (emlrtConstCTX)sp);
    }
    ubLambda = lambda[(mLB + idx) + 2];
    nlpComplError_tmp = 1.0 - xCurrent[i - 1];
    nlpComplError = muDoubleScalarMax(
        nlpComplError,
        muDoubleScalarMin(
            muDoubleScalarAbs(nlpComplError_tmp * ubLambda),
            muDoubleScalarMin(muDoubleScalarAbs(nlpComplError_tmp), ubLambda)));
  }
  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
