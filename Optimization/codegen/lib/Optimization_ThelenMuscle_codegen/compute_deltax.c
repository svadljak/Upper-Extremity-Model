/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: compute_deltax.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "compute_deltax.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "fullColLDL2_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "xpotrf.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double H[64]
 *                c_struct_T *solution
 *                b_struct_T *memspace
 *                const g_struct_T *qrmanager
 *                h_struct_T *cholmanager
 *                const i_struct_T *objective
 *                boolean_T alwaysPositiveDef
 * Return Type  : void
 */
void compute_deltax(const double H[64], c_struct_T *solution,
                    b_struct_T *memspace, const g_struct_T *qrmanager,
                    h_struct_T *cholmanager, const i_struct_T *objective,
                    boolean_T alwaysPositiveDef)
{
  int idx_col;
  int ix;
  int k;
  int mNull_tmp;
  int nVar_tmp;
  int vectorUB;
  nVar_tmp = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    if (nVar_tmp >= 0) {
      memset(&solution->searchDir[0], 0,
             (unsigned int)(nVar_tmp + 1) * sizeof(double));
    }
  } else {
    __m128d r;
    int jjA;
    jjA = ((nVar_tmp + 1) / 2) << 1;
    vectorUB = jjA - 2;
    for (ix = 0; ix <= vectorUB; ix += 2) {
      r = _mm_loadu_pd(&objective->grad[ix]);
      _mm_storeu_pd(&solution->searchDir[ix], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (ix = jjA; ix <= nVar_tmp; ix++) {
      solution->searchDir[ix] = -objective->grad[ix];
    }
    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
      case 5:
        break;
      case 3: {
        if (alwaysPositiveDef) {
          cholmanager->ndims = qrmanager->mrows;
          for (ix = 0; ix <= nVar_tmp; ix++) {
            idx_col = (nVar_tmp + 1) * ix;
            jjA = 23 * ix;
            for (k = 0; k <= nVar_tmp; k++) {
              cholmanager->FMat[jjA + k] = H[idx_col + k];
            }
          }
          cholmanager->info = xpotrf(qrmanager->mrows, cholmanager->FMat);
        } else {
          cholmanager->ndims = qrmanager->mrows;
          for (ix = 0; ix <= nVar_tmp; ix++) {
            idx_col = qrmanager->mrows * ix;
            jjA = 23 * ix;
            for (k = 0; k <= nVar_tmp; k++) {
              cholmanager->FMat[jjA + k] = H[idx_col + k];
            }
          }
          fullColLDL2_(cholmanager, qrmanager->mrows);
          if (cholmanager->ConvexCheck) {
            ix = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (ix <= nVar_tmp) {
                if (cholmanager->FMat[ix + 23 * ix] <= 0.0) {
                  cholmanager->info = -ix - 1;
                  exitg1 = 1;
                } else {
                  ix++;
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
        } else if (alwaysPositiveDef) {
          solve(cholmanager, solution->searchDir);
        } else {
          int i;
          int nVars;
          nVars = cholmanager->ndims - 2;
          if (cholmanager->ndims != 0) {
            for (vectorUB = 0; vectorUB <= nVars + 1; vectorUB++) {
              jjA = vectorUB + vectorUB * 23;
              i = nVars - vectorUB;
              for (idx_col = 0; idx_col <= i; idx_col++) {
                ix = (vectorUB + idx_col) + 1;
                solution->searchDir[ix] -=
                    solution->searchDir[vectorUB] *
                    cholmanager->FMat[(jjA + idx_col) + 1];
              }
            }
          }
          nVars = cholmanager->ndims;
          for (ix = 0; ix < nVars; ix++) {
            solution->searchDir[ix] /= cholmanager->FMat[ix + 23 * ix];
          }
          if (cholmanager->ndims != 0) {
            for (vectorUB = nVars; vectorUB >= 1; vectorUB--) {
              double smax;
              jjA = (vectorUB - 1) * 23;
              smax = solution->searchDir[vectorUB - 1];
              i = vectorUB + 1;
              for (idx_col = nVars; idx_col >= i; idx_col--) {
                smax -= cholmanager->FMat[(jjA + idx_col) - 1] *
                        solution->searchDir[idx_col - 1];
              }
              solution->searchDir[vectorUB - 1] = smax;
            }
          }
        }
      } break;
      case 4: {
        if (alwaysPositiveDef) {
          int nVars;
          nVars = objective->nvar;
          cholmanager->ndims = objective->nvar;
          for (ix = 0; ix < nVars; ix++) {
            idx_col = nVars * ix;
            jjA = 23 * ix;
            for (k = 0; k < nVars; k++) {
              cholmanager->FMat[jjA + k] = H[idx_col + k];
            }
          }
          cholmanager->info = xpotrf(objective->nvar, cholmanager->FMat);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            double smax;
            int i;
            solve(cholmanager, solution->searchDir);
            smax = 1.0 / objective->beta;
            idx_col = objective->nvar + 1;
            i = qrmanager->mrows;
            jjA = ((((i - idx_col) + 1) / 2) << 1) + idx_col;
            vectorUB = jjA - 2;
            for (k = idx_col; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&solution->searchDir[k - 1]);
              _mm_storeu_pd(&solution->searchDir[k - 1],
                            _mm_mul_pd(_mm_set1_pd(smax), r));
            }
            for (k = jjA; k <= i; k++) {
              solution->searchDir[k - 1] *= smax;
            }
          }
        }
      } break;
      }
    } else {
      int nullStartIdx_tmp;
      nullStartIdx_tmp = 23 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        for (ix = 0; ix < mNull_tmp; ix++) {
          memspace->workspace_float[ix] =
              -qrmanager->Q[nVar_tmp + 23 * (qrmanager->ncols + ix)];
        }
        if (qrmanager->mrows != 0) {
          int i;
          memset(&solution->searchDir[0], 0,
                 (unsigned int)(nVar_tmp + 1) * sizeof(double));
          ix = 0;
          i = nullStartIdx_tmp + 23 * (mNull_tmp - 1);
          for (vectorUB = nullStartIdx_tmp; vectorUB <= i; vectorUB += 23) {
            jjA = vectorUB + nVar_tmp;
            for (idx_col = vectorUB; idx_col <= jjA; idx_col++) {
              int nVars;
              nVars = idx_col - vectorUB;
              solution->searchDir[nVars] +=
                  qrmanager->Q[idx_col - 1] * memspace->workspace_float[ix];
            }
            ix++;
          }
        }
      } else {
        int i;
        int nVars;
        if (objective->objtype == 3) {
          xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                memspace->workspace_float);
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_float,
                  cholmanager->FMat);
        } else if (alwaysPositiveDef) {
          nVars = qrmanager->mrows;
          xgemm(objective->nvar, mNull_tmp, objective->nvar, H, objective->nvar,
                qrmanager->Q, nullStartIdx_tmp, memspace->workspace_float);
          i = objective->nvar + 1;
          jjA = ((((nVars - i) + 1) / 2) << 1) + i;
          vectorUB = jjA - 2;
          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            for (ix = i; ix <= vectorUB; ix += 2) {
              r = _mm_loadu_pd(
                  &qrmanager->Q[(ix + 23 * (idx_col + qrmanager->ncols)) - 1]);
              _mm_storeu_pd(&memspace->workspace_float[(ix + 23 * idx_col) - 1],
                            _mm_mul_pd(_mm_set1_pd(objective->beta), r));
            }
            for (ix = jjA; ix <= nVars; ix++) {
              memspace->workspace_float[(ix + 23 * idx_col) - 1] =
                  objective->beta *
                  qrmanager->Q[(ix + 23 * (idx_col + qrmanager->ncols)) - 1];
            }
          }
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_float,
                  cholmanager->FMat);
        }
        if (alwaysPositiveDef) {
          cholmanager->ndims = mNull_tmp;
          cholmanager->info = xpotrf(mNull_tmp, cholmanager->FMat);
        } else {
          cholmanager->ndims = mNull_tmp;
          fullColLDL2_(cholmanager, mNull_tmp);
          if (cholmanager->ConvexCheck) {
            ix = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (ix <= mNull_tmp - 1) {
                if (cholmanager->FMat[ix + 23 * ix] <= 0.0) {
                  cholmanager->info = -ix - 1;
                  exitg1 = 1;
                } else {
                  ix++;
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
          double smax;
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_float[0], 0,
                   (unsigned int)mNull_tmp * sizeof(double));
            i = nullStartIdx_tmp + 23 * (mNull_tmp - 1);
            for (vectorUB = nullStartIdx_tmp; vectorUB <= i; vectorUB += 23) {
              smax = 0.0;
              jjA = vectorUB + nVar_tmp;
              for (idx_col = vectorUB; idx_col <= jjA; idx_col++) {
                smax += qrmanager->Q[idx_col - 1] *
                        objective->grad[idx_col - vectorUB];
              }
              jjA = div_nde_s32_floor(vectorUB - nullStartIdx_tmp, 23);
              memspace->workspace_float[jjA] -= smax;
            }
          }
          if (alwaysPositiveDef) {
            nVars = cholmanager->ndims;
            if (cholmanager->ndims != 0) {
              for (vectorUB = 0; vectorUB < nVars; vectorUB++) {
                jjA = vectorUB * 23;
                smax = memspace->workspace_float[vectorUB];
                for (idx_col = 0; idx_col < vectorUB; idx_col++) {
                  smax -= cholmanager->FMat[jjA + idx_col] *
                          memspace->workspace_float[idx_col];
                }
                memspace->workspace_float[vectorUB] =
                    smax / cholmanager->FMat[jjA + vectorUB];
              }
            }
            if (cholmanager->ndims != 0) {
              for (vectorUB = nVars; vectorUB >= 1; vectorUB--) {
                jjA = (vectorUB + (vectorUB - 1) * 23) - 1;
                memspace->workspace_float[vectorUB - 1] /=
                    cholmanager->FMat[jjA];
                for (idx_col = 0; idx_col <= vectorUB - 2; idx_col++) {
                  ix = (vectorUB - idx_col) - 2;
                  memspace->workspace_float[ix] -=
                      memspace->workspace_float[vectorUB - 1] *
                      cholmanager->FMat[(jjA - idx_col) - 1];
                }
              }
            }
          } else {
            nVars = cholmanager->ndims - 2;
            if (cholmanager->ndims != 0) {
              for (vectorUB = 0; vectorUB <= nVars + 1; vectorUB++) {
                jjA = vectorUB + vectorUB * 23;
                i = nVars - vectorUB;
                for (idx_col = 0; idx_col <= i; idx_col++) {
                  ix = (vectorUB + idx_col) + 1;
                  memspace->workspace_float[ix] -=
                      memspace->workspace_float[vectorUB] *
                      cholmanager->FMat[(jjA + idx_col) + 1];
                }
              }
            }
            nVars = cholmanager->ndims;
            for (ix = 0; ix < nVars; ix++) {
              memspace->workspace_float[ix] /= cholmanager->FMat[ix + 23 * ix];
            }
            if (cholmanager->ndims != 0) {
              for (vectorUB = nVars; vectorUB >= 1; vectorUB--) {
                jjA = (vectorUB - 1) * 23;
                smax = memspace->workspace_float[vectorUB - 1];
                i = vectorUB + 1;
                for (idx_col = nVars; idx_col >= i; idx_col--) {
                  smax -= cholmanager->FMat[(jjA + idx_col) - 1] *
                          memspace->workspace_float[idx_col - 1];
                }
                memspace->workspace_float[vectorUB - 1] = smax;
              }
            }
          }
          if (qrmanager->mrows != 0) {
            memset(&solution->searchDir[0], 0,
                   (unsigned int)(nVar_tmp + 1) * sizeof(double));
            ix = 0;
            i = nullStartIdx_tmp + 23 * (mNull_tmp - 1);
            for (vectorUB = nullStartIdx_tmp; vectorUB <= i; vectorUB += 23) {
              jjA = vectorUB + nVar_tmp;
              for (idx_col = vectorUB; idx_col <= jjA; idx_col++) {
                nVars = idx_col - vectorUB;
                solution->searchDir[nVars] +=
                    qrmanager->Q[idx_col - 1] * memspace->workspace_float[ix];
              }
              ix++;
            }
          }
        }
      }
    }
  }
}

/*
 * File trailer for compute_deltax.c
 *
 * [EOF]
 */
