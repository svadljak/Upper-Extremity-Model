/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Optimization_ThelenMuscle_codegen_data.c
 *
 * Code generation for function 'Optimization_ThelenMuscle_codegen_data'
 *
 */

/* Include files */
#include "Optimization_ThelenMuscle_codegen_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131659U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "Optimization_ThelenMuscle_codegen",                  /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2666790369U, 2630951428U, 3350295197U, 1643587045U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo h_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo k_emlrtRSI = {
    1,                /* lineNo */
    "setProblemType", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p" /* pathName */
};

emlrtRSInfo p_emlrtRSI = {
    38,      /* lineNo */
    "xcopy", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xcopy."
    "m" /* pathName */
};

emlrtRSInfo q_emlrtRSI = {
    69,      /* lineNo */
    "xcopy", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xcopy.m" /* pathName */
};

emlrtRSInfo s_emlrtRSI = {
    86,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv."
    "m" /* pathName */
};

emlrtRSInfo t_emlrtRSI = {
    58,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo u_emlrtRSI = {
    51,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo v_emlrtRSI = {
    23,       /* lineNo */
    "ixamax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\ixamax.m" /* pathName */
};

emlrtRSInfo w_emlrtRSI = {
    24,       /* lineNo */
    "ixamax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\ixamax.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    1,           /* lineNo */
    "factorQRE", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQRE.p" /* pathName */
};

emlrtRSInfo ob_emlrtRSI = {
    31,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" /* pathName */
};

emlrtRSInfo pb_emlrtRSI = {
    18,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xscal.m" /* pathName */
};

emlrtRSInfo rb_emlrtRSI = {
    74,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo sb_emlrtRSI = {
    71,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo tb_emlrtRSI = {
    37,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo vb_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

emlrtRSInfo wb_emlrtRSI = {
    41,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

emlrtRSInfo xb_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

emlrtRSInfo yb_emlrtRSI = {
    1,                /* lineNo */
    "computeSquareQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\computeSquareQ.p" /* pathName */
};

emlrtRSInfo dc_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

emlrtRSInfo hc_emlrtRSI = {
    1,              /* lineNo */
    "sortLambdaQP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p" /* pathName */
};

emlrtRSInfo rc_emlrtRSI =
    {
        35,     /* lineNo */
        "xdot", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xdot.m" /* pathName */
};

emlrtRSInfo sc_emlrtRSI = {
    15,     /* lineNo */
    "xdot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdot.m" /* pathName */
};

emlrtRSInfo tc_emlrtRSI = {
    42,      /* lineNo */
    "xdotx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" /* pathName */
};

emlrtRSInfo vc_emlrtRSI =
    {
        1,           /* lineNo */
        "countsort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
        "utils\\countsort.p" /* pathName */
};

emlrtRSInfo xc_emlrtRSI = {
    1,              /* lineNo */
    "removeConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p" /* pathName */
};

emlrtRSInfo hd_emlrtRSI = {
    1,                        /* lineNo */
    "maxConstraintViolation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation.p" /* pathName */
};

emlrtRSInfo id_emlrtRSI = {
    1,                                           /* lineNo */
    "maxConstraintViolation_AMats_regularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_regul"
    "arized_.p" /* pathName */
};

emlrtRSInfo jd_emlrtRSI = {
    41,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo kd_emlrtRSI = {
    1,                                              /* lineNo */
    "maxConstraintViolation_AMats_nonregularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_nonre"
    "gularized_.p" /* pathName */
};

emlrtRSInfo nd_emlrtRSI = {
    1,         /* lineNo */
    "iterate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p" /* pathName */
};

emlrtRSInfo sd_emlrtRSI = {
    23,      /* lineNo */
    "xrotg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg."
    "m" /* pathName */
};

emlrtRSInfo ud_emlrtRSI = {
    24,     /* lineNo */
    "xrot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xrot.m" /* pathName */
};

emlrtRSInfo ee_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "CholManager\\factor.p" /* pathName */
};

emlrtRSInfo he_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\factor.p" /* pathName */
};

emlrtRSInfo je_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "CholManager\\solve.p" /* pathName */
};

emlrtRSInfo ke_emlrtRSI = {
    55,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsv."
    "m" /* pathName */
};

emlrtRSInfo ne_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p" /* pathName */
};

emlrtRSInfo ye_emlrtRSI = {
    1,             /* lineNo */
    "addLBConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addLBConstr.p" /* pathName */
};

emlrtRSInfo bf_emlrtRSI = {
    1,             /* lineNo */
    "addUBConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addUBConstr.p" /* pathName */
};

emlrtRSInfo cf_emlrtRSI = {
    1,                          /* lineNo */
    "checkUnboundedOrIllPosed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkUnboundedOrIllPosed.p" /* pathName */
};

emlrtRSInfo df_emlrtRSI = {
    1,                            /* lineNo */
    "checkStoppingAndUpdateFval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p" /* pathName */
};

emlrtRSInfo hf_emlrtRSI = {
    1,                    /* lineNo */
    "updatePenaltyParam", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\updatePenaltyParam.p" /* pathName */
};

emlrtRSInfo jf_emlrtRSI = {
    23,      /* lineNo */
    "xasum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xasum."
    "m" /* pathName */
};

emlrtBCInfo b_emlrtBCI = {
    1,                          /* iFirst */
    26,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

emlrtBCInfo c_emlrtBCI = {
    1,                          /* iFirst */
    13,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    3                                       /* checkKind */
};

emlrtRTEInfo d_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtRTEInfo e_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtBCInfo l_emlrtBCI = {
    1,              /* iFirst */
    23,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    0                              /* checkKind */
};

emlrtBCInfo m_emlrtBCI = {
    1,              /* iFirst */
    299,            /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    0                              /* checkKind */
};

emlrtBCInfo n_emlrtBCI = {
    1,              /* iFirst */
    23,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    3                              /* checkKind */
};

emlrtBCInfo q_emlrtBCI = {
    1,                        /* iFirst */
    13,                       /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "maxConstraintViolation", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation.p", /* pName */
    0                                       /* checkKind */
};

emlrtBCInfo t_emlrtBCI = {
    1,              /* iFirst */
    6,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    0                             /* checkKind */
};

emlrtBCInfo u_emlrtBCI = {
    1,         /* iFirst */
    23,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p", /* pName */
    3                         /* checkKind */
};

emlrtBCInfo v_emlrtBCI = {
    1,         /* iFirst */
    23,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p", /* pName */
    0                         /* checkKind */
};

emlrtBCInfo ab_emlrtBCI = {
    1,              /* iFirst */
    23,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    0                             /* checkKind */
};

emlrtBCInfo bb_emlrtBCI = {
    1,              /* iFirst */
    23,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    3                             /* checkKind */
};

emlrtBCInfo cb_emlrtBCI = {
    1,              /* iFirst */
    5,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    3                             /* checkKind */
};

emlrtBCInfo db_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo eb_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p", /* pName */
    3                                         /* checkKind */
};

emlrtBCInfo lb_emlrtBCI = {
    1,           /* iFirst */
    23,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "countsort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort."
    "p", /* pName */
    3    /* checkKind */
};

emlrtBCInfo qb_emlrtBCI = {
    1,           /* iFirst */
    23,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "countsort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort."
    "p", /* pName */
    0    /* checkKind */
};

emlrtBCInfo fc_emlrtBCI = {
    1,          /* iFirst */
    23,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "isActive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\isActive.p", /* pName */
    0                         /* checkKind */
};

emlrtRTEInfo f_emlrtRTEI = {
    18,                               /* lineNo */
    27,                               /* colNo */
    "eml_int_forloop_overflow_check", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pName */
};

emlrtBCInfo vc_emlrtBCI = {
    1,        /* iFirst */
    529,      /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "factor", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\factor.p", /* pName */
    0                                  /* checkKind */
};

emlrtBCInfo jd_emlrtBCI = {
    1,                         /* iFirst */
    23,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "addConstrUpdateRecords_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addConstrUpdateRecords_.p", /* pName */
    3                                        /* checkKind */
};

const int32_T iv[4] = {0, 1, 2, 3};

/* End of code generation (Optimization_ThelenMuscle_codegen_data.c) */
