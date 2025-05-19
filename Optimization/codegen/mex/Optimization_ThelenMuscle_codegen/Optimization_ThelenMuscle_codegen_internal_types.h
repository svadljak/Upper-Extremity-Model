/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen_internal_types.h
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen'
 *
 */

#pragma once

/* Include files */
#include "Optimization_ThelenMuscle_codegen_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  real_T Q[16];
  real_T b[2];
  real_T Fl[8];
  real_T Fpe[8];
  real_T VM[8];
  real_T LM0[8];
  real_T alpha0[8];
  real_T FM0[8];
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  b_struct_T workspace;
} anonymous_function;
#endif /* typedef_anonymous_function */

#ifndef c_typedef_coder_internal_sticky
#define c_typedef_coder_internal_sticky
typedef struct {
  anonymous_function value;
} coder_internal_stickyStruct;
#endif /* c_typedef_coder_internal_sticky */

#ifndef c_typedef_b_coder_internal_stic
#define c_typedef_b_coder_internal_stic
typedef struct {
  coder_internal_stickyStruct next;
} b_coder_internal_stickyStruct;
#endif /* c_typedef_b_coder_internal_stic */

#ifndef c_typedef_c_coder_internal_stic
#define c_typedef_c_coder_internal_stic
typedef struct {
  b_coder_internal_stickyStruct next;
} c_coder_internal_stickyStruct;
#endif /* c_typedef_c_coder_internal_stic */

#ifndef c_typedef_d_coder_internal_stic
#define c_typedef_d_coder_internal_stic
typedef struct {
  c_coder_internal_stickyStruct next;
} d_coder_internal_stickyStruct;
#endif /* c_typedef_d_coder_internal_stic */

#ifndef c_typedef_e_coder_internal_stic
#define c_typedef_e_coder_internal_stic
typedef struct {
  d_coder_internal_stickyStruct next;
} e_coder_internal_stickyStruct;
#endif /* c_typedef_e_coder_internal_stic */

#ifndef c_typedef_f_coder_internal_stic
#define c_typedef_f_coder_internal_stic
typedef struct {
  e_coder_internal_stickyStruct next;
} f_coder_internal_stickyStruct;
#endif /* c_typedef_f_coder_internal_stic */

#ifndef c_typedef_g_coder_internal_stic
#define c_typedef_g_coder_internal_stic
typedef struct {
  f_coder_internal_stickyStruct next;
} g_coder_internal_stickyStruct;
#endif /* c_typedef_g_coder_internal_stic */

#ifndef c_typedef_h_coder_internal_stic
#define c_typedef_h_coder_internal_stic
typedef struct {
  g_coder_internal_stickyStruct next;
} h_coder_internal_stickyStruct;
#endif /* c_typedef_h_coder_internal_stic */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  real_T workspace_float[299];
  int32_T workspace_int[23];
  int32_T workspace_sort[23];
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[8];
  real_T xstarsqp_old[8];
  real_T cEq[2];
  real_T cEq_old[2];
  real_T grad[13];
  real_T grad_old[13];
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  real_T lambdasqp[23];
  real_T lambdaStopTest[23];
  real_T lambdaStopTestPrev[23];
  real_T steplength;
  real_T delta_x[13];
  real_T socDirection[13];
  real_T JacCeqTrans_old[26];
  real_T gradLag[13];
  real_T delta_gradLag[13];
  real_T xstar[13];
  real_T fstar;
  real_T lambda[23];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[13];
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  anonymous_function nonlin;
  real_T f_1;
  real_T cEq_1[2];
  int32_T numEvals;
  boolean_T hasBounds;
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  int32_T mConstr;
  int32_T nVar;
  real_T Aeq[26];
  real_T beq[2];
  real_T lb[13];
  real_T ub[13];
  int32_T indexLB[13];
  int32_T indexUB[13];
  int32_T mEqRemoved;
  int32_T indexEqRemoved[2];
  real_T ATwset[299];
  real_T bwset[23];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[23];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[23];
  int32_T Wid[23];
  int32_T Wlocalidx[23];
  int32_T nWConstr[5];
  int32_T probType;
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
  real_T QR[529];
  real_T Q[529];
  int32_T jpvt[23];
  int32_T mrows;
  int32_T ncols;
  real_T tau[23];
  int32_T minRowCol;
  boolean_T usedPivoting;
} h_struct_T;
#endif /* typedef_h_struct_T */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  real_T FMat[529];
  int32_T ndims;
  int32_T info;
  boolean_T ConvexCheck;
  real_T workspace_;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_j_struct_T
#define typedef_j_struct_T
typedef struct {
  real_T grad[13];
  real_T Hx[12];
  boolean_T hasLinear;
  int32_T nvar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
} j_struct_T;
#endif /* typedef_j_struct_T */

#ifndef typedef_k_struct_T
#define typedef_k_struct_T
typedef struct {
  char_T SolverName[7];
  int32_T MaxIterations;
} k_struct_T;
#endif /* typedef_k_struct_T */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtDoubleCheckInfo
#define typedef_rtDoubleCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
} rtDoubleCheckInfo;
#endif /* typedef_rtDoubleCheckInfo */

#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo
typedef struct {
  int32_T nDims;
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtEqualityCheckInfo;
#endif /* typedef_rtEqualityCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (Optimization_ThelenMuscle_codegen_internal_types.h)
 */
