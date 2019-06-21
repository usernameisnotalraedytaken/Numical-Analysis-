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

double BackwardEuler(double f(double, double), double x, double y, double h)
{
	double x1, x2 = 1, x0 = 0.5;
	while(x2 > EPS)
	{
		double xx = x0;
		x0 = y + h * f(x + h, x0);
		x2 = x0 - xx;
		if(x2 < 0.0)	x2 = 0.0 - x2;
	}
	return x0;
}
double AB2(double f(double, double), double x0 ,double y0, double x1, double y1, double h)
{
	return y1 + h * (3.0 * f(x1, y1) / 2.0 - f(x0, y0) / 2.0);
}
double AM2(double f(double, double), double x0 ,double y0, double x1, double y1, double h)
{
	double wp = 0.5, xp = x1 + h, x2 = 1;
	while(x2 > EPS)
	{
		double ww = wp;
		wp = y0 + h / 12.0 * ( 5.0 * f( xp , wp ) + 8.0 * f( x1, y1 ) - f( x0, y0 ));
		x2 = wp - ww;
		if(x2 < 0.0) x2 = 0.0 - x2;
	}
	return wp;
}
double AM3(double f(double, double), double x0 ,double y0, double x1, double y1, double x2, double y2, double h)
{
	double wp = 0.5, xp = x1 + h, x22 = 1;
	while(x22 > EPS)
	{
		double ww = wp;
		wp = y0 + h / 24.0 * ( 9.0 * f( xp , wp ) + 19.0 * f( x2, y2 ) - 5.0 * f( x1, y1 ) + f( x0, y0 ));
		x22 = wp - ww;
		if(x22 < 0.0) x22 = 0.0 - x22;
	}
	return wp;
}
double AM4(double f(double, double), double x0 ,double y0, double x1, double y1, double x2, double y2, double x3, double y3, double h)
{
	double wp = 0.5, xp = x1 + h, x22 = 1;
	while(x22 > EPS)
	{
		double ww = wp;
		wp = y0 + h / 720.0 * ( 251.0 * f( xp , wp ) + 646.0 * f( x3, y3 ) - 264.0 * f( x2, y2 ) + 106.0 * f( x1, y1 ) - 19.0 * f(x0, y0));
		x22 = wp - ww;
		if(x22 < 0.0) x22 = 0.0 - x22;
	}
	return wp;
}
double AB3(double f(double, double), double x0 ,double y0, double x1, double y1, double x2, double y2, double h)
{
	return y0 + h / 12.0 * ( 23.0 * f(x2, y2) - 16.0 * f(x1, y1) + 5 * f(x0, y0));
}
double AB4(double f(double, double), double x0 ,double y0, double x1, double y1, double x2, double y2, double x3, double y3, double h)
{
	return y0 + h / 12.0 * ( 55.0 * f(x3, y3) - 59.0 * f(x2, y2) + 37.0 * f(x1, y1) - 9.0 * f(x0, y0));
}
#endif
