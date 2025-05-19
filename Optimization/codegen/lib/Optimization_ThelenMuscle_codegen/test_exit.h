/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: test_exit.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef TEST_EXIT_H
#define TEST_EXIT_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_test_exit(j_struct_T *Flags, b_struct_T *memspace,
                 f_struct_T *MeritFunction, e_struct_T *WorkingSet,
                 c_struct_T *TrialState, g_struct_T *QRManager);

boolean_T test_exit(f_struct_T *MeritFunction, const e_struct_T *WorkingSet,
                    c_struct_T *TrialState, boolean_T *Flags_fevalOK,
                    boolean_T *Flags_done, boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int *Flags_stepType);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for test_exit.h
 *
 * [EOF]
 */
