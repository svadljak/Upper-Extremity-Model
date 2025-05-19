/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLambdaQP.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "sortLambdaQP.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double lambda[23]
 *                int WorkingSet_nActiveConstr
 *                const int WorkingSet_sizes[5]
 *                const int WorkingSet_isActiveIdx[6]
 *                const int WorkingSet_Wid[23]
 *                const int WorkingSet_Wlocalidx[23]
 *                double workspace[299]
 * Return Type  : void
 */
void sortLambdaQP(double lambda[23], int WorkingSet_nActiveConstr,
                  const int WorkingSet_sizes[5],
                  const int WorkingSet_isActiveIdx[6],
                  const int WorkingSet_Wid[23],
                  const int WorkingSet_Wlocalidx[23], double workspace[299])
{
  if (WorkingSet_nActiveConstr != 0) {
    int idx;
    int mAll;
    mAll = WorkingSet_sizes[3] + 9;
    idx = (unsigned char)(WorkingSet_sizes[3] + 10);
    memcpy(&workspace[0], &lambda[0], (unsigned int)idx * sizeof(double));
    if (mAll >= 0) {
      memset(&lambda[0], 0, (unsigned int)(mAll + 1) * sizeof(double));
    }
    mAll = 0;
    idx = 0;
    while ((idx + 1 <= WorkingSet_nActiveConstr) &&
           (WorkingSet_Wid[idx] <= 2)) {
      lambda[WorkingSet_Wlocalidx[idx] - 1] = workspace[mAll];
      mAll++;
      idx++;
    }
    while (idx + 1 <= WorkingSet_nActiveConstr) {
      int idxOffset;
      switch (WorkingSet_Wid[idx]) {
      case 3:
        idxOffset = 3;
        break;
      case 4:
        idxOffset = 3;
        break;
      default:
        idxOffset = WorkingSet_isActiveIdx[4];
        break;
      }
      lambda[(idxOffset + WorkingSet_Wlocalidx[idx]) - 2] = workspace[mAll];
      mAll++;
      idx++;
    }
  }
}

/*
 * File trailer for sortLambdaQP.c
 *
 * [EOF]
 */
