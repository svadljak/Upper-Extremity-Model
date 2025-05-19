/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * solve1.c
 *
 * Code generation for function 'solve1'
 *
 */

/* Include files */
#include "solve1.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo oe_emlrtRSI = {
    44,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    53,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtBCInfo ed_emlrtBCI = {
    1,       /* iFirst */
    13,      /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    3                                 /* checkKind */
};

/* Function Definitions */
void b_solve(const emlrtStack *sp, const i_struct_T *obj, real_T rhs[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T jjA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &ke_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &oe_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 23;
      b = jA - j;
      c_st.site = &pe_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i = 0; i < b; i++) {
        int32_T ix;
        ix = (j + i) + 1;
        rhs[ix] -= rhs[j] * obj->FMat[(jjA + i) + 1];
      }
    }
  }
  b = obj->ndims;
  st.site = &ne_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < b; jA++) {
    if ((jA + 1 < 1) || (jA + 1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 13, &ed_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rhs[jA] /= obj->FMat[jA + 23 * jA];
  }
  if (obj->ndims != 0) {
    for (j = b; j >= 1; j--) {
      real_T temp;
      jA = (j - 1) * 23;
      temp = rhs[j - 1];
      jjA = j + 1;
      for (i = b; i >= jjA; i--) {
        temp -= obj->FMat[(jA + i) - 1] * rhs[i - 1];
      }
      rhs[j - 1] = temp;
    }
  }
}

/* End of code generation (solve1.c) */
