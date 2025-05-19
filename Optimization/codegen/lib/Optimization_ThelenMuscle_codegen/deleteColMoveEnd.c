/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: deleteColMoveEnd.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "deleteColMoveEnd.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : g_struct_T *obj
 *                int idx
 * Return Type  : void
 */
void deleteColMoveEnd(g_struct_T *obj, int idx)
{
  double s;
  double temp_tmp;
  int b_k;
  int i;
  int k;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }
    idx = i;
  }
  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    int b_i;
    int u0;
    b_i = obj->ncols - 1;
    obj->jpvt[idx - 1] = obj->jpvt[b_i];
    i = obj->minRowCol;
    for (k = 0; k < i; k++) {
      obj->QR[k + 23 * (idx - 1)] = obj->QR[k + 23 * b_i];
    }
    obj->ncols = b_i;
    u0 = obj->mrows;
    i = obj->ncols;
    if (u0 <= i) {
      i = u0;
    }
    obj->minRowCol = i;
    if (idx < obj->mrows) {
      double c;
      double temp;
      int QRk0;
      int b_temp_tmp;
      int endIdx;
      int n;
      u0 = obj->mrows - 1;
      endIdx = obj->ncols;
      if (u0 <= endIdx) {
        endIdx = u0;
      }
      k = endIdx;
      i = 23 * (idx - 1);
      while (k >= idx) {
        b_i = k + i;
        temp_tmp = obj->QR[b_i];
        c = xrotg(&obj->QR[b_i - 1], &temp_tmp, &s);
        obj->QR[b_i] = temp_tmp;
        b_i = 23 * (k - 1);
        obj->QR[k + b_i] = 0.0;
        QRk0 = k + 23 * idx;
        n = obj->ncols - idx;
        if (n >= 1) {
          for (b_k = 0; b_k < n; b_k++) {
            b_temp_tmp = QRk0 + b_k * 23;
            temp_tmp = obj->QR[b_temp_tmp - 1];
            temp = c * temp_tmp + s * obj->QR[b_temp_tmp];
            obj->QR[b_temp_tmp] = c * obj->QR[b_temp_tmp] - s * temp_tmp;
            obj->QR[b_temp_tmp - 1] = temp;
          }
        }
        n = obj->mrows;
        for (b_k = 0; b_k < n; b_k++) {
          b_temp_tmp = b_i + b_k;
          temp_tmp = obj->Q[b_temp_tmp + 23];
          temp = c * obj->Q[b_temp_tmp] + s * temp_tmp;
          obj->Q[b_temp_tmp + 23] = c * temp_tmp - s * obj->Q[b_temp_tmp];
          obj->Q[b_temp_tmp] = temp;
        }
        k--;
      }
      b_i = idx + 1;
      for (k = b_i; k <= endIdx; k++) {
        u0 = 23 * (k - 1);
        i = k + u0;
        temp_tmp = obj->QR[i];
        c = xrotg(&obj->QR[i - 1], &temp_tmp, &s);
        obj->QR[i] = temp_tmp;
        QRk0 = k * 24;
        n = obj->ncols - k;
        if (n >= 1) {
          for (b_k = 0; b_k < n; b_k++) {
            b_temp_tmp = QRk0 + b_k * 23;
            temp_tmp = obj->QR[b_temp_tmp - 1];
            temp = c * temp_tmp + s * obj->QR[b_temp_tmp];
            obj->QR[b_temp_tmp] = c * obj->QR[b_temp_tmp] - s * temp_tmp;
            obj->QR[b_temp_tmp - 1] = temp;
          }
        }
        n = obj->mrows;
        for (b_k = 0; b_k < n; b_k++) {
          b_temp_tmp = u0 + b_k;
          temp_tmp = obj->Q[b_temp_tmp + 23];
          temp = c * obj->Q[b_temp_tmp] + s * temp_tmp;
          obj->Q[b_temp_tmp + 23] = c * temp_tmp - s * obj->Q[b_temp_tmp];
          obj->Q[b_temp_tmp] = temp;
        }
      }
    }
  }
}

/*
 * File trailer for deleteColMoveEnd.c
 *
 * [EOF]
 */
