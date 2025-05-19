/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assignResidualsToXSlack.h
 *
 * Code generation for function 'assignResidualsToXSlack'
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
void assignResidualsToXSlack(const emlrtStack *sp, int32_T nVarOrig,
                             f_struct_T *WorkingSet, d_struct_T *TrialState,
                             c_struct_T *memspace);

/* End of code generation (assignResidualsToXSlack.h) */
