/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * setProblemType.c
 *
 * Code generation for function 'setProblemType'
 *
 */

/* Include files */
#include "setProblemType.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = {
    1,                            /* lineNo */
    "modifyOverheadRegularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p" /* pathName */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                            /* iFirst */
    299,                          /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                            /* iFirst */
    23,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    0                                           /* checkKind */
};

/* Function Definitions */
void b_setProblemType(const emlrtStack *sp, f_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_idx_col;
  int32_T i;
  int32_T idx_col;
  int32_T idx_row;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  obj->nVar = 12;
  obj->mConstr = 22;
  for (i = 0; i < 5; i++) {
    obj->sizes[i] = obj->sizesRegularized[i];
  }
  if (obj->probType != 4) {
    int32_T b;
    int32_T colOffsetAeq;
    st.site = &k_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    for (idx_col = 0; idx_col < 2; idx_col++) {
      b_idx_col = idx_col + 10;
      colOffsetAeq = 13 * idx_col;
      b_st.site = &m_emlrtRSI;
      i = idx_col + 8;
      b_st.site = &m_emlrtRSI;
      for (idx_row = 9; idx_row <= i; idx_row++) {
        obj->Aeq[colOffsetAeq + 8] = 0.0;
        obj->ATwset[colOffsetAeq + 8] = 0.0;
      }
      i = idx_col + colOffsetAeq;
      obj->Aeq[i + 8] = -1.0;
      obj->ATwset[i + 8] = -1.0;
      b_st.site = &m_emlrtRSI;
      for (idx_row = b_idx_col; idx_row < 11; idx_row++) {
        obj->Aeq[colOffsetAeq + 9] = 0.0;
        obj->ATwset[colOffsetAeq + 9] = 0.0;
      }
      b_st.site = &m_emlrtRSI;
      for (idx_row = 11; idx_row <= b_idx_col; idx_row++) {
        obj->Aeq[colOffsetAeq + 10] = 0.0;
        obj->ATwset[colOffsetAeq + 10] = 0.0;
      }
      obj->Aeq[i + 10] = 1.0;
      obj->ATwset[i + 10] = 1.0;
      i = idx_col + 12;
      b_st.site = &m_emlrtRSI;
      for (idx_row = i; idx_row < 13; idx_row++) {
        obj->Aeq[colOffsetAeq + 11] = 0.0;
        obj->ATwset[colOffsetAeq + 11] = 0.0;
      }
    }
    b_st.site = &m_emlrtRSI;
    obj->indexLB[8] = 9;
    obj->indexLB[9] = 10;
    obj->indexLB[10] = 11;
    obj->indexLB[11] = 12;
    i = obj->isActiveIdx[4];
    b_st.site = &m_emlrtRSI;
    for (b_idx_col = i; b_idx_col < 15; b_idx_col++) {
      obj->isActiveConstr[b_idx_col - 1] = false;
    }
    b_st.site = &m_emlrtRSI;
    obj->lb[8] = 0.0;
    obj->lb[9] = 0.0;
    obj->lb[10] = 0.0;
    obj->lb[11] = 0.0;
    b = obj->nActiveConstr;
    b_st.site = &m_emlrtRSI;
    if (obj->nActiveConstr > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx_col = 3; idx_col <= b; idx_col++) {
      int32_T colOffsetATw;
      colOffsetATw = 13 * (idx_col - 1);
      if (idx_col > 23) {
        emlrtDynamicBoundsCheckR2012b(idx_col, 1, 23, &i_emlrtBCI, &st);
      }
      if (obj->Wid[idx_col - 1] == 3) {
        b_idx_col = obj->Wlocalidx[idx_col - 1];
        colOffsetAeq = b_idx_col + 7;
        b_st.site = &m_emlrtRSI;
        if (b_idx_col + 7 > 2147483646) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx_row = 9; idx_row <= colOffsetAeq; idx_row++) {
          i = idx_row + colOffsetATw;
          if ((i < 1) || (i > 299)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 299, &h_emlrtBCI, &st);
          }
          obj->ATwset[i - 1] = 0.0;
        }
        i = (b_idx_col + colOffsetATw) + 8;
        if ((i < 1) || (i > 299)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 299, &h_emlrtBCI, &st);
        }
        obj->ATwset[i - 1] = -1.0;
        i = b_idx_col + 9;
        b_st.site = &m_emlrtRSI;
        for (idx_row = i; idx_row < 13; idx_row++) {
          b_idx_col = idx_row + colOffsetATw;
          if ((b_idx_col < 1) || (b_idx_col > 299)) {
            emlrtDynamicBoundsCheckR2012b(b_idx_col, 1, 299, &h_emlrtBCI, &st);
          }
          obj->ATwset[b_idx_col - 1] = 0.0;
        }
      } else {
        b_st.site = &m_emlrtRSI;
        if ((colOffsetATw + 9 < 1) || (colOffsetATw + 9 > 299)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw + 9, 1, 299, &h_emlrtBCI,
                                        &st);
        }
        obj->ATwset[colOffsetATw + 8] = 0.0;
        if ((colOffsetATw + 10 < 1) || (colOffsetATw + 10 > 299)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw + 10, 1, 299, &h_emlrtBCI,
                                        &st);
        }
        obj->ATwset[colOffsetATw + 9] = 0.0;
        if ((colOffsetATw + 11 < 1) || (colOffsetATw + 11 > 299)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw + 11, 1, 299, &h_emlrtBCI,
                                        &st);
        }
        obj->ATwset[colOffsetATw + 10] = 0.0;
        if ((colOffsetATw + 12 < 1) || (colOffsetATw + 12 > 299)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw + 12, 1, 299, &h_emlrtBCI,
                                        &st);
        }
        obj->ATwset[colOffsetATw + 11] = 0.0;
      }
    }
  }
  for (i = 0; i < 6; i++) {
    obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
  }
  obj->probType = 2;
}

