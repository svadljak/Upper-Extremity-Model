/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQR.c
 *
 * Code generation for function 'factorQR'
 *
 */

/* Include files */
#include "factorQR.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = {
    1,          /* lineNo */
    "factorQR", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQR.p" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    27,       /* lineNo */
    "xgeqrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqrf.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    99,             /* lineNo */
    "ceval_xgeqrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqrf.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    94,             /* lineNo */
    "ceval_xgeqrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqrf.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    93,             /* lineNo */
    "ceval_xgeqrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqrf.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    91,             /* lineNo */
    "ceval_xgeqrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqrf.m" /* pathName */
};

static emlrtBCInfo me_emlrtBCI = {
    1,          /* iFirst */
    23,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "factorQR", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQR.p", /* pName */
    3                        /* checkKind */
};

/* Function Definitions */
void factorQR(const emlrtStack *sp, h_struct_T *obj, const real_T A[299],
              int32_T mrows, int32_T ncols)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'q', 'r', 'f'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  int32_T j;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    st.site = &wd_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < ncols; idx++) {
      st.site = &wd_emlrtRSI;
      c_xcopy(&st, mrows, A, 13 * idx + 1, obj->QR, 23 * idx + 1);
    }
    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    st.site = &wd_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < ncols; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 23)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &me_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->jpvt[idx] = idx + 1;
    }
    idx = muIntScalarMin_sint32(mrows, ncols);
    obj->minRowCol = idx;
    st.site = &wd_emlrtRSI;
    b_st.site = &xd_emlrtRSI;
    if (ncols == 0) {
      memset(&obj->tau[0], 0, 23U * sizeof(real_T));
    } else {
      ptrdiff_t info_t;
      boolean_T p;
      info_t = LAPACKE_dgeqrf(102, (ptrdiff_t)mrows, (ptrdiff_t)ncols,
                              &obj->QR[0], (ptrdiff_t)23, &obj->tau[0]);
      c_st.site = &ce_emlrtRSI;
      if ((int32_T)info_t != 0) {
        p = true;
        if ((int32_T)info_t != -4) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &c_st, &e_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0], 12,
                (int32_T)info_t);
          }
        }
      } else {
        p = false;
      }
      if (p) {
        c_st.site = &be_emlrtRSI;
        for (j = 0; j < ncols; j++) {
          int32_T b_i;
          c_st.site = &ae_emlrtRSI;
          if (mrows > 2147483646) {
            d_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          b_i = (uint8_T)mrows;
          for (i = 0; i < b_i; i++) {
            obj->QR[j * 23 + i] = rtNaN;
          }
        }
        c_st.site = &yd_emlrtRSI;
        for (i = 0; i < idx; i++) {
          obj->tau[i] = rtNaN;
        }
        idx++;
        for (i = idx; i < 24; i++) {
          obj->tau[i - 1] = 0.0;
        }
      }
    }
  }
}

/* End of code generation (factorQR.c) */
