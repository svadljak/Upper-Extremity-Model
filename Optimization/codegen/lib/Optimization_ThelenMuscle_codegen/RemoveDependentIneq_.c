/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RemoveDependentIneq_.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "RemoveDependentIneq_.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "countsort.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *workingset
 *                g_struct_T *qrmanager
 *                b_struct_T *memspace
 *                double tolfactor
 * Return Type  : void
 */
void RemoveDependentIneq_(e_struct_T *workingset, g_struct_T *qrmanager,
                          b_struct_T *memspace, double tolfactor)
{
  int idx;
  int idxDiag;
  int idx_col;
  int k;
  int nActiveConstr_tmp;
  int nFixedConstr;
  int nVar;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    double maxDiag;
    double tol;
    int nDepIneq;
    idxDiag = workingset->nVar;
    nDepIneq = workingset->nActiveConstr;
    if (idxDiag >= nDepIneq) {
      nDepIneq = idxDiag;
    }
    tol = tolfactor * fmin(1.4901161193847656E-8,
                           2.2204460492503131E-15 * (double)nDepIneq);
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager->jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nActiveConstr_tmp) {
      memset(&qrmanager->jpvt[idxDiag + -1], 0,
             (unsigned int)((nActiveConstr_tmp - idxDiag) + 1) * sizeof(int));
    }
    for (idx_col = 0; idx_col < nActiveConstr_tmp; idx_col++) {
      nDepIneq = 23 * idx_col;
      idx = 13 * idx_col;
      idxDiag = (unsigned char)nVar;
      for (k = 0; k < idxDiag; k++) {
        qrmanager->QR[nDepIneq + k] = workingset->ATwset[idx + k];
      }
    }
    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      idxDiag = workingset->nVar;
      nDepIneq = workingset->nActiveConstr;
      if (idxDiag <= nDepIneq) {
        nDepIneq = idxDiag;
      }
      qrmanager->minRowCol = nDepIneq;
      xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt, qrmanager->tau);
    }
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr - 1; idx + 1 > nVar; idx--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx];
    }
    maxDiag = fabs(qrmanager->QR[0]);
    for (idxDiag = 0; idxDiag < idx; idxDiag++) {
      maxDiag = fmax(maxDiag,
                     fabs(qrmanager->QR[(23 * (idxDiag + 1) + idxDiag) + 1]));
    }
    if (idx + 1 <= workingset->nVar) {
      idxDiag = idx + 23 * idx;
      while ((idx + 1 > nFixedConstr) &&
             (fabs(qrmanager->QR[idxDiag]) < tol * maxDiag)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx];
        idx--;
        idxDiag -= 24;
      }
    }
    countsort(memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      removeConstr(workingset, memspace->workspace_int[idx - 1]);
    }
  }
}

/*
 * File trailer for RemoveDependentIneq_.c
 *
 * [EOF]
 */
