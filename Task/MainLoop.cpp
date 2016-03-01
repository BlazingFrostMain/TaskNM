#include<iostream>
#include<iomanip>
using namespace std;

#include "Inc\TranscendentalFunctions.h"

#define N_1 11
#define H_1 0.4

//#define FIRSTTASK
#define SECONDTASK

int wmain()
{
	double *x = new double[N_1];
	double *f = new double[N_1];

	x[0] = 0;
	for (int i = 1; i < N_1; i++)
		x[i] = x[i - 1] + H_1;

	FIntegralSine::Tabulation(x, f, N_1);
	for (int i = 0; i < N_1; i++) {
		cout << setprecision(1) << setiosflags(ios::fixed) << x[i];
		cout << setprecision(7) << char(9) << "--->" << char(9) << f[i] << '\n';
	}

	delete[] x;
	delete[] f;

	system("pause");
	return 0;
}
