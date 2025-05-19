/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * countsort.c
 *
 * Code generation for function 'countsort'
 *
 */

/* Include files */
#include "countsort.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void countsort(const emlrtStack *sp, int32_T x[23], int32_T xLen,
               int32_T workspace[23], int32_T xMin, int32_T xMax)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T idxFill;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxStart;
    b_tmp = xMax - xMin;
    idxStart = b_tmp + 1;
    st.site = &vc_emlrtRSI;
    if (b_tmp + 1 > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < idxStart; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 23)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &lb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idx] = 0;
    }
    st.site = &vc_emlrtRSI;
    if (xLen > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    idxStart = (uint8_T)xLen;
    for (idx = 0; idx < idxStart; idx++) {
      idxEnd = (x[idx] - xMin) + 1;
      if ((idxEnd < 1) || (idxEnd > 23)) {
        emlrtDynamicBoundsCheckR2012b(idxEnd, 1, 23, &qb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idxEnd - 1]++;
    }
    st.site = &vc_emlrtRSI;
    if (b_tmp + 1 > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 2; idx <= b_tmp + 1; idx++) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &lb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idx - 1] += workspace[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    st.site = &vc_emlrtRSI;
    if (b_tmp > 2147483646) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < b_tmp; idx++) {
      st.site = &vc_emlrtRSI;
      if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
        b_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        if ((idxFill < 1) || (idxFill > 23)) {
          emlrtDynamicBoundsCheckR2012b(idxFill, 1, 23, &lb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        x[idxFill - 1] = idx + xMin;
      }
      if ((idx + 1 < 1) || (idx + 1 > 23)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 23, &qb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxStart = workspace[idx] + 1;
      if ((idx + 2 < 1) || (idx + 2 > 23)) {
        emlrtDynamicBoundsCheckR2012b(idx + 2, 1, 23, &qb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxEnd = workspace[idx + 1];
    }
    st.site = &vc_emlrtRSI;
    if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
      b_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = idxStart; idx <= idxEnd; idx++) {
      if ((idx < 1) || (idx > 23)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 23, &lb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      x[idx - 1] = xMax;
    }
  }
}

/* End of code generation (countsort.c) */
