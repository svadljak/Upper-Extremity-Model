/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.c
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

/* Include files */
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
boolean_T finDiffEvalAndChkErr(const real_T obj_nonlin_workspace_Q[16],
                               const real_T obj_nonlin_workspace_b[2],
                               const real_T obj_nonlin_workspace_Fl[8],
                               const real_T obj_nonlin_workspace_Fpe[8],
                               const real_T obj_nonlin_workspace_VM[8],
                               const real_T obj_nonlin_workspace_LM0[8],
                               const real_T obj_nonlin_workspace_alpha0[8],
                               const real_T obj_nonlin_workspace_FM0[8],
                               real_T cEqPlus[2], int32_T dim, real_T delta,
                               real_T xk[8], real_T *fplus)
{
  __m128d r;
  real_T VMmax[8];
  real_T temp_tmp;
  int32_T i;
  int32_T k;
  boolean_T evalOK;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  r = _mm_loadu_pd(&xk[0]);
  _mm_storeu_pd(&VMmax[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[2]);
  _mm_storeu_pd(&VMmax[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[4]);
  _mm_storeu_pd(&VMmax[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&xk[6]);
  _mm_storeu_pd(&VMmax[6], _mm_mul_pd(r, r));
  *fplus = sumColumnB(VMmax);
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    real_T fvm;
    /*  a shape factor for the force-velocity relationship */
    /*  maximum normalized muscle force achievable when the fiber is lengthening
     */
    for (k = 0; k < 8; k++) {
      real_T d;
      real_T d1;
      fvm = 10.0 * obj_nonlin_workspace_LM0[k];
      d = obj_nonlin_workspace_VM[k];
      if (d <= 0.0) {
        real_T fvm_tmp;
        d1 = xk[k];
        fvm_tmp = 3.0 * d1 + 1.0;
        fvm =
            0.3 * (4.0 * d + fvm * fvm_tmp) / (-4.0 * d + fvm * 0.3 * fvm_tmp);
      } else {
        real_T fvm_tmp;
        d1 = xk[k];
        fvm_tmp = 0.3 * fvm * (((3.0 * d1 * 1.4 - 3.0 * d1) + 1.4) - 1.0);
        fvm = (fvm_tmp + 8.0 * d * 1.4 * 1.3) / (fvm_tmp + 8.0 * d * 1.3);
      }
      /*  Fm(k) = a*Fl(k)*fvm + Fpe(k); */
      fvm = obj_nonlin_workspace_FM0[k] *
            (d1 * obj_nonlin_workspace_Fl[k] * fvm +
             obj_nonlin_workspace_Fpe[k]) *
            muDoubleScalarCos(obj_nonlin_workspace_alpha0[k]);
      VMmax[k] = fvm;
      if (fvm <= 0.0) {
        VMmax[k] = 0.0;
      }
    }
    for (k = 0; k < 2; k++) {
      fvm = 0.0;
      for (i = 0; i < 8; i++) {
        fvm += obj_nonlin_workspace_Q[k + (i << 1)] * VMmax[i];
      }
      cEqPlus[k] = fvm - obj_nonlin_workspace_b[k];
    }
    k = 0;
    while (evalOK && (k + 1 <= 2)) {
      evalOK = ((!muDoubleScalarIsInf(cEqPlus[k])) &&
                (!muDoubleScalarIsNaN(cEqPlus[k])));
      k++;
    }
    xk[dim - 1] = temp_tmp;
  }
  return evalOK;
}

/* End of code generation (finDiffEvalAndChkErr.c) */
