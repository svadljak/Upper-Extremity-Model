/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen_terminate.c
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen_terminate'
 *
 */

/* Include files */
#include "Optimization_ThelenMuscle_codegen_terminate.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "_coder_Optimization_ThelenMuscle_codegen_mex.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void emlrtExitTimeCleanupDtorFcn(const void *r);

/* Function Definitions */
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Optimization_ThelenMuscle_codegen_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Optimization_ThelenMuscle_codegen_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Optimization_ThelenMuscle_codegen_terminate.c) */
