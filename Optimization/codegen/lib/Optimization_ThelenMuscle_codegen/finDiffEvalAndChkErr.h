/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: finDiffEvalAndChkErr.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef FINDIFFEVALANDCHKERR_H
#define FINDIFFEVALANDCHKERR_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T finDiffEvalAndChkErr(const double obj_nonlin_workspace_Q[16],
                               const double obj_nonlin_workspace_b[2],
                               const double obj_nonlin_workspace_Fl[8],
                               const double obj_nonlin_workspace_Fpe[8],
                               const double obj_nonlin_workspace_VM[8],
                               const double obj_nonlin_workspace_LM0[8],
                               const double obj_nonlin_workspace_alpha0[8],
                               const double obj_nonlin_workspace_FM0[8],
                               double cEqPlus[2], int dim, double delta,
                               double xk[8], double *fplus);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for finDiffEvalAndChkErr.h
 *
 * [EOF]
 */
