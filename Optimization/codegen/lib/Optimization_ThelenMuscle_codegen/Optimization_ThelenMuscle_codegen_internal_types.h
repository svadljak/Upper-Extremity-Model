/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Optimization_ThelenMuscle_codegen_internal_types.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

#ifndef OPTIMIZATION_THELENMUSCLE_CODEGEN_INTERNAL_TYPES_H
#define OPTIMIZATION_THELENMUSCLE_CODEGEN_INTERNAL_TYPES_H

/* Include Files */
#include "Optimization_ThelenMuscle_codegen_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double Q[16];
  double b[2];
  double Fl[8];
  double Fpe[8];
  double VM[8];
  double LM0[8];
  double alpha0[8];
  double FM0[8];
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  struct_T workspace;
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

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  double workspace_float[299];
  int workspace_int[23];
  int workspace_sort[23];
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  double sqpFval;
  double sqpFval_old;
  double xstarsqp[8];
  double xstarsqp_old[8];
  double cEq[2];
  double cEq_old[2];
  double grad[13];
  double grad_old[13];
  int FunctionEvaluations;
  int sqpIterations;
  double lambdasqp[23];
  double lambdaStopTest[23];
  double lambdaStopTestPrev[23];
  double steplength;
  double delta_x[13];
  double socDirection[13];
  double JacCeqTrans_old[26];
  double gradLag[13];
  double delta_gradLag[13];
  double xstar[13];
  double fstar;
  double lambda[23];
  int state;
  double maxConstr;
  int iterations;
  double searchDir[13];
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  anonymous_function nonlin;
  double f_1;
  double cEq_1[2];
  int numEvals;
  boolean_T hasBounds;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  int mConstr;
  int nVar;
  double Aeq[26];
  double beq[2];
  double lb[13];
  double ub[13];
  int indexLB[13];
  int indexUB[13];
  int mEqRemoved;
  int indexEqRemoved[2];
  double ATwset[299];
  double bwset[23];
  int nActiveConstr;
  double maxConstrWorkspace[23];
  int sizes[5];
  int sizesNormal[5];
  int sizesPhaseOne[5];
  int sizesRegularized[5];
  int sizesRegPhaseOne[5];
  int isActiveIdx[6];
  int isActiveIdxNormal[6];
  int isActiveIdxPhaseOne[6];
  int isActiveIdxRegularized[6];
  int isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[23];
  int Wid[23];
  int Wlocalidx[23];
  int nWConstr[5];
  int probType;
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  double penaltyParam;
  double threshold;
  int nPenaltyDecreases;
  double linearizedConstrViol;
  double initFval;
  double initConstrViolationEq;
  double phi;
  double phiPrimePlus;
  double phiFullStep;
  double feasRelativeFactor;
  double nlpDualFeasError;
  double nlpComplError;
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  double QR[529];
  double Q[529];
  int jpvt[23];
  int mrows;
  int ncols;
  double tau[23];
  int minRowCol;
  boolean_T usedPivoting;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
  double FMat[529];
  int ndims;
  int info;
  boolean_T ConvexCheck;
  double workspace_;
} h_struct_T;
#endif /* typedef_h_struct_T */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  double grad[13];
  double Hx[12];
  boolean_T hasLinear;
  int nvar;
  double beta;
  double rho;
  int objtype;
  int prev_objtype;
  int prev_nvar;
  boolean_T prev_hasLinear;
  double gammaScalar;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_j_struct_T
#define typedef_j_struct_T
typedef struct {
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int stepType;
} j_struct_T;
#endif /* typedef_j_struct_T */

#ifndef typedef_k_struct_T
#define typedef_k_struct_T
typedef struct {
  char SolverName[7];
  int MaxIterations;
} k_struct_T;
#endif /* typedef_k_struct_T */

#endif
/*
 * File trailer for Optimization_ThelenMuscle_codegen_internal_types.h
 *
 * [EOF]
 */
