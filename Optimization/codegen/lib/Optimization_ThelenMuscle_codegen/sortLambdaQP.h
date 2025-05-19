/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLambdaQP.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef SORTLAMBDAQP_H
#define SORTLAMBDAQP_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void sortLambdaQP(double lambda[23], int WorkingSet_nActiveConstr,
                  const int WorkingSet_sizes[5],
                  const int WorkingSet_isActiveIdx[6],
                  const int WorkingSet_Wid[23],
                  const int WorkingSet_Wlocalidx[23], double workspace[299]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for sortLambdaQP.h
 *
 * [EOF]
 */
