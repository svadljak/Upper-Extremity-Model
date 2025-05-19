/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find_neg_lambda.c
 *
 * Code generation for function 'find_neg_lambda'
 *
 */

/* Include files */
#include "find_neg_lambda.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = {
    1,                 /* lineNo */
    "find_neg_lambda", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_"
    "neg_lambda.p" /* pathName */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                 /* iFirst */
    23,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "find_neg_lambda", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_"
    "neg_lambda.p", /* pName */
    0               /* checkKind */
};

/* Function Definitions */
int32_T find_neg_lambda(const emlrtStack *sp, const real_T solution_lambda[23],
                        int32_T workingset_nActiveConstr,
                        const int32_T workingset_nWConstr[5])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T minLambda;
  int32_T a;
  int32_T idx;
  int32_T idxMinLambda;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idxMinLambda = 0;
  minLambda = 0.0;
  a = (workingset_nWConstr[0] + workingset_nWConstr[1]) + 1;
  st.site = &ve_emlrtRSI;
  if ((a <= workingset_nActiveConstr) &&
      (workingset_nActiveConstr > 2147483646)) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a; idx <= workingset_nActiveConstr; idx++) {
    real_T d;
    if ((idx < 1) || (idx > 23)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &e_emlrtBCI, (emlrtConstCTX)sp);
    }
    d = solution_lambda[idx - 1];
    if (d < minLambda) {
      minLambda = d;
      idxMinLambda = idx;
    }
  }
  return idxMinLambda;
}

/* End of code generation (find_neg_lambda.c) */
