/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * solve.c
 *
 * Code generation for function 'solve'
 *
 */

/* Include files */
#include "solve.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fc_emlrtRSI = {
    37,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    65,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    72,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

/* Function Definitions */
void solve(const emlrtStack *sp, const i_struct_T *obj, real_T rhs[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T n_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &je_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  n_tmp = obj->ndims;
  b_st.site = &ke_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &le_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j < n_tmp; j++) {
      real_T temp;
      jA = j * 23;
      temp = rhs[j];
      c_st.site = &me_emlrtRSI;
      if (j > 2147483646) {
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i = 0; i < j; i++) {
        temp -= obj->FMat[jA + i] * rhs[i];
      }
      rhs[j] = temp / obj->FMat[jA + j];
    }
  }
  st.site = &je_emlrtRSI;
  b_st.site = &ke_emlrtRSI;
  if (obj->ndims != 0) {
    for (j = n_tmp; j >= 1; j--) {
      jA = (j + (j - 1) * 23) - 1;
      rhs[j - 1] /= obj->FMat[jA];
      c_st.site = &fc_emlrtRSI;
      for (i = 0; i <= j - 2; i++) {
        int32_T ix;
        ix = (j - i) - 2;
        rhs[ix] -= rhs[j - 1] * obj->FMat[(jA - i) - 1];
      }
    }
  }
}

/* End of code generation (solve.c) */
