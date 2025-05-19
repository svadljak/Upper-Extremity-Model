/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Optimization_ThelenMuscle_codegen_mex.c
 *
 * Code generation for function '_coder_Optimization_ThelenMuscle_codegen_mex'
 *
 */

/* Include files */
#include "_coder_Optimization_ThelenMuscle_codegen_mex.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_initialize.h"
#include "Optimization_ThelenMuscle_codegen_terminate.h"
#include "_coder_Optimization_ThelenMuscle_codegen_api.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void Optimization_ThelenMuscle_codegen_mexFunction(int32_T nlhs,
                                                   mxArray *plhs[1],
                                                   int32_T nrhs,
                                                   const mxArray *prhs[9])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 9) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 9, 4,
                        33, "Optimization_ThelenMuscle_codegen");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 33,
                        "Optimization_ThelenMuscle_codegen");
  }
  /* Call the function. */
  c_Optimization_ThelenMuscle_cod(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Optimization_ThelenMuscle_codegen_atexit);
  Optimization_ThelenMuscle_codegen_initialize();
  Optimization_ThelenMuscle_codegen_mexFunction(nlhs, plhs, nrhs, prhs);
  Optimization_ThelenMuscle_codegen_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1250", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Optimization_ThelenMuscle_codegen_mex.c) */
