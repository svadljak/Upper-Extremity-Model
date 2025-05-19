/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeGradLag.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef COMPUTEGRADLAG_H
#define COMPUTEGRADLAG_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_computeGradLag(double workspace[299], int nVar, const double grad[13],
                      const double AeqTrans[26], const int finiteLB[13],
                      int mLB, const int finiteUB[13], const double lambda[23]);

void computeGradLag(double workspace[13], int nVar, const double grad[13],
                    const double AeqTrans[26], const int finiteLB[13], int mLB,
                    const int finiteUB[13], const double lambda[23]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for computeGradLag.h
 *
 * [EOF]
 */
