/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_exit.c
 *
 * Code generation for function 'test_exit'
 *
 */

/* Include files */
#include "test_exit.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "isDeltaXTooSmall.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = {
    1,           /* lineNo */
    "test_exit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_"
    "exit.p" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    1,                  /* lineNo */
    "computeLambdaLSQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p" /* pathName */
};

static emlrtBCInfo ae_emlrtBCI = {
    1,                  /* iFirst */
    529,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    1,                  /* iFirst */
    23,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void b_test_exit(const emlrtStack *sp, struct_T *Flags, c_struct_T *memspace,
                 g_struct_T *MeritFunction, f_struct_T *WorkingSet,
                 d_struct_T *TrialState, h_struct_T *QRManager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T c;
  real_T optimRelativeFactor;
  int32_T iQR_diag;
  int32_T iac;
  int32_T idx_max;
  int32_T mLB;
  int32_T nVar;
  int32_T rankR;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  nVar = WorkingSet->nVar;
  mLB = WorkingSet->sizes[3];
  st.site = &o_emlrtRSI;
  xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdasqp,
        TrialState->lambdaStopTest);
  st.site = &o_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aeq, WorkingSet->indexLB, WorkingSet->sizes[3],
                 WorkingSet->indexUB, TrialState->lambdaStopTest);
  st.site = &o_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &o_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cEq, WorkingSet->indexLB,
      WorkingSet->sizes[3], WorkingSet->indexUB);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &o_emlrtRSI;
  Flags->gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
  } else {
    real_T nlpComplErrorTmp;
    st.site = &o_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(
        &st, TrialState->xstarsqp, WorkingSet->indexLB, WorkingSet->sizes[3],
        WorkingSet->indexUB, TrialState->lambdaStopTest);
    if (TrialState->sqpIterations > 1) {
      st.site = &o_emlrtRSI;
      b_computeGradLag(&st, memspace->workspace_float, WorkingSet->nVar,
                       TrialState->grad, WorkingSet->Aeq, WorkingSet->indexLB,
                       WorkingSet->sizes[3], WorkingSet->indexUB,
                       TrialState->lambdaStopTestPrev);
      st.site = &o_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar, memspace->workspace_float,
                             &c);
      st.site = &o_emlrtRSI;
      nlpComplErrorTmp = computeComplError(
          &st, TrialState->xstarsqp, WorkingSet->indexLB, WorkingSet->sizes[3],
          WorkingSet->indexUB, TrialState->lambdaStopTestPrev);
      if ((c < MeritFunction->nlpDualFeasError) &&
          (nlpComplErrorTmp < MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = c;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        st.site = &o_emlrtRSI;
        xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdaStopTestPrev,
              TrialState->lambdaStopTest);
      } else {
        st.site = &o_emlrtRSI;
        xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdaStopTest,
              TrialState->lambdaStopTestPrev);
      }
    } else {
      st.site = &o_emlrtRSI;
      xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdaStopTest,
            TrialState->lambdaStopTestPrev);
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
          boolean_T dxTooSmall;
          st.site = &o_emlrtRSI;
          dxTooSmall = isDeltaXTooSmall(&st, TrialState->xstarsqp,
                                        TrialState->delta_x, WorkingSet->nVar);
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
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr == 0) {
                Flags->done = true;
              } else {
                real_T d;
                boolean_T exitg1;
                st.site = &o_emlrtRSI;
                updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet,
                                         TrialState->cEq, WorkingSet->sizes[3]);
                st.site = &o_emlrtRSI;
                b_st.site = &cb_emlrtRSI;
                b_xcopy(&b_st, nActiveConstr, TrialState->lambda);
                b_st.site = &cb_emlrtRSI;
                factorQRE(&b_st, QRManager, WorkingSet->ATwset, nVar,
                          nActiveConstr);
                b_st.site = &cb_emlrtRSI;
                c_st.site = &yb_emlrtRSI;
                computeQ_(&c_st, QRManager, QRManager->mrows);
                b_st.site = &cb_emlrtRSI;
                c_st.site = &s_emlrtRSI;
                d_st.site = &tb_emlrtRSI;
                if (nVar > 2147483646) {
                  e_st.site = &h_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                rankR = (uint8_T)nVar;
                memset(&memspace->workspace_float[0], 0,
                       (uint32_T)rankR * sizeof(real_T));
                iQR_diag = 23 * (nVar - 1) + 1;
                d_st.site = &sb_emlrtRSI;
                if (iQR_diag > 2147483624) {
                  e_st.site = &h_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                for (iac = 1; iac <= iQR_diag; iac += 23) {
                  c = 0.0;
                  idx_max = (iac + nVar) - 1;
                  d_st.site = &rb_emlrtRSI;
                  if ((iac <= idx_max) && (idx_max > 2147483646)) {
                    e_st.site = &h_emlrtRSI;
                    check_forloop_overflow_error(&e_st);
                  }
                  for (rankR = iac; rankR <= idx_max; rankR++) {
                    c +=
                        QRManager->Q[rankR - 1] * TrialState->grad[rankR - iac];
                  }
                  rankR = div_nde_s32_floor(iac - 1, 23);
                  memspace->workspace_float[rankR] -= c;
                }
                c = muDoubleScalarAbs(QRManager->QR[0]) *
                    muDoubleScalarMin(
                        1.4901161193847656E-8,
                        (real_T)muIntScalarMax_sint32(nVar, nActiveConstr) *
                            2.2204460492503131E-16);
                idx_max = muIntScalarMin_sint32(nVar, nActiveConstr);
                rankR = 0;
                iQR_diag = 1;
                exitg1 = false;
                while ((!exitg1) && (rankR < idx_max)) {
                  if (iQR_diag > 529) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, 529,
                                                  &ae_emlrtBCI, &st);
                  }
                  if (muDoubleScalarAbs(QRManager->QR[iQR_diag - 1]) > c) {
                    rankR++;
                    iQR_diag += 24;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &cb_emlrtRSI;
                xtrsv(rankR, QRManager->QR, memspace->workspace_float);
                idx_max = muIntScalarMin_sint32(nActiveConstr, idx_max);
                b_st.site = &cb_emlrtRSI;
                for (iQR_diag = 0; iQR_diag < idx_max; iQR_diag++) {
                  rankR = QRManager->jpvt[iQR_diag];
                  if ((rankR < 1) || (rankR > 23)) {
                    emlrtDynamicBoundsCheckR2012b(rankR, 1, 23, &be_emlrtBCI,
                                                  &st);
                  }
                  TrialState->lambda[QRManager->jpvt[iQR_diag] - 1] =
                      memspace->workspace_float[iQR_diag];
                }
                st.site = &o_emlrtRSI;
                sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid, WorkingSet->Wlocalidx,
                             memspace->workspace_float);
                st.site = &o_emlrtRSI;
                b_computeGradLag(&st, memspace->workspace_float, nVar,
                                 TrialState->grad, WorkingSet->Aeq,
                                 WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                                 TrialState->lambda);
                st.site = &o_emlrtRSI;
                b_computeDualFeasError(&st, nVar, memspace->workspace_float,
                                       &c);
                st.site = &o_emlrtRSI;
                nlpComplErrorTmp = computeComplError(
                    &st, TrialState->xstarsqp, WorkingSet->indexLB, mLB,
                    WorkingSet->indexUB, TrialState->lambda);
                d = muDoubleScalarMax(c, nlpComplErrorTmp);
                if (d <= muDoubleScalarMax(MeritFunction->nlpDualFeasError,
                                           MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = c;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  st.site = &o_emlrtRSI;
                  xcopy(&st, mLB + 10, TrialState->lambda,
                        TrialState->lambdaStopTest);
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

boolean_T test_exit(const emlrtStack *sp, g_struct_T *MeritFunction,
                    const f_struct_T *WorkingSet, d_struct_T *TrialState,
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType)
{
  emlrtStack st;
  real_T optimRelativeFactor;
  int32_T idx_max;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  st.site = &o_emlrtRSI;
  xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdasqp,
        TrialState->lambdaStopTest);
  st.site = &o_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aeq, WorkingSet->indexLB, WorkingSet->sizes[3],
                 WorkingSet->indexUB, TrialState->lambdaStopTest);
  st.site = &o_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &o_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cEq, WorkingSet->indexLB,
      WorkingSet->sizes[3], WorkingSet->indexUB);
  MeritFunction->feasRelativeFactor =
      muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &o_emlrtRSI;
  Flags_gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags_gradOK) {
    *Flags_done = true;
  } else {
    st.site = &o_emlrtRSI;
    computeComplError(&st, TrialState->xstarsqp, WorkingSet->indexLB,
                      WorkingSet->sizes[3], WorkingSet->indexUB,
                      TrialState->lambdaStopTest);
    MeritFunction->nlpComplError = 0.0;
    st.site = &o_emlrtRSI;
    xcopy(&st, WorkingSet->sizes[3] + 10, TrialState->lambdaStopTest,
          TrialState->lambdaStopTestPrev);
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor)) {
      *Flags_done = true;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
    } else if (TrialState->FunctionEvaluations >= 800) {
      *Flags_done = true;
    }
  }
  return Flags_gradOK;
}

/* End of code generation (test_exit.c) */
