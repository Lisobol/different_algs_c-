#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
long double fact(int z);
int y;

void PrintTabl(int n, long double *c, int i, int y);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "C");
	int n;
	cout << "enter n" << endl;
	cin >> n;
	long double **a = new long double*[n];
	for (int k = 0; k<n; k++)
		a[k] = new long double[n];

	for (int i = 1; i < n; i++)
	{
		for (int p = 1; p < n; p++)
		{
			a[i][p] = pow((1 / fact(i+1)), (p+1));
		}
	}

	long double *c = new long double[n];



	y = int(78 / n);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[j] = a[i][j];
		}
		PrintTabl(n, c, i, y);
	}
	cout << char(192) << setfill(char(196));//низ таблицы
	for (int j = 0; j<n; j++)
		cout << setw(y) << char(217);
	cout << endl;
	system("pause");
	return 0;
}

long double fact(int z)
{
	if (z < 0)
		return 0;
	if (z == 0)
		return 1;
	else
		return z * fact(z - 1);
}

void PrintTabl(int n, long double *c, int i, int y)
{
	if (i == 0)
	{
		cout << char(218) << setfill(char(196));
		for (int j = 0; j < n - 1; j++)
			cout << setw(y) << char(194);
		cout << setw(y) << char(191) << endl;
	}
	else
	{
		cout << char(195) << setfill(char(196));
		for (int j = 0; j < n - 1; j++)
			cout << setw(y) << char(197);
		cout << setw(y) << char(180) << endl;
	}
	int *size = new int[n];
	for (int j = 0; j < n - 1; j++)
		cout << setfill(' ');
	cout << char(179);
	for (int j = 0; j < n; j++)       //заполнение таблицы
	{
		if ((c[j] > 1.000000001) || (c[j]<0.9999999999))
		{
			cout << setw(y - 1) << scientific<<setprecision(y-7) << c[j] << char(179);
		}
		else
			cout << setw(y - 1) << c[j] << char(179);
	}
	cout << endl;
}
