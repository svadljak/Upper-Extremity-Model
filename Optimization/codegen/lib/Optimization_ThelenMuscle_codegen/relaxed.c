/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: relaxed.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "relaxed.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double Hessian[64]
 *                const double grad[13]
 *                c_struct_T *TrialState
 *                f_struct_T *MeritFunction
 *                b_struct_T *memspace
 *                e_struct_T *WorkingSet
 *                g_struct_T *QRManager
 *                h_struct_T *CholManager
 *                i_struct_T *QPObjective
 *                k_struct_T *qpoptions
 * Return Type  : void
 */
void relaxed(const double Hessian[64], const double grad[13],
             c_struct_T *TrialState, f_struct_T *MeritFunction,
             b_struct_T *memspace, e_struct_T *WorkingSet,
             g_struct_T *QRManager, h_struct_T *CholManager,
             i_struct_T *QPObjective, k_struct_T *qpoptions)
{
  double beta;
  double rho;
  double s;
  double smax;
  int i;
  int ia;
  int idx;
  int idx_max;
  int mLBOrig;
  int nVarOrig;
  boolean_T b_tf;
  boolean_T tf;
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  i = (unsigned char)WorkingSet->nVar;
  for (idx = 0; idx < i; idx++) {
    beta += Hessian[idx + (idx << 3)];
  }
  beta /= (double)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    mLBOrig = QPObjective->nvar;
    if (QPObjective->nvar < 1) {
      idx_max = 0;
    } else {
      idx_max = 1;
      if (QPObjective->nvar > 1) {
        smax = fabs(grad[0]);
        for (idx = 2; idx <= mLBOrig; idx++) {
          s = fabs(grad[idx - 1]);
          if (s > smax) {
            idx_max = idx;
            smax = s;
          }
        }
      }
    }
    rho = 100.0 * fmax(1.0, fabs(grad[idx_max - 1]));
  } else {
    mLBOrig = WorkingSet->mConstr;
    idx_max = 1;
    smax = fabs(TrialState->lambdasqp[0]);
    for (idx = 2; idx <= mLBOrig; idx++) {
      s = fabs(TrialState->lambdasqp[idx - 1]);
      if (s > smax) {
        idx_max = idx;
        smax = s;
      }
    }
    rho = fabs(TrialState->lambdasqp[idx_max - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  setProblemType(WorkingSet, 2);
  mLBOrig = WorkingSet->sizes[3] - 3;
  memspace->workspace_float[0] = WorkingSet->beq[0];
  memspace->workspace_float[1] = WorkingSet->beq[1];
  memspace->workspace_float[0] = -memspace->workspace_float[0];
  memspace->workspace_float[1] = -memspace->workspace_float[1];
  for (idx_max = 0; idx_max <= 13; idx_max += 13) {
    smax = 0.0;
    i = idx_max + nVarOrig;
    for (ia = idx_max + 1; ia <= i; ia++) {
      smax += WorkingSet->Aeq[ia - 1] * TrialState->xstar[(ia - idx_max) - 1];
    }
    i = div_nde_s32_floor(idx_max, 13);
    memspace->workspace_float[i] += smax;
  }
  if (memspace->workspace_float[0] <= 0.0) {
    TrialState->xstar[nVarOrig] = 0.0;
    TrialState->xstar[nVarOrig + 2] = -memspace->workspace_float[0];
    addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig);
    if (memspace->workspace_float[0] >= -1.0E-6) {
      addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 2);
    }
  } else {
    TrialState->xstar[nVarOrig] = memspace->workspace_float[0];
    TrialState->xstar[nVarOrig + 2] = 0.0;
    addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 2);
    if (memspace->workspace_float[0] <= 1.0E-6) {
      addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig);
    }
  }
  if (memspace->workspace_float[1] <= 0.0) {
    TrialState->xstar[nVarOrig + 1] = 0.0;
    TrialState->xstar[nVarOrig + 3] = -memspace->workspace_float[1];
    addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 1);
    if (memspace->workspace_float[1] >= -1.0E-6) {
      addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 3);
    }
  } else {
    TrialState->xstar[nVarOrig + 1] = memspace->workspace_float[1];
    TrialState->xstar[nVarOrig + 3] = 0.0;
    addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 3);
    if (memspace->workspace_float[1] <= 1.0E-6) {
      addBoundToActiveSetMatrix_(WorkingSet, 4, mLBOrig + 1);
    }
  }
  mLBOrig = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      (qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig;
  driver(Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, qpoptions, qpoptions);
  qpoptions->MaxIterations = mLBOrig;
  ia = (WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) - 5;
  memspace->workspace_int[0] = WorkingSet->isActiveConstr[ia];
  memspace->workspace_int[2] = WorkingSet->isActiveConstr[ia + 2];
  tf = WorkingSet->isActiveConstr[ia + 1];
  b_tf = WorkingSet->isActiveConstr[ia + 3];
  memspace->workspace_int[1] = tf;
  memspace->workspace_int[3] = b_tf;
  if (TrialState->state != -6) {
    double qpval;
    idx_max = nVarOrig + 1;
    smax = 0.0;
    if (12 - nVarOrig >= 1) {
      for (idx = idx_max; idx < 13; idx++) {
        smax += fabs(TrialState->xstar[idx - 1]);
      }
    }
    s = 0.0;
    if (12 - nVarOrig >= 1) {
      i = (unsigned char)(12 - nVarOrig);
      for (idx = 0; idx < i; idx++) {
        qpval = TrialState->xstar[nVarOrig + idx];
        s += qpval * qpval;
      }
    }
    qpval = (TrialState->fstar - rho * smax) - beta / 2.0 * s;
    rho = MeritFunction->penaltyParam;
    beta = fabs(TrialState->cEq[0]) + fabs(TrialState->cEq[1]);
    smax = MeritFunction->linearizedConstrViol;
    s = 0.0;
    if (12 - nVarOrig >= 1) {
      for (idx = idx_max; idx < 13; idx++) {
        s += fabs(TrialState->xstar[idx - 1]);
      }
    }
    MeritFunction->linearizedConstrViol = s;
    smax = (beta + smax) - s;
    if ((smax > 2.2204460492503131E-16) && (qpval > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        rho = 1.0;
      } else {
        rho = 1.5;
      }
      rho = rho * qpval / smax;
    }
    if (rho < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + rho * beta;
      if ((MeritFunction->initFval +
           rho * MeritFunction->initConstrViolationEq) -
              MeritFunction->phi >
          (double)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam = fmax(rho, 1.0E-10);
      } else {
        MeritFunction->phi =
            TrialState->sqpFval + MeritFunction->penaltyParam * beta;
      }
    } else {
      MeritFunction->penaltyParam = fmax(rho, 1.0E-10);
      MeritFunction->phi =
          TrialState->sqpFval + MeritFunction->penaltyParam * beta;
    }
    MeritFunction->phiPrimePlus =
        fmin(qpval - MeritFunction->penaltyParam * beta, 0.0);
    for (idx = 0; idx < 2; idx++) {
      boolean_T isAeqActive;
      if ((memspace->workspace_int[idx] != 0) &&
          (memspace->workspace_int[idx + 2] != 0)) {
        isAeqActive = true;
      } else {
        isAeqActive = false;
      }
      TrialState->lambda[idx] *= (double)isAeqActive;
    }
    mLBOrig = WorkingSet->nActiveConstr;
    for (idx = 3; idx <= mLBOrig; idx++) {
      if (WorkingSet->Wid[idx - 1] == 3) {
        TrialState->lambda[idx - 1] *=
            (double)memspace->workspace_int[WorkingSet->Wlocalidx[idx - 1] + 3];
      }
    }
  }
  idx_max =
      ((WorkingSet->isActiveConstr[ia] + WorkingSet->isActiveConstr[ia + 2]) +
       tf) +
      b_tf;
  mLBOrig = WorkingSet->sizes[3] - 4;
  idx = WorkingSet->nActiveConstr;
  while ((idx > 2) && (idx_max > 0)) {
    if ((WorkingSet->Wid[idx - 1] == 4) &&
        (WorkingSet->Wlocalidx[idx - 1] > mLBOrig)) {
      ia = WorkingSet->nActiveConstr - 1;
      smax = TrialState->lambda[ia];
      TrialState->lambda[ia] = 0.0;
      TrialState->lambda[idx - 1] = smax;
      removeConstr(WorkingSet, idx);
      idx_max--;
    }
    idx--;
  }
  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  setProblemType(WorkingSet, 3);
  sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid, WorkingSet->Wlocalidx,
               memspace->workspace_float);
}

/*
 * File trailer for relaxed.c
 *
 * [EOF]
 */
