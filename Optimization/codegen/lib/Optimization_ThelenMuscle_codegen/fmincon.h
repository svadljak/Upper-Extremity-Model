/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fmincon.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef FMINCON_H
#define FMINCON_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void fmincon(const double x0[8], const double nonlcon_workspace_Q[16],
             const double nonlcon_workspace_b[2],
             const double nonlcon_workspace_Fl[8],
             const double nonlcon_workspace_Fpe[8],
             const double nonlcon_workspace_VM[8],
             const double nonlcon_workspace_LM0[8],
             const double nonlcon_workspace_alpha0[8],
             const double nonlcon_workspace_FM0[8], double x[8]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for fmincon.h
 *
 * [EOF]
 */
