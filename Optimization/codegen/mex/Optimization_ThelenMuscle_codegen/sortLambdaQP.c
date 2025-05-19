/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortLambdaQP.c
 *
 * Code generation for function 'sortLambdaQP'
 *
 */

/* Include files */
#include "sortLambdaQP.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Function Definitions */
void sortLambdaQP(const emlrtStack *sp, real_T lambda[23],
                  int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const int32_T WorkingSet_Wid[23],
                  const int32_T WorkingSet_Wlocalidx[23], real_T workspace[299])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (WorkingSet_nActiveConstr != 0) {
    int32_T currentMplier;
    int32_T idx;
    int32_T idxOffset;
    boolean_T exitg1;
    st.site = &hc_emlrtRSI;
    d_xcopy(&st, WorkingSet_sizes[3] + 10, lambda, workspace);
    st.site = &hc_emlrtRSI;
    b_xcopy(&st, WorkingSet_sizes[3] + 10, lambda);
    currentMplier = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet_nActiveConstr)) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(24, 1, 23, &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (WorkingSet_Wid[idx - 1] <= 2) {
        if (currentMplier > 299) {
          emlrtDynamicBoundsCheckR2012b(300, 1, 299, &m_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        idxOffset = WorkingSet_Wlocalidx[idx - 1];
        if ((idxOffset < 1) || (idxOffset > 23)) {
          emlrtDynamicBoundsCheckR2012b(idxOffset, 1, 23, &n_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        lambda[idxOffset - 1] = workspace[currentMplier - 1];
        currentMplier++;
        idx++;
      } else {
        exitg1 = true;
      }
    }
    while (idx <= WorkingSet_nActiveConstr) {
      if (idx > 23) {
        emlrtDynamicBoundsCheckR2012b(24, 1, 23, &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      switch (WorkingSet_Wid[idx - 1]) {
      case 3:
        idxOffset = 2;
        break;
      case 4:
        idxOffset = 2;
        break;
      default:
        idxOffset = WorkingSet_isActiveIdx[4] - 1;
        break;
      }
      if (currentMplier > 299) {
        emlrtDynamicBoundsCheckR2012b(300, 1, 299, &m_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxOffset += WorkingSet_Wlocalidx[idx - 1];
      if ((idxOffset < 1) || (idxOffset > 23)) {
        emlrtDynamicBoundsCheckR2012b(idxOffset, 1, 23, &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      lambda[idxOffset - 1] = workspace[currentMplier - 1];
      currentMplier++;
      idx++;
    }
  }
}

/* End of code generation (sortLambdaQP.c) */
