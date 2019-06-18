#include "NumAnalysis.h"
#include "DIff.h"

#ifndef SOLVE_H
#define SOLVE_H

double Bisection(double f(double), double a, double b)
{
	while((b - a) / 2.0 > EPS)
	{
		double c = (a + b) / 2.0;
		if(f(c) == 0)
		{
			return c;
		}
		if(f(a) * f(c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	}
	return (a + b) / 2.0;
}

double FPI(double f(double), double x0)
{
	for(int i = 0; i < FPI_STEP_COUNT; ++i)
	{
		x0 = f(x0);
	}
	return x0;
}

double Newton(double f(double), double x0)
{
	double x1, x2 = 1;
	while(x2 > EPS)
	{
		x1 = x0 - f(x0) / d1f4(f, x0);
		x0 = x1;
		if(f(x0) < 0)
			x2 = 0.0 - f(x0);
		else
			x2 = f(x0);
	}
	return x0;
}

double Secant(double f(double), double x0, double x1)
{
	double x2 = 1;
	while(x2 > EPS)
	{
		x1 = x0 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
		x0 = x1;
		if(f(x0) < 0)
			x2 = 0.0 - f(x0);
		else
			x2 = f(x0);
	}
}

double RegulaFalsi(double f(double), double a, double b)
{
	double c;
	while((b - a) / 2.0 > EPS)
	{
		c = (b * f(a) - a * f(b)) / (f(a) - f(b));
		if(f(c) == 0)
		{
			return c;
		}
		if(f(a) * f(c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	}
	return c;
}
#endif
