#include "NumAnalysis.h"

#ifndef DIFF_H
#define DIFF_H

/*
一阶导数
三点中心差分公式 
二阶公式 
f ：传入函数
x : 参数 
*/
double d1f2(double f(double), double x)
{
	return (f(x + DIFF1_STEP) - f(x - DIFF1_STEP)) / (2.0 * DIFF1_STEP);
}

/*
一阶导数 
五点中心差分公式 
四阶公式 
f ：传入函数
x : 参数 
*/
double d1f4(double f(double), double x)
{
	return (f(x - DIFF1_STEP) - 8.0 * f(x - DIFF1_STEP / 2.0) + 8.0 * f(x + DIFF1_STEP / 2.0) - f(x + DIFF1_STEP)) / (6.0 * DIFF1_STEP);
}

/*
二阶导数
三点中心差分公式 
二阶公式 
f ：传入函数
x : 参数 
*/
double d2f2(double f(double), double x)
{
    return (f(x - DIFF2_STEP) - 2.0 * f(x) + f(x + DIFF2_STEP)) / (DIFF2_STEP * DIFF2_STEP);
}

/*
二阶导数 
五点中心差分公式 
四阶公式 
f ：传入函数
x : 参数 
*/
double d2f4(double f(double), double x)
{
	return (-f(x - DIFF2_STEP) + 16.0 * f(x - DIFF2_STEP / 2.0) - 30.0 * f(x) + 16.0 * f(x + DIFF2_STEP / 2.0) - f(x + DIFF2_STEP)) / (3.0 * DIFF2_STEP * DIFF2_STEP);
}

/*
三阶导数
四点中心差分公式 
二阶公式 
f ：传入函数
x : 参数 
*/
double d3f2(double f(double), double x)
{
	return (-f(x - 2.0 * DIFF3_STEP) + 2.0 * f(x - DIFF3_STEP) - 2.0 * f(x + DIFF3_STEP) + f(x + 2.0 * DIFF3_STEP)) / (2.0 * DIFF3_STEP * DIFF3_STEP * DIFF3_STEP);
}

/*
四阶导数 
五点中心差分公式 
二阶公式 
f ：传入函数
x : 参数 
*/
double d4f2(double f(double), double x)
{
	return (f(x - 2.0 * DIFF4_STEP) - 4.0 * f(x - DIFF4_STEP) + 6.0 * f(x) - 4.0 * f(x + DIFF4_STEP) + f(x + 2.0 * DIFF4_STEP)) / (DIFF4_STEP * DIFF4_STEP * DIFF4_STEP * DIFF4_STEP);
}

#endif
