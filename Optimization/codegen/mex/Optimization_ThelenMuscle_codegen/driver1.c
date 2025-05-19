/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "BFGSUpdate.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "computeDeltaLag.h"
#include "computeFiniteDifferences.h"
#include "computeMeritFcn.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "isDeltaXTooSmall.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = {
    1,        /* lineNo */
    "driver", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\driver.p" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    1,           /* lineNo */
    "saveState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "TrialState\\saveState.p" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    1,            /* lineNo */
    "linesearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\linesearch.p" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    1,                /* lineNo */
    "revertSolution", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "TrialState\\revertSolution.p" /* pathName */
};

static emlrtBCInfo de_emlrtBCI = {
    1,        /* iFirst */
    8,        /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "driver", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\driver.p", /* pName */
    3                       /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    1,            /* iFirst */
    8,            /* iLast */
    1,            /* lineNo */
    1,            /* colNo */
    "",           /* aName */
    "linesearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\linesearch.p", /* pName */
    3                           /* checkKind */
};

/* Function Definitions */
void b_driver(const emlrtStack *sp, d_struct_T *TrialState,
              g_struct_T *MeritFunction,
              const h_coder_internal_stickyStruct *FcnEvaluator,
              e_struct_T *FiniteDifferences, c_struct_T *memspace,
              f_struct_T *WorkingSet, real_T Hessian[64], h_struct_T *QRManager,
              i_struct_T *CholManager, j_struct_T *QPObjective)
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  static const int8_T b_Hessian[64] = {
      1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T expl_temp;
  struct_T Flags;
  int32_T i;
  int32_T k;
  int32_T mLB;
  int32_T nVar_tmp;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  memset(&QPObjective->grad[0], 0, 13U * sizeof(real_T));
  memset(&QPObjective->Hx[0], 0, 12U * sizeof(real_T));
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
  memset(&CholManager->FMat[0], 0, 529U * sizeof(real_T));
  memset(&QRManager->QR[0], 0, 529U * sizeof(real_T));
  memset(&QRManager->Q[0], 0, 529U * sizeof(real_T));
  QRManager->mrows = 0;
  QRManager->ncols = 0;
  memset(&QRManager->jpvt[0], 0, 23U * sizeof(int32_T));
  memset(&QRManager->tau[0], 0, 23U * sizeof(real_T));
  QRManager->minRowCol = 0;
  QRManager->usedPivoting = false;
  for (i = 0; i < 64; i++) {
    Hessian[i] = b_Hessian[i];
  }
  nVar_tmp = WorkingSet->nVar;
  mLB = WorkingSet->sizes[3] + 10;
  y = WorkingSet->sizes[3] + 8;
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  st.site = &n_emlrtRSI;
  Flags.gradOK = test_exit(&st, MeritFunction, WorkingSet, TrialState,
                           &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
                           &Flags.failedLineSearch, &Flags.stepType);
  st.site = &n_emlrtRSI;
  saveJacobian(&st, TrialState, nVar_tmp, WorkingSet->Aeq);
  st.site = &n_emlrtRSI;
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (k = 0; k < 8; k++) {
    TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
    TrialState->grad_old[k] = TrialState->grad[k];
  }
  b_st.site = &jc_emlrtRSI;
  j_xcopy(TrialState->cEq, TrialState->cEq_old);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m128d r;
    __m128d r1;
    real_T phi_alpha;
    int32_T scalarLB;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        st.site = &n_emlrtRSI;
        updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet,
                                 TrialState->cEq, mLB - 10);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      st.site = &n_emlrtRSI;
      step(&st, &Flags, Hessian, TrialState, MeritFunction, memspace,
           WorkingSet, QRManager, CholManager, QPObjective, &expl_temp);
      if (Flags.stepAccepted) {
        st.site = &n_emlrtRSI;
        if (nVar_tmp > 2147483646) {
          b_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        i = (uint8_T)nVar_tmp;
        scalarLB = ((uint8_T)nVar_tmp >> 1) << 1;
        vectorUB = scalarLB - 2;
        for (y = 0; y <= vectorUB; y += 2) {
          r = _mm_loadu_pd(&TrialState->xstarsqp[y]);
          r1 = _mm_loadu_pd(&TrialState->delta_x[y]);
          if (y + 1 > 8) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, 8, &de_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          _mm_storeu_pd(&TrialState->xstarsqp[y], _mm_add_pd(r, r1));
        }
        for (y = scalarLB; y < i; y++) {
          if (y + 1 > 8) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, 8, &de_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          TrialState->xstarsqp[y] += TrialState->delta_x[y];
        }
        st.site = &n_emlrtRSI;
        TrialState->sqpFval = evalObjAndConstr(
            &st,
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
            TrialState->xstarsqp, TrialState->cEq, &y);
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        st.site = &n_emlrtRSI;
        MeritFunction->phiFullStep =
            computeMeritFcn(MeritFunction->penaltyParam, TrialState->sqpFval,
                            TrialState->cEq, Flags.fevalOK);
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        real_T alpha;
        int32_T exitflagLnSrch;
        boolean_T b;
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        st.site = &n_emlrtRSI;
        b = Flags.fevalOK;
        i = WorkingSet->nVar;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        b_st.site = &ag_emlrtRSI;
        f_xcopy(&b_st, WorkingSet->nVar, TrialState->delta_x,
                TrialState->searchDir);
        int32_T exitg1;
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 800) {
            if (b && (phi_alpha <=
                      MeritFunction->phi +
                          alpha * 0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              int32_T scalarLB_tmp;
              int32_T vectorUB_tmp;
              boolean_T tooSmallX;
              alpha *= 0.7;
              b_st.site = &ag_emlrtRSI;
              if (i > 2147483646) {
                c_st.site = &h_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }
              y = (uint8_T)i;
              scalarLB_tmp = ((uint8_T)i >> 1) << 1;
              vectorUB_tmp = scalarLB_tmp - 2;
              for (k = 0; k <= vectorUB_tmp; k += 2) {
                r = _mm_loadu_pd(&TrialState->xstar[k]);
                _mm_storeu_pd(&TrialState->delta_x[k],
                              _mm_mul_pd(_mm_set1_pd(alpha), r));
              }
              for (k = scalarLB_tmp; k < y; k++) {
                TrialState->delta_x[k] = alpha * TrialState->xstar[k];
              }
              if (socTaken) {
                phi_alpha = alpha * alpha;
                if (!(phi_alpha == 0.0)) {
                  scalarLB = (i / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (k = 0; k <= vectorUB; k += 2) {
                    r = _mm_loadu_pd(&TrialState->socDirection[k]);
                    r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
                    _mm_storeu_pd(
                        &TrialState->delta_x[k],
                        _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(phi_alpha), r)));
                  }
                  for (k = scalarLB; k < i; k++) {
                    TrialState->delta_x[k] +=
                        phi_alpha * TrialState->socDirection[k];
                  }
                }
              }
              b_st.site = &ag_emlrtRSI;
              tooSmallX = isDeltaXTooSmall(&b_st, TrialState->xstarsqp,
                                           TrialState->delta_x, i);
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                b_st.site = &ag_emlrtRSI;
                for (k = 0; k <= vectorUB_tmp; k += 2) {
                  r = _mm_loadu_pd(&TrialState->xstarsqp_old[k]);
                  r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
                  if (k + 1 > 8) {
                    emlrtDynamicBoundsCheckR2012b(k + 1, 1, 8, &ee_emlrtBCI,
                                                  &st);
                  }
                  _mm_storeu_pd(&TrialState->xstarsqp[k], _mm_add_pd(r, r1));
                }
                for (k = scalarLB_tmp; k < y; k++) {
                  if (k + 1 > 8) {
                    emlrtDynamicBoundsCheckR2012b(k + 1, 1, 8, &ee_emlrtBCI,
                                                  &st);
                  }
                  TrialState->xstarsqp[k] =
                      TrialState->xstarsqp_old[k] + TrialState->delta_x[k];
                }
                b_st.site = &ag_emlrtRSI;
                TrialState->sqpFval =
                    evalObjAndConstr(&b_st,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.Q,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.b,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.Fl,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.Fpe,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.VM,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.LM0,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.alpha0,
                                     FcnEvaluator->next.next.next.next.next.next
                                         .next.value.workspace.FM0,
                                     TrialState->xstarsqp, TrialState->cEq, &y);
                TrialState->FunctionEvaluations++;
                b = (y == 1);
                b_st.site = &ag_emlrtRSI;
                phi_alpha =
                    computeMeritFcn(MeritFunction->penaltyParam,
                                    TrialState->sqpFval, TrialState->cEq, b);
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = b;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &n_emlrtRSI;
      if (nVar_tmp > 2147483646) {
        b_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)nVar_tmp;
      scalarLB = ((uint8_T)nVar_tmp >> 1) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&TrialState->xstarsqp_old[k]);
        r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
        if (k + 1 > 8) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, 8, &de_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        _mm_storeu_pd(&TrialState->xstarsqp[k], _mm_add_pd(r, r1));
      }
      for (k = scalarLB; k < i; k++) {
        if (k + 1 > 8) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, 8, &de_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->xstarsqp[k] =
            TrialState->xstarsqp_old[k] + TrialState->delta_x[k];
      }
      st.site = &n_emlrtRSI;
      if (mLB > 2147483646) {
        b_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)mLB;
      scalarLB = ((uint8_T)mLB >> 1) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&TrialState->lambda[k]);
        r1 = _mm_loadu_pd(&TrialState->lambdasqp[k]);
        _mm_storeu_pd(
            &TrialState->lambdasqp[k],
            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(TrialState->steplength),
                                      _mm_sub_pd(r, r1))));
      }
      for (k = scalarLB; k < i; k++) {
        phi_alpha = TrialState->lambdasqp[k];
        phi_alpha +=
            TrialState->steplength * (TrialState->lambda[k] - phi_alpha);
        TrialState->lambdasqp[k] = phi_alpha;
      }
      st.site = &n_emlrtRSI;
      TrialState->sqpFval_old = TrialState->sqpFval;
      for (k = 0; k < 8; k++) {
        TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
        TrialState->grad_old[k] = TrialState->grad[k];
      }
      b_st.site = &jc_emlrtRSI;
      j_xcopy(TrialState->cEq, TrialState->cEq_old);
      st.site = &n_emlrtRSI;
      Flags.gradOK = computeFiniteDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cEq,
          TrialState->xstarsqp, TrialState->grad, WorkingSet->Aeq);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      st.site = &n_emlrtRSI;
      TrialState->sqpFval = TrialState->sqpFval_old;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
             8U * sizeof(real_T));
      b_st.site = &bg_emlrtRSI;
      j_xcopy(TrialState->cEq_old, TrialState->cEq);
    }
    st.site = &n_emlrtRSI;
    b_test_exit(&st, &Flags, memspace, MeritFunction, WorkingSet, TrialState,
                QRManager);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &n_emlrtRSI;
      computeDeltaLag(&st, nVar_tmp, TrialState->delta_gradLag,
                      TrialState->grad, WorkingSet->Aeq, TrialState->grad_old,
                      TrialState->JacCeqTrans_old, TrialState->lambdasqp);
      st.site = &n_emlrtRSI;
      saveJacobian(&st, TrialState, nVar_tmp, WorkingSet->Aeq);
      st.site = &n_emlrtRSI;
      BFGSUpdate(&st, nVar_tmp, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_float);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver1.c) */
