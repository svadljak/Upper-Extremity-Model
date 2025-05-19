/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addAineqConstr.c
 *
 * Code generation for function 'addAineqConstr'
 *
 */

/* Include files */
#include "addAineqConstr.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xe_emlrtRSI = {
    1,                /* lineNo */
    "addAineqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p" /* pathName */
};

static emlrtBCInfo hd_emlrtBCI = {
    1,                /* iFirst */
    0,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    1,                /* iFirst */
    299,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void addAineqConstr(const emlrtStack *sp, f_struct_T *obj, int32_T idx_local)
{
  emlrtStack st;
  int32_T b_iv[4];
  int32_T iv1[4];
  int32_T i;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xe_emlrtRSI;
  i = (obj->isActiveIdx[2] + idx_local) - 1;
  if ((i < 1) || (i > 23)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 23, &jd_emlrtBCI, &st);
  }
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 23)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 23, &jd_emlrtBCI, &st);
  }
  iAineq0 = 13 * (idx_local - 1) + 1;
  iAw0 = 13 * (obj->nActiveConstr - 1) + 1;
  i = obj->nVar;
  scalarLB = (i / 4) << 2;
  vectorUB = scalarLB - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    __m128i r;
    r = _mm_set1_epi32(idx);
    _mm_storeu_si128(
        (__m128i *)&b_iv[0],
        _mm_add_epi32(
            _mm_set1_epi32(iAw0),
            _mm_add_epi32(r, _mm_loadu_si128((const __m128i *)&iv[0]))));
    if ((b_iv[0] < 1) || (b_iv[0] > 299)) {
      emlrtDynamicBoundsCheckR2012b(b_iv[0], 1, 299, &id_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((b_iv[1] < 1) || (b_iv[1] > 299)) {
      emlrtDynamicBoundsCheckR2012b(b_iv[1], 1, 299, &id_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((b_iv[2] < 1) || (b_iv[2] > 299)) {
      emlrtDynamicBoundsCheckR2012b(b_iv[2], 1, 299, &id_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((b_iv[3] < 1) || (b_iv[3] > 299)) {
      emlrtDynamicBoundsCheckR2012b(b_iv[3], 1, 299, &id_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    _mm_storeu_si128(
        (__m128i *)&iv1[0],
        _mm_add_epi32(
            _mm_set1_epi32(iAineq0),
            _mm_add_epi32(r, _mm_loadu_si128((const __m128i *)&iv[0]))));
    emlrtDynamicBoundsCheckR2012b(iv1[0], 1, 0, &hd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  for (idx = scalarLB; idx < i; idx++) {
    vectorUB = iAw0 + idx;
    if ((vectorUB < 1) || (vectorUB > 299)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 299, &id_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    emlrtDynamicBoundsCheckR2012b(iAineq0 + idx, 1, 0, &hd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  emlrtDynamicBoundsCheckR2012b(idx_local, 1, 0, &hd_emlrtBCI,
                                (emlrtConstCTX)sp);
}

/* End of code generation (addAineqConstr.c) */
