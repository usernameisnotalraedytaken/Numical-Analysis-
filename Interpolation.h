#include "NumAnalysis.h"

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

struct point
{
	double x;
	double y;
	void set(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

double NewtonPolynomial(point* p, double *c, int datacount, double px)
{
	double py = 0;
	const int n = datacount;
	for(int i = 1; i <= n; ++i)
	{
		double term = c[i];
		for(int j = 1; j < i; ++j)
		{
			term *= px - p[j].x;
		}
		py += term;
	}
	return py;
}
void NewtonInterpolation(point* p, double *c, int datacount)
{
	const int n = datacount;
	double v[n + 1][n + 1];
	for(int j = 1; j <= n; ++j)
	{
		v[j][1] = p[j].y;
	}
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= n + 1 - i; ++j)
		{
			v[j][i] = (v[j + 1][i - 1] - v[j][i - 1]) / (p[j + i - 1].x - p[j].x);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		c[i] = v[1][i];
	}
}

point BesselCurve(point p1, point p2, point p3, point p4, double t)
{
	double bx = 3.0 * (p2.x - p1.x);
	double cx = 3.0 * (p3.x - p2.x) - bx;
	double dx = p4.x - p1.x - bx - cx;
	double by = 3.0 * (p2.y - p1.y);
	double cy = 3.0 * (p3.y - p2.y) - by;
	double dy = p4.y - p1.y - by - cy;
	point tt;
	tt.set(p1.x + bx * t + cx * t * t + dx * t * t * t, p1.y + by * t + cy * t * t + dy * t * t * t);
	return tt;
}
#endif
