/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xpotrf.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int n
 *                double A[529]
 * Return Type  : int
 */
int xpotrf(int n, double A[529])
{
  int ia;
  int iac;
  int info;
  int j;
  int nmj;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= n - 1)) {
    double c;
    double ssq;
    int idxA1j;
    int idxAjj;
    idxA1j = j * 23;
    idxAjj = idxA1j + j;
    ssq = 0.0;
    if (j >= 1) {
      for (nmj = 0; nmj < j; nmj++) {
        c = A[idxA1j + nmj];
        ssq += c * c;
      }
    }
    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = sqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < n) {
        int i;
        int ia0;
        int idxAjjp1;
        nmj = (n - j) - 2;
        ia0 = idxA1j + 24;
        idxAjjp1 = idxAjj + 24;
        if ((j != 0) && (nmj + 1 != 0)) {
          i = (idxA1j + 23 * nmj) + 24;
          for (iac = ia0; iac <= i; iac += 23) {
            int i1;
            c = 0.0;
            i1 = iac + j;
            for (ia = iac; ia < i1; ia++) {
              c += A[ia - 1] * A[(idxA1j + ia) - iac];
            }
            i1 =
                (idxAjj + div_nde_s32_floor((iac - idxA1j) - 24, 23) * 23) + 23;
            A[i1] -= c;
          }
        }
        ssq = 1.0 / ssq;
        i = (idxAjj + 23 * nmj) + 24;
        for (nmj = idxAjjp1; nmj <= i; nmj += 23) {
          A[nmj - 1] *= ssq;
        }
      }
      j++;
    } else {
      A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

/*
 * File trailer for xpotrf.c
 *
 * [EOF]
 */
