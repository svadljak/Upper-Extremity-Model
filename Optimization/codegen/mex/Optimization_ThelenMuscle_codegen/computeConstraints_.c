/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeConstraints_.c
 *
 * Code generation for function 'computeConstraints_'
 *
 */

/* Include files */
#include "computeConstraints_.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = {
    1,                     /* lineNo */
    "computeConstraints_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\computeConstraints_.p" /* pathName */
};

static emlrtBCInfo ce_emlrtBCI = {
    1,                      /* iFirst */
    2,                      /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "checkVectorNonFinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\+internal\\checkVectorNonFinite."
    "p", /* pName */
    0    /* checkKind */
};

/* Function Definitions */
int32_T computeConstraints_(const emlrtStack *sp,
                            const real_T c_obj_next_next_next_next_next_[16],
                            const real_T d_obj_next_next_next_next_next_[2],
                            const real_T e_obj_next_next_next_next_next_[8],
                            const real_T f_obj_next_next_next_next_next_[8],
                            const real_T g_obj_next_next_next_next_next_[8],
                            const real_T h_obj_next_next_next_next_next_[8],
                            const real_T i_obj_next_next_next_next_next_[8],
                            const real_T j_obj_next_next_next_next_next_[8],
                            const real_T x[8], real_T Ceq_workspace[2])
{
  emlrtStack st;
  real_T Fm[8];
  real_T fvm;
  int32_T i;
  int32_T k;
  int32_T status;
  boolean_T allFinite;
  st.prev = sp;
  st.tls = sp->tls;
  /*  a shape factor for the force-velocity relationship */
  /*  maximum normalized muscle force achievable when the fiber is lengthening
   */
  for (k = 0; k < 8; k++) {
    real_T d;
    real_T d1;
    fvm = 10.0 * h_obj_next_next_next_next_next_[k];
    d = g_obj_next_next_next_next_next_[k];
    if (d <= 0.0) {
      real_T fvm_tmp;
      d1 = x[k];
      fvm_tmp = 3.0 * d1 + 1.0;
      fvm = 0.3 * (4.0 * d + fvm * fvm_tmp) / (-4.0 * d + fvm * 0.3 * fvm_tmp);
    } else {
      real_T fvm_tmp;
      d1 = x[k];
      fvm_tmp = 0.3 * fvm * (((3.0 * d1 * 1.4 - 3.0 * d1) + 1.4) - 1.0);
      fvm = (fvm_tmp + 8.0 * d * 1.4 * 1.3) / (fvm_tmp + 8.0 * d * 1.3);
    }
    /*  Fm(k) = a*Fl(k)*fvm + Fpe(k); */
    fvm = j_obj_next_next_next_next_next_[k] *
          (d1 * e_obj_next_next_next_next_next_[k] * fvm +
           f_obj_next_next_next_next_next_[k]) *
          muDoubleScalarCos(i_obj_next_next_next_next_next_[k]);
    Fm[k] = fvm;
    if (fvm <= 0.0) {
      Fm[k] = 0.0;
    }
  }
  for (k = 0; k < 2; k++) {
    fvm = 0.0;
    for (i = 0; i < 8; i++) {
      fvm += c_obj_next_next_next_next_next_[k + (i << 1)] * Fm[i];
    }
    Ceq_workspace[k] = fvm - d_obj_next_next_next_next_next_[k];
  }
  st.site = &e_emlrtRSI;
  status = 1;
  allFinite = true;
  k = 0;
  while (allFinite && (k + 1 <= 2)) {
    allFinite = ((!muDoubleScalarIsInf(Ceq_workspace[k])) &&
                 (!muDoubleScalarIsNaN(Ceq_workspace[k])));
    k++;
  }
  if (!allFinite) {
    if ((k < 1) || (k > 2)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, 2, &ce_emlrtBCI, &st);
    }
    if (muDoubleScalarIsNaN(Ceq_workspace[k - 1])) {
      status = -3;
    } else if (Ceq_workspace[k - 1] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  return status;
}

/* End of code generation (computeConstraints_.c) */
