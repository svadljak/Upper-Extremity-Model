/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: addAeqConstr.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "addAeqConstr.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *obj
 *                int idx_local
 * Return Type  : void
 */
void addAeqConstr(e_struct_T *obj, int idx_local)
{
  int idx;
  int totalEq;
  totalEq = obj->nWConstr[0] + obj->nWConstr[1];
  if ((obj->nActiveConstr == totalEq) && (idx_local > obj->nWConstr[1])) {
    int i;
    int i1;
    int iAeq0;
    int iAw0;
    obj->nWConstr[1]++;
    obj->isActiveConstr[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    obj->nActiveConstr++;
    i = obj->nActiveConstr - 1;
    obj->Wid[i] = 2;
    obj->Wlocalidx[i] = idx_local;
    iAeq0 = 13 * (idx_local - 1);
    iAw0 = 13 * (obj->nActiveConstr - 1);
    i1 = (unsigned char)obj->nVar;
    for (idx = 0; idx < i1; idx++) {
      obj->ATwset[iAw0 + idx] = obj->Aeq[iAeq0 + idx];
    }
    obj->bwset[i] = obj->beq[idx_local - 1];
  } else {
    int i;
    int i1;
    int iAeq0;
    int iAw0;
    obj->nActiveConstr++;
    i = obj->nActiveConstr - 1;
    obj->Wid[i] = obj->Wid[totalEq];
    obj->Wlocalidx[i] = obj->Wlocalidx[totalEq];
    i1 = (unsigned char)obj->nVar;
    for (idx = 0; idx < i1; idx++) {
      obj->ATwset[idx + 13 * i] = obj->ATwset[idx + 13 * totalEq];
    }
    obj->bwset[i] = obj->bwset[totalEq];
    obj->nWConstr[1]++;
    obj->isActiveConstr[idx_local - 1] = true;
    obj->Wid[totalEq] = 2;
    obj->Wlocalidx[totalEq] = idx_local;
    iAeq0 = 13 * (idx_local - 1);
    iAw0 = 13 * totalEq;
    for (idx = 0; idx < i1; idx++) {
      obj->ATwset[iAw0 + idx] = obj->Aeq[iAeq0 + idx];
    }
    obj->bwset[totalEq] = obj->beq[idx_local - 1];
  }
}

/*
 * File trailer for addAeqConstr.c
 *
 * [EOF]
 */
