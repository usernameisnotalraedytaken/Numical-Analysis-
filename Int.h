#include "NumAnalysis.h"

#ifndef INT_H
#define INT_H


double Romberg(double g(double), double x1, double x2, int n)
{
	double R[n + 1][n + 1] = {0};
	double h[n + 1] = {0};
	R[1][1] = (x2 - x1) * (g(x1) + g(x2)) / 2.0;
	for(int j = 2; j <= n; ++j)
	{
		h[j] = (x2 - x1) / pow(2.0, j - 1);
		double sum = 0;
		for(int i = 1; i <= int(pow(2, j - 2)); ++i)
		{
			sum += g(x1 + (2.0 * i - 1.0) * h[j]);
		}
		R[j][1] = R[j - 1][1] / 2.0 + h[j] * sum;
		for(int k = 2; k <= j; ++k)
		{
			R[j][k] = (pow(4.0, k - 1) * R[j][k - 1] - R[j - 1][k - 1]) / (pow(4.0, k - 1) - 1.0);
		}
	}
	return R[n][n];
}
#endif
