/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveJacobian.h
 *
 * Code generation for function 'saveJacobian'
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
void saveJacobian(const emlrtStack *sp, d_struct_T *obj, int32_T nVar,
                  const real_T JacCeqTrans[26]);

/* End of code generation (saveJacobian.h) */
