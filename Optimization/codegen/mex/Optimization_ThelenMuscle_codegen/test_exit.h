/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_exit.h
 *
 * Code generation for function 'test_exit'
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
void b_test_exit(const emlrtStack *sp, struct_T *Flags, c_struct_T *memspace,
                 g_struct_T *MeritFunction, f_struct_T *WorkingSet,
                 d_struct_T *TrialState, h_struct_T *QRManager);

boolean_T test_exit(const emlrtStack *sp, g_struct_T *MeritFunction,
                    const f_struct_T *WorkingSet, d_struct_T *TrialState,
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType);

/* End of code generation (test_exit.h) */
