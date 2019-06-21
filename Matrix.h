#ifndef MATRIX_H
#define MATRIX_H

#include "NumAnalysis.h"
#define SIZE 10

struct matrix
{
	int m, n;
	double mat[SIZE][SIZE];
};
matrix O(int m ,int n)
{
	matrix c;
	c.m = m;
	c.n = n;
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0 ;j < n; ++j)
		{
			c.mat[i][j] = 0;
		}
	}
	return c;
}
matrix add(matrix a, matrix b)
{
	matrix c = a;
	for(int i = 0 ;i < a.m; ++i)
	{
		for(int j = 0; j < a.n; ++j)
		{
			c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
	}
	return c;
}
matrix sub(matrix a, matrix b)
{
	matrix c = a;
	for(int i = 0 ;i < a.m; ++i)
	{
		for(int j = 0; j < a.n; ++j)
		{
			c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
		}
	}
	return c;
}
matrix mul(matrix a, matrix b)
{
	if(b.n == a.m);
	matrix c = O(b.m, a.n);
	for(int i = 0 ;i < b.m; ++i)
	{
		for(int j = 0; j < a.n; ++j)
		{
			double sum = 0;
			for(int k = 0; k < b.n; ++k)
			{
				sum += a.mat[i][k] * b.mat[k][j];
			}
			c.mat[i][j] = sum;			
		}
	}
	return c;
}
#endif
