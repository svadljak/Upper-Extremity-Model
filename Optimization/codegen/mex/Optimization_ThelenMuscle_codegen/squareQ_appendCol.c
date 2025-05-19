/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squareQ_appendCol.c
 *
 * Code generation for function 'squareQ_appendCol'
 *
 */

/* Include files */
#include "squareQ_appendCol.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = {
    98,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv."
    "m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    1,                   /* lineNo */
    "squareQ_appendCol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p" /* pathName */
};

static emlrtBCInfo oc_emlrtBCI = {
    1,                   /* iFirst */
    23,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "squareQ_appendCol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p", /* pName */
    3                                 /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    1,                   /* iFirst */
    529,                 /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "squareQ_appendCol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p", /* pName */
    0                                 /* checkKind */
};

/* Function Definitions */
void squareQ_appendCol(const emlrtStack *sp, h_struct_T *obj,
                       const real_T vec[299], int32_T iv0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T alpha1;
  real_T c;
  real_T s;
  real_T temp;
  int32_T Qk0;
  int32_T i;
  int32_T idx;
  int32_T k;
  char_T TRANSA;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  Qk0 = obj->ncols + 1;
  obj->minRowCol = muIntScalarMin_sint32(obj->mrows, Qk0);
  st.site = &rd_emlrtRSI;
  if (obj->mrows >= 1) {
    b_st.site = &qb_emlrtRSI;
    alpha1 = 1.0;
    temp = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)obj->mrows;
    n_t = (ptrdiff_t)obj->mrows;
    lda_t = (ptrdiff_t)23;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Q[0], &lda_t,
          (real_T *)&vec[iv0 - 1], &incx_t, &temp, &obj->QR[23 * obj->ncols],
          &incy_t);
  }
  obj->ncols = Qk0;
  if ((obj->ncols < 1) || (obj->ncols > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, 23, &oc_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i = obj->ncols - 1;
  obj->jpvt[i] = obj->ncols;
  for (idx = obj->mrows; idx > obj->ncols; idx--) {
    int32_T n;
    st.site = &rd_emlrtRSI;
    Qk0 = idx + 23 * i;
    if ((Qk0 - 1 < 1) || (Qk0 - 1 > 529)) {
      emlrtDynamicBoundsCheckR2012b(Qk0 - 1, 1, 529, &pc_emlrtBCI, &st);
    }
    alpha1 = obj->QR[Qk0 - 2];
    if ((Qk0 < 1) || (Qk0 > 529)) {
      emlrtDynamicBoundsCheckR2012b(Qk0, 1, 529, &pc_emlrtBCI, &st);
    }
    temp = obj->QR[Qk0 - 1];
    b_st.site = &sd_emlrtRSI;
    c = 0.0;
    s = 0.0;
    drotg(&alpha1, &temp, &c, &s);
    obj->QR[Qk0 - 2] = alpha1;
    obj->QR[Qk0 - 1] = temp;
    Qk0 = 23 * (idx - 2);
    st.site = &rd_emlrtRSI;
    n = obj->mrows;
    if (obj->mrows >= 1) {
      b_st.site = &ud_emlrtRSI;
      if (obj->mrows > 2147483646) {
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k < n; k++) {
        int32_T temp_tmp;
        temp_tmp = Qk0 + k;
        alpha1 = obj->Q[temp_tmp + 23];
        temp = c * obj->Q[temp_tmp] + s * alpha1;
        obj->Q[temp_tmp + 23] = c * alpha1 - s * obj->Q[temp_tmp];
        obj->Q[temp_tmp] = temp;
      }
    }
  }
}

/* End of code generation (squareQ_appendCol.c) */
