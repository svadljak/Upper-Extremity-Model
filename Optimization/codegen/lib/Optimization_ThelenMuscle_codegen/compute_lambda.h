/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: compute_lambda.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef COMPUTE_LAMBDA_H
#define COMPUTE_LAMBDA_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void compute_lambda(double workspace[299], c_struct_T *solution,
                    const i_struct_T *objective, const g_struct_T *qrmanager);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for compute_lambda.h
 *
 * [EOF]
 */
