/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveJacobian.c
 *
 * Code generation for function 'saveJacobian'
 *
 */

/* Include files */
#include "saveJacobian.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = {
    1,              /* lineNo */
    "saveJacobian", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "TrialState\\saveJacobian.p" /* pathName */
};

/* Function Definitions */
void saveJacobian(const emlrtStack *sp, d_struct_T *obj, int32_T nVar,
                  const real_T JacCeqTrans[26])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T iCol;
  int32_T idx_col;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ic_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  iCol = -1;
  st.site = &ic_emlrtRSI;
  overflow = (nVar > 2147483646);
  i = (uint8_T)nVar;
  for (idx_col = 0; idx_col < 2; idx_col++) {
    st.site = &ic_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if (overflow) {
      d_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    memcpy(&obj->JacCeqTrans_old[iCol + 1], &JacCeqTrans[iCol + 1],
           (uint32_T)i * sizeof(real_T));
    iCol += 13;
  }
}

/* End of code generation (saveJacobian.c) */
