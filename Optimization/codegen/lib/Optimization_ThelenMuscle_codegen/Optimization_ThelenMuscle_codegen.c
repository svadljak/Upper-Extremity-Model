/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Optimization_ThelenMuscle_codegen.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "Optimization_ThelenMuscle_codegen.h"
#include "fmincon.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Ověření pevné velikosti vstupů
 *
 * Arguments    : const double Q[16]
 *                const double b[2]
 *                const double Fl[8]
 *                const double Fpe[8]
 *                const double VM[8]
 *                const double LM0[8]
 *                const double a0[8]
 *                const double alpha0[8]
 *                const double FM0[8]
 *                double activation[8]
 * Return Type  : void
 */
void Optimization_ThelenMuscle_codegen(const double Q[16], const double b[2],
                                       const double Fl[8], const double Fpe[8],
                                       const double VM[8], const double LM0[8],
                                       const double a0[8],
                                       const double alpha0[8],
                                       const double FM0[8],
                                       double activation[8])
{
  /*  Dolní a horní meze */
  fmincon(a0, Q, b, Fl, Fpe, VM, LM0, alpha0, FM0, activation);
}

/*
 * Arguments    : const double Q[16]
 *                const double b[2]
 *                const double Fl[8]
 *                const double Fpe[8]
 *                const double VM[8]
 *                const double LM0[8]
 *                const double alpha0[8]
 *                const double FM0[8]
 *                const double a[8]
 *                double varargout_2[2]
 * Return Type  : void
 */
void c_Optimization_ThelenMuscle_cod(const double Q[16], const double b[2],
                                     const double Fl[8], const double Fpe[8],
                                     const double VM[8], const double LM0[8],
                                     const double alpha0[8],
                                     const double FM0[8], const double a[8],
                                     double varargout_2[2])
{
  double Fm[8];
  double fvm;
  int i;
  int k;
  /*  a shape factor for the force-velocity relationship */
  /*  maximum normalized muscle force achievable when the fiber is lengthening
   */
  for (k = 0; k < 8; k++) {
    double d;
    double d1;
    fvm = 10.0 * LM0[k];
    d = VM[k];
    if (d <= 0.0) {
      double fvm_tmp;
      d1 = a[k];
      fvm_tmp = 3.0 * d1 + 1.0;
      fvm = 0.3 * (4.0 * d + fvm * fvm_tmp) / (-4.0 * d + fvm * 0.3 * fvm_tmp);
    } else {
      double fvm_tmp;
      d1 = a[k];
      fvm_tmp = 0.3 * fvm * (((3.0 * d1 * 1.4 - 3.0 * d1) + 1.4) - 1.0);
      fvm = (fvm_tmp + 8.0 * d * 1.4 * 1.3) / (fvm_tmp + 8.0 * d * 1.3);
    }
    /*  Fm(k) = a*Fl(k)*fvm + Fpe(k); */
    fvm = FM0[k] * (d1 * Fl[k] * fvm + Fpe[k]) * cos(alpha0[k]);
    Fm[k] = fvm;
    if (fvm <= 0.0) {
      Fm[k] = 0.0;
    }
  }
  for (k = 0; k < 2; k++) {
    fvm = 0.0;
    for (i = 0; i < 8; i++) {
      fvm += Q[k + (i << 1)] * Fm[i];
    }
    varargout_2[k] = fvm - b[k];
  }
}

/*
 * File trailer for Optimization_ThelenMuscle_codegen.c
 *
 * [EOF]
 */
