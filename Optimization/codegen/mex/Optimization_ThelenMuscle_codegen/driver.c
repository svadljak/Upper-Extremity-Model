/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "PresolveWorkingSet.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "find_neg_lambda.h"
#include "linearForm_.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xdot.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = {
    1,        /* lineNo */
    "driver", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\driver.p" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    1,             /* lineNo */
    "snap_bounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p" /* pathName */
};

static emlrtRSInfo ef_emlrtRSI = {
    1,             /* lineNo */
    "computeFval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval.p" /* pathName */
};

static emlrtRSInfo gf_emlrtRSI = {
    1,                /* lineNo */
    "linearFormReg_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\linearFormReg_.p" /* pathName */
};

static emlrtBCInfo w_emlrtBCI = {
    1,             /* iFirst */
    13,            /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "computeFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval.p", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    1,             /* iFirst */
    13,            /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p", /* pName */
    3           /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    1,                /* iFirst */
    299,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "linearFormReg_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\linearFormReg_.p", /* pName */
    3                              /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    1,             /* iFirst */
    299,           /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "computeFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval.p", /* pName */
    3                           /* checkKind */
};

/* Function Definitions */
void driver(const emlrtStack *sp, const real_T H[64], const real_T f[13],
            d_struct_T *solution, c_struct_T *memspace, f_struct_T *workingset,
            h_struct_T *qrmanager, i_struct_T *cholmanager,
            j_struct_T *objective, const k_struct_T *options,
            const k_struct_T *runTimeOptions)
{
  static const char_T b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  f_struct_T r1;
  real_T normDelta;
  int32_T i;
  int32_T idx;
  int32_T idxMinLambda;
  int32_T k;
  int32_T vectorUB;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T updateFval;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  solution->iterations = 0;
  idxMinLambda = workingset->nVar;
  guard1 = false;
  guard2 = false;
  if (workingset->probType == 3) {
    st.site = &mc_emlrtRSI;
    b_st.site = &nc_emlrtRSI;
    b_st.site = &nc_emlrtRSI;
    if (workingset->sizes[3] > 2147483646) {
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (workingset->isActiveConstr[idx + 2]) {
        if ((workingset->indexLB[idx] < 1) || (workingset->indexLB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexLB[idx], 1, 13,
                                        &x_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexLB[idx] - 1] =
            -workingset->lb[workingset->indexLB[idx] - 1];
      }
    }
    b_st.site = &nc_emlrtRSI;
    for (idx = 0; idx < 8; idx++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[4] + idx) - 1]) {
        if ((workingset->indexUB[idx] < 1) || (workingset->indexUB[idx] > 13)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexUB[idx], 1, 13,
                                        &x_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexUB[idx] - 1] =
            workingset->ub[workingset->indexUB[idx] - 1];
      }
    }
    st.site = &mc_emlrtRSI;
    PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
    if (solution->state >= 0) {
      guard2 = true;
    }
  } else {
    solution->state = 82;
    guard2 = true;
  }
  if (guard2) {
    solution->iterations = 0;
    st.site = &mc_emlrtRSI;
    solution->maxConstr =
        c_maxConstraintViolation(&st, workingset, solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      st.site = &mc_emlrtRSI;
      phaseone(&st, H, f, solution, memspace, workingset, qrmanager,
               cholmanager, objective, options->SolverName, runTimeOptions);
      if (solution->state != 0) {
        st.site = &mc_emlrtRSI;
        solution->maxConstr =
            c_maxConstraintViolation(&st, workingset, solution->xstar);
        if (solution->maxConstr > 1.0E-6) {
          st.site = &mc_emlrtRSI;
          b_xcopy(&st, 23, solution->lambda);
          st.site = &mc_emlrtRSI;
          solution->fstar = 0.0;
          switch (objective->objtype) {
          case 5:
            if ((objective->nvar < 1) || (objective->nvar > 13)) {
              emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 13, &w_emlrtBCI,
                                            &st);
            }
            solution->fstar =
                objective->gammaScalar * solution->xstar[objective->nvar - 1];
            break;
          case 3:
            b_st.site = &ef_emlrtRSI;
            linearForm_(&b_st, objective->hasLinear, objective->nvar,
                        memspace->workspace_float, H, f, solution->xstar);
            b_st.site = &ef_emlrtRSI;
            solution->fstar = xdot(&b_st, objective->nvar, solution->xstar,
                                   memspace->workspace_float);
            break;
          case 4:
            b_st.site = &ef_emlrtRSI;
            linearForm_(&b_st, objective->hasLinear, objective->nvar,
                        memspace->workspace_float, H, f, solution->xstar);
            b_st.site = &ef_emlrtRSI;
            i = objective->nvar + 1;
            c_st.site = &gf_emlrtRSI;
            idxMinLambda = (((13 - i) / 2) << 1) + i;
            vectorUB = idxMinLambda - 2;
            for (idx = i; idx <= vectorUB; idx += 2) {
              r = _mm_loadu_pd(&solution->xstar[idx - 1]);
              if ((idx < 1) || (idx > 299)) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 299, &fb_emlrtBCI, &b_st);
              }
              _mm_storeu_pd(
                  &memspace->workspace_float[idx - 1],
                  _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5 * objective->beta), r),
                             _mm_set1_pd(objective->rho)));
            }
            for (idx = idxMinLambda; idx < 13; idx++) {
              if (idx < 1) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 299, &y_emlrtBCI, &b_st);
              }
              memspace->workspace_float[idx - 1] =
                  0.5 * objective->beta * solution->xstar[idx - 1] +
                  objective->rho;
            }
            b_st.site = &ef_emlrtRSI;
            solution->fstar =
                xdot(&b_st, 12, solution->xstar, memspace->workspace_float);
            break;
          }
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            st.site = &mc_emlrtRSI;
            f_xcopy(&st, idxMinLambda, solution->xstar, solution->searchDir);
            st.site = &mc_emlrtRSI;
            PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
            st.site = &mc_emlrtRSI;
            normDelta =
                c_maxConstraintViolation(&st, workingset, solution->xstar);
            if (normDelta >= solution->maxConstr) {
              solution->maxConstr = normDelta;
              st.site = &mc_emlrtRSI;
              f_xcopy(&st, idxMinLambda, solution->searchDir, solution->xstar);
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
    int32_T TYPE;
    int32_T activeSetChangeID;
    int32_T globalActiveConstrIdx;
    boolean_T subProblemChanged;
    st.site = &mc_emlrtRSI;
    subProblemChanged = true;
    updateFval = true;
    activeSetChangeID = 0;
    TYPE = objective->objtype;
    i = workingset->nVar;
    globalActiveConstrIdx = 0;
    b_st.site = &nd_emlrtRSI;
    computeGrad_StoreHx(&b_st, objective, H, f, solution->xstar);
    b_st.site = &nd_emlrtRSI;
    solution->fstar = computeFval_ReuseHx(
        &b_st, objective, memspace->workspace_float, f, solution->xstar);
    if (solution->iterations < runTimeOptions->MaxIterations) {
      solution->state = -5;
    } else {
      solution->state = 0;
    }
    b_st.site = &nd_emlrtRSI;
    b_xcopy(&b_st, 23, solution->lambda);
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (solution->state == -5) {
        boolean_T b_guard1;
        boolean_T b_guard2;
        b_guard1 = false;
        b_guard2 = false;
        if (subProblemChanged) {
          switch (activeSetChangeID) {
          case 1:
            b_st.site = &nd_emlrtRSI;
            squareQ_appendCol(&b_st, qrmanager, workingset->ATwset,
                              13 * (workingset->nActiveConstr - 1) + 1);
            break;
          case -1:
            b_st.site = &nd_emlrtRSI;
            deleteColMoveEnd(&b_st, qrmanager, globalActiveConstrIdx);
            break;
          default:
            b_st.site = &nd_emlrtRSI;
            factorQR(&b_st, qrmanager, workingset->ATwset, i,
                     workingset->nActiveConstr);
            b_st.site = &nd_emlrtRSI;
            c_st.site = &yb_emlrtRSI;
            computeQ_(&c_st, qrmanager, qrmanager->mrows);
            break;
          }
          b_st.site = &nd_emlrtRSI;
          compute_deltax(&b_st, H, solution, memspace, qrmanager, cholmanager,
                         objective,
                         memcmp((char_T *)&options->SolverName[0],
                                (char_T *)&b[0], 7) == 0);
          if (solution->state != -5) {
            exitg1 = 1;
          } else {
            b_st.site = &nd_emlrtRSI;
            normDelta = xnrm2(&b_st, i, solution->searchDir);
            if ((normDelta < 1.0E-6) || (workingset->nActiveConstr >= i)) {
              b_guard2 = true;
            } else {
              real_T a;
              b_st.site = &nd_emlrtRSI;
              a = feasibleratiotest(
                  &b_st, solution->xstar, solution->searchDir, workingset->nVar,
                  workingset->lb, workingset->ub, workingset->indexLB,
                  workingset->indexUB, workingset->sizes,
                  workingset->isActiveIdx, workingset->isActiveConstr,
                  workingset->nWConstr, TYPE == 5, &updateFval, &idx,
                  &idxMinLambda);
              if (updateFval) {
                switch (idx) {
                case 3:
                  r1 = *workingset;
                  b_st.site = &nd_emlrtRSI;
                  c_st.site = &nd_emlrtRSI;
                  addAineqConstr(&c_st, &r1, idxMinLambda);
                  break;
                case 4:
                  b_st.site = &nd_emlrtRSI;
                  c_st.site = &ye_emlrtRSI;
                  addBoundToActiveSetMatrix_(&c_st, workingset, idxMinLambda);
                  break;
                default:
                  b_st.site = &nd_emlrtRSI;
                  c_st.site = &bf_emlrtRSI;
                  b_addBoundToActiveSetMatrix_(&c_st, workingset, idxMinLambda);
                  break;
                }
                activeSetChangeID = 1;
              } else {
                b_st.site = &nd_emlrtRSI;
                if (objective->objtype == 5) {
                  c_st.site = &cf_emlrtRSI;
                  normDelta =
                      xnrm2(&c_st, objective->nvar, solution->searchDir);
                  c_st.site = &cf_emlrtRSI;
                  if (normDelta >
                      100.0 * (real_T)objective->nvar * 1.4901161193847656E-8) {
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
              if (!(a == 0.0)) {
                idxMinLambda = (i / 2) << 1;
                vectorUB = idxMinLambda - 2;
                for (k = 0; k <= vectorUB; k += 2) {
                  __m128d r2;
                  r = _mm_loadu_pd(&solution->searchDir[k]);
                  r2 = _mm_loadu_pd(&solution->xstar[k]);
                  _mm_storeu_pd(&solution->xstar[k],
                                _mm_add_pd(r2, _mm_mul_pd(_mm_set1_pd(a), r)));
                }
                for (k = idxMinLambda; k < i; k++) {
                  solution->xstar[k] += a * solution->searchDir[k];
                }
              }
              b_st.site = &nd_emlrtRSI;
              computeGrad_StoreHx(&b_st, objective, H, f, solution->xstar);
              b_guard1 = true;
            }
          }
        } else {
          b_st.site = &nd_emlrtRSI;
          h_xcopy(&b_st, i, solution->searchDir);
          b_guard2 = true;
        }
        if (b_guard2) {
          b_st.site = &nd_emlrtRSI;
          compute_lambda(&b_st, memspace->workspace_float, solution, objective,
                         qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr > i)) {
            b_st.site = &nd_emlrtRSI;
            idxMinLambda = find_neg_lambda(&b_st, solution->lambda,
                                           workingset->nActiveConstr,
                                           workingset->nWConstr);
            if (idxMinLambda == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = idxMinLambda;
              subProblemChanged = true;
              b_st.site = &nd_emlrtRSI;
              if ((idxMinLambda < 1) || (idxMinLambda > 23)) {
                emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, 23, &ab_emlrtBCI,
                                              &b_st);
              }
              vectorUB = workingset->Wid[idxMinLambda - 1];
              if ((vectorUB < 1) || (vectorUB > 6)) {
                emlrtDynamicBoundsCheckR2012b(workingset->Wid[idxMinLambda - 1],
                                              1, 6, &t_emlrtBCI, &b_st);
              }
              idx = (workingset->isActiveIdx[vectorUB - 1] +
                     workingset->Wlocalidx[idxMinLambda - 1]) -
                    1;
              if ((idx < 1) || (idx > 23)) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &bb_emlrtBCI, &b_st);
              }
              workingset->isActiveConstr[idx - 1] = false;
              if (idxMinLambda < workingset->nActiveConstr) {
                c_st.site = &xc_emlrtRSI;
                moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                                idxMinLambda);
              }
              workingset->nActiveConstr--;
              if ((vectorUB < 1) || (vectorUB > 5)) {
                emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 5, &cb_emlrtBCI,
                                              &b_st);
              }
              workingset->nWConstr[vectorUB - 1]--;
              if (idxMinLambda < workingset->nActiveConstr + 1) {
                idx = workingset->nActiveConstr + 1;
                if ((idx < 1) || (idx > 23)) {
                  emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &v_emlrtBCI, &st);
                }
                solution->lambda[idxMinLambda - 1] = solution->lambda[idx - 1];
              }
              idx = workingset->nActiveConstr + 1;
              if ((idx < 1) || (idx > 23)) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &u_emlrtBCI, &st);
              }
              solution->lambda[idx - 1] = 0.0;
            }
          } else {
            idxMinLambda = workingset->nActiveConstr;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            if ((workingset->nActiveConstr < 1) ||
                (workingset->nActiveConstr > 23)) {
              emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 23,
                                            &v_emlrtBCI, &st);
            }
            b_st.site = &nd_emlrtRSI;
            vectorUB = workingset->nActiveConstr - 1;
            k = workingset->Wid[vectorUB];
            if ((k < 1) || (k > 6)) {
              emlrtDynamicBoundsCheckR2012b(
                  workingset->Wid[workingset->nActiveConstr - 1], 1, 6,
                  &t_emlrtBCI, &b_st);
            }
            idx = (workingset->isActiveIdx[k - 1] +
                   workingset->Wlocalidx[vectorUB]) -
                  1;
            if ((idx < 1) || (idx > 23)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &bb_emlrtBCI, &b_st);
            }
            workingset->isActiveConstr[idx - 1] = false;
            workingset->nActiveConstr = vectorUB;
            if ((k < 1) || (k > 5)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, 5, &cb_emlrtBCI, &b_st);
            }
            workingset->nWConstr[k - 1]--;
            solution->lambda[idxMinLambda - 1] = 0.0;
          }
          b_guard1 = true;
        }
        if (b_guard1) {
          b_st.site = &nd_emlrtRSI;
          solution->iterations++;
          idxMinLambda = objective->nvar;
          if ((solution->iterations >= runTimeOptions->MaxIterations) &&
              ((solution->state != 1) || (objective->objtype == 5))) {
            solution->state = 0;
          }
          if (solution->iterations - solution->iterations / 50 * 50 == 0) {
            c_st.site = &df_emlrtRSI;
            solution->maxConstr =
                c_maxConstraintViolation(&c_st, workingset, solution->xstar);
            normDelta = solution->maxConstr;
            if (objective->objtype == 5) {
              if ((objective->nvar < 1) || (objective->nvar > 13)) {
                emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 13,
                                              &db_emlrtBCI, &b_st);
              }
              normDelta =
                  solution->maxConstr - solution->xstar[objective->nvar - 1];
            }
            if (normDelta > 1.0E-6) {
              c_st.site = &df_emlrtRSI;
              f_xcopy(&c_st, objective->nvar, solution->xstar,
                      solution->searchDir);
              c_st.site = &df_emlrtRSI;
              updateFval = feasibleX0ForWorkingSet(
                  &c_st, memspace->workspace_float, solution->searchDir,
                  workingset, qrmanager);
              if ((!updateFval) && (solution->state != 0)) {
                solution->state = -2;
              }
              activeSetChangeID = 0;
              c_st.site = &df_emlrtRSI;
              normDelta = c_maxConstraintViolation(&c_st, workingset,
                                                   solution->searchDir);
              if (normDelta < solution->maxConstr) {
                c_st.site = &df_emlrtRSI;
                if (objective->nvar > 2147483646) {
                  d_st.site = &h_emlrtRSI;
                  check_forloop_overflow_error(&d_st);
                }
                for (idx = 0; idx < idxMinLambda; idx++) {
                  if ((idx + 1 < 1) || (idx + 1 > 13)) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &eb_emlrtBCI,
                                                  &b_st);
                  }
                  solution->xstar[idx] = solution->searchDir[idx];
                }
                solution->maxConstr = normDelta;
              }
            }
          }
          updateFval = false;
        }
      } else {
        if (!updateFval) {
          b_st.site = &nd_emlrtRSI;
          solution->fstar = computeFval_ReuseHx(
              &b_st, objective, memspace->workspace_float, f, solution->xstar);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (driver.c) */
