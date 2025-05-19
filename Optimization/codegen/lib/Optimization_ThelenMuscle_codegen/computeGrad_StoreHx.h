/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeGrad_StoreHx.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef COMPUTEGRAD_STOREHX_H
#define COMPUTEGRAD_STOREHX_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void computeGrad_StoreHx(i_struct_T *obj, const double H[64],
                         const double f[13], const double x[13]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for computeGrad_StoreHx.h
 *
 * [EOF]
 */
