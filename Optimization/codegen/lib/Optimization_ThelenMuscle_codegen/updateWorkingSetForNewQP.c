/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateWorkingSetForNewQP.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "updateWorkingSetForNewQP.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double xk[8]
 *                e_struct_T *WorkingSet
 *                const double cEq[2]
 *                int mLB
 * Return Type  : void
 */
void updateWorkingSetForNewQP(const double xk[8], e_struct_T *WorkingSet,
                              const double cEq[2], int mLB)
{
  int b_i;
  int i;
  int iEq0;
  int idx;
  int iw0;
  iw0 = 0;
  iEq0 = 0;
  for (idx = 0; idx < 2; idx++) {
    double d;
    d = cEq[idx];
    WorkingSet->beq[idx] = -d;
    WorkingSet->bwset[idx] = -d;
    i = WorkingSet->nVar;
    for (b_i = 0; b_i < i; b_i++) {
      WorkingSet->ATwset[iw0 + b_i] = WorkingSet->Aeq[iEq0 + b_i];
    }
    iEq0 = iw0 + 13;
    iw0 += 13;
  }
  i = (unsigned char)mLB;
  for (idx = 0; idx < i; idx++) {
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        xk[WorkingSet->indexLB[idx] - 1];
  }
  for (idx = 0; idx < 8; idx++) {
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        1.0 - xk[WorkingSet->indexUB[idx] - 1];
  }
  if (WorkingSet->nActiveConstr > 2) {
    i = WorkingSet->nActiveConstr;
    for (idx = 3; idx <= i; idx++) {
      switch (WorkingSet->Wid[idx - 1]) {
      case 4:
        WorkingSet->bwset[idx - 1] =
            WorkingSet
                ->lb[WorkingSet->indexLB[WorkingSet->Wlocalidx[idx - 1] - 1] -
                     1];
        break;
      case 5:
        WorkingSet->bwset[idx - 1] =
            WorkingSet
                ->ub[WorkingSet->indexUB[WorkingSet->Wlocalidx[idx - 1] - 1] -
                     1];
        break;
      default:
        /* A check that is always false is detected at compile-time. Eliminating
         * code that follows. */
        break;
      }
    }
  }
}

/*
 * File trailer for updateWorkingSetForNewQP.c
 *
 * [EOF]
 */
