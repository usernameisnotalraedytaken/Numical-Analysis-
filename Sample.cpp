#include "cna.h"
#define H 1e-6
double f(double x, double y)
{
	return 2 * x;
}
int main()
{
	double x0 = 1.0, y0 = 1.0, x1 = x0 + H, y1 = RK4(f, x0, y0, H);
	for(int i = 0; i < 1000000 - 1; ++i)
	{
		double xx= x0 ,yy = y0;
		x0 = x1;
		y1 = AM2(f, xx, yy, x1, y1, H);
		x1 += H;

		y0 = y1;
		//
	}printf("x0 = %.7lf\ty0 = %.7lf\n", x0, y0);
	return 0;
}
