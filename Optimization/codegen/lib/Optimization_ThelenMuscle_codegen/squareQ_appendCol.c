/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: squareQ_appendCol.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "squareQ_appendCol.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : g_struct_T *obj
 *                const double vec[299]
 *                int iv0
 * Return Type  : void
 */
void squareQ_appendCol(g_struct_T *obj, const double vec[299], int iv0)
{
  double b_temp_tmp;
  double c;
  double s;
  int Qk0;
  int i;
  int idx;
  int iyend;
  int k;
  int temp_tmp;
  iyend = obj->mrows;
  Qk0 = obj->ncols + 1;
  if (iyend <= Qk0) {
    Qk0 = iyend;
  }
  obj->minRowCol = Qk0;
  Qk0 = 23 * obj->ncols;
  if (obj->mrows != 0) {
    iyend = Qk0 + obj->mrows;
    if (Qk0 + 1 <= iyend) {
      memset(&obj->QR[Qk0], 0, (unsigned int)(iyend - Qk0) * sizeof(double));
    }
    i = 23 * (obj->mrows - 1) + 1;
    for (iyend = 1; iyend <= i; iyend += 23) {
      c = 0.0;
      temp_tmp = iyend + obj->mrows;
      for (idx = iyend; idx < temp_tmp; idx++) {
        c += obj->Q[idx - 1] * vec[((iv0 + idx) - iyend) - 1];
      }
      temp_tmp = Qk0 + div_nde_s32_floor(iyend - 1, 23);
      obj->QR[temp_tmp] += c;
    }
  }
  obj->ncols++;
  i = obj->ncols - 1;
  obj->jpvt[i] = obj->ncols;
  for (idx = obj->mrows - 2; idx + 2 > obj->ncols; idx--) {
    temp_tmp = idx + 23 * i;
    b_temp_tmp = obj->QR[temp_tmp + 1];
    c = xrotg(&obj->QR[temp_tmp], &b_temp_tmp, &s);
    obj->QR[temp_tmp + 1] = b_temp_tmp;
    Qk0 = 23 * idx;
    iyend = obj->mrows;
    if (obj->mrows >= 1) {
      for (k = 0; k < iyend; k++) {
        double temp;
        temp_tmp = Qk0 + k;
        b_temp_tmp = obj->Q[temp_tmp + 23];
        temp = c * obj->Q[temp_tmp] + s * b_temp_tmp;
        obj->Q[temp_tmp + 23] = c * b_temp_tmp - s * obj->Q[temp_tmp];
        obj->Q[temp_tmp] = temp;
      }
    }
  }
}

/*
 * File trailer for squareQ_appendCol.c
 *
 * [EOF]
 */
