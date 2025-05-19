/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: modifyOverheadPhaseOne_.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "modifyOverheadPhaseOne_.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *obj
 * Return Type  : void
 */
void modifyOverheadPhaseOne_(e_struct_T *obj)
{
  int idx;
  int idxEq;
  int idxEq_tmp;
  idxEq_tmp = obj->nVar - 1;
  obj->Aeq[idxEq_tmp] = 0.0;
  obj->ATwset[idxEq_tmp] = 0.0;
  idxEq = obj->nVar + 12;
  obj->Aeq[idxEq] = 0.0;
  obj->ATwset[idxEq] = 0.0;
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[idxEq_tmp] = 1.0E-5;
  idxEq_tmp = obj->nActiveConstr;
  for (idx = 3; idx <= idxEq_tmp; idx++) {
    obj->ATwset[(obj->nVar + 13 * (idx - 1)) - 1] = -1.0;
  }
  idxEq = obj->isActiveIdx[4];
  if (obj->nWConstr[4] > 0) {
    for (idx = 7; idx >= 0; idx--) {
      idxEq_tmp = idxEq + idx;
      obj->isActiveConstr[idxEq_tmp] = obj->isActiveConstr[idxEq_tmp - 1];
    }
  } else {
    obj->isActiveConstr[obj->isActiveIdx[4] + 7] = false;
  }
  obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
}

/*
 * File trailer for modifyOverheadPhaseOne_.c
 *
 * [EOF]
 */
