/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstr.c
 *
 * Code generation for function 'evalObjAndConstr'
 *
 */

/* Include files */
#include "evalObjAndConstr.h"
#include "computeConstraints_.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xf_emlrtRSI = {
    1,                  /* lineNo */
    "evalObjAndConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\evalObjAndConstr.p" /* pathName */
};

/* Function Definitions */
real_T evalObjAndConstr(const emlrtStack *sp,
                        const real_T c_obj_next_next_next_next_next_[16],
                        const real_T d_obj_next_next_next_next_next_[2],
                        const real_T e_obj_next_next_next_next_next_[8],
                        const real_T f_obj_next_next_next_next_next_[8],
                        const real_T g_obj_next_next_next_next_next_[8],
                        const real_T h_obj_next_next_next_next_next_[8],
                        const real_T i_obj_next_next_next_next_next_[8],
                        const real_T j_obj_next_next_next_next_next_[8],
                        const real_T x[8], real_T Ceq_workspace[2],
                        int32_T *status)
{
  __m128d r;
  emlrtStack st;
  real_T y[8];
  real_T fval;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  r = _mm_loadu_pd(&x[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[2]);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[4]);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[6]);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  fval = sumColumnB(y);
  *status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  if (*status == 1) {
    st.site = &xf_emlrtRSI;
    *status = computeConstraints_(
        &st, c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, h_obj_next_next_next_next_next_,
        i_obj_next_next_next_next_next_, j_obj_next_next_next_next_next_, x,
        Ceq_workspace);
  }
  return fval;
}

/* End of code generation (evalObjAndConstr.c) */
