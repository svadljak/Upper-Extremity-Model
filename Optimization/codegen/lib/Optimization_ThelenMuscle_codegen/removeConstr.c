/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: removeConstr.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "removeConstr.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_struct_T *obj
 *                int idx_global
 * Return Type  : void
 */
void removeConstr(e_struct_T *obj, int idx_global)
{
  int TYPE_tmp;
  int idx;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] +
                       obj->Wlocalidx[idx_global - 1]) -
                      2] = false;
  if (idx_global < obj->nActiveConstr) {
    int i;
    int i1;
    i = obj->nActiveConstr - 1;
    obj->Wid[idx_global - 1] = obj->Wid[i];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[i];
    i1 = (unsigned char)obj->nVar;
    for (idx = 0; idx < i1; idx++) {
      obj->ATwset[idx + 13 * (idx_global - 1)] = obj->ATwset[idx + 13 * i];
    }
    obj->bwset[idx_global - 1] = obj->bwset[i];
  }
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

/*
 * File trailer for removeConstr.c
 *
 * [EOF]
 */
