/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval_ReuseHx.h
 *
 * Code generation for function 'computeFval_ReuseHx'
 *
 */

#pragma once

/* Include files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T computeFval_ReuseHx(const emlrtStack *sp, const j_struct_T *obj,
                           real_T workspace[299], const real_T f[13],
                           const real_T x[13]);

/* End of code generation (computeFval_ReuseHx.h) */
