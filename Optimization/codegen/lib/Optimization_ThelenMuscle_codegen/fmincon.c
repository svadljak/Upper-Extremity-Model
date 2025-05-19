/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fmincon.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "fmincon.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "driver1.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x0[8]
 *                const double nonlcon_workspace_Q[16]
 *                const double nonlcon_workspace_b[2]
 *                const double nonlcon_workspace_Fl[8]
 *                const double nonlcon_workspace_Fpe[8]
 *                const double nonlcon_workspace_VM[8]
 *                const double nonlcon_workspace_LM0[8]
 *                const double nonlcon_workspace_alpha0[8]
 *                const double nonlcon_workspace_FM0[8]
 *                double x[8]
 * Return Type  : void
 */
void fmincon(const double x0[8], const double nonlcon_workspace_Q[16],
             const double nonlcon_workspace_b[2],
             const double nonlcon_workspace_Fl[8],
             const double nonlcon_workspace_Fpe[8],
             const double nonlcon_workspace_VM[8],
             const double nonlcon_workspace_LM0[8],
             const double nonlcon_workspace_alpha0[8],
             const double nonlcon_workspace_FM0[8], double x[8])
{
  static const signed char b_iv[13] = {1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0};
  static const signed char iv2[6] = {1, 1, 3, 3, 11, 19};
  static const signed char iv5[6] = {1, 1, 3, 3, 12, 20};
  static const signed char iv7[6] = {1, 1, 3, 3, 15, 23};
  static const signed char iv8[6] = {1, 1, 3, 3, 16, 24};
  static const signed char iv1[5] = {0, 2, 0, 8, 8};
  static const signed char iv3[5] = {0, 2, 0, 9, 8};
  static const signed char iv4[5] = {0, 2, 0, 12, 8};
  static const signed char iv6[5] = {0, 2, 0, 13, 8};
  b_struct_T memspace;
  c_struct_T TrialState;
  d_struct_T FiniteDifferences;
  e_struct_T WorkingSet;
  f_struct_T MeritFunction;
  g_struct_T QRManager;
  h_coder_internal_stickyStruct FcnEvaluator;
  h_struct_T CholManager;
  i_struct_T QPObjective;
  double y[8];
  double fval;
  int i;
  int i1;
  int iEq0;
  int idx;
  signed char b_i;
  boolean_T b;
  TrialState.sqpFval_old = 0.0;
  TrialState.sqpIterations = 0;
  memset(&TrialState.lambdasqp[0], 0, 23U * sizeof(double));
  TrialState.steplength = 1.0;
  memset(&TrialState.delta_x[0], 0, 13U * sizeof(double));
  TrialState.fstar = 0.0;
  memset(&TrialState.lambda[0], 0, 23U * sizeof(double));
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
  memcpy(&TrialState.xstarsqp[0], &x0[0], 8U * sizeof(double));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Q[0],
         &nonlcon_workspace_Q[0], 16U * sizeof(double));
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b[0] =
      nonlcon_workspace_b[0];
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b[1] =
      nonlcon_workspace_b[1];
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fl[0],
         &nonlcon_workspace_Fl[0], 8U * sizeof(double));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fpe[0],
      &nonlcon_workspace_Fpe[0], 8U * sizeof(double));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace.VM[0],
         &nonlcon_workspace_VM[0], 8U * sizeof(double));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.LM0[0],
      &nonlcon_workspace_LM0[0], 8U * sizeof(double));
  memcpy(&FcnEvaluator.next.next.next.next.next.next.next.value.workspace
              .alpha0[0],
         &nonlcon_workspace_alpha0[0], 8U * sizeof(double));
  memcpy(
      &FcnEvaluator.next.next.next.next.next.next.next.value.workspace.FM0[0],
      &nonlcon_workspace_FM0[0], 8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.Q[0], &nonlcon_workspace_Q[0],
         16U * sizeof(double));
  FiniteDifferences.nonlin.workspace.b[0] = nonlcon_workspace_b[0];
  FiniteDifferences.nonlin.workspace.b[1] = nonlcon_workspace_b[1];
  memcpy(&FiniteDifferences.nonlin.workspace.Fl[0], &nonlcon_workspace_Fl[0],
         8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.Fpe[0], &nonlcon_workspace_Fpe[0],
         8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.VM[0], &nonlcon_workspace_VM[0],
         8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.LM0[0], &nonlcon_workspace_LM0[0],
         8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.alpha0[0],
         &nonlcon_workspace_alpha0[0], 8U * sizeof(double));
  memcpy(&FiniteDifferences.nonlin.workspace.FM0[0], &nonlcon_workspace_FM0[0],
         8U * sizeof(double));
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
  memset(&WorkingSet.ATwset[0], 0, 299U * sizeof(double));
  WorkingSet.nActiveConstr = 0;
  memset(&WorkingSet.bwset[0], 0, 23U * sizeof(double));
  memset(&WorkingSet.maxConstrWorkspace[0], 0, 23U * sizeof(double));
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
  memset(&WorkingSet.Wid[0], 0, 23U * sizeof(int));
  memset(&WorkingSet.Wlocalidx[0], 0, 23U * sizeof(int));
  for (i = 0; i < 23; i++) {
    WorkingSet.isActiveConstr[i] = false;
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.nWConstr[i] = 0;
  }
  WorkingSet.probType = 3;
  for (idx = 0; idx < 8; idx++) {
    i1 = b_iv[idx] - 1;
    TrialState.xstarsqp[i1] = fmax(TrialState.xstarsqp[i1], 0.0);
  }
  for (idx = 0; idx < 8; idx++) {
    i1 = b_iv[idx] - 1;
    TrialState.xstarsqp[i1] = fmin(TrialState.xstarsqp[i1], 1.0);
  }
  __m128d r;
  r = _mm_loadu_pd(&TrialState.xstarsqp[0]);
  _mm_storeu_pd(&x[0], r);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[2]);
  _mm_storeu_pd(&x[2], r);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[4]);
  _mm_storeu_pd(&x[4], r);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&TrialState.xstarsqp[6]);
  _mm_storeu_pd(&x[6], r);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  fval = y[0];
  for (i = 0; i < 7; i++) {
    fval += y[i + 1];
  }
  i = 1;
  b = rtIsNaN(fval);
  if (rtIsInf(fval) || b) {
    if (b) {
      i = -3;
    } else if (fval < 0.0) {
      i = -1;
    } else {
      i = -2;
    }
  }
  TrialState.sqpFval = fval;
  if (i == 1) {
    computeConstraints_(
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Q,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.b,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fl,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.Fpe,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.VM,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.LM0,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.alpha0,
        FcnEvaluator.next.next.next.next.next.next.next.value.workspace.FM0, x,
        TrialState.cEq);
  }
  memset(&WorkingSet.Aeq[0], 0, 26U * sizeof(double));
  computeFiniteDifferences(&FiniteDifferences, fval, TrialState.cEq,
                           TrialState.xstarsqp, TrialState.grad,
                           WorkingSet.Aeq);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  i = 0;
  iEq0 = 0;
  for (idx = 0; idx < 2; idx++) {
    double d;
    d = TrialState.cEq[idx];
    WorkingSet.beq[idx] = -d;
    WorkingSet.bwset[idx] = -d;
    memcpy(&WorkingSet.ATwset[i], &WorkingSet.Aeq[iEq0], 8U * sizeof(double));
    iEq0 = i + 13;
    i += 13;
  }
  for (idx = 0; idx < 8; idx++) {
    WorkingSet.lb[WorkingSet.indexLB[idx] - 1] =
        x0[WorkingSet.indexLB[idx] - 1];
    WorkingSet.ub[WorkingSet.indexUB[idx] - 1] =
        1.0 - x0[WorkingSet.indexUB[idx] - 1];
  }
  setProblemType(&WorkingSet, 3);
  for (idx = 0; idx < 21; idx++) {
    WorkingSet.isActiveConstr[idx + 2] = false;
  }
  WorkingSet.nWConstr[0] = 0;
  WorkingSet.nWConstr[1] = 2;
  WorkingSet.nWConstr[2] = 0;
  WorkingSet.nWConstr[3] = 0;
  WorkingSet.nWConstr[4] = 0;
  WorkingSet.nActiveConstr = 2;
  MeritFunction.initFval = fval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  fval = 0.0;
  i1 = WorkingSet.nVar;
  for (i = 0; i < 2; i++) {
    WorkingSet.Wid[i] = 2;
    WorkingSet.Wlocalidx[i] = i + 1;
    WorkingSet.isActiveConstr[i] = true;
    iEq0 = 13 * i;
    memcpy(&WorkingSet.ATwset[iEq0], &WorkingSet.Aeq[iEq0],
           (unsigned int)i1 * sizeof(double));
    WorkingSet.bwset[i] = WorkingSet.beq[i];
    fval += fabs(TrialState.cEq[i]);
  }
  double Hessian[64];
  MeritFunction.initConstrViolationEq = fval;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  b_driver(&TrialState, &MeritFunction, &FcnEvaluator, &FiniteDifferences,
           &memspace, &WorkingSet, Hessian, &QRManager, &CholManager,
           &QPObjective);
  memcpy(&x[0], &TrialState.xstarsqp[0], 8U * sizeof(double));
}

/*
 * File trailer for fmincon.c
 *
 * [EOF]
 */
