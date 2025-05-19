/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: PresolveWorkingSet.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "PresolveWorkingSet.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "RemoveDependentIneq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : c_struct_T *solution
 *                b_struct_T *memspace
 *                e_struct_T *workingset
 *                g_struct_T *qrmanager
 * Return Type  : void
 */
void PresolveWorkingSet(c_struct_T *solution, b_struct_T *memspace,
                        e_struct_T *workingset, g_struct_T *qrmanager)
{
  double tol;
  int idxDiag;
  int idx_col;
  int ix;
  int ix0;
  int k;
  int mTotalWorkingEq_tmp;
  int mWorkingFixed;
  int nDepInd;
  solution->state = 82;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    int i;
    int i1;
    int u0;
    i = (unsigned char)workingset->nVar;
    for (ix = 0; ix < mTotalWorkingEq_tmp; ix++) {
      for (idx_col = 0; idx_col < i; idx_col++) {
        qrmanager->QR[ix + 23 * idx_col] =
            workingset->ATwset[idx_col + 13 * ix];
      }
    }
    nDepInd = mTotalWorkingEq_tmp - workingset->nVar;
    if (nDepInd <= 0) {
      nDepInd = 0;
    }
    memset(&qrmanager->jpvt[0], 0, (unsigned int)i * sizeof(int));
    i1 = mTotalWorkingEq_tmp * workingset->nVar;
    if (i1 == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      idxDiag = workingset->nVar;
      if (mTotalWorkingEq_tmp <= idxDiag) {
        idxDiag = mTotalWorkingEq_tmp;
      }
      qrmanager->minRowCol = idxDiag;
      xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }
    idxDiag = workingset->nVar;
    if (mTotalWorkingEq_tmp >= idxDiag) {
      idxDiag = mTotalWorkingEq_tmp;
    }
    tol = fmin(1.4901161193847656E-8, 2.2204460492503131E-15 * (double)idxDiag);
    u0 = workingset->nVar;
    if (u0 > mTotalWorkingEq_tmp) {
      u0 = mTotalWorkingEq_tmp;
    }
    idxDiag = u0 + 23 * (u0 - 1);
    while ((idxDiag > 0) &&
           (fabs(qrmanager->QR[idxDiag - 1]) < tol * fabs(qrmanager->QR[0]))) {
      idxDiag -= 24;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      computeQ_(qrmanager, qrmanager->mrows);
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        double qtb;
        ix = 23 * ((mTotalWorkingEq_tmp - idx_col) - 1);
        qtb = 0.0;
        for (k = 0; k < mTotalWorkingEq_tmp; k++) {
          qtb += qrmanager->Q[ix + k] * workingset->bwset[k];
        }
        if (fabs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx_col++;
        }
      }
    }
    if (nDepInd > 0) {
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
        idxDiag = 23 * idx_col;
        ix0 = 13 * idx_col;
        for (k = 0; k < i; k++) {
          qrmanager->QR[idxDiag + k] = workingset->ATwset[ix0 + k];
        }
      }
      for (idx_col = 0; idx_col < mWorkingFixed; idx_col++) {
        qrmanager->jpvt[idx_col] = 1;
      }
      ix0 = workingset->nWConstr[0] + 1;
      if (ix0 <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt[ix0 + -1], 0,
               (unsigned int)((mTotalWorkingEq_tmp - ix0) + 1) * sizeof(int));
      }
      if (i1 == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = u0;
        xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
               qrmanager->jpvt, qrmanager->tau);
      }
      for (idx_col = 0; idx_col < nDepInd; idx_col++) {
        memspace->workspace_int[idx_col] =
            qrmanager->jpvt[(mTotalWorkingEq_tmp - nDepInd) + idx_col];
      }
      countsort(memspace->workspace_int, nDepInd, memspace->workspace_sort, 1,
                mTotalWorkingEq_tmp);
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        i1 = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (i1 != 0) {
          ix0 = memspace->workspace_int[idx_col - 1];
          if (ix0 <= i1) {
            if ((workingset->nActiveConstr == i1) || (ix0 == i1)) {
              workingset->mEqRemoved++;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                  workingset->Wlocalidx[ix0 - 1];
              removeConstr(workingset, ix0);
            } else {
              workingset->mEqRemoved++;
              idxDiag = workingset->Wid[ix0 - 1] - 1;
              ix = workingset->Wlocalidx[ix0 - 1];
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] = ix;
              workingset
                  ->isActiveConstr[(workingset->isActiveIdx[idxDiag] + ix) -
                                   2] = false;
              workingset->Wid[ix0 - 1] = workingset->Wid[i1 - 1];
              workingset->Wlocalidx[ix0 - 1] = workingset->Wlocalidx[i1 - 1];
              for (ix = 0; ix < i; ix++) {
                workingset->ATwset[ix + 13 * (ix0 - 1)] =
                    workingset->ATwset[ix + 13 * (i1 - 1)];
              }
              workingset->bwset[ix0 - 1] = workingset->bwset[i1 - 1];
              ix0 = workingset->nActiveConstr - 1;
              workingset->Wid[i1 - 1] = workingset->Wid[ix0];
              workingset->Wlocalidx[i1 - 1] = workingset->Wlocalidx[ix0];
              for (ix = 0; ix < i; ix++) {
                workingset->ATwset[ix + 13 * (i1 - 1)] =
                    workingset->ATwset[ix + 13 * ix0];
              }
              workingset->bwset[i1 - 1] = workingset->bwset[ix0];
              workingset->nActiveConstr = ix0;
              workingset->nWConstr[idxDiag]--;
            }
          }
        }
      }
    }
  }
  if ((nDepInd != -1) && (workingset->nActiveConstr <= 23)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace->workspace_float, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace->workspace_float, solution->xstar, workingset, qrmanager);
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
      tol = maxConstraintViolation(workingset, solution->xstar);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    idxDiag = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
    ix = workingset->nActiveConstr;
    for (ix0 = idxDiag; ix0 <= ix; ix0++) {
      workingset->isActiveConstr
          [(workingset->isActiveIdx[workingset->Wid[ix0 - 1] - 1] +
            workingset->Wlocalidx[ix0 - 1]) -
           2] = false;
    }
    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr =
        workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

/*
 * File trailer for PresolveWorkingSet.c
 *
 * [EOF]
 */
