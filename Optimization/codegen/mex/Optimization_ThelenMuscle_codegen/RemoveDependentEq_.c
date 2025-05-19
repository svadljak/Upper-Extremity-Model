/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RemoveDependentEq_.c
 *
 * Code generation for function 'RemoveDependentEq_'
 *
 */

/* Include files */
#include "RemoveDependentEq_.h"
#include "ComputeNumDependentEq_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = {
    1,                    /* lineNo */
    "RemoveDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    1,                     /* lineNo */
    "IndexOfDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    1,                /* lineNo */
    "removeEqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p" /* pathName */
};

static emlrtBCInfo jb_emlrtBCI = {
    1,                    /* iFirst */
    23,                   /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    1,                     /* iFirst */
    23,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p", /* pName */
    3                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    1,                /* iFirst */
    6,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    1,                    /* iFirst */
    299,                  /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    1,                    /* iFirst */
    529,                  /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    1,                     /* iFirst */
    23,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    1,                /* iFirst */
    23,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    1,                /* iFirst */
    2,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    1,                /* iFirst */
    23,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    1,                /* iFirst */
    5,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
int32_T RemoveDependentEq_(const emlrtStack *sp, c_struct_T *memspace,
                           f_struct_T *workingset, h_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idxFill;
  int32_T idxW;
  int32_T idx_col;
  int32_T idx_row;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVar = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    int32_T i;
    boolean_T overflow;
    st.site = &pc_emlrtRSI;
    if (mTotalWorkingEq_tmp > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    overflow = (nVar > 2147483646);
    idxW = (uint8_T)nVar;
    for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
      st.site = &pc_emlrtRSI;
      if (overflow) {
        b_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx_col = 0; idx_col < idxW; idx_col++) {
        idxFill = (idx_col + 13 * idx_row) + 1;
        if ((idxFill < 1) || (idxFill > 299)) {
          emlrtDynamicBoundsCheckR2012b(idxFill, 1, 299, &nb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        i = (idx_row + 23 * idx_col) + 1;
        if ((i < 1) || (i > 529)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 529, &ob_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        qrmanager->QR[i - 1] = workingset->ATwset[idxFill - 1];
      }
    }
    st.site = &pc_emlrtRSI;
    nDepInd = ComputeNumDependentEq_(&st, qrmanager, workingset->bwset,
                                     mTotalWorkingEq_tmp, workingset->nVar);
    if (nDepInd > 0) {
      st.site = &pc_emlrtRSI;
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
        st.site = &pc_emlrtRSI;
        c_xcopy(&st, nVar, workingset->ATwset, 13 * idx_col + 1, qrmanager->QR,
                23 * idx_col + 1);
      }
      st.site = &pc_emlrtRSI;
      b_st.site = &uc_emlrtRSI;
      if (workingset->nWConstr[0] > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_row = 0; idx_row < mWorkingFixed; idx_row++) {
        if ((idx_row + 1 < 1) || (idx_row + 1 > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 23, &kb_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx_row] = 1;
      }
      nVar = workingset->nWConstr[0] + 1;
      b_st.site = &uc_emlrtRSI;
      for (idx_row = nVar; idx_row <= mTotalWorkingEq_tmp; idx_row++) {
        if ((idx_row < 1) || (idx_row > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &kb_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx_row - 1] = 0;
      }
      b_st.site = &uc_emlrtRSI;
      if (workingset->nVar * mTotalWorkingEq_tmp == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol =
            muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq_tmp);
        c_st.site = &db_emlrtRSI;
        xgeqp3(&c_st, qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
               qrmanager->jpvt, qrmanager->tau);
      }
      b_st.site = &uc_emlrtRSI;
      if (nDepInd > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_row = 0; idx_row < nDepInd; idx_row++) {
        idxW = ((mTotalWorkingEq_tmp - nDepInd) + idx_row) + 1;
        if ((idxW < 1) || (idxW > 23)) {
          emlrtDynamicBoundsCheckR2012b(idxW, 1, 23, &pb_emlrtBCI, &st);
        }
        if (idx_row + 1 > 23) {
          emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 23, &kb_emlrtBCI, &st);
        }
        memspace->workspace_int[idx_row] = qrmanager->jpvt[idxW - 1];
      }
      st.site = &pc_emlrtRSI;
      if ((nDepInd > 1) && (mTotalWorkingEq_tmp > 1)) {
        b_st.site = &vc_emlrtRSI;
        for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
          if (idx_row + 1 > 23) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 23, &lb_emlrtBCI,
                                          &st);
          }
          memspace->workspace_sort[idx_row] = 0;
        }
        b_st.site = &vc_emlrtRSI;
        for (idx_row = 0; idx_row < nDepInd; idx_row++) {
          if (idx_row + 1 > 23) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 23, &qb_emlrtBCI,
                                          &st);
          }
          idxW = memspace->workspace_int[idx_row];
          if ((idxW < 1) || (idxW > 23)) {
            emlrtDynamicBoundsCheckR2012b(idxW, 1, 23, &qb_emlrtBCI, &st);
          }
          if (idx_row + 1 > 23) {
            emlrtDynamicBoundsCheckR2012b(idx_row + 1, 1, 23, &qb_emlrtBCI,
                                          &st);
          }
          idxFill = memspace->workspace_int[idx_row];
          if ((idxFill < 1) || (idxFill > 23)) {
            emlrtDynamicBoundsCheckR2012b(idxFill, 1, 23, &lb_emlrtBCI, &st);
          }
          memspace->workspace_sort[idxFill - 1] =
              memspace->workspace_sort[idxW - 1] + 1;
        }
        b_st.site = &vc_emlrtRSI;
        for (idx_row = 2; idx_row <= mTotalWorkingEq_tmp; idx_row++) {
          if (idx_row > 23) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &lb_emlrtBCI, &st);
          }
          memspace->workspace_sort[idx_row - 1] +=
              memspace->workspace_sort[idx_row - 2];
        }
        nVar = 1;
        mWorkingFixed = memspace->workspace_sort[0];
        b_st.site = &vc_emlrtRSI;
        for (idxW = 0; idxW <= mTotalWorkingEq_tmp - 2; idxW++) {
          b_st.site = &vc_emlrtRSI;
          if ((nVar <= mWorkingFixed) && (mWorkingFixed > 2147483646)) {
            c_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (idxFill = nVar; idxFill <= mWorkingFixed; idxFill++) {
            if ((idxFill < 1) || (idxFill > 23)) {
              emlrtDynamicBoundsCheckR2012b(idxFill, 1, 23, &lb_emlrtBCI, &st);
            }
            memspace->workspace_int[idxFill - 1] = idxW + 1;
          }
          if (idxW + 1 > 23) {
            emlrtDynamicBoundsCheckR2012b(idxW + 1, 1, 23, &qb_emlrtBCI, &st);
          }
          nVar = memspace->workspace_sort[idxW] + 1;
          if (idxW + 2 > 23) {
            emlrtDynamicBoundsCheckR2012b(idxW + 2, 1, 23, &qb_emlrtBCI, &st);
          }
          mWorkingFixed = memspace->workspace_sort[idxW + 1];
        }
        b_st.site = &vc_emlrtRSI;
        if ((nVar <= mWorkingFixed) && (mWorkingFixed > 2147483646)) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx_row = nVar; idx_row <= mWorkingFixed; idx_row++) {
          if ((idx_row < 1) || (idx_row > 23)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &lb_emlrtBCI, &st);
          }
          memspace->workspace_int[idx_row - 1] = mTotalWorkingEq_tmp;
        }
      }
      for (idx_row = nDepInd; idx_row >= 1; idx_row--) {
        st.site = &pc_emlrtRSI;
        if (idx_row > 23) {
          emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &jb_emlrtBCI, &st);
        }
        idxW = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (idxW != 0) {
          idxFill = memspace->workspace_int[idx_row - 1];
          if (idxFill <= idxW) {
            if ((workingset->nActiveConstr == idxW) || (idxFill == idxW)) {
              workingset->mEqRemoved++;
              if ((idxFill < 1) || (idxFill > 23)) {
                emlrtDynamicBoundsCheckR2012b(idxFill, 1, 23, &rb_emlrtBCI,
                                              &st);
              }
              if ((workingset->mEqRemoved < 1) ||
                  (workingset->mEqRemoved > 2)) {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 2,
                                              &sb_emlrtBCI, &st);
              }
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                  workingset->Wlocalidx[idxFill - 1];
              b_st.site = &wc_emlrtRSI;
              nVar = workingset->Wid[idxFill - 1];
              if ((nVar < 1) || (nVar > 6)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 6, &t_emlrtBCI, &b_st);
              }
              idxW =
                  (workingset->isActiveIdx[workingset->Wid[idxFill - 1] - 1] +
                   workingset->Wlocalidx[idxFill - 1]) -
                  1;
              if ((idxW < 1) || (idxW > 23)) {
                emlrtDynamicBoundsCheckR2012b(idxW, 1, 23, &bb_emlrtBCI, &b_st);
              }
              workingset->isActiveConstr[idxW - 1] = false;
              if (idxFill < workingset->nActiveConstr) {
                c_st.site = &xc_emlrtRSI;
                moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                                idxFill);
              }
              workingset->nActiveConstr--;
              if ((nVar < 1) || (nVar > 5)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 5, &cb_emlrtBCI, &b_st);
              }
              workingset->nWConstr[nVar - 1]--;
            } else {
              workingset->mEqRemoved++;
              if ((idxFill < 1) || (idxFill > 23)) {
                emlrtDynamicBoundsCheckR2012b(idxFill, 1, 23, &rb_emlrtBCI,
                                              &st);
              }
              nVar = workingset->Wid[idxFill - 1];
              if ((workingset->mEqRemoved < 1) ||
                  (workingset->mEqRemoved > 2)) {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 2,
                                              &sb_emlrtBCI, &st);
              }
              i = workingset->Wlocalidx[idxFill - 1];
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] = i;
              if ((nVar < 1) || (nVar > 6)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 6, &mb_emlrtBCI, &st);
              }
              i = (workingset->isActiveIdx[nVar - 1] + i) - 1;
              if ((i < 1) || (i > 23)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, 23, &tb_emlrtBCI, &st);
              }
              workingset->isActiveConstr[i - 1] = false;
              b_st.site = &wc_emlrtRSI;
              moveConstraint_(&b_st, workingset, idxW, idxFill);
              b_st.site = &wc_emlrtRSI;
              moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                              idxW);
              workingset->nActiveConstr--;
              if ((nVar < 1) || (nVar > 5)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 5, &ub_emlrtBCI, &st);
              }
              workingset->nWConstr[nVar - 1]--;
            }
          }
        }
      }
    }
  }
  return nDepInd;
}

/* End of code generation (RemoveDependentEq_.c) */
