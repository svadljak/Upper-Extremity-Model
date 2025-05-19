/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQRE.c
 *
 * Code generation for function 'factorQRE'
 *
 */

/* Include files */
#include "factorQRE.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void factorQRE(const emlrtStack *sp, h_struct_T *obj, const real_T A[299],
               int32_T mrows, int32_T ncols)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    st.site = &db_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < ncols; idx++) {
      st.site = &db_emlrtRSI;
      c_xcopy(&st, mrows, A, 13 * idx + 1, obj->QR, 23 * idx + 1);
    }
    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = muIntScalarMin_sint32(mrows, ncols);
    st.site = &db_emlrtRSI;
    xgeqp3(&st, obj->QR, mrows, ncols, obj->jpvt, obj->tau);
  }
}

/* End of code generation (factorQRE.c) */
