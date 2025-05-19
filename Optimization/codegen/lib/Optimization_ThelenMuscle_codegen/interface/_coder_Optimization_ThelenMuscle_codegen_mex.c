/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Optimization_ThelenMuscle_codegen_mex.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "_coder_Optimization_ThelenMuscle_codegen_mex.h"
#include "_coder_Optimization_ThelenMuscle_codegen_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Optimization_ThelenMuscle_codegen_atexit);
  Optimization_ThelenMuscle_codegen_initialize();
  unsafe_Optimization_ThelenMuscle_codegen_mexFunction(nlhs, plhs, nrhs, prhs);
  Optimization_ThelenMuscle_codegen_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1250", true);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[9]
 * Return Type  : void
 */
void unsafe_Optimization_ThelenMuscle_codegen_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[9])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[9];
  const mxArray *outputs;
  int32_T i;
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
  for (i = 0; i < 9; i++) {
    b_prhs[i] = prhs[i];
  }
  c_Optimization_ThelenMuscle_cod(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * File trailer for _coder_Optimization_ThelenMuscle_codegen_mex.c
 *
 * [EOF]
 */
