/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDeltaLag.c
 *
 * Code generation for function 'computeDeltaLag'
 *
 */

/* Include files */
#include "computeDeltaLag.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo cg_emlrtRSI = {
    1,                 /* lineNo */
    "computeDeltaLag", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeDeltaLag.p" /* pathName */
};

/* Function Definitions */
void computeDeltaLag(const emlrtStack *sp, int32_T nVar, real_T workspace[13],
                     const real_T grad[13], const real_T JacEqTrans[26],
                     const real_T grad_old[13], const real_T JacEqTrans_old[26],
                     const real_T lambda[23])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  int32_T k;
  int32_T scalarLB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cg_emlrtRSI;
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
  scalarLB = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)scalarLB * sizeof(real_T));
  scalarLB = (nVar / 2) << 1;
  ix = scalarLB - 2;
  for (k = 0; k <= ix; k += 2) {
    __m128d r;
    r = _mm_loadu_pd(&workspace[k]);
    _mm_storeu_pd(&workspace[k], _mm_sub_pd(r, _mm_loadu_pd(&grad_old[k])));
  }
  for (k = scalarLB; k < nVar; k++) {
    workspace[k] -= grad_old[k];
  }
  st.site = &cg_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  ix = 0;
  c_st.site = &u_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    k = iac + nVar;
    c_st.site = &t_emlrtRSI;
    if ((iac + 1 <= k) && (k > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac + 1; ia <= k; ia++) {
      scalarLB = (ia - iac) - 1;
      workspace[scalarLB] += JacEqTrans[ia - 1] * lambda[ix];
    }
    ix++;
  }
  st.site = &cg_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  ix = 0;
  c_st.site = &u_emlrtRSI;
  for (iac = 0; iac <= 13; iac += 13) {
    k = iac + nVar;
    c_st.site = &t_emlrtRSI;
    if ((iac + 1 <= k) && (k > 2147483646)) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = iac + 1; ia <= k; ia++) {
      scalarLB = (ia - iac) - 1;
      workspace[scalarLB] += JacEqTrans_old[ia - 1] * -lambda[ix];
    }
    ix++;
  }
}

/* End of code generation (computeDeltaLag.c) */
