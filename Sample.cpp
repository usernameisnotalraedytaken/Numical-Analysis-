#include "cna.h"
#define H 1e-6
double f(double x)
{
	return cos(x) - sin(x);
}
int main()
{
	printf("%.7lf", Brent(f, 0 ,0.5, 1));
	return 0;
}
