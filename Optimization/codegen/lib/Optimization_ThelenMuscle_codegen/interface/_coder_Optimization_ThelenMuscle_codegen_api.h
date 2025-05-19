/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Optimization_ThelenMuscle_codegen_api.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef _CODER_OPTIMIZATION_THELENMUSCLE_CODEGEN_API_H
#define _CODER_OPTIMIZATION_THELENMUSCLE_CODEGEN_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Optimization_ThelenMuscle_codegen(real_T Q[16], real_T b[2], real_T Fl[8],
                                       real_T Fpe[8], real_T VM[8],
                                       real_T LM0[8], real_T a0[8],
                                       real_T alpha0[8], real_T FM0[8],
                                       real_T activation[8]);

void Optimization_ThelenMuscle_codegen_atexit(void);

void Optimization_ThelenMuscle_codegen_initialize(void);

void Optimization_ThelenMuscle_codegen_terminate(void);

void Optimization_ThelenMuscle_codegen_xil_shutdown(void);

void Optimization_ThelenMuscle_codegen_xil_terminate(void);

void c_Optimization_ThelenMuscle_cod(const mxArray *const prhs[9],
                                     const mxArray **plhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Optimization_ThelenMuscle_codegen_api.h
 *
 * [EOF]
 */
