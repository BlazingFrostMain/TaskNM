#pragma once

#include <math.h>

#define EPSILON 0.000001

class FIntegralSine
{
public:
	static void Tabulation(double* x, double* f, int n);
	static double NIP(double* x, double* f, int n, double xx);
protected:

private:
	static double Sum(double x);
	static void SplitDifference(double* x, double* f, int n);
};