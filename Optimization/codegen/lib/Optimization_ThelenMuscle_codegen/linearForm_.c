/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: linearForm_.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : boolean_T obj_hasLinear
 *                int obj_nvar
 *                double workspace[299]
 *                const double H[64]
 *                const double f[13]
 *                const double x[13]
 * Return Type  : void
 */
void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace[299],
                 const double H[64], const double f[13], const double x[13])
{
  int ia;
  int iac;
  int ix;
  ix = 0;
  if (obj_hasLinear) {
    if (obj_nvar - 1 >= 0) {
      memcpy(&workspace[0], &f[0], (unsigned int)obj_nvar * sizeof(double));
    }
    ix = 1;
  }
  if (obj_nvar != 0) {
    int i;
    if ((ix != 1) && (obj_nvar - 1 >= 0)) {
      memset(&workspace[0], 0, (unsigned int)obj_nvar * sizeof(double));
    }
    ix = 0;
    i = obj_nvar * (obj_nvar - 1) + 1;
    for (iac = 1; obj_nvar < 0 ? iac >= i : iac <= i; iac += obj_nvar) {
      double c;
      int i1;
      c = 0.5 * x[ix];
      i1 = iac + obj_nvar;
      for (ia = iac; ia < i1; ia++) {
        int i2;
        i2 = ia - iac;
        workspace[i2] += H[ia - 1] * c;
      }
      ix++;
    }
  }
}

/*
 * File trailer for linearForm_.c
 *
 * [EOF]
 */
