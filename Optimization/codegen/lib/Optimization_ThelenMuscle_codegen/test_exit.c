/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: test_exit.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "test_exit.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "computeGradLag.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : j_struct_T *Flags
 *                b_struct_T *memspace
 *                f_struct_T *MeritFunction
 *                e_struct_T *WorkingSet
 *                c_struct_T *TrialState
 *                g_struct_T *QRManager
 * Return Type  : void
 */
void b_test_exit(j_struct_T *Flags, b_struct_T *memspace,
                 f_struct_T *MeritFunction, e_struct_T *WorkingSet,
                 c_struct_T *TrialState, g_struct_T *QRManager)
{
  double optimRelativeFactor;
  double s;
  double smax;
  double val;
  int b_i;
  int fullRank_R;
  int i;
  int i1;
  int idx_max;
  int ix;
  int j;
  int mLB;
  int nVar;
  int rankR;
  boolean_T dxTooSmall;
  boolean_T exitg1;
  boolean_T isFeasible;
  nVar = WorkingSet->nVar;
  mLB = WorkingSet->sizes[3];
  i = (unsigned char)(WorkingSet->sizes[3] + 10);
  memcpy(&TrialState->lambdaStopTest[0], &TrialState->lambdasqp[0],
         (unsigned int)i * sizeof(double));
  computeGradLag(TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aeq, WorkingSet->indexLB, WorkingSet->sizes[3],
                 WorkingSet->indexUB, TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    idx_max = 1;
    if (WorkingSet->nVar > 1) {
      smax = fabs(TrialState->grad[0]);
      for (ix = 2; ix <= nVar; ix++) {
        s = fabs(TrialState->grad[ix - 1]);
        if (s > smax) {
          idx_max = ix;
          smax = s;
        }
      }
    }
  }
  optimRelativeFactor = fmax(1.0, fabs(TrialState->grad[idx_max - 1]));
  if (rtIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  smax = fmax(fmax(0.0, fabs(TrialState->cEq[0])), fabs(TrialState->cEq[1]));
  i1 = (unsigned char)WorkingSet->sizes[3];
  for (idx_max = 0; idx_max < i1; idx_max++) {
    smax = fmax(smax,
                0.0 - TrialState->xstarsqp[WorkingSet->indexLB[idx_max] - 1]);
  }
  for (idx_max = 0; idx_max < 8; idx_max++) {
    smax = fmax(smax,
                TrialState->xstarsqp[WorkingSet->indexUB[idx_max] - 1] - 1.0);
  }
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = fmax(1.0, smax);
  }
  isFeasible = (smax <= 1.0E-6 * MeritFunction->feasRelativeFactor);
  dxTooSmall = true;
  val = 0.0;
  ix = (unsigned char)WorkingSet->nVar;
  idx_max = 0;
  exitg1 = false;
  while ((!exitg1) && (idx_max <= ix - 1)) {
    dxTooSmall = ((!rtIsInf(TrialState->gradLag[idx_max])) &&
                  (!rtIsNaN(TrialState->gradLag[idx_max])));
    if (!dxTooSmall) {
      exitg1 = true;
    } else {
      val = fmax(val, fabs(TrialState->gradLag[idx_max]));
      idx_max++;
    }
  }
  MeritFunction->nlpDualFeasError = val;
  if (!dxTooSmall) {
    Flags->done = true;
  } else {
    double nlpComplError;
    double nlpComplErrorLSQ;
    double nlpComplErrorTmp;
    nlpComplError = 0.0;
    for (idx_max = 0; idx_max < i1; idx_max++) {
      s = TrialState->xstarsqp[WorkingSet->indexLB[idx_max] - 1];
      smax = TrialState->lambdaStopTest[idx_max + 2];
      nlpComplError =
          fmax(nlpComplError, fmin(fabs(s * smax), fmin(fabs(s), smax)));
    }
    for (idx_max = 0; idx_max < 8; idx_max++) {
      smax = TrialState->lambdaStopTest[(WorkingSet->sizes[3] + idx_max) + 2];
      s = 1.0 - TrialState->xstarsqp[WorkingSet->indexUB[idx_max] - 1];
      nlpComplError =
          fmax(nlpComplError, fmin(fabs(s * smax), fmin(fabs(s), smax)));
    }
    MeritFunction->nlpComplError = nlpComplError;
    if (TrialState->sqpIterations > 1) {
      b_computeGradLag(memspace->workspace_float, WorkingSet->nVar,
                       TrialState->grad, WorkingSet->Aeq, WorkingSet->indexLB,
                       WorkingSet->sizes[3], WorkingSet->indexUB,
                       TrialState->lambdaStopTestPrev);
      s = 0.0;
      idx_max = 0;
      while ((idx_max <= ix - 1) &&
             ((!rtIsInf(memspace->workspace_float[idx_max])) &&
              (!rtIsNaN(memspace->workspace_float[idx_max])))) {
        s = fmax(s, fabs(memspace->workspace_float[idx_max]));
        idx_max++;
      }
      nlpComplErrorTmp = 0.0;
      for (idx_max = 0; idx_max < i1; idx_max++) {
        nlpComplErrorLSQ =
            TrialState->xstarsqp[WorkingSet->indexLB[idx_max] - 1];
        smax = TrialState->lambdaStopTestPrev[idx_max + 2];
        nlpComplErrorTmp =
            fmax(nlpComplErrorTmp, fmin(fabs(nlpComplErrorLSQ * smax),
                                        fmin(fabs(nlpComplErrorLSQ), smax)));
      }
      for (idx_max = 0; idx_max < 8; idx_max++) {
        smax = TrialState
                   ->lambdaStopTestPrev[(WorkingSet->sizes[3] + idx_max) + 2];
        nlpComplErrorLSQ =
            1.0 - TrialState->xstarsqp[WorkingSet->indexUB[idx_max] - 1];
        nlpComplErrorTmp =
            fmax(nlpComplErrorTmp, fmin(fabs(nlpComplErrorLSQ * smax),
                                        fmin(fabs(nlpComplErrorLSQ), smax)));
      }
      if ((s < val) && (nlpComplErrorTmp < nlpComplError)) {
        MeritFunction->nlpDualFeasError = s;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        memcpy(&TrialState->lambdaStopTest[0],
               &TrialState->lambdaStopTestPrev[0],
               (unsigned int)i * sizeof(double));
      } else {
        memcpy(&TrialState->lambdaStopTestPrev[0],
               &TrialState->lambdaStopTest[0],
               (unsigned int)i * sizeof(double));
      }
    } else {
      memcpy(&TrialState->lambdaStopTestPrev[0], &TrialState->lambdaStopTest[0],
             (unsigned int)i * sizeof(double));
    }
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          dxTooSmall = true;
          idx_max = 0;
          exitg1 = false;
          while ((!exitg1) && (idx_max <= ix - 1)) {
            if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[idx_max])) <=
                fabs(TrialState->delta_x[idx_max])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              idx_max++;
            }
          }
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType == 2) {
                Flags->done = true;
              } else {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              }
            } else {
              int nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr == 0) {
                Flags->done = true;
              } else {
                updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet,
                                         TrialState->cEq, WorkingSet->sizes[3]);
                if (nActiveConstr - 1 >= 0) {
                  memset(&TrialState->lambda[0], 0,
                         (unsigned int)nActiveConstr * sizeof(double));
                }
                factorQRE(QRManager, WorkingSet->ATwset, nVar, nActiveConstr);
                computeQ_(QRManager, QRManager->mrows);
                memset(&memspace->workspace_float[0], 0,
                       (unsigned int)ix * sizeof(double));
                ix = 23 * (nVar - 1) + 1;
                for (rankR = 1; rankR <= ix; rankR += 23) {
                  smax = 0.0;
                  idx_max = rankR + nVar;
                  for (fullRank_R = rankR; fullRank_R < idx_max; fullRank_R++) {
                    smax += QRManager->Q[fullRank_R - 1] *
                            TrialState->grad[fullRank_R - rankR];
                  }
                  idx_max = div_nde_s32_floor(rankR - 1, 23);
                  memspace->workspace_float[idx_max] -= smax;
                }
                if (nVar >= nActiveConstr) {
                  idx_max = nVar;
                } else {
                  idx_max = nActiveConstr;
                }
                smax = fabs(QRManager->QR[0]) *
                       fmin(1.4901161193847656E-8,
                            (double)idx_max * 2.2204460492503131E-16);
                if (nVar <= nActiveConstr) {
                  fullRank_R = nVar;
                } else {
                  fullRank_R = nActiveConstr;
                }
                rankR = 0;
                idx_max = 0;
                while ((rankR < fullRank_R) &&
                       (fabs(QRManager->QR[idx_max]) > smax)) {
                  rankR++;
                  idx_max += 24;
                }
                if (rankR != 0) {
                  for (j = rankR; j >= 1; j--) {
                    idx_max = (j + (j - 1) * 23) - 1;
                    memspace->workspace_float[j - 1] /= QRManager->QR[idx_max];
                    for (b_i = 0; b_i <= j - 2; b_i++) {
                      ix = (j - b_i) - 2;
                      memspace->workspace_float[ix] -=
                          memspace->workspace_float[j - 1] *
                          QRManager->QR[(idx_max - b_i) - 1];
                    }
                  }
                }
                if (nActiveConstr <= fullRank_R) {
                  fullRank_R = nActiveConstr;
                }
                for (idx_max = 0; idx_max < fullRank_R; idx_max++) {
                  TrialState->lambda[QRManager->jpvt[idx_max] - 1] =
                      memspace->workspace_float[idx_max];
                }
                sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid, WorkingSet->Wlocalidx,
                             memspace->workspace_float);
                b_computeGradLag(memspace->workspace_float, nVar,
                                 TrialState->grad, WorkingSet->Aeq,
                                 WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                                 TrialState->lambda);
                nlpComplErrorTmp = 0.0;
                idx_max = 0;
                while ((idx_max <= (unsigned char)nVar - 1) &&
                       ((!rtIsInf(memspace->workspace_float[idx_max])) &&
                        (!rtIsNaN(memspace->workspace_float[idx_max])))) {
                  nlpComplErrorTmp =
                      fmax(nlpComplErrorTmp,
                           fabs(memspace->workspace_float[idx_max]));
                  idx_max++;
                }
                nlpComplErrorLSQ = 0.0;
                for (idx_max = 0; idx_max < i1; idx_max++) {
                  s = TrialState->xstarsqp[WorkingSet->indexLB[idx_max] - 1];
                  smax = TrialState->lambda[idx_max + 2];
                  nlpComplErrorLSQ =
                      fmax(nlpComplErrorLSQ,
                           fmin(fabs(s * smax), fmin(fabs(s), smax)));
                }
                for (idx_max = 0; idx_max < 8; idx_max++) {
                  smax = TrialState->lambda[(mLB + idx_max) + 2];
                  s = 1.0 -
                      TrialState->xstarsqp[WorkingSet->indexUB[idx_max] - 1];
                  nlpComplErrorLSQ =
                      fmax(nlpComplErrorLSQ,
                           fmin(fabs(s * smax), fmin(fabs(s), smax)));
                }
                smax = fmax(nlpComplErrorTmp, nlpComplErrorLSQ);
                if (smax <= fmax(MeritFunction->nlpDualFeasError,
                                 MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = nlpComplErrorTmp;
                  MeritFunction->nlpComplError = nlpComplErrorLSQ;
                  memcpy(&TrialState->lambdaStopTest[0], &TrialState->lambda[0],
                         (unsigned int)i * sizeof(double));
                }
                Flags->done = true;
                guard1 = true;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
          } else if (TrialState->FunctionEvaluations >= 800) {
            Flags->done = true;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : f_struct_T *MeritFunction
 *                const e_struct_T *WorkingSet
 *                c_struct_T *TrialState
 *                boolean_T *Flags_fevalOK
 *                boolean_T *Flags_done
 *                boolean_T *Flags_stepAccepted
 *                boolean_T *Flags_failedLineSearch
 *                int *Flags_stepType
 * Return Type  : boolean_T
 */
boolean_T test_exit(f_struct_T *MeritFunction, const e_struct_T *WorkingSet,
                    c_struct_T *TrialState, boolean_T *Flags_fevalOK,
                    boolean_T *Flags_done, boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int *Flags_stepType)
{
  double s;
  double smax;
  int i;
  int idx_max;
  int k;
  int nVar;
  boolean_T Flags_gradOK;
  boolean_T exitg1;
  boolean_T isFeasible;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  nVar = WorkingSet->nVar;
  i = (unsigned char)(WorkingSet->sizes[3] + 10);
  memcpy(&TrialState->lambdaStopTest[0], &TrialState->lambdasqp[0],
         (unsigned int)i * sizeof(double));
  computeGradLag(TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aeq, WorkingSet->indexLB, WorkingSet->sizes[3],
                 WorkingSet->indexUB, TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    idx_max = 1;
    if (WorkingSet->nVar > 1) {
      smax = fabs(TrialState->grad[0]);
      for (k = 2; k <= nVar; k++) {
        s = fabs(TrialState->grad[k - 1]);
        if (s > smax) {
          idx_max = k;
          smax = s;
        }
      }
    }
  }
  s = fmax(1.0, fabs(TrialState->grad[idx_max - 1]));
  if (rtIsInf(s)) {
    s = 1.0;
  }
  smax = fmax(fmax(0.0, fabs(TrialState->cEq[0])), fabs(TrialState->cEq[1]));
  nVar = (unsigned char)WorkingSet->sizes[3];
  for (idx_max = 0; idx_max < nVar; idx_max++) {
    smax = fmax(smax,
                0.0 - TrialState->xstarsqp[WorkingSet->indexLB[idx_max] - 1]);
  }
  for (idx_max = 0; idx_max < 8; idx_max++) {
    smax = fmax(smax,
                TrialState->xstarsqp[WorkingSet->indexUB[idx_max] - 1] - 1.0);
  }
  MeritFunction->feasRelativeFactor = fmax(1.0, smax);
  isFeasible = (smax <= 1.0E-6 * MeritFunction->feasRelativeFactor);
  Flags_gradOK = true;
  smax = 0.0;
  nVar = (unsigned char)WorkingSet->nVar;
  idx_max = 0;
  exitg1 = false;
  while ((!exitg1) && (idx_max <= nVar - 1)) {
    Flags_gradOK = ((!rtIsInf(TrialState->gradLag[idx_max])) &&
                    (!rtIsNaN(TrialState->gradLag[idx_max])));
    if (!Flags_gradOK) {
      exitg1 = true;
    } else {
      smax = fmax(smax, fabs(TrialState->gradLag[idx_max]));
      idx_max++;
    }
  }
  MeritFunction->nlpDualFeasError = smax;
  if (!Flags_gradOK) {
    *Flags_done = true;
  } else {
    MeritFunction->nlpComplError = 0.0;
    memcpy(&TrialState->lambdaStopTestPrev[0], &TrialState->lambdaStopTest[0],
           (unsigned int)i * sizeof(double));
    if (isFeasible && (smax <= 1.0E-6 * s)) {
      *Flags_done = true;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
    } else if (TrialState->FunctionEvaluations >= 800) {
      *Flags_done = true;
    }
  }
  return Flags_gradOK;
}

/*
 * File trailer for test_exit.c
 *
 * [EOF]
 */
