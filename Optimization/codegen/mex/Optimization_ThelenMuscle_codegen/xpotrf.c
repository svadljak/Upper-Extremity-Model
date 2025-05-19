/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xpotrf.c
 *
 * Code generation for function 'xpotrf'
 *
 */

/* Include files */
#include "xpotrf.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = {
    79,             /* lineNo */
    "ceval_xpotrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xpotrf.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    13,       /* lineNo */
    "xpotrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xpotrf.m" /* pathName */
};

/* Function Definitions */
int32_T xpotrf(const emlrtStack *sp, int32_T n, real_T A[529])
{
  static const char_T fname[19] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'p', 'o', 't', 'r', 'f',
                                   '_', 'w', 'o', 'r', 'k'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ge_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)n, &A[0], (ptrdiff_t)23);
  b_st.site = &fe_emlrtRSI;
  if ((int32_T)info_t < 0) {
    if ((int32_T)info_t == -1010) {
      emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                    "Coder:toolbox:LAPACKCallErrorInfo",
                                    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                    19, &fname[0], 12, (int32_T)info_t);
    }
  }
  return (int32_T)info_t;
}

/* End of code generation (xpotrf.c) */
