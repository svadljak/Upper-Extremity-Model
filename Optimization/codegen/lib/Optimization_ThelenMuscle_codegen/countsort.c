/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: countsort.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "countsort.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int x[23]
 *                int xLen
 *                int workspace[23]
 *                int xMin
 *                int xMax
 * Return Type  : void
 */
void countsort(int x[23], int xLen, int workspace[23], int xMin, int xMax)
{
  int idx;
  int idxFill;
  if ((xLen > 1) && (xMax > xMin)) {
    int i;
    int idxEnd;
    int idxStart;
    i = xMax - xMin;
    if (i >= 0) {
      memset(&workspace[0], 0, (unsigned int)(i + 1) * sizeof(int));
    }
    for (idx = 0; idx < xLen; idx++) {
      idxStart = x[idx] - xMin;
      workspace[idxStart]++;
    }
    for (idx = 2; idx <= i + 1; idx++) {
      workspace[idx - 1] += workspace[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    for (idx = 0; idx < i; idx++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = idx + xMin;
      }
      idxStart = workspace[idx] + 1;
      idxEnd = workspace[idx + 1];
    }
    for (idx = idxStart; idx <= idxEnd; idx++) {
      x[idx - 1] = xMax;
    }
  }
}

/*
 * File trailer for countsort.c
 *
 * [EOF]
 */
