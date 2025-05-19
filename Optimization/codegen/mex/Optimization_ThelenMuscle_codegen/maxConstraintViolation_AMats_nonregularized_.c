/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_nonregularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_nonregularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T d_maxConstraintViolation_AMats_(const emlrtStack *sp, f_struct_T *obj,
                                       const real_T x[13])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  obj->maxConstrWorkspace[0] = obj->beq[0];
  obj->maxConstrWorkspace[1] = obj->beq[1];
  st.site = &kd_emlrtRSI;
  e_xgemv(&st, obj->nVar, obj->Aeq, x, obj->maxConstrWorkspace);
  return muDoubleScalarMax(
      muDoubleScalarMax(0.0, muDoubleScalarAbs(obj->maxConstrWorkspace[0])),
      muDoubleScalarAbs(obj->maxConstrWorkspace[1]));
}

/* End of code generation (maxConstraintViolation_AMats_nonregularized_.c) */
