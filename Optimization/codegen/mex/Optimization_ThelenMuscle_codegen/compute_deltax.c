/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_deltax.c
 *
 * Code generation for function 'compute_deltax'
 *
 */

/* Include files */
#include "compute_deltax.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "factor1.h"
#include "fullColLDL2_.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "solve1.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "xtrsv.h"
#include "blas.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = {
    1,                /* lineNo */
    "compute_deltax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    1,                         /* lineNo */
    "computeProjectedHessian", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\computeProjectedHessian.p" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    1,                                     /* lineNo */
    "computeProjectedHessian_regularized", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtBCInfo uc_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    1,                /* iFirst */
    529,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    1,                /* iFirst */
    299,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    1,                                     /* iFirst */
    23,                                    /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    1,                                     /* iFirst */
    23,                                    /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    3         /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    1,                                     /* iFirst */
    13,                                    /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    3         /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    1,       /* iFirst */
    529,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    1,       /* iFirst */
    299,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    3                                 /* checkKind */
};

/* Function Definitions */
void compute_deltax(const emlrtStack *sp, const real_T H[64],
                    d_struct_T *solution, c_struct_T *memspace,
                    const h_struct_T *qrmanager, i_struct_T *cholmanager,
                    const j_struct_T *objective, boolean_T alwaysPositiveDef)
{
  ptrdiff_t incx_t;
  ptrdiff_t lda_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx;
  int32_T idx_row;
  int32_T k;
  int32_T mNull_tmp;
  int32_T nVar_tmp;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nVar_tmp = qrmanager->mrows;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    st.site = &de_emlrtRSI;
    if (qrmanager->mrows > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < nVar_tmp; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &uc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      solution->searchDir[idx] = 0.0;
    }
  } else {
    __m128d r;
    int32_T scalarLB;
    int32_T vectorUB;
    st.site = &de_emlrtRSI;
    if (qrmanager->mrows > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    scalarLB = (nVar_tmp / 2) << 1;
    vectorUB = scalarLB - 2;
    for (idx = 0; idx <= vectorUB; idx += 2) {
      r = _mm_loadu_pd(&objective->grad[idx]);
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &uc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      _mm_storeu_pd(&solution->searchDir[idx],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idx = scalarLB; idx < nVar_tmp; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &uc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      solution->searchDir[idx] = -objective->grad[idx];
    }
    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
      case 5:
        break;
      case 3:
        st.site = &de_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &de_emlrtRSI;
          factor(&b_st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          b_st.site = &de_emlrtRSI;
          b_factor(&b_st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &de_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &de_emlrtRSI;
            solve(&b_st, cholmanager, solution->searchDir);
          } else {
            b_st.site = &de_emlrtRSI;
            b_solve(&b_st, cholmanager, solution->searchDir);
          }
        }
        break;
      case 4: {
        if (alwaysPositiveDef) {
          st.site = &de_emlrtRSI;
          b_st.site = &de_emlrtRSI;
          factor(&b_st, cholmanager, H, objective->nvar, objective->nvar);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            real_T a;
            int32_T A_maxDiag_idx;
            st.site = &de_emlrtRSI;
            b_st.site = &de_emlrtRSI;
            solve(&b_st, cholmanager, solution->searchDir);
            st.site = &de_emlrtRSI;
            a = 1.0 / objective->beta;
            A_maxDiag_idx = objective->nvar + 1;
            b_st.site = &ob_emlrtRSI;
            c_st.site = &pb_emlrtRSI;
            if ((A_maxDiag_idx <= qrmanager->mrows) &&
                (qrmanager->mrows > 2147483646)) {
              d_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            scalarLB =
                ((((nVar_tmp - A_maxDiag_idx) + 1) / 2) << 1) + A_maxDiag_idx;
            vectorUB = scalarLB - 2;
            for (k = A_maxDiag_idx; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&solution->searchDir[k - 1]);
              _mm_storeu_pd(&solution->searchDir[k - 1],
                            _mm_mul_pd(_mm_set1_pd(a), r));
            }
            for (k = scalarLB; k <= nVar_tmp; k++) {
              solution->searchDir[k - 1] *= a;
            }
          }
        }
      } break;
      }
    } else {
      int32_T nullStartIdx_tmp;
      nullStartIdx_tmp = 23 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        st.site = &de_emlrtRSI;
        if (mNull_tmp > 2147483646) {
          b_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (idx = 0; idx < mNull_tmp; idx++) {
          k = nVar_tmp + 23 * (qrmanager->ncols + idx);
          if ((k < 1) || (k > 529)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, 529, &wc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (idx + 1 > 299) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 299, &xc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          memspace->workspace_float[idx] = -qrmanager->Q[k - 1];
        }
        st.site = &de_emlrtRSI;
        f_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                nullStartIdx_tmp, memspace->workspace_float,
                solution->searchDir);
      } else {
        int32_T A_maxDiag_idx;
        if (objective->objtype == 3) {
          st.site = &de_emlrtRSI;
          b_st.site = &qe_emlrtRSI;
          c_xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                  qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                  memspace->workspace_float);
          b_st.site = &qe_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_float,
                  cholmanager->FMat);
        } else if (alwaysPositiveDef) {
          A_maxDiag_idx = objective->nvar + 1;
          st.site = &de_emlrtRSI;
          b_st.site = &re_emlrtRSI;
          c_xgemm(objective->nvar, mNull_tmp, objective->nvar, H,
                  objective->nvar, qrmanager->Q, nullStartIdx_tmp,
                  memspace->workspace_float);
          b_st.site = &re_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            c_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          scalarLB =
              ((((nVar_tmp - A_maxDiag_idx) + 1) / 2) << 1) + A_maxDiag_idx;
          vectorUB = scalarLB - 2;
          for (idx = 0; idx < mNull_tmp; idx++) {
            b_st.site = &re_emlrtRSI;
            if ((A_maxDiag_idx <= nVar_tmp) && (nVar_tmp > 2147483646)) {
              c_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_row = A_maxDiag_idx; idx_row <= vectorUB; idx_row += 2) {
              k = (idx + qrmanager->ncols) + 1;
              if ((k < 1) || (k > 23)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 23, &yc_emlrtBCI, &st);
              }
              r = _mm_loadu_pd(&qrmanager->Q[(idx_row + 23 * (k - 1)) - 1]);
              if ((idx_row < 1) || (idx_row > 23)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &ad_emlrtBCI,
                                              &st);
              }
              if (idx + 1 > 13) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &bd_emlrtBCI,
                                              &st);
              }
              _mm_storeu_pd(
                  &memspace->workspace_float[(idx_row + 23 * idx) - 1],
                  _mm_mul_pd(_mm_set1_pd(objective->beta), r));
            }
            for (idx_row = scalarLB; idx_row <= nVar_tmp; idx_row++) {
              k = (idx + qrmanager->ncols) + 1;
              if ((k < 1) || (k > 23)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 23, &yc_emlrtBCI, &st);
              }
              if ((idx_row < 1) || (idx_row > 23)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, 23, &ad_emlrtBCI,
                                              &st);
              }
              if (idx + 1 > 13) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &bd_emlrtBCI,
                                              &st);
              }
              memspace->workspace_float[(idx_row + 23 * idx) - 1] =
                  objective->beta * qrmanager->Q[(idx_row + 23 * (k - 1)) - 1];
            }
          }
          b_st.site = &re_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_float,
                  cholmanager->FMat);
        }
        st.site = &de_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &se_emlrtRSI;
          cholmanager->ndims = mNull_tmp;
          c_st.site = &ee_emlrtRSI;
          cholmanager->info = xpotrf(&c_st, mNull_tmp, cholmanager->FMat);
        } else {
          b_st.site = &se_emlrtRSI;
          cholmanager->ndims = mNull_tmp;
          c_st.site = &he_emlrtRSI;
          A_maxDiag_idx = b_ixamax(&c_st, mNull_tmp, cholmanager->FMat) - 1;
          k = A_maxDiag_idx + 23 * A_maxDiag_idx;
          if ((k + 1 < 1) || (k + 1 > 529)) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, 529, &vc_emlrtBCI, &b_st);
          }
          c_st.site = &he_emlrtRSI;
          fullColLDL2_(&c_st, cholmanager, mNull_tmp);
          if (cholmanager->ConvexCheck) {
            c_st.site = &he_emlrtRSI;
            if (mNull_tmp > 2147483646) {
              d_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            idx = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (idx <= mNull_tmp - 1) {
                k = (idx + 23 * idx) + 1;
                if ((k < 1) || (k > 529)) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, 529, &vc_emlrtBCI, &b_st);
                }
                if (cholmanager->FMat[k - 1] <= 0.0) {
                  cholmanager->info = -(idx + 1);
                  exitg1 = 1;
                } else {
                  idx++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &de_emlrtRSI;
          g_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                  nullStartIdx_tmp, objective->grad, memspace->workspace_float);
          st.site = &de_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &te_emlrtRSI;
            c_st.site = &je_emlrtRSI;
            if (cholmanager->ndims >= 1) {
              DIAGA1 = 'N';
              TRANSA1 = 'T';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)23;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &cholmanager->FMat[0],
                    &lda_t, &memspace->workspace_float[0], &incx_t);
            }
            c_st.site = &je_emlrtRSI;
            xtrsv(cholmanager->ndims, cholmanager->FMat,
                  memspace->workspace_float);
          } else {
            b_st.site = &te_emlrtRSI;
            c_st.site = &ne_emlrtRSI;
            if (cholmanager->ndims >= 1) {
              DIAGA1 = 'U';
              TRANSA1 = 'N';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)23;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &cholmanager->FMat[0],
                    &lda_t, &memspace->workspace_float[0], &incx_t);
            }
            A_maxDiag_idx = cholmanager->ndims;
            c_st.site = &ne_emlrtRSI;
            if (cholmanager->ndims > 2147483646) {
              d_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            for (idx = 0; idx < A_maxDiag_idx; idx++) {
              k = (idx + 23 * idx) + 1;
              if ((k < 1) || (k > 529)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 529, &cd_emlrtBCI, &b_st);
              }
              if ((idx + 1 < 1) || (idx + 1 > 299)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 299, &dd_emlrtBCI,
                                              &b_st);
              }
              memspace->workspace_float[idx] /= cholmanager->FMat[k - 1];
            }
            c_st.site = &ne_emlrtRSI;
            if (cholmanager->ndims >= 1) {
              DIAGA1 = 'U';
              TRANSA1 = 'T';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)23;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &cholmanager->FMat[0],
                    &lda_t, &memspace->workspace_float[0], &incx_t);
            }
          }
          st.site = &de_emlrtRSI;
          f_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_float,
                  solution->searchDir);
        }
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
