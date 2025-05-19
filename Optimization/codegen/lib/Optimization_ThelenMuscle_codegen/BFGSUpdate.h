/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BFGSUpdate.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef BFGSUPDATE_H
#define BFGSUPDATE_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T BFGSUpdate(int nvar, double Bk[64], const double sk[13],
                     double yk[13], double workspace[299]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for BFGSUpdate.h
 *
 * [EOF]
 */
