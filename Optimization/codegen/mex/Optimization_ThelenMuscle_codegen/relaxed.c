/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relaxed.c
 *
 * Code generation for function 'relaxed'
 *
 */

/* Include files */
#include "relaxed.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "assignResidualsToXSlack.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixamax.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "xasum.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo if_emlrtRSI = {
    1,                           /* lineNo */
    "computeConstrViolationEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\computeConstrViolationEq_.p" /* pathName */
};

static emlrtRSInfo lf_emlrtRSI = {
    1,                             /* lineNo */
    "computeConstrViolationIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\computeConstrViolationIneq_.p" /* pathName */
};

static emlrtRSInfo of_emlrtRSI = {
    1,         /* lineNo */
    "relaxed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p" /* pathName */
};

static emlrtRSInfo qf_emlrtRSI = {
    1,                            /* lineNo */
    "findActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\findActiveSlackLowerBounds.p" /* pathName */
};

static emlrtRSInfo rf_emlrtRSI = {
    1,                              /* lineNo */
    "removeActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p" /* pathName */
};

static emlrtBCInfo sd_emlrtBCI = {
    1,                              /* iFirst */
    23,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    3                                                 /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    1,         /* iFirst */
    23,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    1,         /* iFirst */
    13,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    1,         /* iFirst */
    8,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    1,                              /* iFirst */
    23,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    0                                                 /* checkKind */
};

