/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feasibleratiotest.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef FEASIBLERATIOTEST_H
#define FEASIBLERATIOTEST_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double feasibleratiotest(
    const double solution_xstar[13], const double solution_searchDir[13],
    int workingset_nVar, const double workingset_lb[13],
    const double workingset_ub[13], const int workingset_indexLB[13],
    const int workingset_indexUB[13], const int workingset_sizes[5],
    const int workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[23],
    const int workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T *newBlocking, int *constrType, int *constrIdx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for feasibleratiotest.h
 *
 * [EOF]
 */
