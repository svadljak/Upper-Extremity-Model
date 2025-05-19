/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: factorQRE.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "factorQRE.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : g_struct_T *obj
 *                const double A[299]
 *                int mrows
 *                int ncols
 * Return Type  : void
 */
void factorQRE(g_struct_T *obj, const double A[299], int mrows, int ncols)
{
  int idx;
  int k;
  int y;
  boolean_T guard1;
  y = mrows * ncols;
  guard1 = false;
  if (y > 0) {
    for (idx = 0; idx < ncols; idx++) {
      int ix0;
      int iy0;
      ix0 = 13 * idx;
      iy0 = 23 * idx;
      y = (unsigned char)mrows;
      for (k = 0; k < y; k++) {
        obj->QR[iy0 + k] = A[ix0 + k];
      }
    }
    guard1 = true;
  } else if (y == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      y = mrows;
    } else {
      y = ncols;
    }
    obj->minRowCol = y;
    xgeqp3(obj->QR, mrows, ncols, obj->jpvt, obj->tau);
  }
}

/*
 * File trailer for factorQRE.c
 *
 * [EOF]
 */
