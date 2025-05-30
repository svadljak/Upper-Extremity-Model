/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feasibleratiotest.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "feasibleratiotest.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double solution_xstar[13]
 *                const double solution_searchDir[13]
 *                int workingset_nVar
 *                const double workingset_lb[13]
 *                const double workingset_ub[13]
 *                const int workingset_indexLB[13]
 *                const int workingset_indexUB[13]
 *                const int workingset_sizes[5]
 *                const int workingset_isActiveIdx[6]
 *                const boolean_T workingset_isActiveConstr[23]
 *                const int workingset_nWConstr[5]
 *                boolean_T isPhaseOne
 *                boolean_T *newBlocking
 *                int *constrType
 *                int *constrIdx
 * Return Type  : double
 */
double feasibleratiotest(
    const double solution_xstar[13], const double solution_searchDir[13],
    int workingset_nVar, const double workingset_lb[13],
    const double workingset_ub[13], const int workingset_indexLB[13],
    const int workingset_indexUB[13], const int workingset_sizes[5],
    const int workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[23],
    const int workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T *newBlocking, int *constrType, int *constrIdx)
{
  double alpha;
  double denomTol;
  double phaseOneCorrectionP;
  double phaseOneCorrectionX;
  double pk_corrected;
  double ratio;
  int i;
  int idx;
  alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol =
      2.2204460492503131E-13 * b_xnrm2(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX =
        (double)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (double)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    i = (unsigned char)(workingset_sizes[3] - 1);
    for (idx = 0; idx < i; idx++) {
      int i1;
      i1 = workingset_indexLB[idx];
      pk_corrected = -solution_searchDir[i1 - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + idx) - 1])) {
        ratio = (-solution_xstar[i1 - 1] - workingset_lb[i1 - 1]) -
                phaseOneCorrectionX;
        pk_corrected = fmin(fabs(ratio), 1.0E-6 - ratio) / pk_corrected;
        if (pk_corrected < alpha) {
          alpha = pk_corrected;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }
    i = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    pk_corrected = -solution_searchDir[i];
    if ((pk_corrected > denomTol) &&
        (!workingset_isActiveConstr
             [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[i] - workingset_lb[i];
      pk_corrected = fmin(fabs(ratio), 1.0E-6 - ratio) / pk_corrected;
      if (pk_corrected < alpha) {
        alpha = pk_corrected;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }
  if (workingset_nWConstr[4] < 8) {
    phaseOneCorrectionX =
        (double)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (double)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    for (idx = 0; idx < 8; idx++) {
      i = workingset_indexUB[idx];
      pk_corrected = solution_searchDir[i - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + idx) - 1])) {
        ratio = (solution_xstar[i - 1] - workingset_ub[i - 1]) -
                phaseOneCorrectionX;
        pk_corrected = fmin(fabs(ratio), 1.0E-6 - ratio) / pk_corrected;
        if (pk_corrected < alpha) {
          alpha = pk_corrected;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }
  }
  if (!isPhaseOne) {
    if ((*newBlocking) && (alpha > 1.0)) {
      *newBlocking = false;
    }
    alpha = fmin(alpha, 1.0);
  }
  return alpha;
}

/*
 * File trailer for feasibleratiotest.c
 *
 * [EOF]
 */
