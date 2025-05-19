/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: driver.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "driver.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "PresolveWorkingSet.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "linearForm_.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double H[64]
 *                const double f[13]
 *                c_struct_T *solution
 *                b_struct_T *memspace
 *                e_struct_T *workingset
 *                g_struct_T *qrmanager
 *                h_struct_T *cholmanager
 *                i_struct_T *objective
 *                const k_struct_T *options
 *                const k_struct_T *runTimeOptions
 * Return Type  : void
 */
void driver(const double H[64], const double f[13], c_struct_T *solution,
            b_struct_T *memspace, e_struct_T *workingset, g_struct_T *qrmanager,
            h_struct_T *cholmanager, i_struct_T *objective,
            const k_struct_T *options, const k_struct_T *runTimeOptions)
{
  static const char b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  __m128d r;
  double d;
  double minLambda;
  int i;
  int idx;
  int k;
  int ret;
  int vectorUB;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T updateFval;
  solution->iterations = 0;
  ret = workingset->nVar;
  guard1 = false;
  guard2 = false;
  if (workingset->probType == 3) {
    i = (unsigned char)workingset->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (workingset->isActiveConstr[idx + 2]) {
        solution->xstar[workingset->indexLB[idx] - 1] =
            -workingset->lb[workingset->indexLB[idx] - 1];
      }
    }
    for (idx = 0; idx < 8; idx++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[4] + idx) - 1]) {
        solution->xstar[workingset->indexUB[idx] - 1] =
            workingset->ub[workingset->indexUB[idx] - 1];
      }
    }
    PresolveWorkingSet(solution, memspace, workingset, qrmanager);
    if (solution->state >= 0) {
      guard2 = true;
    }
  } else {
    solution->state = 82;
    guard2 = true;
  }
  if (guard2) {
    solution->iterations = 0;
    solution->maxConstr = maxConstraintViolation(workingset, solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      phaseone(H, f, solution, memspace, workingset, qrmanager, cholmanager,
               objective, options->SolverName, runTimeOptions);
      if (solution->state != 0) {
        solution->maxConstr =
            maxConstraintViolation(workingset, solution->xstar);
        if (solution->maxConstr > 1.0E-6) {
          memset(&solution->lambda[0], 0, 23U * sizeof(double));
          d = 0.0;
          switch (objective->objtype) {
          case 5:
            d = objective->gammaScalar * solution->xstar[objective->nvar - 1];
            break;
          case 3:
            linearForm_(objective->hasLinear, objective->nvar,
                        memspace->workspace_float, H, f, solution->xstar);
            if (objective->nvar >= 1) {
              ret = objective->nvar;
              for (k = 0; k < ret; k++) {
                d += solution->xstar[k] * memspace->workspace_float[k];
              }
            }
            break;
          case 4:
            linearForm_(objective->hasLinear, objective->nvar,
                        memspace->workspace_float, H, f, solution->xstar);
            i = objective->nvar + 1;
            ret = (((13 - i) / 2) << 1) + i;
            vectorUB = ret - 2;
            for (idx = i; idx <= vectorUB; idx += 2) {
              r = _mm_loadu_pd(&solution->xstar[idx - 1]);
              _mm_storeu_pd(
                  &memspace->workspace_float[idx - 1],
                  _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5 * objective->beta), r),
                             _mm_set1_pd(objective->rho)));
            }
            for (idx = ret; idx < 13; idx++) {
              memspace->workspace_float[idx - 1] =
                  0.5 * objective->beta * solution->xstar[idx - 1] +
                  objective->rho;
            }
            for (k = 0; k < 12; k++) {
              d += solution->xstar[k] * memspace->workspace_float[k];
            }
            break;
          }
          solution->fstar = d;
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (ret - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     (unsigned int)ret * sizeof(double));
            }
            PresolveWorkingSet(solution, memspace, workingset, qrmanager);
            minLambda = maxConstraintViolation(workingset, solution->xstar);
            if (minLambda >= solution->maxConstr) {
              solution->maxConstr = minLambda;
              if (ret - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       (unsigned int)ret * sizeof(double));
              }
            }
          }
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    int TYPE;
    int activeSetChangeID;
    int globalActiveConstrIdx;
    boolean_T subProblemChanged;
    subProblemChanged = true;
    updateFval = true;
    activeSetChangeID = 0;
    TYPE = objective->objtype;
    i = workingset->nVar;
    globalActiveConstrIdx = 0;
    computeGrad_StoreHx(objective, H, f, solution->xstar);
    solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float,
                                          f, solution->xstar);
    if (solution->iterations < runTimeOptions->MaxIterations) {
      solution->state = -5;
    } else {
      solution->state = 0;
    }
    memset(&solution->lambda[0], 0, 23U * sizeof(double));
    int exitg1;
    do {
      exitg1 = 0;
      if (solution->state == -5) {
        boolean_T guard3;
        boolean_T guard4;
        guard3 = false;
        guard4 = false;
        if (subProblemChanged) {
          switch (activeSetChangeID) {
          case 1:
            squareQ_appendCol(qrmanager, workingset->ATwset,
                              13 * (workingset->nActiveConstr - 1) + 1);
            break;
          case -1:
            deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
            break;
          default:
            factorQR(qrmanager, workingset->ATwset, i,
                     workingset->nActiveConstr);
            computeQ_(qrmanager, qrmanager->mrows);
            break;
          }
          ret = memcmp(&options->SolverName[0], &b[0], 7);
          compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                         objective, ret == 0);
          if (solution->state != -5) {
            exitg1 = 1;
          } else if ((b_xnrm2(i, solution->searchDir) < 1.0E-6) ||
                     (workingset->nActiveConstr >= i)) {
            guard4 = true;
          } else {
            minLambda = feasibleratiotest(
                solution->xstar, solution->searchDir, workingset->nVar,
                workingset->lb, workingset->ub, workingset->indexLB,
                workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
                workingset->isActiveConstr, workingset->nWConstr, TYPE == 5,
                &updateFval, &k, &ret);
            if (updateFval) {
              switch (k) {
              case 3:
                /* A check that is always false is detected at compile-time.
                 * Eliminating code that follows. */
                break;
              case 4:
                addBoundToActiveSetMatrix_(workingset, 4, ret);
                break;
              default:
                addBoundToActiveSetMatrix_(workingset, 5, ret);
                break;
              }
              activeSetChangeID = 1;
            } else {
              if (objective->objtype == 5) {
                if (b_xnrm2(objective->nvar, solution->searchDir) >
                    100.0 * (double)objective->nvar * 1.4901161193847656E-8) {
                  solution->state = 3;
                } else {
                  solution->state = 4;
                }
              }
              subProblemChanged = false;
              if (workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }
            if ((i >= 1) && (!(minLambda == 0.0))) {
              ret = (i / 2) << 1;
              vectorUB = ret - 2;
              for (k = 0; k <= vectorUB; k += 2) {
                __m128d r1;
                r = _mm_loadu_pd(&solution->searchDir[k]);
                r1 = _mm_loadu_pd(&solution->xstar[k]);
                _mm_storeu_pd(
                    &solution->xstar[k],
                    _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(minLambda), r)));
              }
              for (k = ret; k < i; k++) {
                solution->xstar[k] += minLambda * solution->searchDir[k];
              }
            }
            computeGrad_StoreHx(objective, H, f, solution->xstar);
            guard3 = true;
          }
        } else {
          k = (unsigned char)i;
          memset(&solution->searchDir[0], 0, (unsigned int)k * sizeof(double));
          guard4 = true;
        }
        if (guard4) {
          compute_lambda(memspace->workspace_float, solution, objective,
                         qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr > i)) {
            ret = 0;
            minLambda = 0.0;
            k = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            vectorUB = workingset->nActiveConstr;
            for (idx = k; idx <= vectorUB; idx++) {
              d = solution->lambda[idx - 1];
              if (d < minLambda) {
                minLambda = d;
                ret = idx;
              }
            }
            if (ret == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = ret;
              subProblemChanged = true;
              removeConstr(workingset, ret);
              if (ret < workingset->nActiveConstr + 1) {
                solution->lambda[ret - 1] =
                    solution->lambda[workingset->nActiveConstr];
              }
              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            ret = workingset->nActiveConstr;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[ret - 1] = 0.0;
          }
          guard3 = true;
        }
        if (guard3) {
          solution->iterations++;
          ret = objective->nvar;
          if ((solution->iterations >= runTimeOptions->MaxIterations) &&
              ((solution->state != 1) || (objective->objtype == 5))) {
            solution->state = 0;
          }
          if (solution->iterations - solution->iterations / 50 * 50 == 0) {
            solution->maxConstr =
                maxConstraintViolation(workingset, solution->xstar);
            minLambda = solution->maxConstr;
            if (objective->objtype == 5) {
              minLambda =
                  solution->maxConstr - solution->xstar[objective->nvar - 1];
            }
            if (minLambda > 1.0E-6) {
              if (ret - 1 >= 0) {
                memcpy(&solution->searchDir[0], &solution->xstar[0],
                       (unsigned int)ret * sizeof(double));
              }
              updateFval = feasibleX0ForWorkingSet(memspace->workspace_float,
                                                   solution->searchDir,
                                                   workingset, qrmanager);
              if ((!updateFval) && (solution->state != 0)) {
                solution->state = -2;
              }
              activeSetChangeID = 0;
              minLambda =
                  maxConstraintViolation(workingset, solution->searchDir);
              if (minLambda < solution->maxConstr) {
                if (ret - 1 >= 0) {
                  memcpy(&solution->xstar[0], &solution->searchDir[0],
                         (unsigned int)ret * sizeof(double));
                }
                solution->maxConstr = minLambda;
              }
            }
          }
          updateFval = false;
        }
      } else {
        if (!updateFval) {
          solution->fstar = computeFval_ReuseHx(
              objective, memspace->workspace_float, f, solution->xstar);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/*
 * File trailer for driver.c
 *
 * [EOF]
 */
