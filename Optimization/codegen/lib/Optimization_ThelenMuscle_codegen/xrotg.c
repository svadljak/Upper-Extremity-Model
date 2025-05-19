/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrotg.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 07-Mar-2025 22:05:45
 */

/* Include Files */
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double *a
 *                double *b
 *                double *s
 * Return Type  : double
 */
double xrotg(double *a, double *b, double *s)
{
  double absa;
  double absb;
  double c;
  double scale;
  c = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    c = *a;
  }
  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    double ads;
    double bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (c < 0.0) {
      scale = -scale;
    }
    c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (c != 0.0) {
      *b = 1.0 / c;
    } else {
      *b = 1.0;
    }
    *a = scale;
  }
  return c;
}

/*
 * File trailer for xrotg.c
 *
 * [EOF]
 */
