/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = {
    1,                          /* lineNo */
    "updateWorkingSetForNewQP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p" /* pathName */
};

static emlrtBCInfo fe_emlrtBCI = {
    1,                          /* iFirst */
    8,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    1,                          /* iFirst */
    23,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    1,                          /* iFirst */
    13,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    1,                          /* iFirst */
    0,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

/* Function Definitions */
void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[8],
                              f_struct_T *WorkingSet, const real_T cEq[2],
                              int32_T mLB)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T i;
  int32_T iEq0;
  int32_T idx;
  int32_T iw0;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &i_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = _mm_mul_pd(_mm_loadu_pd(&cEq[0]), _mm_set1_pd(-1.0));
  _mm_storeu_pd(&WorkingSet->beq[0], r);
  _mm_storeu_pd(&WorkingSet->bwset[0], r);
  iw0 = 1;
  iEq0 = 1;
  st.site = &i_emlrtRSI;
  for (idx = 0; idx < 2; idx++) {
    i = WorkingSet->nVar;
    for (b_i = 0; b_i < i; b_i++) {
      int32_T i1;
      i1 = iEq0 + b_i;
      if ((i1 < 1) || (i1 > 26)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 26, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      WorkingSet->ATwset[i1 - 1] = WorkingSet->Aeq[i1 - 1];
    }
    iEq0 = iw0 + 13;
    iw0 += 13;
  }
  st.site = &i_emlrtRSI;
  st.site = &i_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 8,
                                    &fe_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        xk[WorkingSet->indexLB[idx] - 1];
  }
  st.site = &i_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 13,
                                    &c_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        1.0 - xk[WorkingSet->indexUB[idx] - 1];
  }
  st.site = &i_emlrtRSI;
  if (WorkingSet->nActiveConstr > 2) {
    iw0 = WorkingSet->nActiveConstr;
    st.site = &i_emlrtRSI;
    if (WorkingSet->nActiveConstr > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 3; idx <= iw0; idx++) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &ge_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      switch (WorkingSet->Wid[idx - 1]) {
      case 4:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 13,
                                        &he_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexLB[i - 1];
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 13, &he_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->lb[i - 1];
        break;
      case 5:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 13,
                                        &he_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexUB[WorkingSet->Wlocalidx[idx - 1] - 1];
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 13, &he_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->ub[i - 1];
        break;
      default:
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 0,
                                      &ie_emlrtBCI, (emlrtConstCTX)sp);
        break;
      }
    }
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
