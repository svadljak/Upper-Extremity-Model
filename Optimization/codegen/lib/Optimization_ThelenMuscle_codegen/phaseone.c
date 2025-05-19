/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: phaseone.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "phaseone.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
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
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
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
 *                const char options_SolverName[7]
 *                const k_struct_T *runTimeOptions
 * Return Type  : void
 */
void phaseone(const double H[64], const double f[13], c_struct_T *solution,
              b_struct_T *memspace, e_struct_T *workingset,
              g_struct_T *qrmanager, h_struct_T *cholmanager,
              i_struct_T *objective, const char options_SolverName[7],
              const k_struct_T *runTimeOptions)
{
  static const char b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  int PROBTYPE_ORIG;
  int activeSetChangeID;
  int globalActiveConstrIdx;
  int i;
  int idx;
  int idxMinLambda;
  int nVar;
  int nVar_tmp;
  int ret;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  PROBTYPE_ORIG = workingset->probType;
  nVar_tmp = workingset->nVar;
  solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    ret = 1;
  } else {
    ret = 4;
  }
  setProblemType(workingset, ret);
  ret = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = ret + 1;
  idxMinLambda = workingset->nActiveConstr;
  for (activeSetChangeID = nVar; activeSetChangeID <= idxMinLambda;
       activeSetChangeID++) {
    workingset->isActiveConstr
        [(workingset->isActiveIdx[workingset->Wid[activeSetChangeID - 1] - 1] +
          workingset->Wlocalidx[activeSetChangeID - 1]) -
         2] = false;
  }
  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = ret;
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = nVar_tmp + 1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  i = workingset->nVar;
  globalActiveConstrIdx = 0;
  computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float, f,
                                        solution->xstar);
  solution->state = -5;
  memset(&solution->lambda[0], 0, 23U * sizeof(double));
  int exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      double minLambda;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
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
          factorQR(qrmanager, workingset->ATwset, i, workingset->nActiveConstr);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }
        ret = memcmp(&options_SolverName[0], &b[0], 7);
        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective,
                       ret == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else if ((b_xnrm2(i, solution->searchDir) < 1.4901161193847657E-10) ||
                   (workingset->nActiveConstr >= i)) {
          guard2 = true;
        } else {
          minLambda = feasibleratiotest(
              solution->xstar, solution->searchDir, workingset->nVar,
              workingset->lb, workingset->ub, workingset->indexLB,
              workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
              workingset->isActiveConstr, workingset->nWConstr, true,
              &updateFval, &nVar, &idxMinLambda);
          if (updateFval) {
            switch (nVar) {
            case 3:
              /* A check that is always false is detected at compile-time.
               * Eliminating code that follows. */
              break;
            case 4:
              addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;
            default:
              addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
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
            idxMinLambda = (i / 2) << 1;
            ret = idxMinLambda - 2;
            for (nVar = 0; nVar <= ret; nVar += 2) {
              __m128d r;
              __m128d r1;
              r = _mm_loadu_pd(&solution->searchDir[nVar]);
              r1 = _mm_loadu_pd(&solution->xstar[nVar]);
              _mm_storeu_pd(
                  &solution->xstar[nVar],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(minLambda), r)));
            }
            for (nVar = idxMinLambda; nVar < i; nVar++) {
              solution->xstar[nVar] += minLambda * solution->searchDir[nVar];
            }
          }
          computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        nVar = (unsigned char)i;
        memset(&solution->searchDir[0], 0, (unsigned int)nVar * sizeof(double));
        guard2 = true;
      }
      if (guard2) {
        compute_lambda(memspace->workspace_float, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > i)) {
          idxMinLambda = 0;
          minLambda = 0.0;
          nVar = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          ret = workingset->nActiveConstr;
          for (idx = nVar; idx <= ret; idx++) {
            double d;
            d = solution->lambda[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              idxMinLambda = idx;
            }
          }
          if (idxMinLambda == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            removeConstr(workingset, idxMinLambda);
            if (idxMinLambda < workingset->nActiveConstr + 1) {
              solution->lambda[idxMinLambda - 1] =
                  solution->lambda[workingset->nActiveConstr];
            }
            solution->lambda[workingset->nActiveConstr] = 0.0;
          }
        } else {
          nVar = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          removeConstr(workingset, workingset->nActiveConstr);
          solution->lambda[nVar - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        solution->iterations++;
        nVar = objective->nvar;
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
            boolean_T nonDegenerateWset;
            if (nVar - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     (unsigned int)nVar * sizeof(double));
            }
            nonDegenerateWset = feasibleX0ForWorkingSet(
                memspace->workspace_float, solution->searchDir, workingset,
                qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }
            activeSetChangeID = 0;
            minLambda = maxConstraintViolation(workingset, solution->searchDir);
            if ((minLambda < solution->maxConstr) && (nVar - 1 >= 0)) {
              memcpy(&solution->xstar[0], &solution->searchDir[0],
                     (unsigned int)nVar * sizeof(double));
            }
          }
        }
        if (updateFval) {
          solution->fstar = computeFval_ReuseHx(
              objective, memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-6) &&
              ((solution->state != 0) || (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(
            objective, memspace->workspace_float, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (workingset
          ->isActiveConstr[(workingset->isActiveIdx[3] + workingset->sizes[3]) -
                           2]) {
    boolean_T exitg2;
    idx = 3;
    exitg2 = false;
    while ((!exitg2) && (idx <= workingset->nActiveConstr)) {
      if ((workingset->Wid[idx - 1] == 4) &&
          (workingset->Wlocalidx[idx - 1] == workingset->sizes[3])) {
        removeConstr(workingset, idx);
        exitg2 = true;
      } else {
        idx++;
      }
    }
  }
  ret = workingset->nActiveConstr;
  while ((ret > 2) && (ret > nVar_tmp)) {
    removeConstr(workingset, ret);
    ret--;
  }
  solution->maxConstr = solution->xstar[nVar_tmp];
  setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

/*
 * File trailer for phaseone.c
 *
 * [EOF]
 */
