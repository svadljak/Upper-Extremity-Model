/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: evalObjAndConstr.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "evalObjAndConstr.h"
#include "computeConstraints_.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double c_obj_next_next_next_next_next_[16]
 *                const double d_obj_next_next_next_next_next_[2]
 *                const double e_obj_next_next_next_next_next_[8]
 *                const double f_obj_next_next_next_next_next_[8]
 *                const double g_obj_next_next_next_next_next_[8]
 *                const double h_obj_next_next_next_next_next_[8]
 *                const double i_obj_next_next_next_next_next_[8]
 *                const double j_obj_next_next_next_next_next_[8]
 *                const double x[8]
 *                double Ceq_workspace[2]
 *                int *status
 * Return Type  : double
 */
double evalObjAndConstr(const double c_obj_next_next_next_next_next_[16],
                        const double d_obj_next_next_next_next_next_[2],
                        const double e_obj_next_next_next_next_next_[8],
                        const double f_obj_next_next_next_next_next_[8],
                        const double g_obj_next_next_next_next_next_[8],
                        const double h_obj_next_next_next_next_next_[8],
                        const double i_obj_next_next_next_next_next_[8],
                        const double j_obj_next_next_next_next_next_[8],
                        const double x[8], double Ceq_workspace[2], int *status)
{
  __m128d r;
  double y[8];
  double fval;
  int k;
  boolean_T b;
  r = _mm_loadu_pd(&x[0]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[2]);
  _mm_storeu_pd(&y[2], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[4]);
  _mm_storeu_pd(&y[4], _mm_mul_pd(r, r));
  r = _mm_loadu_pd(&x[6]);
  _mm_storeu_pd(&y[6], _mm_mul_pd(r, r));
  fval = y[0];
  for (k = 0; k < 7; k++) {
    fval += y[k + 1];
  }
  *status = 1;
  b = rtIsNaN(fval);
  if (rtIsInf(fval) || b) {
    if (b) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  if (*status == 1) {
    *status = computeConstraints_(
        c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, h_obj_next_next_next_next_next_,
        i_obj_next_next_next_next_next_, j_obj_next_next_next_next_next_, x,
        Ceq_workspace);
  }
  return fval;
}

/*
 * File trailer for evalObjAndConstr.c
 *
 * [EOF]
 */
