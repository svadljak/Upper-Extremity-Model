/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "RemoveDependentEq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = {
    1,                    /* lineNo */
    "PresolveWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\PresolveWorkingSet.p" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    1,                      /* lineNo */
    "RemoveDependentIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p" /* pathName */
};

static emlrtBCInfo gb_emlrtBCI = {
    1,                      /* iFirst */
    23,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    3                                     /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    1,                      /* iFirst */
    529,                    /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    1,                      /* iFirst */
    23,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
void PresolveWorkingSet(const emlrtStack *sp, d_struct_T *solution,
                        c_struct_T *memspace, f_struct_T *workingset,
                        h_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T a;
  int32_T idx;
  int32_T nActiveConstr;
  int32_T nFixedConstr_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->state = 82;
  st.site = &oc_emlrtRSI;
  nFixedConstr_tmp = RemoveDependentEq_(&st, memspace, workingset, qrmanager);
  if ((nFixedConstr_tmp != -1) && (workingset->nActiveConstr <= 23)) {
    real_T maxDiag;
    real_T tol;
    int32_T nDepIneq;
    int32_T nVar_tmp;
    boolean_T exitg1;
    boolean_T guard1;
    boolean_T okWorkingSet;
    st.site = &oc_emlrtRSI;
    nActiveConstr = workingset->nActiveConstr;
    nFixedConstr_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    nVar_tmp = workingset->nVar;
    if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
            workingset->nWConstr[4] >
        0) {
      tol = muDoubleScalarMin(
          1.4901161193847656E-8,
          2.2204460492503131E-15 *
              (real_T)muIntScalarMax_sint32(workingset->nVar,
                                            workingset->nActiveConstr));
      b_st.site = &ad_emlrtRSI;
      if (nFixedConstr_tmp > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx = 0; idx < nFixedConstr_tmp; idx++) {
        if ((idx + 1 < 1) || (idx + 1 > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &gb_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx] = 1;
      }
      a = nFixedConstr_tmp + 1;
      b_st.site = &ad_emlrtRSI;
      if ((nFixedConstr_tmp + 1 <= workingset->nActiveConstr) &&
          (workingset->nActiveConstr > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx = a; idx <= nActiveConstr; idx++) {
        if ((idx < 1) || (idx > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &gb_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx - 1] = 0;
      }
      b_st.site = &ad_emlrtRSI;
      if (workingset->nActiveConstr > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (a = 0; a < nActiveConstr; a++) {
        b_st.site = &ad_emlrtRSI;
        c_xcopy(&b_st, nVar_tmp, workingset->ATwset, 13 * a + 1, qrmanager->QR,
                23 * a + 1);
      }
      b_st.site = &ad_emlrtRSI;
      if (workingset->nVar * workingset->nActiveConstr == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol =
            muIntScalarMin_sint32(workingset->nVar, workingset->nActiveConstr);
        c_st.site = &db_emlrtRSI;
        xgeqp3(&c_st, qrmanager->QR, workingset->nVar,
               workingset->nActiveConstr, qrmanager->jpvt, qrmanager->tau);
      }
      nDepIneq = 0;
      for (idx = workingset->nActiveConstr; idx > nVar_tmp; idx--) {
        nDepIneq++;
        if ((idx < 1) || (idx > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &ib_emlrtBCI, &st);
        }
        if (nDepIneq > 23) {
          emlrtDynamicBoundsCheckR2012b(24, 1, 23, &gb_emlrtBCI, &st);
        }
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
      }
      maxDiag = muDoubleScalarAbs(qrmanager->QR[0]);
      b_st.site = &ad_emlrtRSI;
      if (idx - 1 > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (nActiveConstr = 0; nActiveConstr <= idx - 2; nActiveConstr++) {
        maxDiag = muDoubleScalarMax(
            maxDiag,
            muDoubleScalarAbs(
                qrmanager->QR[(23 * (nActiveConstr + 1) + nActiveConstr) + 1]));
      }
      if (idx <= workingset->nVar) {
        nActiveConstr = idx + 23 * (idx - 1);
        exitg1 = false;
        while ((!exitg1) && (idx > nFixedConstr_tmp)) {
          if ((nActiveConstr < 1) || (nActiveConstr > 529)) {
            emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 529, &hb_emlrtBCI,
                                          &st);
          }
          if (muDoubleScalarAbs(qrmanager->QR[nActiveConstr - 1]) <
              tol * maxDiag) {
            nDepIneq++;
            if ((idx < 1) || (idx > 23)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &ib_emlrtBCI, &st);
            }
            if (nDepIneq > 23) {
              emlrtDynamicBoundsCheckR2012b(24, 1, 23, &gb_emlrtBCI, &st);
            }
            memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
            idx--;
            nActiveConstr -= 24;
          } else {
            exitg1 = true;
          }
        }
      }
      b_st.site = &ad_emlrtRSI;
      countsort(&b_st, memspace->workspace_int, nDepIneq,
                memspace->workspace_sort, nFixedConstr_tmp + 1,
                workingset->nActiveConstr);
      for (idx = nDepIneq; idx >= 1; idx--) {
        b_st.site = &ad_emlrtRSI;
        nFixedConstr_tmp = memspace->workspace_int[idx - 1];
        if ((nFixedConstr_tmp < 1) || (nFixedConstr_tmp > 23)) {
          emlrtDynamicBoundsCheckR2012b(nFixedConstr_tmp, 1, 23, &ab_emlrtBCI,
                                        &b_st);
        }
        nActiveConstr = workingset->Wid[nFixedConstr_tmp - 1];
        if ((nActiveConstr < 1) || (nActiveConstr > 6)) {
          emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 6, &t_emlrtBCI,
                                        &b_st);
        }
        a = (workingset->isActiveIdx[nActiveConstr - 1] +
             workingset->Wlocalidx[nFixedConstr_tmp - 1]) -
            1;
        if ((a < 1) || (a > 23)) {
          emlrtDynamicBoundsCheckR2012b(a, 1, 23, &bb_emlrtBCI, &b_st);
        }
        workingset->isActiveConstr[a - 1] = false;
        if (nFixedConstr_tmp < workingset->nActiveConstr) {
          c_st.site = &xc_emlrtRSI;
          moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                          nFixedConstr_tmp);
        }
        workingset->nActiveConstr--;
        if ((nActiveConstr < 1) || (nActiveConstr > 5)) {
          emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 5, &cb_emlrtBCI,
                                        &b_st);
        }
        workingset->nWConstr[nActiveConstr - 1]--;
      }
    }
    st.site = &oc_emlrtRSI;
    okWorkingSet = feasibleX0ForWorkingSet(
        &st, memspace->workspace_float, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      st.site = &oc_emlrtRSI;
      nActiveConstr = workingset->nActiveConstr;
      nFixedConstr_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
      if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
              workingset->nWConstr[4] >
          0) {
        tol = 10.0 * muDoubleScalarMin(
                         1.4901161193847656E-8,
                         2.2204460492503131E-15 *
                             (real_T)muIntScalarMax_sint32(
                                 workingset->nVar, workingset->nActiveConstr));
        b_st.site = &ad_emlrtRSI;
        if (nFixedConstr_tmp > 2147483646) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx = 0; idx < nFixedConstr_tmp; idx++) {
          if ((idx + 1 < 1) || (idx + 1 > 23)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &gb_emlrtBCI, &st);
          }
          qrmanager->jpvt[idx] = 1;
        }
        a = nFixedConstr_tmp + 1;
        b_st.site = &ad_emlrtRSI;
        if ((nFixedConstr_tmp + 1 <= workingset->nActiveConstr) &&
            (workingset->nActiveConstr > 2147483646)) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx = a; idx <= nActiveConstr; idx++) {
          if ((idx < 1) || (idx > 23)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &gb_emlrtBCI, &st);
          }
          qrmanager->jpvt[idx - 1] = 0;
        }
        b_st.site = &ad_emlrtRSI;
        if (workingset->nActiveConstr > 2147483646) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (a = 0; a < nActiveConstr; a++) {
          b_st.site = &ad_emlrtRSI;
          c_xcopy(&b_st, nVar_tmp, workingset->ATwset, 13 * a + 1,
                  qrmanager->QR, 23 * a + 1);
        }
        b_st.site = &ad_emlrtRSI;
        if (workingset->nVar * workingset->nActiveConstr == 0) {
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = 0;
        } else {
          qrmanager->usedPivoting = true;
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = muIntScalarMin_sint32(
              workingset->nVar, workingset->nActiveConstr);
          c_st.site = &db_emlrtRSI;
          xgeqp3(&c_st, qrmanager->QR, workingset->nVar,
                 workingset->nActiveConstr, qrmanager->jpvt, qrmanager->tau);
        }
        nDepIneq = 0;
        for (idx = workingset->nActiveConstr; idx > nVar_tmp; idx--) {
          nDepIneq++;
          if ((idx < 1) || (idx > 23)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &ib_emlrtBCI, &st);
          }
          if (nDepIneq > 23) {
            emlrtDynamicBoundsCheckR2012b(24, 1, 23, &gb_emlrtBCI, &st);
          }
          memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
        }
        maxDiag = muDoubleScalarAbs(qrmanager->QR[0]);
        b_st.site = &ad_emlrtRSI;
        if (idx - 1 > 2147483646) {
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (nActiveConstr = 0; nActiveConstr <= idx - 2; nActiveConstr++) {
          maxDiag = muDoubleScalarMax(
              maxDiag,
              muDoubleScalarAbs(
                  qrmanager
                      ->QR[(23 * (nActiveConstr + 1) + nActiveConstr) + 1]));
        }
        if (idx <= workingset->nVar) {
          nActiveConstr = idx + 23 * (idx - 1);
          exitg1 = false;
          while ((!exitg1) && (idx > nFixedConstr_tmp)) {
            if ((nActiveConstr < 1) || (nActiveConstr > 529)) {
              emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 529, &hb_emlrtBCI,
                                            &st);
            }
            if (muDoubleScalarAbs(qrmanager->QR[nActiveConstr - 1]) <
                tol * maxDiag) {
              nDepIneq++;
              if ((idx < 1) || (idx > 23)) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &ib_emlrtBCI, &st);
              }
              if (nDepIneq > 23) {
                emlrtDynamicBoundsCheckR2012b(24, 1, 23, &gb_emlrtBCI, &st);
              }
              memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
              idx--;
              nActiveConstr -= 24;
            } else {
              exitg1 = true;
            }
          }
        }
        b_st.site = &ad_emlrtRSI;
        countsort(&b_st, memspace->workspace_int, nDepIneq,
                  memspace->workspace_sort, nFixedConstr_tmp + 1,
                  workingset->nActiveConstr);
        for (idx = nDepIneq; idx >= 1; idx--) {
          b_st.site = &ad_emlrtRSI;
          nFixedConstr_tmp = memspace->workspace_int[idx - 1];
          if ((nFixedConstr_tmp < 1) || (nFixedConstr_tmp > 23)) {
            emlrtDynamicBoundsCheckR2012b(nFixedConstr_tmp, 1, 23, &ab_emlrtBCI,
                                          &b_st);
          }
          nActiveConstr = workingset->Wid[nFixedConstr_tmp - 1];
          if ((nActiveConstr < 1) || (nActiveConstr > 6)) {
            emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 6, &t_emlrtBCI,
                                          &b_st);
          }
          a = (workingset->isActiveIdx[nActiveConstr - 1] +
               workingset->Wlocalidx[nFixedConstr_tmp - 1]) -
              1;
          if ((a < 1) || (a > 23)) {
            emlrtDynamicBoundsCheckR2012b(a, 1, 23, &bb_emlrtBCI, &b_st);
          }
          workingset->isActiveConstr[a - 1] = false;
          if (nFixedConstr_tmp < workingset->nActiveConstr) {
            c_st.site = &xc_emlrtRSI;
            moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                            nFixedConstr_tmp);
          }
          workingset->nActiveConstr--;
          if ((nActiveConstr < 1) || (nActiveConstr > 5)) {
            emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 5, &cb_emlrtBCI,
                                          &b_st);
          }
          workingset->nWConstr[nActiveConstr - 1]--;
        }
      }
      st.site = &oc_emlrtRSI;
      okWorkingSet =
          feasibleX0ForWorkingSet(&st, memspace->workspace_float,
                                  solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      st.site = &oc_emlrtRSI;
      tol = c_maxConstraintViolation(&st, workingset, solution->xstar);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    st.site = &oc_emlrtRSI;
    removeAllIneqConstr(&st, workingset);
  }
}

/* End of code generation (PresolveWorkingSet.c) */
