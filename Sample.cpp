#include "cna.h"
double f(double x)
{
	return log(x);
}
int main()
{
	printf("f(x) := ln x\n");
	printf("f\'(1) = %.10lf\n", d1f4(f, 1));
	printf("f\'\'(1) = %.10lf\n", d2f4(f, 1));
	printf("f\'\'\'(1) = %.10lf\n", d3f2(f, 1));
	printf("f\'\'\'\'(1) = %.10lf\n", d4f2(f, 1));
	printf("Intt f(x) from 1 to 2 dx using Romberg Intt = %.10lf\n", Romberg(f, 1.0, 2.0, 10));
	return 0;
}
