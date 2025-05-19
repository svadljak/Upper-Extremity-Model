/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assignResidualsToXSlack.c
 *
 * Code generation for function 'assignResidualsToXSlack'
 *
 */

/* Include files */
#include "assignResidualsToXSlack.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = {
    1,                         /* lineNo */
    "assignResidualsToXSlack", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\assignResidualsToXSlack.p" /* pathName */
};

static emlrtBCInfo xd_emlrtBCI = {
    1,                         /* iFirst */
    13,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "assignResidualsToXSlack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\assignResidualsToXSlack.p", /* pName */
    3                                            /* checkKind */
};

/* Function Definitions */
void assignResidualsToXSlack(const emlrtStack *sp, int32_T nVarOrig,
                             f_struct_T *WorkingSet, d_struct_T *TrialState,
                             c_struct_T *memspace)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  st.site = &pf_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  memspace->workspace_float[0] = WorkingSet->beq[0];
  memspace->workspace_float[1] = WorkingSet->beq[1];
  st.site = &pf_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &jd_emlrtRSI;
  memspace->workspace_float[0] = -memspace->workspace_float[0];
  memspace->workspace_float[1] = -memspace->workspace_float[1];
  c_st.site = &sb_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = iac + nVarOrig;
    c_st.site = &rb_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += WorkingSet->Aeq[ia - 1] * TrialState->xstar[(ia - iac) - 1];
    }
    b = div_nde_s32_floor(iac, 13);
    memspace->workspace_float[b] += c;
  }
  st.site = &pf_emlrtRSI;
  if (memspace->workspace_float[0] <= 0.0) {
    if ((nVarOrig + 1 < 1) || (nVarOrig + 1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 1, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig] = 0.0;
    if ((nVarOrig + 3 < 1) || (nVarOrig + 3 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 3, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 2] = -memspace->workspace_float[0];
    st.site = &pf_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    addBoundToActiveSetMatrix_(&b_st, WorkingSet, 9);
    if (memspace->workspace_float[0] >= -1.0E-6) {
      st.site = &pf_emlrtRSI;
      b_st.site = &ye_emlrtRSI;
      addBoundToActiveSetMatrix_(&b_st, WorkingSet, 11);
    }
  } else {
    if ((nVarOrig + 1 < 1) || (nVarOrig + 1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 1, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig] = memspace->workspace_float[0];
    if ((nVarOrig + 3 < 1) || (nVarOrig + 3 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 3, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 2] = 0.0;
    st.site = &pf_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    addBoundToActiveSetMatrix_(&b_st, WorkingSet, 11);
    if (memspace->workspace_float[0] <= 1.0E-6) {
      st.site = &pf_emlrtRSI;
      b_st.site = &ye_emlrtRSI;
      addBoundToActiveSetMatrix_(&b_st, WorkingSet, 9);
    }
  }
  if (memspace->workspace_float[1] <= 0.0) {
    if ((nVarOrig + 2 < 1) || (nVarOrig + 2 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 2, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 1] = 0.0;
    if ((nVarOrig + 4 < 1) || (nVarOrig + 4 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 4, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 3] = -memspace->workspace_float[1];
    st.site = &pf_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    addBoundToActiveSetMatrix_(&b_st, WorkingSet, 10);
    if (memspace->workspace_float[1] >= -1.0E-6) {
      st.site = &pf_emlrtRSI;
      b_st.site = &ye_emlrtRSI;
      addBoundToActiveSetMatrix_(&b_st, WorkingSet, 12);
    }
  } else {
    if ((nVarOrig + 2 < 1) || (nVarOrig + 2 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 2, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 1] = memspace->workspace_float[1];
    if ((nVarOrig + 4 < 1) || (nVarOrig + 4 > 13)) {
      emlrtDynamicBoundsCheckR2012b(nVarOrig + 4, 1, 13, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    TrialState->xstar[nVarOrig + 3] = 0.0;
    st.site = &pf_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    addBoundToActiveSetMatrix_(&b_st, WorkingSet, 12);
    if (memspace->workspace_float[1] <= 1.0E-6) {
      st.site = &pf_emlrtRSI;
      b_st.site = &ye_emlrtRSI;
      addBoundToActiveSetMatrix_(&b_st, WorkingSet, 10);
    }
  }
}

/* End of code generation (assignResidualsToXSlack.c) */
