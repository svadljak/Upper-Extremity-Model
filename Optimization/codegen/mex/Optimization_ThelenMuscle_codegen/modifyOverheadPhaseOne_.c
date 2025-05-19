/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    1,                         /* lineNo */
    "modifyOverheadPhaseOne_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p" /* pathName */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                         /* iFirst */
    299,                       /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                         /* iFirst */
    23,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

/* Function Definitions */
void modifyOverheadPhaseOne_(const emlrtStack *sp, f_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T idxEq;
  int32_T idxUpperExisting;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &l_emlrtRSI;
  idxUpperExisting = obj->nVar - 1;
  obj->Aeq[idxUpperExisting] = 0.0;
  obj->ATwset[idxUpperExisting] = 0.0;
  idxEq = obj->nVar + 12;
  obj->Aeq[idxEq] = 0.0;
  obj->ATwset[idxEq] = 0.0;
  st.site = &l_emlrtRSI;
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[idxUpperExisting] = 1.0E-5;
  idxUpperExisting = obj->nActiveConstr;
  st.site = &l_emlrtRSI;
  if (obj->nActiveConstr > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = 3; idx <= idxUpperExisting; idx++) {
    idxEq = obj->nVar + 13 * (idx - 1);
    if ((idxEq < 1) || (idxEq > 299)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, 299, &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->ATwset[idxEq - 1] = -1.0;
  }
  idxUpperExisting = obj->isActiveIdx[4] - 1;
  if (obj->nWConstr[4] > 0) {
    for (idx = 7; idx >= 0; idx--) {
      idxEq = idxUpperExisting + idx;
      if ((idxEq + 2 < 1) || (idxEq + 2 > 23)) {
        emlrtDynamicBoundsCheckR2012b(idxEq + 2, 1, 23, &k_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->isActiveConstr[idxEq + 1] = obj->isActiveConstr[idxEq];
    }
  } else {
    idxEq = obj->isActiveIdx[4] + 8;
    if ((idxEq < 1) || (idxEq > 23)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, 23, &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->isActiveConstr[idxEq - 1] = false;
  }
  obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
