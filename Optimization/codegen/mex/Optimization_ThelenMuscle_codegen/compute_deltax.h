/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_deltax.h
 *
 * Code generation for function 'compute_deltax'
 *
 */

#pragma once

/* Include files */
#include "Optimization_ThelenMuscle_codegen_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void compute_deltax(const emlrtStack *sp, const real_T H[64],
                    d_struct_T *solution, c_struct_T *memspace,
                    const h_struct_T *qrmanager, i_struct_T *cholmanager,
                    const j_struct_T *objective, boolean_T alwaysPositiveDef);

/* End of code generation (compute_deltax.h) */
