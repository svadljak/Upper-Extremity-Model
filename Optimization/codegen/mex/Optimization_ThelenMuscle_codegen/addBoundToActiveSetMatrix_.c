/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addBoundToActiveSetMatrix_.c
 *
 * Code generation for function 'addBoundToActiveSetMatrix_'
 *
 */

/* Include files */
#include "addBoundToActiveSetMatrix_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo af_emlrtRSI = {
    1,                            /* lineNo */
    "addBoundToActiveSetMatrix_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p" /* pathName */
};

static emlrtBCInfo kd_emlrtBCI = {
    1,                            /* iFirst */
    299,                          /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    1,                            /* iFirst */
    23,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

/* Function Definitions */
void addBoundToActiveSetMatrix_(const emlrtStack *sp, f_struct_T *obj,
                                int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &af_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[3]++;
  i = (obj->isActiveIdx[3] + idx_local) - 1;
  if ((i < 1) || (i > 23)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 23, &jd_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &jd_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 4;
  obj->Wlocalidx[i] = idx_local;
  colOffset = 13 * i;
  if ((idx_local < 1) || (idx_local > 13)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 13, &ld_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i1 = obj->indexLB[idx_local - 1];
  if ((i1 < 1) || (i1 > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx_local - 1], 1, 13,
                                  &ld_emlrtBCI, (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &md_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->lb[i1 - 1];
  st.site = &af_emlrtRSI;
  for (idx = 0; idx <= i1 - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = i1 + colOffset;
  if ((i < 1) || (i > 299)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = -1.0;
  a_tmp = i1 + 1;
  b = obj->nVar;
  st.site = &af_emlrtRSI;
  if ((i1 + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a_tmp; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  switch (obj->probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj->nVar + colOffset;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

void b_addBoundToActiveSetMatrix_(const emlrtStack *sp, f_struct_T *obj,
                                  int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &af_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[4]++;
  i = (obj->isActiveIdx[4] + idx_local) - 1;
  if ((i < 1) || (i > 23)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 23, &jd_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &jd_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 5;
  obj->Wlocalidx[i] = idx_local;
  colOffset = 13 * i;
  if ((idx_local < 1) || (idx_local > 13)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 13, &ld_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i1 = obj->indexUB[idx_local - 1];
  if ((i1 < 1) || (i1 > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx_local - 1], 1, 13,
                                  &ld_emlrtBCI, (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &md_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->ub[i1 - 1];
  st.site = &af_emlrtRSI;
  for (idx = 0; idx <= i1 - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = i1 + colOffset;
  if ((i < 1) || (i > 299)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = 1.0;
  a_tmp = i1 + 1;
  b = obj->nVar;
  st.site = &af_emlrtRSI;
  if ((i1 + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a_tmp; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  switch (obj->probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj->nVar + colOffset;
    if ((i < 1) || (i > 299)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 299, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

/* End of code generation (addBoundToActiveSetMatrix_.c) */
