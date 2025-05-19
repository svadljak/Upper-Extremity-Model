/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: finDiffEvalAndChkErr.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "finDiffEvalAndChkErr.h"
#include "Optimization_ThelenMuscle_codegen.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double obj_nonlin_workspace_Q[16]
 *                const double obj_nonlin_workspace_b[2]
 *                const double obj_nonlin_workspace_Fl[8]
 *                const double obj_nonlin_workspace_Fpe[8]
 *                const double obj_nonlin_workspace_VM[8]
 *                const double obj_nonlin_workspace_LM0[8]
 *                const double obj_nonlin_workspace_alpha0[8]
 *                const double obj_nonlin_workspace_FM0[8]
 *                double cEqPlus[2]
 *                int dim
 *                double delta
 *                double xk[8]
 *                double *fplus
 * Return Type  : boolean_T
 */
boolean_T finDiffEvalAndChkErr(const double obj_nonlin_workspace_Q[16],
                               const double obj_nonlin_workspace_b[2],
                               const double obj_nonlin_workspace_Fl[8],
                               const double obj_nonlin_workspace_Fpe[8],
                               const double obj_nonlin_workspace_VM[8],
                               const double obj_nonlin_workspace_LM0[8],
                               const double obj_nonlin_workspace_alpha0[8],
                               const double obj_nonlin_workspace_FM0[8],
                               double cEqPlus[2], int dim, double delta,
                               double xk[8], double *fplus)
{
  __m128d r;
  double y[8];
  double temp_tmp;
  int idx;
  boolean_T evalOK;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  r = _mm_loadu_pd(&xk[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[2]);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[4]);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[6]);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  *fplus = y[0];
  for (idx = 0; idx < 7; idx++) {
    *fplus += y[idx + 1];
  }
  evalOK = ((!rtIsInf(*fplus)) && (!rtIsNaN(*fplus)));
  if (evalOK) {
    c_Optimization_ThelenMuscle_cod(
        obj_nonlin_workspace_Q, obj_nonlin_workspace_b, obj_nonlin_workspace_Fl,
        obj_nonlin_workspace_Fpe, obj_nonlin_workspace_VM,
        obj_nonlin_workspace_LM0, obj_nonlin_workspace_alpha0,
        obj_nonlin_workspace_FM0, xk, cEqPlus);
    idx = 0;
    while (evalOK && (idx + 1 <= 2)) {
      evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
      idx++;
    }
    xk[dim - 1] = temp_tmp;
  }
  return evalOK;
}

/*
 * File trailer for finDiffEvalAndChkErr.c
 *
 * [EOF]
 */
