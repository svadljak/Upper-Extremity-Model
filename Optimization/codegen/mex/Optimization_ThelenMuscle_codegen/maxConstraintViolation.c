/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation.c
 *
 * Code generation for function 'maxConstraintViolation'
 *
 */

/* Include files */
#include "maxConstraintViolation.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "maxConstraintViolation_AMats_regularized_.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T b_maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                                const real_T x[299])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T idx;
  int32_T idxUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->probType == 2) {
    real_T d;
    st.site = &hd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->beq[0];
    obj->maxConstrWorkspace[1] = obj->beq[1];
    b_st.site = &id_emlrtRSI;
    d_xgemv(&b_st, 8, obj->Aeq, x, obj->maxConstrWorkspace);
    d = (obj->maxConstrWorkspace[0] - x[31]) + x[33];
    obj->maxConstrWorkspace[0] = d;
    v = muDoubleScalarMax(0.0, muDoubleScalarAbs(d));
    d = (obj->maxConstrWorkspace[1] - x[32]) + x[34];
    obj->maxConstrWorkspace[1] = d;
    v = muDoubleScalarMax(v, muDoubleScalarAbs(d));
  } else {
    st.site = &hd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->beq[0];
    obj->maxConstrWorkspace[1] = obj->beq[1];
    b_st.site = &kd_emlrtRSI;
    d_xgemv(&b_st, obj->nVar, obj->Aeq, x, obj->maxConstrWorkspace);
    v = muDoubleScalarMax(
        muDoubleScalarMax(0.0, muDoubleScalarAbs(obj->maxConstrWorkspace[0])),
        muDoubleScalarAbs(obj->maxConstrWorkspace[1]));
  }
  st.site = &hd_emlrtRSI;
  if (obj->sizes[3] > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  idxUB = (uint8_T)obj->sizes[3];
  for (idx = 0; idx < idxUB; idx++) {
    int32_T idxLB;
    idxLB = obj->indexLB[idx];
    if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, -x[idxLB + 22] - obj->lb[idxLB - 1]);
  }
  st.site = &hd_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    idxUB = obj->indexUB[idx];
    if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, x[idxUB + 22] - obj->ub[idxUB - 1]);
  }
  return v;
}

real_T c_maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                                const real_T x[13])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T idx;
  int32_T mLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mLB = obj->sizes[3];
  if (obj->probType == 2) {
    st.site = &hd_emlrtRSI;
    v = c_maxConstraintViolation_AMats_(&st, obj, x);
  } else {
    st.site = &hd_emlrtRSI;
    v = d_maxConstraintViolation_AMats_(&st, obj, x);
  }
  st.site = &hd_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  mLB = (uint8_T)mLB;
  for (idx = 0; idx < mLB; idx++) {
    int32_T idxLB;
    idxLB = obj->indexLB[idx] - 1;
    if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
  }
  st.site = &hd_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    mLB = obj->indexUB[idx] - 1;
    if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, x[mLB] - obj->ub[mLB]);
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, f_struct_T *obj,
                              const real_T x[299])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T idx;
  int32_T idxUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->probType == 2) {
    real_T d;
    st.site = &hd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->beq[0];
    obj->maxConstrWorkspace[1] = obj->beq[1];
    b_st.site = &id_emlrtRSI;
    c_xgemv(&b_st, 8, obj->Aeq, x, obj->maxConstrWorkspace);
    d = (obj->maxConstrWorkspace[0] - x[8]) + x[10];
    obj->maxConstrWorkspace[0] = d;
    v = muDoubleScalarMax(0.0, muDoubleScalarAbs(d));
    d = (obj->maxConstrWorkspace[1] - x[9]) + x[11];
    obj->maxConstrWorkspace[1] = d;
    v = muDoubleScalarMax(v, muDoubleScalarAbs(d));
  } else {
    st.site = &hd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->beq[0];
    obj->maxConstrWorkspace[1] = obj->beq[1];
    b_st.site = &kd_emlrtRSI;
    c_xgemv(&b_st, obj->nVar, obj->Aeq, x, obj->maxConstrWorkspace);
    v = muDoubleScalarMax(
        muDoubleScalarMax(0.0, muDoubleScalarAbs(obj->maxConstrWorkspace[0])),
        muDoubleScalarAbs(obj->maxConstrWorkspace[1]));
  }
  st.site = &hd_emlrtRSI;
  if (obj->sizes[3] > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  idxUB = (uint8_T)obj->sizes[3];
  for (idx = 0; idx < idxUB; idx++) {
    int32_T idxLB;
    idxLB = obj->indexLB[idx] - 1;
    if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
  }
  st.site = &hd_emlrtRSI;
  for (idx = 0; idx < 8; idx++) {
    idxUB = obj->indexUB[idx] - 1;
    if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 13, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    v = muDoubleScalarMax(v, x[idxUB] - obj->ub[idxUB]);
  }
  return v;
}

/* End of code generation (maxConstraintViolation.c) */
