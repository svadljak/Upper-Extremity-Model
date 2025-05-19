/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: compute_deltax.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef COMPUTE_DELTAX_H
#define COMPUTE_DELTAX_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void compute_deltax(const double H[64], c_struct_T *solution,
                    b_struct_T *memspace, const g_struct_T *qrmanager,
                    h_struct_T *cholmanager, const i_struct_T *objective,
                    boolean_T alwaysPositiveDef);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for compute_deltax.h
 *
 * [EOF]
 */
