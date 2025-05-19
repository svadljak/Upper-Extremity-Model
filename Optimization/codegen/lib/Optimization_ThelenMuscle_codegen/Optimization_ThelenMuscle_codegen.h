/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Optimization_ThelenMuscle_codegen.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef OPTIMIZATION_THELENMUSCLE_CODEGEN_H
#define OPTIMIZATION_THELENMUSCLE_CODEGEN_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
Optimization_ThelenMuscle_codegen(const double Q[16], const double b[2],
                                  const double Fl[8], const double Fpe[8],
                                  const double VM[8], const double LM0[8],
                                  const double a0[8], const double alpha0[8],
                                  const double FM0[8], double activation[8]);

void c_Optimization_ThelenMuscle_cod(const double Q[16], const double b[2],
                                     const double Fl[8], const double Fpe[8],
                                     const double VM[8], const double LM0[8],
                                     const double alpha0[8],
                                     const double FM0[8], const double a[8],
                                     double varargout_2[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Optimization_ThelenMuscle_codegen.h
 *
 * [EOF]
 */
