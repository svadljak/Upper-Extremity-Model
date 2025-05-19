/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen.c
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen'
 *
 */

/* Include files */
#include "Optimization_ThelenMuscle_codegen.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "driver1.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    22,                                  /* lineNo */
    "Optimization_ThelenMuscle_codegen", /* fcnName */
    "C:\\Users\\jakub\\MATLAB Drive\\GACR_Exoskelety\\01_Planar "
    "Model\\UpperLimb_Exo_ModelReference\\Equations_of_Motion\\Optimalizac"
    "e\\Optimization_ThelenMuscle_codegen.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    1,         /* lineNo */
    "fmincon", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\optim\\eml\\fmincon.p" /* pathName
                                                                         */
};

static emlrtRSInfo d_emlrtRSI = {
    1,                                /* lineNo */
    "evalObjAndConstrAndDerivatives", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\evalObjAndConstrAndDerivatives.p" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    1,               /* lineNo */
    "initActiveSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\initActiveSet.p" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "fmincon", /* fName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\optim\\eml\\fmincon.p" /* pName
                                                                         */
};

static emlrtRTEInfo b_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "checkX0", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "validate\\checkX0.p" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,         /* iFirst */
    8,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "fmincon", /* fName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\optim\\eml\\fmincon.p", /* pName
                                                                          */
    3 /* checkKind */
};

