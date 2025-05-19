/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "addAeqConstr.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sf_emlrtRSI = {
    1,     /* lineNo */
    "soc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\soc.p" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    1,                  /* lineNo */
    "updateWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\updateWorkingSet.p" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    1,                   /* lineNo */
    "restoreWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\restoreWorkingSet.p" /* pathName */
};

static emlrtBCInfo yd_emlrtBCI = {
    1,     /* iFirst */
    2,     /* iLast */
    1,     /* lineNo */
    1,     /* colNo */
    "",    /* aName */
    "soc", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\soc.p", /* pName */
    0              /* checkKind */
};

/* Function Definitions */
boolean_T soc(const emlrtStack *sp, const real_T Hessian[64],
              const real_T grad[13], d_struct_T *TrialState,
              c_struct_T *memspace, f_struct_T *WorkingSet,
              h_struct_T *QRManager, i_struct_T *CholManager,
              j_struct_T *QPObjective, const k_struct_T *qpoptions)
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T c;
  real_T oldDirIdx;
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T nVar;
  boolean_T exitg1;
  boolean_T success;
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
  nVar = WorkingSet->nVar;
  st.site = &sf_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    d_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &sf_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  memcpy(&TrialState->socDirection[0], &TrialState->xstar[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &sf_emlrtRSI;
  xcopy(&st, 23, TrialState->lambda, TrialState->lambdaStopTest);
  st.site = &sf_emlrtRSI;
  b_st.site = &tf_emlrtRSI;
  r = _mm_loadu_pd(&TrialState->cEq[0]);
  r1 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&WorkingSet->beq[0], _mm_mul_pd(r, r1));
  b_st.site = &tf_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &sb_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    c = 0.0;
    b = iac + WorkingSet->nVar;
    d_st.site = &rb_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      e_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += WorkingSet->Aeq[ia - 1] * TrialState->searchDir[(ia - iac) - 1];
    }
    i = div_nde_s32_floor(iac, 13);
    WorkingSet->beq[i] += c;
  }
  b_st.site = &tf_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  d_st.site = &q_emlrtRSI;
  WorkingSet->bwset[0] = WorkingSet->beq[0];
  WorkingSet->bwset[1] = WorkingSet->beq[1];
  st.site = &sf_emlrtRSI;
  e_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  st.site = &sf_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, qpoptions, qpoptions);
  exitg1 = false;
  while ((!exitg1) && (WorkingSet->mEqRemoved > 0)) {
    if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 2)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 2, &yd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >= 1) {
      if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 2)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 2,
                                      &yd_emlrtBCI, (emlrtConstCTX)sp);
      }
      st.site = &sf_emlrtRSI;
      addAeqConstr(&st, WorkingSet,
                   WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1]);
      WorkingSet->mEqRemoved--;
    } else {
      exitg1 = true;
    }
  }
  st.site = &sf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  b = ((uint8_T)nVar >> 1) << 1;
  ia = b - 2;
  for (iac = 0; iac <= ia; iac += 2) {
    __m128d r2;
    r = _mm_loadu_pd(&TrialState->socDirection[iac]);
    r2 = _mm_loadu_pd(&TrialState->xstar[iac]);
    _mm_storeu_pd(&TrialState->socDirection[iac], _mm_sub_pd(r2, r));
    _mm_storeu_pd(&TrialState->xstar[iac], r);
  }
  for (iac = b; iac < i; iac++) {
    c = TrialState->socDirection[iac];
    oldDirIdx = c;
    c = TrialState->xstar[iac] - c;
    TrialState->socDirection[iac] = c;
    TrialState->xstar[iac] = oldDirIdx;
  }
  st.site = &sf_emlrtRSI;
  c = xnrm2(&st, nVar, TrialState->socDirection);
  st.site = &sf_emlrtRSI;
  oldDirIdx = xnrm2(&st, nVar, TrialState->xstar);
  success = (c <= 2.0 * oldDirIdx);
  st.site = &sf_emlrtRSI;
  b_st.site = &uf_emlrtRSI;
  r = _mm_loadu_pd(&TrialState->cEq[0]);
  _mm_storeu_pd(&WorkingSet->beq[0], _mm_mul_pd(r, r1));
  b_st.site = &uf_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  d_st.site = &q_emlrtRSI;
  WorkingSet->bwset[0] = WorkingSet->beq[0];
  WorkingSet->bwset[1] = WorkingSet->beq[1];
  if (!success) {
    st.site = &sf_emlrtRSI;
    xcopy(&st, 23, TrialState->lambdaStopTest, TrialState->lambda);
  } else {
    st.site = &sf_emlrtRSI;
    sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                 WorkingSet->Wlocalidx, memspace->workspace_float);
  }
  return success;
}

/* End of code generation (soc.c) */
