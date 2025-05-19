/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_lambda.c
 *
 * Code generation for function 'compute_lambda'
 *
 */

/* Include files */
#include "compute_lambda.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "Optimization_ThelenMuscle_codegen_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = {
    1,                /* lineNo */
    "compute_lambda", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_lambda.p" /* pathName */
};

static emlrtBCInfo fd_emlrtBCI = {
    1,                 /* iFirst */
    529,               /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "isNonDegenerate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\isNonDegenerate.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    1,                /* iFirst */
    23,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_lambda", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_lambda.p", /* pName */
    3                                /* checkKind */
};

/* Function Definitions */
void compute_lambda(const emlrtStack *sp, real_T workspace[299],
                    d_struct_T *solution, const j_struct_T *objective,
                    const h_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  int32_T idx;
  int32_T nActiveConstr_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nActiveConstr_tmp = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      c = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 *
                                (real_T)muIntScalarMax_sint32(
                                    qrmanager->mrows, qrmanager->ncols));
      st.site = &ue_emlrtRSI;
      if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
        nonDegenerate = true;
      } else {
        nonDegenerate = false;
      }
      if (nonDegenerate) {
        boolean_T exitg1;
        boolean_T guard2;
        idx = nActiveConstr_tmp;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = qrmanager->mrows + 23 * (qrmanager->ncols - 1);
          exitg1 = false;
          while ((!exitg1) && (idx > qrmanager->mrows)) {
            if ((idxQR < 1) || (idxQR > 529)) {
              emlrtDynamicBoundsCheckR2012b(idxQR, 1, 529, &fd_emlrtBCI, &st);
            }
            if (muDoubleScalarAbs(qrmanager->QR[idxQR - 1]) >= c) {
              idx--;
              idxQR -= 23;
            } else {
              exitg1 = true;
            }
          }
          nonDegenerate = (idx == qrmanager->mrows);
          if (nonDegenerate) {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        if (guard2) {
          idxQR = idx + 23 * (idx - 1);
          exitg1 = false;
          while ((!exitg1) && (idx >= 1)) {
            if ((idxQR < 1) || (idxQR > 529)) {
              emlrtDynamicBoundsCheckR2012b(idxQR, 1, 529, &fd_emlrtBCI, &st);
            }
            if (muDoubleScalarAbs(qrmanager->QR[idxQR - 1]) >= c) {
              idx--;
              idxQR -= 24;
            } else {
              exitg1 = true;
            }
          }
          nonDegenerate = (idx == 0);
        }
      }
      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      st.site = &ue_emlrtRSI;
      b_st.site = &s_emlrtRSI;
      if (qrmanager->mrows != 0) {
        c_st.site = &tb_emlrtRSI;
        if (qrmanager->ncols > 2147483646) {
          d_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        memset(&workspace[0], 0, (uint32_T)nActiveConstr_tmp * sizeof(real_T));
        idx = 23 * (qrmanager->ncols - 1) + 1;
        c_st.site = &sb_emlrtRSI;
        if (idx > 2147483624) {
          d_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (iac = 1; iac <= idx; iac += 23) {
          c = 0.0;
          idxQR = (iac + qrmanager->mrows) - 1;
          c_st.site = &rb_emlrtRSI;
          if ((iac <= idxQR) && (idxQR > 2147483646)) {
            d_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          for (ia = iac; ia <= idxQR; ia++) {
            c += qrmanager->Q[ia - 1] * objective->grad[ia - iac];
          }
          idxQR = div_nde_s32_floor(iac - 1, 23);
          workspace[idxQR] += c;
        }
      }
      st.site = &ue_emlrtRSI;
      xtrsv(qrmanager->ncols, qrmanager->QR, workspace);
      st.site = &ue_emlrtRSI;
      if (qrmanager->ncols > 2147483646) {
        b_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx = 0; idx < nActiveConstr_tmp; idx++) {
        if ((idx + 1 < 1) || (idx + 1 > 23)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &gd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        solution->lambda[idx] = -workspace[idx];
      }
    }
  }
}

/* End of code generation (compute_lambda.c) */
