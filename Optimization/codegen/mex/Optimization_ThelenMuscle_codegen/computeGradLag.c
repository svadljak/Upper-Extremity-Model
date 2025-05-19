/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    1,                /* lineNo */
    "computeGradLag", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p" /* pathName */
};

static emlrtBCInfo je_emlrtBCI = {
    1,                /* iFirst */
    23,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    3                             /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = {
    1,                /* iFirst */
    299,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    3                             /* checkKind */
};

/* Function Definitions */
void b_computeGradLag(const emlrtStack *sp, real_T workspace[299], int32_T nVar,
                      const real_T grad[13], const real_T AeqTrans[26],
                      const int32_T finiteLB[13], int32_T mLB,
                      const int32_T finiteUB[13], const real_T lambda[23])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)i * sizeof(real_T));
  st.site = &r_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  ix = 0;
  c_st.site = &u_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    b = iac + nVar;
    c_st.site = &t_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      i = (ia - iac) - 1;
      workspace[i] += AeqTrans[ia - 1] * lambda[ix];
    }
    ix++;
  }
  st.site = &r_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (b = 0; b < i; b++) {
    if (b + 3 > 23) {
      emlrtDynamicBoundsCheckR2012b(b + 3, 1, 23, &je_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ix = finiteLB[b];
    if ((ix < 1) || (ix > 299)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 299, &oe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    workspace[ix - 1] -= lambda[b + 2];
  }
  st.site = &r_emlrtRSI;
  for (b = 0; b < 8; b++) {
    i = ((uint8_T)mLB + b) + 3;
    if (i > 23) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 23, &je_emlrtBCI, (emlrtConstCTX)sp);
    }
    ix = finiteUB[b];
    if ((ix < 1) || (ix > 299)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 299, &oe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    workspace[ix - 1] += lambda[i - 1];
  }
}

void computeGradLag(const emlrtStack *sp, real_T workspace[13], int32_T nVar,
                    const real_T grad[13], const real_T AeqTrans[26],
                    const int32_T finiteLB[13], int32_T mLB,
                    const int32_T finiteUB[13], const real_T lambda[23])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)i * sizeof(real_T));
  st.site = &r_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  ix = 0;
  c_st.site = &u_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    b = iac + nVar;
    c_st.site = &t_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      i = (ia - iac) - 1;
      workspace[i] += AeqTrans[ia - 1] * lambda[ix];
    }
    ix++;
  }
  st.site = &r_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (b = 0; b < i; b++) {
    if (b + 3 > 23) {
      emlrtDynamicBoundsCheckR2012b(b + 3, 1, 23, &je_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ix = finiteLB[b];
    if ((ix < 1) || (ix > 13)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 13, &ke_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ix - 1] -= lambda[b + 2];
  }
  st.site = &r_emlrtRSI;
  for (b = 0; b < 8; b++) {
    i = ((uint8_T)mLB + b) + 3;
    if (i > 23) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 23, &je_emlrtBCI, (emlrtConstCTX)sp);
    }
    ix = finiteUB[b];
    if ((ix < 1) || (ix > 13)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 13, &ke_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ix - 1] += lambda[i - 1];
  }
}

/* End of code generation (computeGradLag.c) */
