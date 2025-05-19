/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeMeritFcn.c
 *
 * Code generation for function 'computeMeritFcn'
 *
 */

/* Include files */
#include "computeMeritFcn.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T computeMeritFcn(real_T obj_penaltyParam, real_T fval,
                       const real_T Ceq_workspace[2], boolean_T evalWellDefined)
{
  real_T val;
  if (evalWellDefined) {
    val = fval + obj_penaltyParam * (muDoubleScalarAbs(Ceq_workspace[0]) +
                                     muDoubleScalarAbs(Ceq_workspace[1]));
  } else {
    val = rtInf;
  }
  return val;
}

/* End of code generation (computeMeritFcn.c) */