void setProblemType(const emlrtStack *sp, f_struct_T *obj, int32_T PROBLEM_TYPE)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T colOffsetAeq;
  int32_T i;
  int32_T idx_col;
  int32_T idx_row;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  switch (PROBLEM_TYPE) {
  case 3: {
    obj->nVar = 8;
    obj->mConstr = 18;
    if (obj->nWConstr[4] > 0) {
      int32_T idxUpperExisting;
      idxUpperExisting = obj->isActiveIdx[4] - 2;
      st.site = &k_emlrtRSI;
      for (colOffsetAeq = 0; colOffsetAeq < 8; colOffsetAeq++) {
        i = (idxUpperExisting + colOffsetAeq) + 1;
        obj->isActiveConstr[colOffsetAeq + 10] = obj->isActiveConstr[i];
        obj->isActiveConstr[i] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj->nVar = 9;
    obj->mConstr = 19;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesPhaseOne[i];
    }
    st.site = &k_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    obj->nVar = 12;
    obj->mConstr = 22;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }
    if (obj->probType != 4) {
      int32_T b;
      int32_T idxUpperExisting;
      st.site = &k_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      for (idx_col = 0; idx_col < 2; idx_col++) {
        idxUpperExisting = idx_col + 10;
        colOffsetAeq = 13 * idx_col;
        b_st.site = &m_emlrtRSI;
        i = idx_col + 8;
        b_st.site = &m_emlrtRSI;
        for (idx_row = 9; idx_row <= i; idx_row++) {
          obj->Aeq[colOffsetAeq + 8] = 0.0;
          obj->ATwset[colOffsetAeq + 8] = 0.0;
        }
        i = idx_col + colOffsetAeq;
        obj->Aeq[i + 8] = -1.0;
        obj->ATwset[i + 8] = -1.0;
        b_st.site = &m_emlrtRSI;
        for (idx_row = idxUpperExisting; idx_row < 11; idx_row++) {
          obj->Aeq[colOffsetAeq + 9] = 0.0;
          obj->ATwset[colOffsetAeq + 9] = 0.0;
        }
        b_st.site = &m_emlrtRSI;
        for (idx_row = 11; idx_row <= idxUpperExisting; idx_row++) {
          obj->Aeq[colOffsetAeq + 10] = 0.0;
          obj->ATwset[colOffsetAeq + 10] = 0.0;
        }
        obj->Aeq[i + 10] = 1.0;
        obj->ATwset[i + 10] = 1.0;
        i = idx_col + 12;
        b_st.site = &m_emlrtRSI;
        for (idx_row = i; idx_row < 13; idx_row++) {
          obj->Aeq[colOffsetAeq + 11] = 0.0;
          obj->ATwset[colOffsetAeq + 11] = 0.0;
        }
      }
      b_st.site = &m_emlrtRSI;
      obj->indexLB[8] = 9;
      obj->indexLB[9] = 10;
      obj->indexLB[10] = 11;
      obj->indexLB[11] = 12;
      if (obj->nWConstr[4] > 0) {
        b_st.site = &m_emlrtRSI;
        for (colOffsetAeq = 0; colOffsetAeq < 8; colOffsetAeq++) {
          obj->isActiveConstr[colOffsetAeq + 15] =
              obj->isActiveConstr[(obj->isActiveIdx[4] + colOffsetAeq) - 1];
        }
      }
      i = obj->isActiveIdx[4];
      b_st.site = &m_emlrtRSI;
      for (colOffsetAeq = i; colOffsetAeq < 15; colOffsetAeq++) {
        obj->isActiveConstr[colOffsetAeq - 1] = false;
      }
      b_st.site = &m_emlrtRSI;
      obj->lb[8] = 0.0;
      obj->lb[9] = 0.0;
      obj->lb[10] = 0.0;
      obj->lb[11] = 0.0;
      b = obj->nActiveConstr;
      b_st.site = &m_emlrtRSI;
      if (obj->nActiveConstr > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_col = 3; idx_col <= b; idx_col++) {
        int32_T colOffsetATw;
        colOffsetATw = 13 * (idx_col - 1);
        if (idx_col > 23) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 23, &i_emlrtBCI, &st);
        }
        if (obj->Wid[idx_col - 1] == 3) {
          idxUpperExisting = obj->Wlocalidx[idx_col - 1];
          colOffsetAeq = idxUpperExisting + 7;
          b_st.site = &m_emlrtRSI;
          if (idxUpperExisting + 7 > 2147483646) {
            c_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (idx_row = 9; idx_row <= colOffsetAeq; idx_row++) {
            i = idx_row + colOffsetATw;
            if ((i < 1) || (i > 299)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 299, &h_emlrtBCI, &st);
            }
            obj->ATwset[i - 1] = 0.0;
          }
          i = (idxUpperExisting + colOffsetATw) + 8;
          if ((i < 1) || (i > 299)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 299, &h_emlrtBCI, &st);
          }
          obj->ATwset[i - 1] = -1.0;
          i = idxUpperExisting + 9;
          b_st.site = &m_emlrtRSI;
          for (idx_row = i; idx_row < 13; idx_row++) {
            idxUpperExisting = idx_row + colOffsetATw;
            if ((idxUpperExisting < 1) || (idxUpperExisting > 299)) {
              emlrtDynamicBoundsCheckR2012b(idxUpperExisting, 1, 299,
                                            &h_emlrtBCI, &st);
            }
            obj->ATwset[idxUpperExisting - 1] = 0.0;
          }
        } else {
          b_st.site = &m_emlrtRSI;
          if ((colOffsetATw + 9 < 1) || (colOffsetATw + 9 > 299)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 9, 1, 299, &h_emlrtBCI,
                                          &st);
          }
          obj->ATwset[colOffsetATw + 8] = 0.0;
          if ((colOffsetATw + 10 < 1) || (colOffsetATw + 10 > 299)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 10, 1, 299,
                                          &h_emlrtBCI, &st);
          }
          obj->ATwset[colOffsetATw + 9] = 0.0;
          if ((colOffsetATw + 11 < 1) || (colOffsetATw + 11 > 299)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 11, 1, 299,
                                          &h_emlrtBCI, &st);
          }
          obj->ATwset[colOffsetATw + 10] = 0.0;
          if ((colOffsetATw + 12 < 1) || (colOffsetATw + 12 > 299)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 12, 1, 299,
                                          &h_emlrtBCI, &st);
          }
          obj->ATwset[colOffsetATw + 11] = 0.0;
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj->nVar = 13;
    obj->mConstr = 23;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }
    st.site = &k_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj->probType = PROBLEM_TYPE;
}

/* End of code generation (setProblemType.c) */