/* Function Definitions */
void Optimization_ThelenMuscle_codegen(const emlrtStack *sp, const real_T Q[16],
                                       const real_T b[2], const real_T Fl[8],
                                       const real_T Fpe[8], const real_T VM[8],
                                       const real_T LM0[8], const real_T a0[8],
                                       const real_T alpha0[8],
                                       const real_T FM0[8],
                                       real_T activation[8])
{
  static const int8_T b_iv[13] = {1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {1, 1, 3, 3, 11, 19};
  static const int8_T iv5[6] = {1, 1, 3, 3, 12, 20};
  static const int8_T iv7[6] = {1, 1, 3, 3, 15, 23};
  static const int8_T iv8[6] = {1, 1, 3, 3, 16, 24};
  static const int8_T iv1[5] = {0, 2, 0, 8, 8};
  static const int8_T iv3[5] = {0, 2, 0, 9, 8};
  static const int8_T iv4[5] = {0, 2, 0, 12, 8};
  static const int8_T iv6[5] = {0, 2, 0, 13, 8};
  __m128d r;
  c_struct_T memspace;
  d_struct_T TrialState;
  e_struct_T FiniteDifferences;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_struct_T WorkingSet;
  g_struct_T MeritFunction;
  h_coder_internal_stickyStruct FcnEvaluator;
  h_struct_T QRManager;
  i_struct_T CholManager;
  j_struct_T QPObjective;
  real_T b_y[8];
  real_T fval;
  int32_T i;
  int32_T i1;
  int32_T iEq0;
  int32_T idx;
  int32_T iw0;
  int8_T b_i;
  boolean_T b_b[8];
  boolean_T c_b[8];
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  /*  Ověření pevné velikosti vstupů */
  /*  Dolní a horní meze */
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  for (i = 0; i < 8; i++) {
    fval = a0[i];
    b_b[i] = muDoubleScalarIsInf(fval);
    c_b[i] = muDoubleScalarIsNaN(fval);
  }
  y = true;
  iw0 = 0;
  exitg1 = false;
  while ((!exitg1) && (iw0 < 8)) {
    if (b_b[iw0] || c_b[iw0]) {
      y = false;
      exitg1 = true;
    } else {
      iw0++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  b_st.site = &b_emlrtRSI;
  TrialState.sqpFval_old = 0.0;
  TrialState.sqpIterations = 0;
  memset(&TrialState.lambdasqp[0], 0, 23U * sizeof(real_T));
  TrialState.steplength = 1.0;
  memset(&TrialState.delta_x[0], 0, 13U * sizeof(real_T));
  TrialState.fstar = 0.0;
  memset(&TrialState.lambda[0], 0, 23U * sizeof(real_T));
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
  memcpy(&TrialState.xstarsqp[0], &a0[0], 8U * sizeof(real_T));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Q[0],
         &Q[0], 16U * sizeof(real_T));
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b[0] = b[0];
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b[1] = b[1];
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fl[0],
         &Fl[0], 8U * sizeof(real_T));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fpe[0],
      &Fpe[0], 8U * sizeof(real_T));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.VM[0],
         &VM[0], 8U * sizeof(real_T));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.LM0[0],
      &LM0[0], 8U * sizeof(real_T));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace
              .alpha0[0],
         &alpha0[0], 8U * sizeof(real_T));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.FM0[0],
      &FM0[0], 8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.Q[0], &Q[0], 16U * sizeof(real_T));
  FiniteDifferences.nonlin.workspace.b[0] = b[0];
  FiniteDifferences.nonlin.workspace.b[1] = b[1];
  memcpy(&FiniteDifferences.nonlin.workspace.Fl[0], &Fl[0],
         8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.Fpe[0], &Fpe[0],
         8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.VM[0], &VM[0],
         8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.LM0[0], &LM0[0],
         8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.alpha0[0], &alpha0[0],
         8U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.FM0[0], &FM0[0],
         8U * sizeof(real_T));
  FiniteDifferences.f_1 = 0.0;
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.hasBounds = true;
  WorkingSet.mConstr = 18;
  WorkingSet.nVar = 8;
  WorkingSet.beq[0] = 0.0;
  WorkingSet.beq[1] = 0.0;
  for (i = 0; i < 13; i++) {
    WorkingSet.lb[i] = 0.0;
    WorkingSet.ub[i] = 0.0;
    b_i = b_iv[i];
    WorkingSet.indexLB[i] = b_i;
    WorkingSet.indexUB[i] = b_i;
  }
  WorkingSet.mEqRemoved = 0;
  WorkingSet.indexEqRemoved[0] = 0;
  WorkingSet.indexEqRemoved[1] = 0;
  memset(&WorkingSet.ATwset[0], 0, 299U * sizeof(real_T));
  WorkingSet.nActiveConstr = 0;
  memset(&WorkingSet.bwset[0], 0, 23U * sizeof(real_T));
  memset(&WorkingSet.maxConstrWorkspace[0], 0, 23U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    b_i = iv1[i];
    WorkingSet.sizes[i] = b_i;
    WorkingSet.sizesNormal[i] = b_i;
    WorkingSet.sizesPhaseOne[i] = iv3[i];
    WorkingSet.sizesRegularized[i] = iv4[i];
    WorkingSet.sizesRegPhaseOne[i] = iv6[i];
  }
  for (i = 0; i < 6; i++) {
    b_i = iv2[i];
    WorkingSet.isActiveIdx[i] = b_i;
    WorkingSet.isActiveIdxNormal[i] = b_i;
    WorkingSet.isActiveIdxPhaseOne[i] = iv5[i];
    WorkingSet.isActiveIdxRegularized[i] = iv7[i];
    WorkingSet.isActiveIdxRegPhaseOne[i] = iv8[i];
  }
  memset(&WorkingSet.Wid[0], 0, 23U * sizeof(int32_T));
  memset(&WorkingSet.Wlocalidx[0], 0, 23U * sizeof(int32_T));
  for (i = 0; i < 23; i++) {
    WorkingSet.isActiveConstr[i] = false;
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.nWConstr[i] = 0;
  }
  WorkingSet.probType = 3;
  for (idx = 0; idx < 8; idx++) {
    b_i = b_iv[idx];
    if (b_i < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 8, &emlrtBCI, &st);
    }
    TrialState.xstarsqp[b_i - 1] =
        muDoubleScalarMax(TrialState.xstarsqp[b_i - 1], 0.0);
  }
  for (idx = 0; idx < 8; idx++) {
    b_i = b_iv[idx];
    if (b_i < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 8, &emlrtBCI, &st);
    }
    TrialState.xstarsqp[b_i - 1] =
        muDoubleScalarMin(TrialState.xstarsqp[b_i - 1], 1.0);
  }
  b_st.site = &b_emlrtRSI;
  r = _mm_loadu_pd(&TrialState.xstarsqp[0]);
  _mm_storeu_pd(&b_y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[2]);
  _mm_storeu_pd(&b_y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[4]);
  _mm_storeu_pd(&b_y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[6]);
  _mm_storeu_pd(&b_y[6], _mm_mul_pd(r, r));
  fval = sumColumnB(b_y);
  iw0 = 1;
  y = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || y) {
    if (y) {
      iw0 = -3;
    } else if (fval < 0.0) {
      iw0 = -1;
    } else {
      iw0 = -2;
    }
  }
  TrialState.sqpFval = fval;
  if (iw0 == 1) {
    c_st.site = &d_emlrtRSI;
    iw0 = computeConstraints_(
        &c_st,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Q,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fl,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fpe,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.VM,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.LM0,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.alpha0,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.FM0,
        TrialState.xstarsqp, TrialState.cEq);
  }
  if (iw0 != 1) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "optim_codegen:fmincon:UndefAtX0",
                                  "optim_codegen:fmincon:UndefAtX0", 0);
  }
  memset(&WorkingSet.Aeq[0], 0, 26U * sizeof(real_T));
  b_st.site = &b_emlrtRSI;
  computeFiniteDifferences(&FiniteDifferences, fval, TrialState.cEq,
                           TrialState.xstarsqp, TrialState.grad,
                           WorkingSet.Aeq);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  b_st.site = &b_emlrtRSI;
  r = _mm_loadu_pd(&TrialState.cEq[0]);
  r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
  _mm_storeu_pd(&WorkingSet.beq[0], r);
  _mm_storeu_pd(&WorkingSet.bwset[0], r);
  iw0 = 1;
  iEq0 = 1;
  for (idx = 0; idx < 2; idx++) {
    for (i = 0; i < 8; i++) {
      i1 = iEq0 + i;
      if ((i1 < 1) || (i1 > 26)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 26, &b_emlrtBCI, &b_st);
      }
      WorkingSet.ATwset[i1 - 1] = WorkingSet.Aeq[i1 - 1];
    }
    iEq0 = iw0 + 13;
    iw0 += 13;
  }
  for (idx = 0; idx < 8; idx++) {
    if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, 13, &c_emlrtBCI,
                                    &b_st);
    }
    WorkingSet.lb[WorkingSet.indexLB[idx] - 1] =
        a0[WorkingSet.indexLB[idx] - 1];
  }
  for (idx = 0; idx < 8; idx++) {
    if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, 13, &c_emlrtBCI,
                                    &b_st);
    }
    WorkingSet.ub[WorkingSet.indexUB[idx] - 1] =
        1.0 - a0[WorkingSet.indexUB[idx] - 1];
  }
  b_st.site = &b_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  setProblemType(&c_st, &WorkingSet, 3);
  for (idx = 0; idx < 21; idx++) {
    WorkingSet.isActiveConstr[idx + 2] = false;
  }
  WorkingSet.nWConstr[0] = 0;
  WorkingSet.nWConstr[1] = 2;
  WorkingSet.nWConstr[2] = 0;
  WorkingSet.nWConstr[3] = 0;
  WorkingSet.nWConstr[4] = 0;
  WorkingSet.nActiveConstr = 2;
  i1 = WorkingSet.nVar;
  for (iEq0 = 0; iEq0 < 2; iEq0++) {
    WorkingSet.Wid[iEq0] = 2;
    WorkingSet.Wlocalidx[iEq0] = iEq0 + 1;
    WorkingSet.isActiveConstr[iEq0] = true;
    iw0 = 13 * iEq0;
    memcpy(&WorkingSet.ATwset[iw0], &WorkingSet.Aeq[iw0],
           (uint32_T)i1 * sizeof(real_T));
    WorkingSet.bwset[iEq0] = WorkingSet.beq[iEq0];
  }
  real_T Hessian[64];
  MeritFunction.initFval = fval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = muDoubleScalarAbs(TrialState.cEq[0]) +
                                        muDoubleScalarAbs(TrialState.cEq[1]);
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  b_st.site = &b_emlrtRSI;
  b_driver(&b_st, &TrialState, &MeritFunction, &FcnEvaluator,
           &FiniteDifferences, &memspace, &WorkingSet, Hessian, &QRManager,
           &CholManager, &QPObjective);
  memcpy(&activation[0], &TrialState.xstarsqp[0], 8U * sizeof(real_T));
}

/* End of code generation (Optimization_ThelenMuscle_codegen.c) */
