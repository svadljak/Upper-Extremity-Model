/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeFiniteDifferences.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "computeFiniteDifferences.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : d_struct_T *obj
 *                double fCurrent
 *                const double cEqCurrent[2]
 *                double xk[8]
 *                double gradf[13]
 *                double JacCeqTrans[26]
 * Return Type  : boolean_T
 */
boolean_T computeFiniteDifferences(d_struct_T *obj, double fCurrent,
                                   const double cEqCurrent[2], double xk[8],
                                   double gradf[13], double JacCeqTrans[26])
{
  int idx;
  boolean_T evalOK;
  boolean_T exitg1;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 8)) {
    double b_deltaX;
    double d;
    double deltaX;
    boolean_T guard1;
    boolean_T modifiedStep;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (double)(xk[idx] < 0.0)) *
             fmax(fabs(xk[idx]), 1.0);
    modifiedStep = false;
    if ((xk[idx] >= 0.0) && (xk[idx] <= 1.0)) {
      d = xk[idx] + deltaX;
      if ((d > 1.0) || (d < 0.0)) {
        deltaX = -deltaX;
        modifiedStep = true;
        d = xk[idx] + deltaX;
        if ((d > 1.0) || (d < 0.0)) {
          if (xk[idx] <= 1.0 - xk[idx]) {
            deltaX = -xk[idx];
          } else {
            deltaX = 1.0 - xk[idx];
          }
        }
      }
    }
    b_deltaX = deltaX;
    evalOK = finDiffEvalAndChkErr(
        obj->nonlin.workspace.Q, obj->nonlin.workspace.b,
        obj->nonlin.workspace.Fl, obj->nonlin.workspace.Fpe,
        obj->nonlin.workspace.VM, obj->nonlin.workspace.LM0,
        obj->nonlin.workspace.alpha0, obj->nonlin.workspace.FM0, obj->cEq_1,
        idx + 1, deltaX, xk, &obj->f_1);
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        b_deltaX = -deltaX;
        d = xk[idx] - deltaX;
        if ((d >= 0.0) && (d <= 1.0)) {
          modifiedStep = true;
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          evalOK = finDiffEvalAndChkErr(
              obj->nonlin.workspace.Q, obj->nonlin.workspace.b,
              obj->nonlin.workspace.Fl, obj->nonlin.workspace.Fpe,
              obj->nonlin.workspace.VM, obj->nonlin.workspace.LM0,
              obj->nonlin.workspace.alpha0, obj->nonlin.workspace.FM0,
              obj->cEq_1, idx + 1, -deltaX, xk, &obj->f_1);
          obj->numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf[idx] = (obj->f_1 - fCurrent) / b_deltaX;
      JacCeqTrans[idx] = (obj->cEq_1[0] - cEqCurrent[0]) / b_deltaX;
      JacCeqTrans[idx + 13] = (obj->cEq_1[1] - cEqCurrent[1]) / b_deltaX;
      idx++;
    }
  }
  return evalOK;
}

/*
 * File trailer for computeFiniteDifferences.c
 *
 * [EOF]
 */
