/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleratiotest.c
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

/* Include files */
#include "feasibleratiotest.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = {
    1,                   /* lineNo */
    "feasibleratiotest", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\feasibleratiotest.p" /* pathName */
};

static emlrtBCInfo le_emlrtBCI = {
    1,                   /* iFirst */
    13,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "feasibleratiotest", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\feasibleratiotest.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
real_T feasibleratiotest(
    const emlrtStack *sp, const real_T solution_xstar[13],
    const real_T solution_searchDir[13], int32_T workingset_nVar,
    const real_T workingset_lb[13], const real_T workingset_ub[13],
    const int32_T workingset_indexLB[13], const int32_T workingset_indexUB[13],
    const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[23],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  emlrtStack st;
  real_T alpha;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  real_T ratio;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  st.site = &we_emlrtRSI;
  denomTol =
      2.2204460492503131E-13 * xnrm2(&st, workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX =
        (real_T)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (real_T)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    i = (uint8_T)(workingset_sizes[3] - 1);
    for (idx = 0; idx < i; idx++) {
      i1 = workingset_indexLB[idx];
      if ((i1 < 1) || (i1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 13, &le_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      pk_corrected = -solution_searchDir[i1 - 1] - phaseOneCorrectionP;
      if (pk_corrected > denomTol) {
        int32_T i2;
        st.site = &we_emlrtRSI;
        i2 = workingset_isActiveIdx[3] + idx;
        if ((i2 < 1) || (i2 > 23)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, 23, &fc_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i2 - 1]) {
          ratio = (-solution_xstar[i1 - 1] - workingset_lb[i1 - 1]) -
                  phaseOneCorrectionX;
          pk_corrected =
              muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
              pk_corrected;
          if (pk_corrected < alpha) {
            alpha = pk_corrected;
            *constrType = 4;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
    i = workingset_indexLB[workingset_sizes[3] - 1];
    if ((i < 1) || (i > 13)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 13, &le_emlrtBCI, (emlrtConstCTX)sp);
    }
    pk_corrected = -solution_searchDir[i - 1];
    if (pk_corrected > denomTol) {
      st.site = &we_emlrtRSI;
      i1 = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((i1 - 1 < 1) || (i1 - 1 > 23)) {
        emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, 23, &fc_emlrtBCI, &st);
      }
      if (!workingset_isActiveConstr[i1 - 2]) {
        ratio = -solution_xstar[i - 1] - workingset_lb[i - 1];
        pk_corrected =
            muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
            pk_corrected;
        if (pk_corrected < alpha) {
          alpha = pk_corrected;
          *constrType = 4;
          *constrIdx = workingset_sizes[3];
          *newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[4] < 8) {
    phaseOneCorrectionX =
        (real_T)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (real_T)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    for (idx = 0; idx < 8; idx++) {
      i = workingset_indexUB[idx];
      if ((i < 1) || (i > 13)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 13, &le_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      pk_corrected = solution_searchDir[i - 1] - phaseOneCorrectionP;
      if (pk_corrected > denomTol) {
        st.site = &we_emlrtRSI;
        i1 = workingset_isActiveIdx[4] + idx;
        if ((i1 < 1) || (i1 > 23)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 23, &fc_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i1 - 1]) {
          ratio = (solution_xstar[i - 1] - workingset_ub[i - 1]) -
                  phaseOneCorrectionX;
          pk_corrected =
              muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
              pk_corrected;
          if (pk_corrected < alpha) {
            alpha = pk_corrected;
            *constrType = 5;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }
  if (!isPhaseOne) {
    if ((*newBlocking) && (alpha > 1.0)) {
      *newBlocking = false;
    }
    alpha = muDoubleScalarMin(alpha, 1.0);
  }
  return alpha;
}

/* End of code generation (feasibleratiotest.c) */
