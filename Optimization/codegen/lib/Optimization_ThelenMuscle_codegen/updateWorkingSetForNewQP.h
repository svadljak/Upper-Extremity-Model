/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateWorkingSetForNewQP.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef UPDATEWORKINGSETFORNEWQP_H
#define UPDATEWORKINGSETFORNEWQP_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void updateWorkingSetForNewQP(const double xk[8], e_struct_T *WorkingSet,
                              const double cEq[2], int mLB);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for updateWorkingSetForNewQP.h
 *
 * [EOF]
 */
