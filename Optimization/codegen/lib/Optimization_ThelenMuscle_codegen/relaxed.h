/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: relaxed.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef RELAXED_H
#define RELAXED_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void relaxed(const double Hessian[64], const double grad[13],
             c_struct_T *TrialState, f_struct_T *MeritFunction,
             b_struct_T *memspace, e_struct_T *WorkingSet,
             g_struct_T *QRManager, h_struct_T *CholManager,
             i_struct_T *QPObjective, k_struct_T *qpoptions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for relaxed.h
 *
 * [EOF]
 */
