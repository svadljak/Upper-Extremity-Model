/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeFiniteDifferences.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef COMPUTEFINITEDIFFERENCES_H
#define COMPUTEFINITEDIFFERENCES_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T computeFiniteDifferences(d_struct_T *obj, double fCurrent,
                                   const double cEqCurrent[2], double xk[8],
                                   double gradf[13], double JacCeqTrans[26]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for computeFiniteDifferences.h
 *
 * [EOF]
 */
