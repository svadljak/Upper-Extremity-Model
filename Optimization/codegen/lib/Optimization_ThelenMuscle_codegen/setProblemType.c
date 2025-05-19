/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: setProblemType.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "setProblemType.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *obj
 *                int PROBLEM_TYPE
 * Return Type  : void
 */
void setProblemType(e_struct_T *obj, int PROBLEM_TYPE)
{
  int colOffsetAeq;
  int i;
  int idx_col;
  int idx_row;
  switch (PROBLEM_TYPE) {
  case 3: {
    obj->nVar = 8;
    obj->mConstr = 18;
    if (obj->nWConstr[4] > 0) {
      int idxUpperExisting;
      idxUpperExisting = obj->isActiveIdx[4] - 2;
      for (colOffsetAeq = 0; colOffsetAeq < 8; colOffsetAeq++) {
        i = (idxUpperExisting + colOffsetAeq) + 1;
        obj->isActiveConstr[colOffsetAeq + 10] = obj->isActiveConstr[i];
        obj->isActiveConstr[i] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj->nVar = 9;
    obj->mConstr = 19;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    obj->nVar = 12;
    obj->mConstr = 22;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }
    if (obj->probType != 4) {
      int idxUpperExisting;
      for (idx_col = 0; idx_col < 2; idx_col++) {
        idxUpperExisting = idx_col + 10;
        colOffsetAeq = 13 * idx_col;
        i = idx_col + 8;
        for (idx_row = 9; idx_row <= i; idx_row++) {
          obj->Aeq[colOffsetAeq + 8] = 0.0;
          obj->ATwset[colOffsetAeq + 8] = 0.0;
        }
        i = idx_col + colOffsetAeq;
        obj->Aeq[i + 8] = -1.0;
        obj->ATwset[i + 8] = -1.0;
        for (idx_row = idxUpperExisting; idx_row < 11; idx_row++) {
          obj->Aeq[colOffsetAeq + 9] = 0.0;
          obj->ATwset[colOffsetAeq + 9] = 0.0;
        }
        for (idx_row = 11; idx_row <= idxUpperExisting; idx_row++) {
          obj->Aeq[colOffsetAeq + 10] = 0.0;
          obj->ATwset[colOffsetAeq + 10] = 0.0;
        }
        obj->Aeq[i + 10] = 1.0;
        obj->ATwset[i + 10] = 1.0;
        i = idx_col + 12;
        for (idx_row = i; idx_row < 13; idx_row++) {
          obj->Aeq[colOffsetAeq + 11] = 0.0;
          obj->ATwset[colOffsetAeq + 11] = 0.0;
        }
      }
      obj->indexLB[8] = 9;
      obj->indexLB[9] = 10;
      obj->indexLB[10] = 11;
      obj->indexLB[11] = 12;
      if (obj->nWConstr[4] > 0) {
        for (colOffsetAeq = 0; colOffsetAeq < 8; colOffsetAeq++) {
          obj->isActiveConstr[colOffsetAeq + 15] =
              obj->isActiveConstr[(obj->isActiveIdx[4] + colOffsetAeq) - 1];
        }
      }
      i = obj->isActiveIdx[4];
      for (colOffsetAeq = i; colOffsetAeq < 15; colOffsetAeq++) {
        obj->isActiveConstr[colOffsetAeq - 1] = false;
      }
      obj->lb[8] = 0.0;
      obj->lb[9] = 0.0;
      obj->lb[10] = 0.0;
      obj->lb[11] = 0.0;
      i = obj->nActiveConstr;
      for (idx_col = 3; idx_col <= i; idx_col++) {
        idxUpperExisting = 13 * (idx_col - 1) - 1;
        if (obj->Wid[idx_col - 1] == 3) {
          colOffsetAeq = obj->Wlocalidx[idx_col - 1];
          idx_row = colOffsetAeq + 7;
          if (idx_row >= 9) {
            memset(&obj->ATwset[idxUpperExisting + 9], 0,
                   (unsigned int)(idx_row - 8) * sizeof(double));
          }
          obj->ATwset[(colOffsetAeq + idxUpperExisting) + 8] = -1.0;
          colOffsetAeq += 9;
          if (colOffsetAeq <= 12) {
            memset(&obj->ATwset[colOffsetAeq + idxUpperExisting], 0,
                   (unsigned int)(((idxUpperExisting - colOffsetAeq) -
                                   idxUpperExisting) +
                                  13) *
                       sizeof(double));
          }
        } else {
          obj->ATwset[idxUpperExisting + 9] = 0.0;
          obj->ATwset[idxUpperExisting + 10] = 0.0;
          obj->ATwset[idxUpperExisting + 11] = 0.0;
          obj->ATwset[idxUpperExisting + 12] = 0.0;
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj->nVar = 13;
    obj->mConstr = 23;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj->probType = PROBLEM_TYPE;
}

/*
 * File trailer for setProblemType.c
 *
 * [EOF]
 */
