/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_regularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_regularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_regularized_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T c_maxConstraintViolation_AMats_(const emlrtStack *sp, f_struct_T *obj,
                                       const real_T x[13])
{
  emlrtStack st;
  real_T d;
  real_T v;
  st.prev = sp;
  st.tls = sp->tls;
  obj->maxConstrWorkspace[0] = obj->beq[0];
  obj->maxConstrWorkspace[1] = obj->beq[1];
  st.site = &id_emlrtRSI;
  e_xgemv(&st, 8, obj->Aeq, x, obj->maxConstrWorkspace);
  d = (obj->maxConstrWorkspace[0] - x[8]) + x[10];
  obj->maxConstrWorkspace[0] = d;
  v = muDoubleScalarMax(0.0, muDoubleScalarAbs(d));
  d = (obj->maxConstrWorkspace[1] - x[9]) + x[11];
  obj->maxConstrWorkspace[1] = d;
  return muDoubleScalarMax(v, muDoubleScalarAbs(d));
}

/* End of code generation (maxConstraintViolation_AMats_regularized_.c) */
