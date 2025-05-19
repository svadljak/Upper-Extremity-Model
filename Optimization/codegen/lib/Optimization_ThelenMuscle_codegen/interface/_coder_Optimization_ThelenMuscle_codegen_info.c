/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Optimization_ThelenMuscle_codegen_info.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "_coder_Optimization_ThelenMuscle_codegen_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  static const int32_T iv[2] = {0, 1};
  const mxArray *m;
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&nameCaptureInfo, m);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 9);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("Optimization_ThelenMuscle_codegen"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(9.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\jakub\\MATLAB Drive\\GACR_Exoskelety\\01_Planar "
          "Model\\UpperLimb_Exo_ModelReference\\Equations_of_"
          "Motion\\Optimalizac"
          "e\\Optimization_ThelenMuscle_codegen.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739683.91706018522));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2863752 (R2024b) Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("UZNV6GSDjNHqUjgyPa3PcG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_Optimization_ThelenMuscle_codegen_info.c
 *
 * [EOF]
 */
