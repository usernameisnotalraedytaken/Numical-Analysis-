#include "NumAnalysis.h"

#ifndef ODE_H
#define ODE_H

double Euler(double f(double, double), double x, double y, double h)
{
	double Yn = y + h * f(x, y);
}
double MEuler(double f(double, double), double x, double y, double h)
{
	double Yn = y + h * f(x + h / 2.0, y + h / 2.0 * f(x, y));
	return Yn;
}
double RK2(double f(double, double), double x, double y, double h)
{
	double Yn = y + h / 2.0 * (f(x, y) + f(x + h, y + h * f(x, y)));
	return Yn;
}
double RK4(double f(double, double), double x, double y, double h)
{
	double K1 = f(x, y);
	double K2 = f(x + h / 2.0, y + h / 2.0 * K1);
	double K3 = f(x + h / 2.0, y + h / 2.0 * K2);
	double K4 = f(x + h, y + h * K3);
	double Yn = y + h / 6.0 * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
	return Yn;
}

#endif
