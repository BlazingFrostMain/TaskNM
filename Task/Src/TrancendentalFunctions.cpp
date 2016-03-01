#include "..\Inc\TranscendentalFunctions.h"

void FIntegralSine::Tabulation(double * x, double * f, int n)
{
	for (int i = 0; i < n; i++)
	{
		f[i] = Sum(x[i]);
	}
}

double FIntegralSine::NIP(double * x, double * f, int n, double xx)
{
	double Result;

	for (int i = 0;i < n;i++)
	{
		double P = f[i];
		for (int j = 0;j < n;j++)
			P *= (xx - x[j]);
		Result += P;
	}

	return Result;
}

double FIntegralSine::Sum(double x) {
	double Unit = x;
	double Result = Unit;
	for (int i = 0;fabs(Unit) >= EPSILON;i++)
	{
		int temp = 2 * i;
		Unit *= (-1) * x * x * (temp + 1) / (temp + 3) / (temp + 3) / (temp + 2);
		Result += Unit;
	}
	return Result;
}

void FIntegralSine::SplitDifference(double * x, double * f, int n)
{
	double* temp = new double[n];

	for (int i = 1;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			temp[j] = (f[j] - f[j - 1]) / (x[j] - x[j - i]);
		}
		for (int j = i;j < n;j++)
		{
			f[j] = temp[j];
		}
	}

	delete[] temp;
}
