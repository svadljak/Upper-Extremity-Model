/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.c
 *
 * Code generation for function 'step'
 *
 */

/* Include files */
#include "step.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "addAeqConstr.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "maxConstraintViolation_AMats_regularized_.h"
#include "relaxed.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kc_emlrtRSI =
    {
        1,      /* lineNo */
        "step", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
        "fminconsqp\\step.p" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    1,        /* lineNo */
    "normal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\normal.p" /* pathName */
};

static emlrtRSInfo nf_emlrtRSI = {
    1,                   /* lineNo */
    "makeBoundFeasible", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    1,                   /* lineNo */
    "saturateDirection", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    1,           /* lineNo */
    "BFGSReset", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\BFGSReset.p" /* pathName */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "makeBoundFeasible", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "saturateDirection", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                   /* iFirst */
    13,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "makeBoundFeasible", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    1,        /* iFirst */
    2,        /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "normal", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\normal.p", /* pName */
    0                 /* checkKind */
};

/* Function Definitions */
void step(const emlrtStack *sp, struct_T *stepFlags, real_T Hessian[64],
          d_struct_T *TrialState, g_struct_T *MeritFunction,
          c_struct_T *memspace, f_struct_T *WorkingSet, h_struct_T *QRManager,
          i_struct_T *CholManager, j_struct_T *QPObjective,
          k_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  f_struct_T obj;
  real_T dv[13];
  real_T constrViolDelta;
  real_T linearizedConstrViolPrev;
  int32_T i;
  int32_T idx;
  int32_T nVar;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T checkBoundViolation;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  stepFlags->stepAccepted = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  if (stepFlags->stepType != 3) {
    st.site = &kc_emlrtRSI;
    e_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  } else {
    st.site = &kc_emlrtRSI;
    f_xcopy(&st, WorkingSet->nVar, TrialState->xstar, TrialState->searchDir);
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (stepFlags->stepType) {
    case 1: {
      boolean_T exitg2;
      boolean_T nonlinEqRemoved;
      st.site = &kc_emlrtRSI;
      b_st.site = &lc_emlrtRSI;
      driver(&b_st, Hessian, TrialState->grad, TrialState, memspace, WorkingSet,
             QRManager, CholManager, QPObjective, qpoptions, qpoptions);
      b_st.site = &lc_emlrtRSI;
      if (WorkingSet->probType == 2) {
        obj = *WorkingSet;
        c_st.site = &hd_emlrtRSI;
        linearizedConstrViolPrev =
            c_maxConstraintViolation_AMats_(&c_st, &obj, TrialState->xstar);
      } else {
        obj = *WorkingSet;
        c_st.site = &hd_emlrtRSI;
        linearizedConstrViolPrev =
            d_maxConstraintViolation_AMats_(&c_st, &obj, TrialState->xstar);
      }
      c_st.site = &hd_emlrtRSI;
      if (WorkingSet->sizes[3] > 2147483646) {
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      i = (uint8_T)WorkingSet->sizes[3];
      for (idx = 0; idx < i; idx++) {
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, 13, &q_emlrtBCI,
                                        &b_st);
        }
        linearizedConstrViolPrev = muDoubleScalarMax(
            linearizedConstrViolPrev, -TrialState->xstar[obj.indexLB[idx] - 1] -
                                          obj.lb[obj.indexLB[idx] - 1]);
      }
      c_st.site = &hd_emlrtRSI;
      for (idx = 0; idx < 8; idx++) {
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, 13, &q_emlrtBCI,
                                        &b_st);
        }
        linearizedConstrViolPrev = muDoubleScalarMax(
            linearizedConstrViolPrev, TrialState->xstar[obj.indexUB[idx] - 1] -
                                          obj.ub[obj.indexUB[idx] - 1]);
      }
      if ((TrialState->state > 0) ||
          ((TrialState->state == 0) && (linearizedConstrViolPrev <= 1.0E-6))) {
        real_T constrViolationEq;
        real_T penaltyParamTrial;
        b_st.site = &lc_emlrtRSI;
        penaltyParamTrial = MeritFunction->penaltyParam;
        c_st.site = &hf_emlrtRSI;
        constrViolationEq = muDoubleScalarAbs(TrialState->cEq[0]) +
                            muDoubleScalarAbs(TrialState->cEq[1]);
        c_st.site = &hf_emlrtRSI;
        linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
        MeritFunction->linearizedConstrViol = 0.0;
        constrViolDelta = constrViolationEq + linearizedConstrViolPrev;
        if ((constrViolDelta > 2.2204460492503131E-16) &&
            (TrialState->fstar > 0.0)) {
          if (TrialState->sqpFval == 0.0) {
            linearizedConstrViolPrev = 1.0;
          } else {
            linearizedConstrViolPrev = 1.5;
          }
          penaltyParamTrial =
              linearizedConstrViolPrev * TrialState->fstar / constrViolDelta;
        }
        if (penaltyParamTrial < MeritFunction->penaltyParam) {
          MeritFunction->phi =
              TrialState->sqpFval + penaltyParamTrial * constrViolationEq;
          if ((MeritFunction->initFval +
               penaltyParamTrial * MeritFunction->initConstrViolationEq) -
                  MeritFunction->phi >
              (real_T)MeritFunction->nPenaltyDecreases *
                  MeritFunction->threshold) {
            MeritFunction->nPenaltyDecreases++;
            if ((MeritFunction->nPenaltyDecreases << 1) >
                TrialState->sqpIterations) {
              MeritFunction->threshold *= 10.0;
            }
            MeritFunction->penaltyParam =
                muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          } else {
            MeritFunction->phi =
                TrialState->sqpFval +
                MeritFunction->penaltyParam * constrViolationEq;
          }
        } else {
          MeritFunction->penaltyParam =
              muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          MeritFunction->phi = TrialState->sqpFval +
                               MeritFunction->penaltyParam * constrViolationEq;
        }
        MeritFunction->phiPrimePlus = muDoubleScalarMin(
            TrialState->fstar - MeritFunction->penaltyParam * constrViolationEq,
            0.0);
      } else if (TrialState->state != -6) {
        stepFlags->stepType = 2;
      }
      b_st.site = &lc_emlrtRSI;
      sortLambdaQP(&b_st, TrialState->lambda, WorkingSet->nActiveConstr,
                   WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                   WorkingSet->Wlocalidx, memspace->workspace_float);
      nonlinEqRemoved = (WorkingSet->mEqRemoved > 0);
      exitg2 = false;
      while ((!exitg2) && (WorkingSet->mEqRemoved > 0)) {
        if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 2)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 2,
                                        &s_emlrtBCI, &st);
        }
        if (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >= 1) {
          if ((WorkingSet->mEqRemoved < 1) || (WorkingSet->mEqRemoved > 2)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 2,
                                          &s_emlrtBCI, &st);
          }
          b_st.site = &lc_emlrtRSI;
          addAeqConstr(&b_st, WorkingSet,
                       WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1]);
          WorkingSet->mEqRemoved--;
        } else {
          exitg2 = true;
        }
      }
      if (nonlinEqRemoved) {
        b_st.site = &lc_emlrtRSI;
        WorkingSet->Wlocalidx[0] = 1;
        WorkingSet->Wlocalidx[1] = 2;
      }
      if (stepFlags->stepType != 2) {
        st.site = &kc_emlrtRSI;
        f_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
        guard1 = true;
      }
    } break;
    case 2:
      st.site = &kc_emlrtRSI;
      removeAllIneqConstr(&st, WorkingSet);
      st.site = &kc_emlrtRSI;
      memcpy(&dv[0], &TrialState->xstar[0], 13U * sizeof(real_T));
      b_st.site = &nf_emlrtRSI;
      if (WorkingSet->sizes[3] > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      i = (uint8_T)WorkingSet->sizes[3];
      for (idx = 0; idx < i; idx++) {
        if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 13,
                                        &r_emlrtBCI, &st);
        }
        linearizedConstrViolPrev = WorkingSet->lb[WorkingSet->indexLB[idx] - 1];
        if (-dv[WorkingSet->indexLB[idx] - 1] > linearizedConstrViolPrev) {
          if ((WorkingSet->indexLB[idx] < 1) ||
              (WorkingSet->indexLB[idx] > 8)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 8,
                                          &o_emlrtBCI, &st);
          }
          dv[WorkingSet->indexLB[idx] - 1] =
              (WorkingSet->ub[WorkingSet->indexLB[idx] - 1] -
               linearizedConstrViolPrev) /
              2.0;
        }
      }
      b_st.site = &nf_emlrtRSI;
      for (idx = 0; idx < 8; idx++) {
        if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 13,
                                        &r_emlrtBCI, &st);
        }
        linearizedConstrViolPrev = WorkingSet->ub[WorkingSet->indexUB[idx] - 1];
        if (dv[WorkingSet->indexUB[idx] - 1] > linearizedConstrViolPrev) {
          dv[WorkingSet->indexUB[idx] - 1] =
              (linearizedConstrViolPrev -
               WorkingSet->lb[WorkingSet->indexUB[idx] - 1]) /
              2.0;
        }
      }
      memcpy(&TrialState->xstar[0], &dv[0], 13U * sizeof(real_T));
      st.site = &kc_emlrtRSI;
      relaxed(&st, Hessian, TrialState->grad, TrialState, MeritFunction,
              memspace, WorkingSet, QRManager, CholManager, QPObjective,
              qpoptions);
      st.site = &kc_emlrtRSI;
      f_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
      guard1 = true;
      break;
    default: {
      memcpy(&dv[0], &TrialState->grad[0], 13U * sizeof(real_T));
      st.site = &kc_emlrtRSI;
      checkBoundViolation =
          soc(&st, Hessian, dv, TrialState, memspace, WorkingSet, QRManager,
              CholManager, QPObjective, qpoptions);
      stepFlags->stepAccepted = checkBoundViolation;
      if (stepFlags->stepAccepted && (TrialState->state != -6)) {
        st.site = &kc_emlrtRSI;
        if (nVar > 2147483646) {
          b_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        i = (uint8_T)nVar;
        scalarLB = ((uint8_T)nVar >> 1) << 1;
        vectorUB = scalarLB - 2;
        for (idx = 0; idx <= vectorUB; idx += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&TrialState->xstar[idx]);
          r1 = _mm_loadu_pd(&TrialState->socDirection[idx]);
          _mm_storeu_pd(&TrialState->delta_x[idx], _mm_add_pd(r, r1));
        }
        for (idx = scalarLB; idx < i; idx++) {
          TrialState->delta_x[idx] =
              TrialState->xstar[idx] + TrialState->socDirection[idx];
        }
      }
      guard1 = true;
    } break;
    }
    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        st.site = &kc_emlrtRSI;
        linearizedConstrViolPrev = 0.0;
        constrViolDelta = 1.0;
        for (idx = 0; idx < 8; idx++) {
          linearizedConstrViolPrev =
              muDoubleScalarMax(linearizedConstrViolPrev,
                                muDoubleScalarAbs(TrialState->grad[idx]));
          constrViolDelta = muDoubleScalarMax(
              constrViolDelta, muDoubleScalarAbs(TrialState->xstar[idx]));
        }
        linearizedConstrViolPrev = muDoubleScalarMax(
            2.2204460492503131E-16, linearizedConstrViolPrev / constrViolDelta);
        for (vectorUB = 0; vectorUB < 8; vectorUB++) {
          scalarLB = vectorUB << 3;
          b_st.site = &wf_emlrtRSI;
          i_xcopy(&b_st, vectorUB, Hessian, scalarLB + 1);
          i = vectorUB + scalarLB;
          Hessian[i] = linearizedConstrViolPrev;
          b_st.site = &wf_emlrtRSI;
          i_xcopy(&b_st, 7 - vectorUB, Hessian, i + 2);
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    st.site = &kc_emlrtRSI;
    memcpy(&dv[0], &TrialState->delta_x[0], 13U * sizeof(real_T));
    b_st.site = &vf_emlrtRSI;
    if (WorkingSet->sizes[3] > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)WorkingSet->sizes[3];
    for (idx = 0; idx < i; idx++) {
      scalarLB = WorkingSet->indexLB[idx];
      if ((scalarLB < 1) || (scalarLB > 8)) {
        emlrtDynamicBoundsCheckR2012b(scalarLB, 1, 8, &p_emlrtBCI, &st);
      }
      linearizedConstrViolPrev = dv[WorkingSet->indexLB[idx] - 1];
      constrViolDelta = TrialState->xstarsqp[WorkingSet->indexLB[idx] - 1] +
                        linearizedConstrViolPrev;
      if (constrViolDelta < 0.0) {
        dv[WorkingSet->indexLB[idx] - 1] =
            linearizedConstrViolPrev - constrViolDelta;
        TrialState->xstar[WorkingSet->indexLB[idx] - 1] -= constrViolDelta;
      }
    }
    b_st.site = &vf_emlrtRSI;
    for (idx = 0; idx < 8; idx++) {
      i = WorkingSet->indexUB[idx];
      if ((i < 1) || (i > 8)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 8, &p_emlrtBCI, &st);
      }
      linearizedConstrViolPrev = dv[WorkingSet->indexUB[idx] - 1];
      constrViolDelta =
          (1.0 - TrialState->xstarsqp[WorkingSet->indexUB[idx] - 1]) -
          linearizedConstrViolPrev;
      if (constrViolDelta < 0.0) {
        dv[WorkingSet->indexUB[idx] - 1] =
            linearizedConstrViolPrev + constrViolDelta;
        TrialState->xstar[WorkingSet->indexUB[idx] - 1] += constrViolDelta;
      }
    }
    memcpy(&TrialState->delta_x[0], &dv[0], 13U * sizeof(real_T));
  }
}

/* End of code generation (step.c) */
