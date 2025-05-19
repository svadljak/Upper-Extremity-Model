/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: step.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "step.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "addAeqConstr.h"
#include "driver.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : j_struct_T *stepFlags
 *                double Hessian[64]
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
void step(j_struct_T *stepFlags, double Hessian[64], c_struct_T *TrialState,
          f_struct_T *MeritFunction, b_struct_T *memspace,
          e_struct_T *WorkingSet, g_struct_T *QRManager,
          h_struct_T *CholManager, i_struct_T *QPObjective,
          k_struct_T *qpoptions)
{
  __m128d r1;
  double obj_maxConstrWorkspace[23];
  double dv[13];
  double c;
  double oldDirIdx;
  int b_nVar;
  int iac;
  int idxStartIneq;
  int idx_global;
  int nVar;
  boolean_T checkBoundViolation;
  stepFlags->stepAccepted = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar - 1;
  if (stepFlags->stepType != 3) {
    idx_global = (unsigned char)WorkingSet->nVar;
    memcpy(&TrialState->xstar[0], &TrialState->xstarsqp[0],
           (unsigned int)idx_global * sizeof(double));
  } else if (nVar >= 0) {
    memcpy(&TrialState->searchDir[0], &TrialState->xstar[0],
           (unsigned int)(nVar + 1) * sizeof(double));
  }
  r1 = _mm_set1_pd(-1.0);
  int exitg1;
  boolean_T guard1;
  do {
    int idxLB;
    exitg1 = 0;
    guard1 = false;
    switch (stepFlags->stepType) {
    case 1: {
      boolean_T nonlinEqRemoved;
      driver(Hessian, TrialState->grad, TrialState, memspace, WorkingSet,
             QRManager, CholManager, QPObjective, qpoptions, qpoptions);
      if (WorkingSet->probType == 2) {
        __m128d r;
        memcpy(&obj_maxConstrWorkspace[0], &WorkingSet->maxConstrWorkspace[0],
               23U * sizeof(double));
        r = _mm_loadu_pd(&WorkingSet->beq[0]);
        _mm_storeu_pd(&obj_maxConstrWorkspace[0],
                      _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        for (iac = 0; iac <= 13; iac += 13) {
          c = 0.0;
          idx_global = iac + 8;
          for (idxStartIneq = iac + 1; idxStartIneq <= idx_global;
               idxStartIneq++) {
            c += WorkingSet->Aeq[idxStartIneq - 1] *
                 TrialState->xstar[(idxStartIneq - iac) - 1];
          }
          idxLB = div_nde_s32_floor(iac, 13);
          obj_maxConstrWorkspace[idxLB] += c;
        }
        c = fmax(
            fmax(0.0, fabs((obj_maxConstrWorkspace[0] - TrialState->xstar[8]) +
                           TrialState->xstar[10])),
            fabs((obj_maxConstrWorkspace[1] - TrialState->xstar[9]) +
                 TrialState->xstar[11]));
      } else {
        __m128d r;
        memcpy(&obj_maxConstrWorkspace[0], &WorkingSet->maxConstrWorkspace[0],
               23U * sizeof(double));
        r = _mm_loadu_pd(&WorkingSet->beq[0]);
        _mm_storeu_pd(&obj_maxConstrWorkspace[0],
                      _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        for (iac = 0; iac <= 13; iac += 13) {
          c = 0.0;
          idx_global = iac + WorkingSet->nVar;
          for (idxStartIneq = iac + 1; idxStartIneq <= idx_global;
               idxStartIneq++) {
            c += WorkingSet->Aeq[idxStartIneq - 1] *
                 TrialState->xstar[(idxStartIneq - iac) - 1];
          }
          idxLB = div_nde_s32_floor(iac, 13);
          obj_maxConstrWorkspace[idxLB] += c;
        }
        c = fmax(fmax(0.0, fabs(obj_maxConstrWorkspace[0])),
                 fabs(obj_maxConstrWorkspace[1]));
      }
      idx_global = (unsigned char)WorkingSet->sizes[3];
      for (iac = 0; iac < idx_global; iac++) {
        idxLB = WorkingSet->indexLB[iac] - 1;
        c = fmax(c, -TrialState->xstar[idxLB] - WorkingSet->lb[idxLB]);
      }
      for (iac = 0; iac < 8; iac++) {
        idxLB = WorkingSet->indexUB[iac] - 1;
        c = fmax(c, TrialState->xstar[idxLB] - WorkingSet->ub[idxLB]);
      }
      if ((TrialState->state > 0) ||
          ((TrialState->state == 0) && (c <= 1.0E-6))) {
        double constrViolationEq;
        oldDirIdx = MeritFunction->penaltyParam;
        constrViolationEq = fabs(TrialState->cEq[0]) + fabs(TrialState->cEq[1]);
        c = MeritFunction->linearizedConstrViol;
        MeritFunction->linearizedConstrViol = 0.0;
        c += constrViolationEq;
        if ((c > 2.2204460492503131E-16) && (TrialState->fstar > 0.0)) {
          if (TrialState->sqpFval == 0.0) {
            oldDirIdx = 1.0;
          } else {
            oldDirIdx = 1.5;
          }
          oldDirIdx = oldDirIdx * TrialState->fstar / c;
        }
        if (oldDirIdx < MeritFunction->penaltyParam) {
          MeritFunction->phi =
              TrialState->sqpFval + oldDirIdx * constrViolationEq;
          if ((MeritFunction->initFval +
               oldDirIdx * MeritFunction->initConstrViolationEq) -
                  MeritFunction->phi >
              (double)MeritFunction->nPenaltyDecreases *
                  MeritFunction->threshold) {
            MeritFunction->nPenaltyDecreases++;
            if ((MeritFunction->nPenaltyDecreases << 1) >
                TrialState->sqpIterations) {
              MeritFunction->threshold *= 10.0;
            }
            MeritFunction->penaltyParam = fmax(oldDirIdx, 1.0E-10);
          } else {
            MeritFunction->phi =
                TrialState->sqpFval +
                MeritFunction->penaltyParam * constrViolationEq;
          }
        } else {
          MeritFunction->penaltyParam = fmax(oldDirIdx, 1.0E-10);
          MeritFunction->phi = TrialState->sqpFval +
                               MeritFunction->penaltyParam * constrViolationEq;
        }
        MeritFunction->phiPrimePlus = fmin(
            TrialState->fstar - MeritFunction->penaltyParam * constrViolationEq,
            0.0);
      } else if (TrialState->state != -6) {
        stepFlags->stepType = 2;
      }
      sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                   WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                   WorkingSet->Wlocalidx, memspace->workspace_float);
      nonlinEqRemoved = (WorkingSet->mEqRemoved > 0);
      while ((WorkingSet->mEqRemoved > 0) &&
             (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >= 1)) {
        addAeqConstr(WorkingSet,
                     WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1]);
        WorkingSet->mEqRemoved--;
      }
      if (nonlinEqRemoved) {
        WorkingSet->Wlocalidx[0] = 1;
        WorkingSet->Wlocalidx[1] = 2;
      }
      if (stepFlags->stepType != 2) {
        if (nVar >= 0) {
          memcpy(&TrialState->delta_x[0], &TrialState->xstar[0],
                 (unsigned int)(nVar + 1) * sizeof(double));
        }
        guard1 = true;
      }
    } break;
    case 2:
      idxLB = WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      idxStartIneq = idxLB + 1;
      b_nVar = WorkingSet->nActiveConstr;
      for (idx_global = idxStartIneq; idx_global <= b_nVar; idx_global++) {
        WorkingSet->isActiveConstr
            [(WorkingSet->isActiveIdx[WorkingSet->Wid[idx_global - 1] - 1] +
              WorkingSet->Wlocalidx[idx_global - 1]) -
             2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = idxLB;
      memcpy(&dv[0], &TrialState->xstar[0], 13U * sizeof(double));
      idx_global = (unsigned char)WorkingSet->sizes[3];
      for (iac = 0; iac < idx_global; iac++) {
        c = WorkingSet->lb[WorkingSet->indexLB[iac] - 1];
        if (-dv[WorkingSet->indexLB[iac] - 1] > c) {
          dv[WorkingSet->indexLB[iac] - 1] =
              (WorkingSet->ub[WorkingSet->indexLB[iac] - 1] - c) / 2.0;
        }
      }
      for (iac = 0; iac < 8; iac++) {
        c = WorkingSet->ub[WorkingSet->indexUB[iac] - 1];
        if (dv[WorkingSet->indexUB[iac] - 1] > c) {
          dv[WorkingSet->indexUB[iac] - 1] =
              (c - WorkingSet->lb[WorkingSet->indexUB[iac] - 1]) / 2.0;
        }
      }
      memcpy(&TrialState->xstar[0], &dv[0], 13U * sizeof(double));
      relaxed(Hessian, TrialState->grad, TrialState, MeritFunction, memspace,
              WorkingSet, QRManager, CholManager, QPObjective, qpoptions);
      if (nVar >= 0) {
        memcpy(&TrialState->delta_x[0], &TrialState->xstar[0],
               (unsigned int)(nVar + 1) * sizeof(double));
      }
      guard1 = true;
      break;
    default: {
      __m128d r;
      __m128d r2;
      b_nVar = WorkingSet->nVar;
      idx_global = (unsigned char)WorkingSet->nVar;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
             (unsigned int)idx_global * sizeof(double));
      memcpy(&TrialState->socDirection[0], &TrialState->xstar[0],
             (unsigned int)idx_global * sizeof(double));
      memcpy(&TrialState->lambdaStopTest[0], &TrialState->lambda[0],
             23U * sizeof(double));
      r = _mm_loadu_pd(&TrialState->cEq[0]);
      _mm_storeu_pd(&WorkingSet->beq[0], _mm_mul_pd(r, r1));
      for (iac = 0; iac <= 13; iac += 13) {
        c = 0.0;
        idxLB = iac + WorkingSet->nVar;
        for (idxStartIneq = iac + 1; idxStartIneq <= idxLB; idxStartIneq++) {
          c += WorkingSet->Aeq[idxStartIneq - 1] *
               TrialState->searchDir[(idxStartIneq - iac) - 1];
        }
        idxLB = div_nde_s32_floor(iac, 13);
        WorkingSet->beq[idxLB] += c;
      }
      WorkingSet->bwset[0] = WorkingSet->beq[0];
      WorkingSet->bwset[1] = WorkingSet->beq[1];
      memcpy(&TrialState->xstar[0], &TrialState->xstarsqp[0],
             (unsigned int)idx_global * sizeof(double));
      memcpy(&dv[0], &TrialState->grad[0], 13U * sizeof(double));
      driver(Hessian, dv, TrialState, memspace, WorkingSet, QRManager,
             CholManager, QPObjective, qpoptions, qpoptions);
      while ((WorkingSet->mEqRemoved > 0) &&
             (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >= 1)) {
        addAeqConstr(WorkingSet,
                     WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1]);
        WorkingSet->mEqRemoved--;
      }
      idx_global = (unsigned char)b_nVar;
      idxLB = ((unsigned char)b_nVar >> 1) << 1;
      idxStartIneq = idxLB - 2;
      for (iac = 0; iac <= idxStartIneq; iac += 2) {
        r = _mm_loadu_pd(&TrialState->socDirection[iac]);
        r2 = _mm_loadu_pd(&TrialState->xstar[iac]);
        _mm_storeu_pd(&TrialState->socDirection[iac], _mm_sub_pd(r2, r));
        _mm_storeu_pd(&TrialState->xstar[iac], r);
      }
      for (iac = idxLB; iac < idx_global; iac++) {
        c = TrialState->socDirection[iac];
        oldDirIdx = c;
        c = TrialState->xstar[iac] - c;
        TrialState->socDirection[iac] = c;
        TrialState->xstar[iac] = oldDirIdx;
      }
      checkBoundViolation = (b_xnrm2(b_nVar, TrialState->socDirection) <=
                             2.0 * b_xnrm2(b_nVar, TrialState->xstar));
      r = _mm_loadu_pd(&TrialState->cEq[0]);
      r = _mm_mul_pd(r, r1);
      _mm_storeu_pd(&WorkingSet->beq[0], r);
      _mm_storeu_pd(&WorkingSet->bwset[0], r);
      if (!checkBoundViolation) {
        memcpy(&TrialState->lambda[0], &TrialState->lambdaStopTest[0],
               23U * sizeof(double));
      } else {
        sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                     WorkingSet->sizes, WorkingSet->isActiveIdx,
                     WorkingSet->Wid, WorkingSet->Wlocalidx,
                     memspace->workspace_float);
      }
      stepFlags->stepAccepted = checkBoundViolation;
      if (checkBoundViolation && (TrialState->state != -6)) {
        idx_global = (unsigned char)(nVar + 1);
        idxLB = ((unsigned char)(nVar + 1) >> 1) << 1;
        idxStartIneq = idxLB - 2;
        for (iac = 0; iac <= idxStartIneq; iac += 2) {
          r = _mm_loadu_pd(&TrialState->xstar[iac]);
          r2 = _mm_loadu_pd(&TrialState->socDirection[iac]);
          _mm_storeu_pd(&TrialState->delta_x[iac], _mm_add_pd(r, r2));
        }
        for (iac = idxLB; iac < idx_global; iac++) {
          TrialState->delta_x[iac] =
              TrialState->xstar[iac] + TrialState->socDirection[iac];
        }
      }
      guard1 = true;
    } break;
    }
    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        c = 0.0;
        oldDirIdx = 1.0;
        for (iac = 0; iac < 8; iac++) {
          c = fmax(c, fabs(TrialState->grad[iac]));
          oldDirIdx = fmax(oldDirIdx, fabs(TrialState->xstar[iac]));
        }
        c = fmax(2.2204460492503131E-16, c / oldDirIdx);
        for (b_nVar = 0; b_nVar < 8; b_nVar++) {
          idxLB = b_nVar << 3;
          for (idxStartIneq = 0; idxStartIneq < b_nVar; idxStartIneq++) {
            Hessian[idxLB + idxStartIneq] = 0.0;
          }
          idxLB += b_nVar;
          Hessian[idxLB] = c;
          idx_global = 6 - b_nVar;
          if (idx_global >= 0) {
            memset(&Hessian[idxLB + 1], 0,
                   (unsigned int)(idx_global + 1) * sizeof(double));
          }
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    memcpy(&dv[0], &TrialState->delta_x[0], 13U * sizeof(double));
    idx_global = (unsigned char)WorkingSet->sizes[3];
    for (iac = 0; iac < idx_global; iac++) {
      c = dv[WorkingSet->indexLB[iac] - 1];
      oldDirIdx = TrialState->xstarsqp[WorkingSet->indexLB[iac] - 1] + c;
      if (oldDirIdx < 0.0) {
        dv[WorkingSet->indexLB[iac] - 1] = c - oldDirIdx;
        TrialState->xstar[WorkingSet->indexLB[iac] - 1] -= oldDirIdx;
      }
    }
    for (iac = 0; iac < 8; iac++) {
      c = dv[WorkingSet->indexUB[iac] - 1];
      oldDirIdx =
          (1.0 - TrialState->xstarsqp[WorkingSet->indexUB[iac] - 1]) - c;
      if (oldDirIdx < 0.0) {
        dv[WorkingSet->indexUB[iac] - 1] = c + oldDirIdx;
        TrialState->xstar[WorkingSet->indexUB[iac] - 1] += oldDirIdx;
      }
    }
    memcpy(&TrialState->delta_x[0], &dv[0], 13U * sizeof(double));
  }
}

/*
 * File trailer for step.c
 *
 * [EOF]
 */
