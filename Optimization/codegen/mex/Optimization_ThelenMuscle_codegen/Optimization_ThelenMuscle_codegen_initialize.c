/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen_initialize.c
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen_initialize'
 *
 */

/* Include files */
#include "Optimization_ThelenMuscle_codegen_initialize.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "_coder_Optimization_ThelenMuscle_codegen_mex.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void Optimization_ThelenMuscle_codegen_once(void);

/* Function Definitions */
static void Optimization_ThelenMuscle_codegen_once(void)
{
  mex_InitInfAndNan();
}

void Optimization_ThelenMuscle_codegen_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "optimization_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Optimization_ThelenMuscle_codegen_once();
  }
}

/* End of code generation (Optimization_ThelenMuscle_codegen_initialize.c) */
