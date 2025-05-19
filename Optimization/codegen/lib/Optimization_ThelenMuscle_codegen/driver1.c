/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: driver1.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "driver1.h"
#include "BFGSUpdate.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "computeFiniteDifferences.h"
#include "evalObjAndConstr.h"
#include "rt_nonfinite.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : c_struct_T *TrialState
 *                f_struct_T *MeritFunction
 *                const h_coder_internal_stickyStruct *FcnEvaluator
 *                d_struct_T *FiniteDifferences
 *                b_struct_T *memspace
 *                e_struct_T *WorkingSet
 *                double Hessian[64]
 *                g_struct_T *QRManager
 *                h_struct_T *CholManager
 *                i_struct_T *QPObjective
 * Return Type  : void
 */
void b_driver(c_struct_T *TrialState, f_struct_T *MeritFunction,
              const h_coder_internal_stickyStruct *FcnEvaluator,
              d_struct_T *FiniteDifferences, b_struct_T *memspace,
              e_struct_T *WorkingSet, double Hessian[64], g_struct_T *QRManager,
              h_struct_T *CholManager, i_struct_T *QPObjective)
{
  static const signed char b_Hessian[64] = {
      1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  static const char qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                               'c', 'o', 'n'};
  j_struct_T Flags;
  k_struct_T expl_temp;
  int i;
  int i1;
  int iCol;
  int ix;
  int k;
  int mLB;
  int nVar_tmp;
  int qpoptions_MaxIterations;
  int scalarLB;
  memset(&QPObjective->grad[0], 0, 13U * sizeof(double));
  memset(&QPObjective->Hx[0], 0, 12U * sizeof(double));
  QPObjective->hasLinear = true;
  QPObjective->nvar = 8;
  QPObjective->beta = 0.0;
  QPObjective->rho = 0.0;
  QPObjective->objtype = 3;
  QPObjective->prev_objtype = 3;
  QPObjective->prev_nvar = 0;
  QPObjective->prev_hasLinear = false;
  QPObjective->gammaScalar = 0.0;
  CholManager->ndims = 0;
  CholManager->info = 0;
  CholManager->ConvexCheck = true;
  CholManager->workspace_ = rtInf;
  memset(&CholManager->FMat[0], 0, 529U * sizeof(double));
  memset(&QRManager->QR[0], 0, 529U * sizeof(double));
  memset(&QRManager->Q[0], 0, 529U * sizeof(double));
  QRManager->mrows = 0;
  QRManager->ncols = 0;
  memset(&QRManager->jpvt[0], 0, 23U * sizeof(int));
  memset(&QRManager->tau[0], 0, 23U * sizeof(double));
  QRManager->minRowCol = 0;
  QRManager->usedPivoting = false;
  for (i = 0; i < 64; i++) {
    Hessian[i] = b_Hessian[i];
  }
  nVar_tmp = WorkingSet->nVar;
  mLB = WorkingSet->sizes[3];
  iCol = WorkingSet->nVar;
  ix = WorkingSet->sizes[3] + 8;
  if (iCol >= ix) {
    ix = iCol;
  }
  qpoptions_MaxIterations = 10 * ix;
  TrialState->steplength = 1.0;
  test_exit(MeritFunction, WorkingSet, TrialState, &Flags.fevalOK, &Flags.done,
            &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  iCol = -1;
  i = (unsigned char)nVar_tmp;
  for (ix = 0; ix < 2; ix++) {
    memcpy(&TrialState->JacCeqTrans_old[iCol + 1], &WorkingSet->Aeq[iCol + 1],
           (unsigned int)i * sizeof(double));
    iCol += 13;
  }
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (k = 0; k < 8; k++) {
    TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
    TrialState->grad_old[k] = TrialState->grad[k];
  }
  TrialState->cEq_old[0] = TrialState->cEq[0];
  TrialState->cEq_old[1] = TrialState->cEq[1];
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m128d r;
    __m128d r1;
    double phi_alpha;
    int i2;
    int vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet,
                                 TrialState->cEq, mLB);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i1 = 0; i1 < 7; i1++) {
        expl_temp.SolverName[i1] = qpoptions_SolverName[i1];
      }
      step(&Flags, Hessian, TrialState, MeritFunction, memspace, WorkingSet,
           QRManager, CholManager, QPObjective, &expl_temp);
      if (Flags.stepAccepted) {
        scalarLB = ((unsigned char)nVar_tmp >> 1) << 1;
        vectorUB = scalarLB - 2;
        for (iCol = 0; iCol <= vectorUB; iCol += 2) {
          r = _mm_loadu_pd(&TrialState->xstarsqp[iCol]);
          r1 = _mm_loadu_pd(&TrialState->delta_x[iCol]);
          _mm_storeu_pd(&TrialState->xstarsqp[iCol], _mm_add_pd(r, r1));
        }
        for (iCol = scalarLB; iCol < i; iCol++) {
          TrialState->xstarsqp[iCol] += TrialState->delta_x[iCol];
        }
        TrialState->sqpFval = evalObjAndConstr(
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.Q,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.b,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.Fl,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .Fpe,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.VM,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .LM0,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .alpha0,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .FM0,
            TrialState->xstarsqp, TrialState->cEq, &iCol);
        Flags.fevalOK = (iCol == 1);
        TrialState->FunctionEvaluations++;
        if (Flags.fevalOK) {
          MeritFunction->phiFullStep =
              TrialState->sqpFval +
              MeritFunction->penaltyParam *
                  (fabs(TrialState->cEq[0]) + fabs(TrialState->cEq[1]));
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        double alpha;
        int exitflagLnSrch;
        boolean_T evalWellDefined;
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        evalWellDefined = Flags.fevalOK;
        i1 = WorkingSet->nVar;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        if (i1 - 1 >= 0) {
          memcpy(&TrialState->searchDir[0], &TrialState->delta_x[0],
                 (unsigned int)i1 * sizeof(double));
        }
        int exitg1;
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 800) {
            if (evalWellDefined &&
                (phi_alpha <=
                 MeritFunction->phi +
                     alpha * 0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              boolean_T exitg2;
              boolean_T tooSmallX;
              alpha *= 0.7;
              i2 = (unsigned char)i1;
              iCol = ((unsigned char)i1 >> 1) << 1;
              ix = iCol - 2;
              for (k = 0; k <= ix; k += 2) {
                r = _mm_loadu_pd(&TrialState->xstar[k]);
                _mm_storeu_pd(&TrialState->delta_x[k],
                              _mm_mul_pd(_mm_set1_pd(alpha), r));
              }
              for (k = iCol; k < i2; k++) {
                TrialState->delta_x[k] = alpha * TrialState->xstar[k];
              }
              if (socTaken) {
                phi_alpha = alpha * alpha;
                if ((i1 >= 1) && (!(phi_alpha == 0.0))) {
                  scalarLB = (i1 / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (k = 0; k <= vectorUB; k += 2) {
                    r = _mm_loadu_pd(&TrialState->socDirection[k]);
                    r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
                    _mm_storeu_pd(
                        &TrialState->delta_x[k],
                        _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(phi_alpha), r)));
                  }
                  for (k = scalarLB; k < i1; k++) {
                    TrialState->delta_x[k] +=
                        phi_alpha * TrialState->socDirection[k];
                  }
                }
              }
              tooSmallX = true;
              k = 0;
              exitg2 = false;
              while ((!exitg2) && (k <= (unsigned char)i1 - 1)) {
                if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[k])) <=
                    fabs(TrialState->delta_x[k])) {
                  tooSmallX = false;
                  exitg2 = true;
                } else {
                  k++;
                }
              }
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                for (k = 0; k <= ix; k += 2) {
                  r = _mm_loadu_pd(&TrialState->xstarsqp_old[k]);
                  r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
                  _mm_storeu_pd(&TrialState->xstarsqp[k], _mm_add_pd(r, r1));
                }
                for (k = iCol; k < i2; k++) {
                  TrialState->xstarsqp[k] =
                      TrialState->xstarsqp_old[k] + TrialState->delta_x[k];
                }
                TrialState->sqpFval = evalObjAndConstr(
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.Q,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.b,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.Fl,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.Fpe,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.VM,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.LM0,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.alpha0,
                    FcnEvaluator->next.next.next.next.next.next.next.value
                        .workspace.FM0,
                    TrialState->xstarsqp, TrialState->cEq, &ix);
                TrialState->FunctionEvaluations++;
                evalWellDefined = (ix == 1);
                if (evalWellDefined) {
                  phi_alpha =
                      TrialState->sqpFval +
                      MeritFunction->penaltyParam *
                          (fabs(TrialState->cEq[0]) + fabs(TrialState->cEq[1]));
                } else {
                  phi_alpha = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      scalarLB = ((unsigned char)nVar_tmp >> 1) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&TrialState->xstarsqp_old[k]);
        r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
        _mm_storeu_pd(&TrialState->xstarsqp[k], _mm_add_pd(r, r1));
      }
      for (k = scalarLB; k < i; k++) {
        TrialState->xstarsqp[k] =
            TrialState->xstarsqp_old[k] + TrialState->delta_x[k];
      }
      i1 = (unsigned char)(mLB + 10);
      scalarLB = ((unsigned char)(mLB + 10) >> 1) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&TrialState->lambda[k]);
        r1 = _mm_loadu_pd(&TrialState->lambdasqp[k]);
        _mm_storeu_pd(
            &TrialState->lambdasqp[k],
            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(TrialState->steplength),
                                      _mm_sub_pd(r, r1))));
      }
      for (k = scalarLB; k < i1; k++) {
        phi_alpha = TrialState->lambdasqp[k];
        phi_alpha +=
            TrialState->steplength * (TrialState->lambda[k] - phi_alpha);
        TrialState->lambdasqp[k] = phi_alpha;
      }
      TrialState->sqpFval_old = TrialState->sqpFval;
      for (k = 0; k < 8; k++) {
        TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
        TrialState->grad_old[k] = TrialState->grad[k];
      }
      TrialState->cEq_old[0] = TrialState->cEq[0];
      TrialState->cEq_old[1] = TrialState->cEq[1];
      computeFiniteDifferences(FiniteDifferences, TrialState->sqpFval,
                               TrialState->cEq, TrialState->xstarsqp,
                               TrialState->grad, WorkingSet->Aeq);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
             8U * sizeof(double));
      TrialState->cEq[0] = TrialState->cEq_old[0];
      TrialState->cEq[1] = TrialState->cEq_old[1];
    }
    b_test_exit(&Flags, memspace, MeritFunction, WorkingSet, TrialState,
                QRManager);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      memcpy(&TrialState->delta_gradLag[0], &TrialState->grad[0],
             (unsigned int)i * sizeof(double));
      if (nVar_tmp >= 1) {
        scalarLB = (nVar_tmp / 2) << 1;
        vectorUB = scalarLB - 2;
        for (k = 0; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&TrialState->delta_gradLag[k]);
          r1 = _mm_loadu_pd(&TrialState->grad_old[k]);
          _mm_storeu_pd(&TrialState->delta_gradLag[k], _mm_sub_pd(r, r1));
        }
        for (k = scalarLB; k < nVar_tmp; k++) {
          TrialState->delta_gradLag[k] -= TrialState->grad_old[k];
        }
      }
      ix = 0;
      for (iCol = 0; iCol <= 13; iCol += 13) {
        i1 = iCol + nVar_tmp;
        for (scalarLB = iCol + 1; scalarLB <= i1; scalarLB++) {
          i2 = (scalarLB - iCol) - 1;
          TrialState->delta_gradLag[i2] +=
              WorkingSet->Aeq[scalarLB - 1] * TrialState->lambdasqp[ix];
        }
        ix++;
      }
      ix = 0;
      for (iCol = 0; iCol <= 13; iCol += 13) {
        i1 = iCol + nVar_tmp;
        for (scalarLB = iCol + 1; scalarLB <= i1; scalarLB++) {
          i2 = (scalarLB - iCol) - 1;
          TrialState->delta_gradLag[i2] +=
              TrialState->JacCeqTrans_old[scalarLB - 1] *
              -TrialState->lambdasqp[ix];
        }
        ix++;
      }
      iCol = -1;
      for (ix = 0; ix < 2; ix++) {
        memcpy(&TrialState->JacCeqTrans_old[iCol + 1],
               &WorkingSet->Aeq[iCol + 1], (unsigned int)i * sizeof(double));
        iCol += 13;
      }
      BFGSUpdate(nVar_tmp, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_float);
      TrialState->sqpIterations++;
    }
  }
}

/*
 * File trailer for driver1.c
 *
 * [EOF]
 */
