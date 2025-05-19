/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addAeqConstr.c
 *
 * Code generation for function 'addAeqConstr'
 *
 */

/* Include files */
#include "addAeqConstr.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mf_emlrtRSI = {
    1,              /* lineNo */
    "addAeqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAeqConstr.p" /* pathName */
};

static emlrtBCInfo od_emlrtBCI = {
    1,              /* iFirst */
    23,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "addAeqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAeqConstr.p", /* pName */
    3                             /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    1,              /* iFirst */
    2,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "addAeqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAeqConstr.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    1,              /* iFirst */
    26,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "addAeqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAeqConstr.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    1,              /* iFirst */
    299,            /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "addAeqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAeqConstr.p", /* pName */
    3                             /* checkKind */
};

/* Function Definitions */
void addAeqConstr(const emlrtStack *sp, f_struct_T *obj, int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T totalEq;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  totalEq = obj->nWConstr[0] + obj->nWConstr[1];
  if ((obj->nActiveConstr == totalEq) && (idx_local > obj->nWConstr[1])) {
    int32_T i;
    int32_T i1;
    int32_T iAeq0;
    int32_T iAw0;
    st.site = &mf_emlrtRSI;
    obj->nWConstr[1]++;
    i = (obj->isActiveIdx[1] + idx_local) - 1;
    if ((i < 1) || (i > 23)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 23, &jd_emlrtBCI, &st);
    }
    obj->isActiveConstr[i - 1] = true;
    obj->nActiveConstr++;
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &jd_emlrtBCI,
                                    &st);
    }
    i = obj->nActiveConstr - 1;
    obj->Wid[i] = 2;
    obj->Wlocalidx[i] = idx_local;
    iAeq0 = 13 * (idx_local - 1);
    iAw0 = 13 * i;
    st.site = &mf_emlrtRSI;
    if (obj->nVar > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i1 = (uint8_T)obj->nVar;
    for (idx = 0; idx < i1; idx++) {
      int32_T i2;
      i2 = (iAeq0 + idx) + 1;
      if ((i2 < 1) || (i2 > 26)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 26, &qd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      totalEq = (iAw0 + idx) + 1;
      if ((totalEq < 1) || (totalEq > 299)) {
        emlrtDynamicBoundsCheckR2012b(totalEq, 1, 299, &rd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->ATwset[totalEq - 1] = obj->Aeq[i2 - 1];
    }
    if ((idx_local < 1) || (idx_local > 2)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 2, &pd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &od_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[i] = obj->beq[idx_local - 1];
  } else {
    int32_T i;
    int32_T iAeq0;
    int32_T iAw0;
    obj->nActiveConstr++;
    st.site = &mf_emlrtRSI;
    moveConstraint_(&st, obj, totalEq + 1, obj->nActiveConstr);
    obj->nWConstr[1]++;
    if ((idx_local < 1) || (idx_local > 23)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 23, &od_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->isActiveConstr[idx_local - 1] = true;
    if ((totalEq + 1 < 1) || (totalEq + 1 > 23)) {
      emlrtDynamicBoundsCheckR2012b(totalEq + 1, 1, 23, &od_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->Wid[totalEq] = 2;
    obj->Wlocalidx[totalEq] = idx_local;
    iAeq0 = 13 * (idx_local - 1);
    iAw0 = 13 * totalEq;
    st.site = &mf_emlrtRSI;
    if (obj->nVar > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->nVar;
    for (idx = 0; idx < i; idx++) {
      int32_T i1;
      int32_T i2;
      i1 = (iAeq0 + idx) + 1;
      if (i1 > 26) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 26, &qd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i2 = (iAw0 + idx) + 1;
      if ((i2 < 1) || (i2 > 299)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 299, &rd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->ATwset[i2 - 1] = obj->Aeq[i1 - 1];
    }
    if (idx_local > 2) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 2, &pd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[totalEq] = obj->beq[idx_local - 1];
  }
}

/* End of code generation (addAeqConstr.c) */
