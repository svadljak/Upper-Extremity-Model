/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: solve.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "solve.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const h_struct_T *obj
 *                double rhs[13]
 * Return Type  : void
 */
void solve(const h_struct_T *obj, double rhs[13])
{
  int i;
  int j;
  int jA;
  int n_tmp;
  n_tmp = obj->ndims;
  if (obj->ndims != 0) {
    for (j = 0; j < n_tmp; j++) {
      double temp;
      jA = j * 23;
      temp = rhs[j];
      for (i = 0; i < j; i++) {
        temp -= obj->FMat[jA + i] * rhs[i];
      }
      rhs[j] = temp / obj->FMat[jA + j];
    }
  }
  if (obj->ndims != 0) {
    for (j = n_tmp; j >= 1; j--) {
      jA = (j + (j - 1) * 23) - 1;
      rhs[j - 1] /= obj->FMat[jA];
      for (i = 0; i <= j - 2; i++) {
        int ix;
        ix = (j - i) - 2;
        rhs[ix] -= rhs[j - 1] * obj->FMat[(jA - i) - 1];
      }
    }
  }
}

/*
 * File trailer for solve.c
 *
 * [EOF]
 */
