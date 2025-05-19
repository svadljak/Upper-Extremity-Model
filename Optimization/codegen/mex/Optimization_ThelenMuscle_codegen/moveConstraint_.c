/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * moveConstraint_.c
 *
 * Code generation for function 'moveConstraint_'
 *
 */

/* Include files */
#include "moveConstraint_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yc_emlrtRSI = {
    1,                 /* lineNo */
    "moveConstraint_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\moveConstraint_.p" /* pathName */
};

static emlrtBCInfo vb_emlrtBCI = {
    1,                 /* iFirst */
    23,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "moveConstraint_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\moveConstraint_.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    1,                 /* iFirst */
    23,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "moveConstraint_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\moveConstraint_.p", /* pName */
    3                                /* checkKind */
};

/* Function Definitions */
void moveConstraint_(const emlrtStack *sp, f_struct_T *obj,
                     int32_T idx_global_start, int32_T idx_global_dest)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((idx_global_start < 1) || (idx_global_start > 23)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_start, 1, 23, &vb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((idx_global_dest < 1) || (idx_global_dest > 23)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_dest, 1, 23, &wb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->Wid[idx_global_dest - 1] = obj->Wid[idx_global_start - 1];
  obj->Wlocalidx[idx_global_dest - 1] = obj->Wlocalidx[idx_global_start - 1];
  st.site = &yc_emlrtRSI;
  if (obj->nVar > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)obj->nVar;
  for (idx = 0; idx < i; idx++) {
    obj->ATwset[idx + 13 * (idx_global_dest - 1)] =
        obj->ATwset[idx + 13 * (idx_global_start - 1)];
  }
  obj->bwset[idx_global_dest - 1] = obj->bwset[idx_global_start - 1];
}

/* End of code generation (moveConstraint_.c) */
