#include "NumAnalysis.h"

#ifndef DIFF_H
#define DIFF_H

double d1f2(double f(double), double x)
{
	return (f(x + DIFF1_STEP) - f(x - DIFF1_STEP)) / (2.0 * DIFF1_STEP);
}
double d1f4(double f(double), double x)
{
	return (f(x - DIFF1_STEP) - 8.0 * f(x - DIFF1_STEP / 2.0) + 8.0 * f(x + DIFF1_STEP / 2.0) - f(x + DIFF1_STEP)) / (6.0 * DIFF1_STEP);
}
double d2f2(double f(double), double x)
{
    return (f(x - DIFF2_STEP) - 2.0 * f(x) + f(x + DIFF2_STEP)) / (DIFF2_STEP * DIFF2_STEP);
}
double d2f4(double f(double), double x)
{
	return (-f(x - DIFF2_STEP) + 16.0 * f(x - DIFF2_STEP / 2.0) - 30.0 * f(x) + 16.0 * f(x + DIFF2_STEP / 2.0) - f(x + DIFF2_STEP)) / (3.0 * DIFF2_STEP * DIFF2_STEP);
}
double d3f2(double f(double), double x)
{
	return (-f(x - 2.0 * DIFF3_STEP) + 2.0 * f(x - DIFF3_STEP) - 2.0 * f(x + DIFF3_STEP) + f(x + 2.0 * DIFF3_STEP)) / (2.0 * DIFF3_STEP * DIFF3_STEP * DIFF3_STEP);
}
double d4f2(double f(double), double x)
{
	return (f(x - 2.0 * DIFF4_STEP) - 4.0 * f(x - DIFF4_STEP) + 6.0 * f(x) - 4.0 * f(x + DIFF4_STEP) + f(x + 2.0 * DIFF4_STEP)) / (DIFF4_STEP * DIFF4_STEP * DIFF4_STEP * DIFF4_STEP);
}
double d1f2eps(double f(double), double x, double eps)
{
	return (f(x + eps) - f(x - eps)) / (2.0 * eps);
}
double d1f4eps(double f(double), double x, double eps)
{
	return (f(x - eps) - 8.0 * f(x - eps / 2.0) + 8.0 * f(x + eps / 2.0) - f(x + eps)) / (6.0 * eps);
}
double d2f2eps(double f(double), double x, double eps)
{
    return (f(x - eps) - 2.0 * f(x) + f(x + eps)) / (eps * eps);
}
double d2f4eps(double f(double), double x, double eps)
{
	return (-f(x - eps) + 16.0 * f(x - eps / 2.0) - 30.0 * f(x) + 16.0 * f(x + eps / 2.0) - f(x + eps)) / (3.0 * eps * eps);
}
double d3f2eps(double f(double), double x, double eps)
{
	return (-f(x - 2.0 * eps) + 2.0 * f(x - eps) - 2.0 * f(x + eps) + f(x + 2.0 * eps)) / (2.0 * eps * eps * eps);
}
double d4f2eps(double f(double), double x, double eps)
{
	return (f(x - 2.0 * eps) - 4.0 * f(x - eps) + 6.0 * f(x) - 4.0 * f(x + eps) + f(x + 2.0 * eps)) / (eps * eps * eps * eps);
}
#endif
