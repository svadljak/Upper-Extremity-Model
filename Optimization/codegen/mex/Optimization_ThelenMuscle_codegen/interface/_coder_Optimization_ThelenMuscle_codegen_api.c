/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Optimization_ThelenMuscle_codegen_api.c
 *
 * Code generation for function '_coder_Optimization_ThelenMuscle_codegen_api'
 *
 */

/* Include files */
#include "_coder_Optimization_ThelenMuscle_codegen_api.h"
#include "Optimization_ThelenMuscle_codegen.h"
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[8];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[16];

static const mxArray *emlrt_marshallOut(real_T u[8]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[8];

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16]
{
  real_T(*y)[16];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[8]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[8];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[16]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[16];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(real_T u[8])
{
  static const int32_T i = 0;
  static const int32_T i1 = 8;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[8]
{
  real_T(*y)[8];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16]
{
  static const int32_T dims[2] = {2, 8};
  real_T(*ret)[16];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[16])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  real_T(*ret)[2];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8]
{
  static const int32_T dims = 8;
  real_T(*ret)[8];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[8])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void c_Optimization_ThelenMuscle_cod(const mxArray *const prhs[9],
                                     const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*Q)[16];
  real_T(*FM0)[8];
  real_T(*Fl)[8];
  real_T(*Fpe)[8];
  real_T(*LM0)[8];
  real_T(*VM)[8];
  real_T(*a0)[8];
  real_T(*activation)[8];
  real_T(*alpha0)[8];
  real_T(*b)[2];
  st.tls = emlrtRootTLSGlobal;
  activation = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
  /* Marshall function inputs */
  Q = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Q");
  b = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "b");
  Fl = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Fl");
  Fpe = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Fpe");
  VM = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "VM");
  LM0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "LM0");
  a0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "a0");
  alpha0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "alpha0");
  FM0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "FM0");
  /* Invoke the target function */
  Optimization_ThelenMuscle_codegen(&st, *Q, *b, *Fl, *Fpe, *VM, *LM0, *a0,
                                    *alpha0, *FM0, *activation);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*activation);
}

/* End of code generation (_coder_Optimization_ThelenMuscle_codegen_api.c) */
