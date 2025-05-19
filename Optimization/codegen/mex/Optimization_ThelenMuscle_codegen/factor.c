/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factor.c
 *
 * Code generation for function 'factor'
 *
 */

/* Include files */
#include "factor.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xpotrf.h"
#include <string.h>

/* Function Definitions */
void factor(const emlrtStack *sp, i_struct_T *obj, const real_T A[64],
            int32_T ndims, int32_T ldA)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->ndims = ndims;
  st.site = &ee_emlrtRSI;
  if (ndims > 2147483646) {
    b_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = 0; idx < ndims; idx++) {
    st.site = &ee_emlrtRSI;
    g_xcopy(&st, ndims, A, ldA * idx + 1, obj->FMat, 23 * idx + 1);
  }
  st.site = &ee_emlrtRSI;
  obj->info = xpotrf(&st, ndims, obj->FMat);
}

/* End of code generation (factor.c) */
