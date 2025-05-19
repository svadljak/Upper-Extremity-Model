/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ComputeNumDependentEq_.c
 *
 * Code generation for function 'ComputeNumDependentEq_'
 *
 */

/* Include files */
#include "ComputeNumDependentEq_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = {
    1,                        /* lineNo */
    "ComputeNumDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\ComputeNumDependentEq_.p" /* pathName */
};

/* Function Definitions */
int32_T ComputeNumDependentEq_(const emlrtStack *sp, h_struct_T *qrmanager,
                               const real_T beqf[23], int32_T mConstr,
                               int32_T nVar)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T tol;
  int32_T k;
  int32_T numDependent;
  int32_T totalRank;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  totalRank = mConstr - nVar;
  numDependent = muIntScalarMax_sint32(0, totalRank);
  st.site = &qc_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  totalRank = (uint8_T)nVar;
  memset(&qrmanager->jpvt[0], 0, (uint32_T)totalRank * sizeof(int32_T));
  st.site = &qc_emlrtRSI;
  if (mConstr * nVar == 0) {
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    qrmanager->minRowCol = muIntScalarMin_sint32(mConstr, nVar);
    b_st.site = &db_emlrtRSI;
    xgeqp3(&b_st, qrmanager->QR, mConstr, nVar, qrmanager->jpvt,
           qrmanager->tau);
  }
  tol = muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 *
                              (real_T)muIntScalarMax_sint32(mConstr, nVar));
  totalRank = muIntScalarMin_sint32(nVar, mConstr);
  totalRank += 23 * (totalRank - 1);
  while ((totalRank > 0) && (muDoubleScalarAbs(qrmanager->QR[totalRank - 1]) <
                             tol * muDoubleScalarAbs(qrmanager->QR[0]))) {
    totalRank -= 24;
    numDependent++;
  }
  if (numDependent > 0) {
    boolean_T exitg1;
    st.site = &qc_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    computeQ_(&b_st, qrmanager, qrmanager->mrows);
    st.site = &qc_emlrtRSI;
    if (numDependent > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    totalRank = 0;
    exitg1 = false;
    while ((!exitg1) && (totalRank <= numDependent - 1)) {
      real_T qtb;
      int32_T ix;
      ix = 23 * ((mConstr - totalRank) - 1);
      st.site = &qc_emlrtRSI;
      b_st.site = &rc_emlrtRSI;
      c_st.site = &sc_emlrtRSI;
      qtb = 0.0;
      d_st.site = &tc_emlrtRSI;
      if (mConstr > 2147483646) {
        e_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (k = 0; k < mConstr; k++) {
        qtb += qrmanager->Q[ix + k] * beqf[k];
      }
      if (muDoubleScalarAbs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        totalRank++;
      }
    }
  }
  return numDependent;
}

/* End of code generation (ComputeNumDependentEq_.c) */
