/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feasibleX0ForWorkingSet.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "feasibleX0ForWorkingSet.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_rtwutil.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double workspace[299]
 *                double xCurrent[13]
 *                e_struct_T *workingset
 *                g_struct_T *qrmanager
 * Return Type  : boolean_T
 */
boolean_T feasibleX0ForWorkingSet(double workspace[299], double xCurrent[13],
                                  e_struct_T *workingset, g_struct_T *qrmanager)
{
  double B[299];
  int ar;
  int ic;
  int k;
  int mWConstr;
  int minmn;
  int nVar;
  int u1;
  boolean_T nonDegenerateWset;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    __m128d r;
    __m128d r1;
    double d;
    double tol;
    int i;
    int ix;
    if (mWConstr >= nVar) {
      int i1;
      int i2;
      int rankQR;
      i = (unsigned char)nVar;
      for (minmn = 0; minmn < i; minmn++) {
        ix = 23 * minmn;
        for (u1 = 0; u1 < mWConstr; u1++) {
          qrmanager->QR[u1 + ix] = workingset->ATwset[minmn + 13 * u1];
        }
        qrmanager->jpvt[minmn] = 0;
      }
      if (mWConstr * nVar == 0) {
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        if (mWConstr <= nVar) {
          ix = mWConstr;
        } else {
          ix = nVar;
        }
        qrmanager->minRowCol = ix;
        xgeqp3(qrmanager->QR, mWConstr, nVar, qrmanager->jpvt, qrmanager->tau);
      }
      computeQ_(qrmanager, qrmanager->mrows);
      rankQR = 0;
      ix = qrmanager->mrows;
      minmn = qrmanager->ncols;
      if (ix <= minmn) {
        minmn = ix;
      }
      if (minmn > 0) {
        u1 = qrmanager->ncols;
        if (ix >= u1) {
          u1 = ix;
        }
        tol = fmin(1.4901161193847656E-8, 2.2204460492503131E-15 * (double)u1) *
              fabs(qrmanager->QR[0]);
        while ((rankQR < minmn) &&
               (!(fabs(qrmanager->QR[rankQR + 23 * rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        d = workingset->bwset[minmn];
        workspace[minmn] = d;
        workspace[minmn + 23] = d;
      }
      i1 = 13 * (mWConstr - 1) + 1;
      for (minmn = 1; minmn <= i1; minmn += 13) {
        tol = 0.0;
        i2 = minmn + nVar;
        for (u1 = minmn; u1 < i2; u1++) {
          tol += workingset->ATwset[u1 - 1] * xCurrent[u1 - minmn];
        }
        i2 = div_nde_s32_floor(minmn - 1, 13);
        workspace[i2] -= tol;
      }
      memcpy(&B[0], &workspace[0], 299U * sizeof(double));
      for (k = 0; k <= 23; k += 23) {
        i1 = k + 1;
        i2 = k + nVar;
        if (i1 <= i2) {
          memset(&workspace[i1 + -1], 0,
                 (unsigned int)((i2 - i1) + 1) * sizeof(double));
        }
      }
      ix = -1;
      for (k = 0; k <= 23; k += 23) {
        ar = -1;
        i1 = k + 1;
        i2 = k + nVar;
        for (ic = i1; ic <= i2; ic++) {
          tol = 0.0;
          for (minmn = 0; minmn < mWConstr; minmn++) {
            tol += qrmanager->Q[(minmn + ar) + 1] * B[(minmn + ix) + 1];
          }
          workspace[ic - 1] += tol;
          ar += 23;
        }
        ix += 23;
      }
      for (ar = 0; ar < 2; ar++) {
        ix = 23 * ar - 1;
        for (k = rankQR; k >= 1; k--) {
          minmn = 23 * (k - 1) - 1;
          i1 = k + ix;
          d = workspace[i1];
          if (d != 0.0) {
            workspace[i1] = d / qrmanager->QR[k + minmn];
            i2 = (unsigned char)(k - 1);
            for (mWConstr = 0; mWConstr < i2; mWConstr++) {
              u1 = (mWConstr + ix) + 1;
              workspace[u1] -=
                  workspace[i1] * qrmanager->QR[(mWConstr + minmn) + 1];
            }
          }
        }
      }
      i1 = rankQR + 1;
      for (mWConstr = i1; mWConstr <= nVar; mWConstr++) {
        workspace[mWConstr - 1] = 0.0;
        workspace[mWConstr + 22] = 0.0;
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[qrmanager->jpvt[mWConstr] + 45] = workspace[mWConstr];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[mWConstr] = workspace[mWConstr + 46];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[qrmanager->jpvt[mWConstr] + 45] = workspace[mWConstr + 23];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[mWConstr + 23] = workspace[mWConstr + 46];
      }
    } else {
      int i1;
      int rankQR;
      if (mWConstr - 1 >= 0) {
        memset(&qrmanager->jpvt[0], 0, (unsigned int)mWConstr * sizeof(int));
      }
      factorQRE(qrmanager, workingset->ATwset, nVar, mWConstr);
      computeQ_(qrmanager, qrmanager->minRowCol);
      rankQR = 0;
      ix = qrmanager->mrows;
      minmn = qrmanager->ncols;
      if (ix <= minmn) {
        minmn = ix;
      }
      if (minmn > 0) {
        u1 = qrmanager->ncols;
        if (ix >= u1) {
          u1 = ix;
        }
        tol = fmin(1.4901161193847656E-8, 2.2204460492503131E-15 * (double)u1) *
              fabs(qrmanager->QR[0]);
        while ((rankQR < minmn) &&
               (!(fabs(qrmanager->QR[rankQR + 23 * rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        ix = (qrmanager->jpvt[minmn] - 1) * 13;
        tol = 0.0;
        i = (unsigned char)nVar;
        for (k = 0; k < i; k++) {
          tol += workingset->ATwset[ix + k] * xCurrent[k];
        }
        d = workingset->bwset[qrmanager->jpvt[minmn] - 1];
        workspace[minmn] = d - tol;
        workspace[minmn + 23] = d;
      }
      i = (unsigned char)rankQR;
      for (ar = 0; ar < 2; ar++) {
        ix = 23 * ar;
        for (mWConstr = 0; mWConstr < i; mWConstr++) {
          minmn = 23 * mWConstr;
          u1 = mWConstr + ix;
          tol = workspace[u1];
          for (k = 0; k < mWConstr; k++) {
            tol -= qrmanager->QR[k + minmn] * workspace[k + ix];
          }
          workspace[u1] = tol / qrmanager->QR[mWConstr + minmn];
        }
      }
      memcpy(&B[0], &workspace[0], 299U * sizeof(double));
      for (k = 0; k <= 23; k += 23) {
        i = k + 1;
        i1 = k + nVar;
        if (i <= i1) {
          memset(&workspace[i + -1], 0,
                 (unsigned int)((i1 - i) + 1) * sizeof(double));
        }
      }
      ix = 1;
      for (k = 0; k <= 23; k += 23) {
        ar = -1;
        i = ix + rankQR;
        for (mWConstr = ix; mWConstr < i; mWConstr++) {
          int i2;
          i1 = k + 1;
          i2 = k + nVar;
          minmn = ((i2 - i1) + 1) / 2 * 2 + i1;
          u1 = minmn - 2;
          for (ic = i1; ic <= u1; ic += 2) {
            r = _mm_loadu_pd(&qrmanager->Q[(ar + ic) - k]);
            r = _mm_mul_pd(_mm_set1_pd(B[mWConstr - 1]), r);
            r1 = _mm_loadu_pd(&workspace[ic - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&workspace[ic - 1], r);
          }
          for (ic = minmn; ic <= i2; ic++) {
            workspace[ic - 1] += B[mWConstr - 1] * qrmanager->Q[(ar + ic) - k];
          }
          ar += 23;
        }
        ix += 23;
      }
    }
    minmn = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (minmn <= (unsigned char)nVar - 1) {
        if (rtIsInf(workspace[minmn]) || rtIsNaN(workspace[minmn])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          d = workspace[minmn + 23];
          if (rtIsInf(d) || rtIsNaN(d)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            minmn++;
          }
        }
      } else {
        double v;
        minmn = nVar / 2 * 2;
        u1 = minmn - 2;
        for (k = 0; k <= u1; k += 2) {
          r = _mm_loadu_pd(&workspace[k]);
          r1 = _mm_loadu_pd(&xCurrent[k]);
          r = _mm_add_pd(r, r1);
          _mm_storeu_pd(&workspace[k], r);
        }
        for (k = minmn; k < nVar; k++) {
          workspace[k] += xCurrent[k];
        }
        if (workingset->probType == 2) {
          r = _mm_loadu_pd(&workingset->beq[0]);
          _mm_storeu_pd(&workingset->maxConstrWorkspace[0],
                        _mm_mul_pd(r, _mm_set1_pd(-1.0)));
          for (minmn = 0; minmn <= 13; minmn += 13) {
            tol = 0.0;
            i = minmn + 8;
            for (u1 = minmn + 1; u1 <= i; u1++) {
              tol += workingset->Aeq[u1 - 1] * workspace[(u1 - minmn) - 1];
            }
            i = div_nde_s32_floor(minmn, 13);
            workingset->maxConstrWorkspace[i] += tol;
          }
          d = (workingset->maxConstrWorkspace[0] - workspace[8]) +
              workspace[10];
          workingset->maxConstrWorkspace[0] = d;
          tol = fmax(0.0, fabs(d));
          d = (workingset->maxConstrWorkspace[1] - workspace[9]) +
              workspace[11];
          workingset->maxConstrWorkspace[1] = d;
          tol = fmax(tol, fabs(d));
        } else {
          r = _mm_loadu_pd(&workingset->beq[0]);
          _mm_storeu_pd(&workingset->maxConstrWorkspace[0],
                        _mm_mul_pd(r, _mm_set1_pd(-1.0)));
          for (minmn = 0; minmn <= 13; minmn += 13) {
            tol = 0.0;
            i = minmn + workingset->nVar;
            for (u1 = minmn + 1; u1 <= i; u1++) {
              tol += workingset->Aeq[u1 - 1] * workspace[(u1 - minmn) - 1];
            }
            i = div_nde_s32_floor(minmn, 13);
            workingset->maxConstrWorkspace[i] += tol;
          }
          tol = fmax(fmax(0.0, fabs(workingset->maxConstrWorkspace[0])),
                     fabs(workingset->maxConstrWorkspace[1]));
        }
        i = (unsigned char)workingset->sizes[3];
        for (minmn = 0; minmn < i; minmn++) {
          ix = workingset->indexLB[minmn] - 1;
          tol = fmax(tol, -workspace[ix] - workingset->lb[ix]);
        }
        for (minmn = 0; minmn < 8; minmn++) {
          ix = workingset->indexUB[minmn] - 1;
          tol = fmax(tol, workspace[ix] - workingset->ub[ix]);
        }
        if (workingset->probType == 2) {
          workingset->maxConstrWorkspace[0] = workingset->beq[0];
          workingset->maxConstrWorkspace[1] = workingset->beq[1];
          xgemv(8, workingset->Aeq, workspace, workingset->maxConstrWorkspace);
          d = (workingset->maxConstrWorkspace[0] - workspace[31]) +
              workspace[33];
          workingset->maxConstrWorkspace[0] = d;
          v = fmax(0.0, fabs(d));
          d = (workingset->maxConstrWorkspace[1] - workspace[32]) +
              workspace[34];
          workingset->maxConstrWorkspace[1] = d;
          v = fmax(v, fabs(d));
        } else {
          workingset->maxConstrWorkspace[0] = workingset->beq[0];
          workingset->maxConstrWorkspace[1] = workingset->beq[1];
          xgemv(workingset->nVar, workingset->Aeq, workspace,
                workingset->maxConstrWorkspace);
          v = fmax(fmax(0.0, fabs(workingset->maxConstrWorkspace[0])),
                   fabs(workingset->maxConstrWorkspace[1]));
        }
        for (minmn = 0; minmn < i; minmn++) {
          ix = workingset->indexLB[minmn];
          v = fmax(v, -workspace[ix + 22] - workingset->lb[ix - 1]);
        }
        for (minmn = 0; minmn < 8; minmn++) {
          ix = workingset->indexUB[minmn];
          v = fmax(v, workspace[ix + 22] - workingset->ub[ix - 1]);
        }
        if ((tol <= 2.2204460492503131E-16) || (tol < v)) {
          i = (unsigned char)nVar;
          memcpy(&xCurrent[0], &workspace[0], (unsigned int)i * sizeof(double));
        } else {
          i = (unsigned char)nVar;
          memcpy(&xCurrent[0], &workspace[23],
                 (unsigned int)i * sizeof(double));
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

/*
 * File trailer for feasibleX0ForWorkingSet.c
 *
 * [EOF]
 */
