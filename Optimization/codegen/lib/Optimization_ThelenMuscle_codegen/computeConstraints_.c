/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeConstraints_.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "computeConstraints_.h"
#include "Optimization_ThelenMuscle_codegen.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
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
 * Return Type  : int
 */
int computeConstraints_(const double c_obj_next_next_next_next_next_[16],
                        const double d_obj_next_next_next_next_next_[2],
                        const double e_obj_next_next_next_next_next_[8],
                        const double f_obj_next_next_next_next_next_[8],
                        const double g_obj_next_next_next_next_next_[8],
                        const double h_obj_next_next_next_next_next_[8],
                        const double i_obj_next_next_next_next_next_[8],
                        const double j_obj_next_next_next_next_next_[8],
                        const double x[8], double Ceq_workspace[2])
{
  int idx_current;
  int status;
  boolean_T allFinite;
  c_Optimization_ThelenMuscle_cod(
      c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
      e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
      g_obj_next_next_next_next_next_, h_obj_next_next_next_next_next_,
      i_obj_next_next_next_next_next_, j_obj_next_next_next_next_next_, x,
      Ceq_workspace);
  status = 1;
  allFinite = true;
  idx_current = 0;
  while (allFinite && (idx_current + 1 <= 2)) {
    allFinite = ((!rtIsInf(Ceq_workspace[idx_current])) &&
                 (!rtIsNaN(Ceq_workspace[idx_current])));
    idx_current++;
  }
  if (!allFinite) {
    idx_current--;
    if (rtIsNaN(Ceq_workspace[idx_current])) {
      status = -3;
    } else if (Ceq_workspace[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  return status;
}

/*
 * File trailer for computeConstraints_.c
 *
 * [EOF]
 */
