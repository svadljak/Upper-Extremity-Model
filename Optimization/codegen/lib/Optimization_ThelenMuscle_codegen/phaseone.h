/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: phaseone.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef PHASEONE_H
#define PHASEONE_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void phaseone(const double H[64], const double f[13], c_struct_T *solution,
              b_struct_T *memspace, e_struct_T *workingset,
              g_struct_T *qrmanager, h_struct_T *cholmanager,
              i_struct_T *objective, const char options_SolverName[7],
              const k_struct_T *runTimeOptions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for phaseone.h
 *
 * [EOF]
 */
