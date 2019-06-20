#include "NumAnalysis.h"

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

double NewtonPolynomial(double *x, double *c, int datacount, double px)
{
	double py = 0;
	const int n = datacount;
	for(int i = 1; i <= n; ++i)
	{
		double term = c[i];
		for(int j = 1; j < i; ++j)
		{
			term *= px - x[j];
		}
		py += term;
	}
	return py;
}
void NewtonInterpolation(double *x, double *y, double *c, int datacount)
{
	const int n = datacount;
	double v[n + 1][n + 1];
	for(int j = 1; j <= n; ++j)
	{
		v[j][1] = y[j];
	}
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= n + 1 - i; ++j)
		{
			v[j][i] = (v[j + 1][i - 1] - v[j][i - 1]) / (x[j + i - 1] - x[j]);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		c[i] = v[1][i];
	}
}

#endif
