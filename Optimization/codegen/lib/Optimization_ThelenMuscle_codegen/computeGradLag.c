/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeGradLag.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "computeGradLag.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double workspace[299]
 *                int nVar
 *                const double grad[13]
 *                const double AeqTrans[26]
 *                const int finiteLB[13]
 *                int mLB
 *                const int finiteUB[13]
 *                const double lambda[23]
 * Return Type  : void
 */
void b_computeGradLag(double workspace[299], int nVar, const double grad[13],
                      const double AeqTrans[26], const int finiteLB[13],
                      int mLB, const int finiteUB[13], const double lambda[23])
{
  int i;
  int i1;
  int ia;
  int iac;
  int ix;
  i = (unsigned char)nVar;
  memcpy(&workspace[0], &grad[0], (unsigned int)i * sizeof(double));
  ix = 0;
  for (iac = 0; iac <= 13; iac += 13) {
    i = iac + nVar;
    for (ia = iac + 1; ia <= i; ia++) {
      i1 = (ia - iac) - 1;
      workspace[i1] += AeqTrans[ia - 1] * lambda[ix];
    }
    ix++;
  }
  i = (unsigned char)mLB;
  for (ix = 0; ix < i; ix++) {
    i1 = finiteLB[ix];
    workspace[i1 - 1] -= lambda[ix + 2];
  }
  for (ix = 0; ix < 8; ix++) {
    i = finiteUB[ix];
    workspace[i - 1] += lambda[((unsigned char)mLB + ix) + 2];
  }
}

/*
 * Arguments    : double workspace[13]
 *                int nVar
 *                const double grad[13]
 *                const double AeqTrans[26]
 *                const int finiteLB[13]
 *                int mLB
 *                const int finiteUB[13]
 *                const double lambda[23]
 * Return Type  : void
 */
void computeGradLag(double workspace[13], int nVar, const double grad[13],
                    const double AeqTrans[26], const int finiteLB[13], int mLB,
                    const int finiteUB[13], const double lambda[23])
{
  int i;
  int i1;
  int ia;
  int iac;
  int ix;
  i = (unsigned char)nVar;
  memcpy(&workspace[0], &grad[0], (unsigned int)i * sizeof(double));
  ix = 0;
  for (iac = 0; iac <= 13; iac += 13) {
    i = iac + nVar;
    for (ia = iac + 1; ia <= i; ia++) {
      i1 = (ia - iac) - 1;
      workspace[i1] += AeqTrans[ia - 1] * lambda[ix];
    }
    ix++;
  }
  i = (unsigned char)mLB;
  for (ix = 0; ix < i; ix++) {
    i1 = finiteLB[ix];
    workspace[i1 - 1] -= lambda[ix + 2];
  }
  for (ix = 0; ix < 8; ix++) {
    i = finiteUB[ix];
    workspace[i - 1] += lambda[((unsigned char)mLB + ix) + 2];
  }
}

/*
 * File trailer for computeGradLag.c
 *
 * [EOF]
 */
