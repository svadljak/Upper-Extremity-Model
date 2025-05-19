/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computePrimalFeasError.c
 *
 * Code generation for function 'computePrimalFeasError'
 *
 */

/* Include files */
#include "computePrimalFeasError.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = {
    1,                        /* lineNo */
    "computePrimalFeasError", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computePrimalFeasError.p" /* pathName */
};

static emlrtBCInfo f_emlrtBCI = {
    1,                        /* iFirst */
    8,                        /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "computePrimalFeasError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computePrimalFeasError.p", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[8],
                              const real_T cEq[2], const int32_T finiteLB[13],
                              int32_T mLB, const int32_T finiteUB[13])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T feasError;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  feasError =
      muDoubleScalarMax(muDoubleScalarMax(0.0, muDoubleScalarAbs(cEq[0])),
                        muDoubleScalarAbs(cEq[1]));
  st.site = &x_emlrtRSI;
  st.site = &x_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    int32_T i1;
    i1 = finiteLB[idx];
    if ((i1 < 1) || (i1 > 8)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 8, &f_emlrtBCI, (emlrtConstCTX)sp);
    }
    feasError = muDoubleScalarMax(feasError, 0.0 - x[i1 - 1]);
  }
  st.site = &x_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    i = finiteUB[idx];
    if ((i < 1) || (i > 8)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 8, &f_emlrtBCI, (emlrtConstCTX)sp);
    }
    feasError = muDoubleScalarMax(feasError, x[i - 1] - 1.0);
  }
  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
