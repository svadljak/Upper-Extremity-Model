/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linearForm_.c
 *
 * Code generation for function 'linearForm_'
 *
 */

/* Include files */
#include "linearForm_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ff_emlrtRSI = {
    1,             /* lineNo */
    "linearForm_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\linearForm_.p" /* pathName */
};

static emlrtBCInfo nd_emlrtBCI = {
    1,             /* iFirst */
    13,            /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "linearForm_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\linearForm_.p", /* pName */
    0                           /* checkKind */
};

/* Function Definitions */
void linearForm_(const emlrtStack *sp, boolean_T obj_hasLinear,
                 int32_T obj_nvar, real_T workspace[299], const real_T H[64],
                 const real_T f[13], const real_T x[13])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  ix = 0;
  if (obj_hasLinear) {
    st.site = &ff_emlrtRSI;
    if (obj_nvar > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (ix = 0; ix < obj_nvar; ix++) {
      if ((ix + 1 < 1) || (ix + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(ix + 1, 1, 13, &nd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[ix] = f[ix];
    }
    ix = 1;
  }
  st.site = &ff_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  if (obj_nvar != 0) {
    int32_T b_tmp;
    boolean_T overflow;
    if (ix != 1) {
      c_st.site = &tb_emlrtRSI;
      if (obj_nvar > 2147483646) {
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      if (obj_nvar - 1 >= 0) {
        memset(&workspace[0], 0, (uint32_T)obj_nvar * sizeof(real_T));
      }
    }
    ix = 0;
    b_tmp = obj_nvar * (obj_nvar - 1) + 1;
    c_st.site = &u_emlrtRSI;
    if ((obj_nvar == 0) || ((obj_nvar > 0) && (b_tmp < 1)) ||
        ((obj_nvar < 0) && (b_tmp > 1))) {
      overflow = false;
    } else if (obj_nvar > 0) {
      overflow = (b_tmp > MAX_int32_T - obj_nvar);
    } else {
      overflow = (b_tmp < MIN_int32_T - obj_nvar);
    }
    if (obj_nvar == 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (iac = 1; obj_nvar < 0 ? iac >= b_tmp : iac <= b_tmp; iac += obj_nvar) {
      real_T c;
      int32_T b;
      c = 0.5 * x[ix];
      b = (iac + obj_nvar) - 1;
      c_st.site = &t_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ia = iac; ia <= b; ia++) {
        int32_T i;
        i = ia - iac;
        workspace[i] += H[ia - 1] * c;
      }
      ix++;
    }
  }
}

/* End of code generation (linearForm_.c) */