/* Function Definitions */
void relaxed(const emlrtStack *sp, const real_T Hessian[64],
             const real_T grad[13], d_struct_T *TrialState,
             g_struct_T *MeritFunction, c_struct_T *memspace,
             f_struct_T *WorkingSet, h_struct_T *QRManager,
             i_struct_T *CholManager, j_struct_T *QPObjective,
             k_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T beta;
  real_T s;
  real_T smax;
  int32_T i;
  int32_T idx;
  int32_T idx_max;
  int32_T mFiniteLB_tmp;
  int32_T nVarOrig;
  int32_T temp;
  boolean_T b_tf;
  boolean_T tf;
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
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  st.site = &of_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &vd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    beta += Hessian[idx + (idx << 3)];
  }
  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    st.site = &of_emlrtRSI;
    idx_max = ixamax(&st, QPObjective->nvar, grad);
    if ((idx_max < 1) || (idx_max > 13)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 13, &ud_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    smax = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    st.site = &of_emlrtRSI;
    temp = WorkingSet->mConstr;
    b_st.site = &v_emlrtRSI;
    idx_max = 1;
    smax = muDoubleScalarAbs(TrialState->lambdasqp[0]);
    c_st.site = &w_emlrtRSI;
    if (WorkingSet->mConstr > 2147483646) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (idx = 2; idx <= temp; idx++) {
      s = muDoubleScalarAbs(TrialState->lambdasqp[idx - 1]);
      if (s > smax) {
        idx_max = idx;
        smax = s;
      }
    }
    smax = muDoubleScalarAbs(TrialState->lambdasqp[idx_max - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = smax;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &of_emlrtRSI;
  b_setProblemType(&st, WorkingSet);
  st.site = &of_emlrtRSI;
  assignResidualsToXSlack(&st, nVarOrig, WorkingSet, TrialState, memspace);
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      (qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig;
  st.site = &of_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, qpoptions, qpoptions);
  qpoptions->MaxIterations = temp;
  st.site = &of_emlrtRSI;
  mFiniteLB_tmp = WorkingSet->sizes[3] - 4;
  b_st.site = &qf_emlrtRSI;
  b_st.site = &qf_emlrtRSI;
  i = WorkingSet->isActiveIdx[3] + mFiniteLB_tmp;
  if ((i < 1) || (i > 23)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 23, &fc_emlrtBCI, &b_st);
  }
  b_st.site = &qf_emlrtRSI;
  if ((i + 2 < 1) || (i + 2 > 23)) {
    emlrtDynamicBoundsCheckR2012b(i + 2, 1, 23, &fc_emlrtBCI, &b_st);
  }
  memspace->workspace_int[0] = WorkingSet->isActiveConstr[i - 1];
  memspace->workspace_int[2] = WorkingSet->isActiveConstr[i + 1];
  b_st.site = &qf_emlrtRSI;
  if ((i + 1 < 1) || (i + 1 > 23)) {
    emlrtDynamicBoundsCheckR2012b(i + 1, 1, 23, &fc_emlrtBCI, &b_st);
  }
  tf = WorkingSet->isActiveConstr[i];
  b_st.site = &qf_emlrtRSI;
  if ((i + 3 < 1) || (i + 3 > 23)) {
    emlrtDynamicBoundsCheckR2012b(i + 3, 1, 23, &fc_emlrtBCI, &b_st);
  }
  b_tf = WorkingSet->isActiveConstr[i + 2];
  memspace->workspace_int[1] = tf;
  memspace->workspace_int[3] = b_tf;
  b_st.site = &qf_emlrtRSI;
  if (TrialState->state != -6) {
    real_T constrViolationEq;
    real_T qpfvalQuadExcess;
    st.site = &of_emlrtRSI;
    s = xasum(&st, 12 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    st.site = &of_emlrtRSI;
    b_st.site = &rc_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    qpfvalQuadExcess = 0.0;
    if (12 - nVarOrig >= 1) {
      d_st.site = &tc_emlrtRSI;
      if (12 - nVarOrig > 2147483646) {
        e_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      idx_max = (uint8_T)(12 - nVarOrig);
      for (idx = 0; idx < idx_max; idx++) {
        constrViolationEq = TrialState->xstar[nVarOrig + idx];
        qpfvalQuadExcess += constrViolationEq * constrViolationEq;
      }
    }
    st.site = &of_emlrtRSI;
    s = (TrialState->fstar - smax * s) - beta / 2.0 * qpfvalQuadExcess;
    qpfvalQuadExcess = MeritFunction->penaltyParam;
    b_st.site = &hf_emlrtRSI;
    c_st.site = &if_emlrtRSI;
    d_st.site = &jf_emlrtRSI;
    constrViolationEq = muDoubleScalarAbs(TrialState->cEq[0]) +
                        muDoubleScalarAbs(TrialState->cEq[1]);
    b_st.site = &hf_emlrtRSI;
    c_st.site = &lf_emlrtRSI;
    smax = MeritFunction->linearizedConstrViol;
    b_st.site = &hf_emlrtRSI;
    MeritFunction->linearizedConstrViol =
        xasum(&b_st, 12 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    smax = (constrViolationEq + smax) - MeritFunction->linearizedConstrViol;
    if ((smax > 2.2204460492503131E-16) && (s > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        beta = 1.0;
      } else {
        beta = 1.5;
      }
      qpfvalQuadExcess = beta * s / smax;
    }
    if (qpfvalQuadExcess < MeritFunction->penaltyParam) {
      MeritFunction->phi =
          TrialState->sqpFval + qpfvalQuadExcess * constrViolationEq;
      if ((MeritFunction->initFval +
           qpfvalQuadExcess * MeritFunction->initConstrViolationEq) -
              MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam =
            muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval +
                             MeritFunction->penaltyParam * constrViolationEq;
      }
    } else {
      MeritFunction->penaltyParam =
          muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      MeritFunction->phi =
          TrialState->sqpFval + MeritFunction->penaltyParam * constrViolationEq;
    }
    MeritFunction->phiPrimePlus = muDoubleScalarMin(
        s - MeritFunction->penaltyParam * constrViolationEq, 0.0);
    st.site = &of_emlrtRSI;
    for (idx = 0; idx < 2; idx++) {
      boolean_T isAeqActive;
      if ((memspace->workspace_int[idx] != 0) &&
          (memspace->workspace_int[idx + 2] != 0)) {
        isAeqActive = true;
      } else {
        isAeqActive = false;
      }
      TrialState->lambda[idx] *= (real_T)isAeqActive;
    }
    temp = WorkingSet->nActiveConstr;
    st.site = &of_emlrtRSI;
    if (WorkingSet->nActiveConstr > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 3; idx <= temp; idx++) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &td_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (WorkingSet->Wid[idx - 1] == 3) {
        idx_max = WorkingSet->Wlocalidx[idx - 1];
        if ((idx_max + 4 < 1) || (idx_max + 4 > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx_max + 4, 1, 23, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->lambda[idx - 1] *=
            (real_T)memspace->workspace_int[idx_max + 3];
      }
    }
  }
  st.site = &of_emlrtRSI;
  temp =
      ((WorkingSet->isActiveConstr[i - 1] + WorkingSet->isActiveConstr[i + 1]) +
       tf) +
      b_tf;
  idx = WorkingSet->nActiveConstr - 1;
  while ((idx + 1 > 2) && (temp > 0)) {
    if ((idx + 1 < 1) || (idx + 1 > 23)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &wd_emlrtBCI, &st);
    }
    if ((WorkingSet->Wid[idx] == 4) &&
        (WorkingSet->Wlocalidx[idx] > mFiniteLB_tmp)) {
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 23)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 23,
                                      &wd_emlrtBCI, &st);
      }
      smax = TrialState->lambda[WorkingSet->nActiveConstr - 1];
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 23)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 23,
                                      &sd_emlrtBCI, &st);
      }
      TrialState->lambda[WorkingSet->nActiveConstr - 1] = 0.0;
      TrialState->lambda[idx] = smax;
      b_st.site = &rf_emlrtRSI;
      idx_max = WorkingSet->Wid[idx];
      if ((WorkingSet->Wid[idx] < 1) || (WorkingSet->Wid[idx] > 6)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wid[idx], 1, 6, &t_emlrtBCI,
                                      &b_st);
      }
      i = (WorkingSet->isActiveIdx[WorkingSet->Wid[idx] - 1] +
           WorkingSet->Wlocalidx[idx]) -
          1;
      if ((i < 1) || (i > 23)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 23, &bb_emlrtBCI, &b_st);
      }
      WorkingSet->isActiveConstr[i - 1] = false;
      if (idx + 1 < WorkingSet->nActiveConstr) {
        c_st.site = &xc_emlrtRSI;
        moveConstraint_(&c_st, WorkingSet, WorkingSet->nActiveConstr, idx + 1);
      }
      WorkingSet->nActiveConstr--;
      if ((idx_max < 1) || (idx_max > 5)) {
        emlrtDynamicBoundsCheckR2012b(idx_max, 1, 5, &cb_emlrtBCI, &b_st);
      }
      WorkingSet->nWConstr[idx_max - 1]--;
      temp--;
    }
    idx--;
  }
  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &of_emlrtRSI;
  WorkingSet->nVar = 8;
  WorkingSet->mConstr = 18;
  if (WorkingSet->nWConstr[4] > 0) {
    temp = WorkingSet->isActiveIdx[4] - 2;
    b_st.site = &k_emlrtRSI;
    for (idx = 0; idx < 8; idx++) {
      i = (temp + idx) + 1;
      WorkingSet->isActiveConstr[idx + 10] = WorkingSet->isActiveConstr[i];
      WorkingSet->isActiveConstr[i] = false;
    }
  }
  for (i = 0; i < 5; i++) {
    WorkingSet->sizes[i] = WorkingSet->sizesNormal[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet->isActiveIdx[i] = WorkingSet->isActiveIdxNormal[i];
  }
  WorkingSet->probType = 3;
  st.site = &of_emlrtRSI;
  if (WorkingSet->nActiveConstr != 0) {
    boolean_T exitg1;
    b_st.site = &hc_emlrtRSI;
    d_xcopy(&b_st, 18, TrialState->lambda, memspace->workspace_float);
    b_st.site = &hc_emlrtRSI;
    b_xcopy(&b_st, 18, TrialState->lambda);
    idx_max = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet->nActiveConstr)) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(24, 1, 23, &l_emlrtBCI, &st);
      }
      if (WorkingSet->Wid[idx - 1] <= 2) {
        if (idx_max > 299) {
          emlrtDynamicBoundsCheckR2012b(300, 1, 299, &m_emlrtBCI, &st);
        }
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 23)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 23,
                                        &n_emlrtBCI, &st);
        }
        TrialState->lambda[i - 1] = memspace->workspace_float[idx_max - 1];
        idx_max++;
        idx++;
      } else {
        exitg1 = true;
      }
    }
    while (idx <= WorkingSet->nActiveConstr) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(24, 1, 23, &l_emlrtBCI, &st);
      }
      switch (WorkingSet->Wid[idx - 1]) {
      case 3:
        temp = 2;
        break;
      case 4:
        temp = 2;
        break;
      default:
        temp = 10;
        break;
      }
      if (idx_max > 299) {
        emlrtDynamicBoundsCheckR2012b(300, 1, 299, &m_emlrtBCI, &st);
      }
      i = temp + WorkingSet->Wlocalidx[idx - 1];
      if ((i < 1) || (i > 23)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 23, &n_emlrtBCI, &st);
      }
      TrialState->lambda[i - 1] = memspace->workspace_float[idx_max - 1];
      idx_max++;
      idx++;
    }
  }
}

/* End of code generation (relaxed.c) */
