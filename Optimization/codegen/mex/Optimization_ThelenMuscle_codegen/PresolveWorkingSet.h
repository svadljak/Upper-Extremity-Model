/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PresolveWorkingSet.h
 *
 * Code generation for function 'PresolveWorkingSet'
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
void PresolveWorkingSet(const emlrtStack *sp, d_struct_T *solution,
                        c_struct_T *memspace, f_struct_T *workingset,
                        h_struct_T *qrmanager);

/* End of code generation (PresolveWorkingSet.h) */
