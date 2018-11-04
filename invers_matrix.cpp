#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>

using namespace std;
long double fact(int z);
int h;

void PrintTabl(int n, double *c, int i, int h);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "C");
	int n;
	cout << "enter n" << endl;
	cin >> n;
	int **a = new int*[n];
	for (int k = 0; k<n; k++)
		a[k] = new int[n];
	double **b = new double*[n];
	for (int k = 0; k<n; k++)
		b[k] = new double[2 * n];
	double *t = new double[n];
	
	for (int i = 0; i<n; i++)   //ввод массива
	{
		for (int k = 0; k<n; k++)
		{
			//a[i][k] = rand() % 100;
			//cout << a[i][k] << "; ";
			cout << "enter a" << endl;
			cin >> a[i][k];
		}
	}
	h = int(78 / n);                  //выравнивание размера таблицы
	int m = 0;
	cout << endl;
	for (int k = 0; k < n; k++) //проверка существования матрицы
	{
		m = 0;
		if (a[k][k] == 0)
		{
			for (int p = 0; p < n; p++)
			{
				if ((a[p][k] != 0) && (a[k][p] != 0))
				{
					for (int y = 0; y < n; y++)
					{
						t[y] = a[p][y];
						a[p][y] = a[k][y];
						a[k][y] = t[y];
						m++;
					}
				}
			}
			if (m == 0)
			{
				cout << "reverse matrix doesn't exist" << endl;
				system("pause");
				return 0;
			}
		}
	}

	for (int k = 0; k < n; k++)//единичная матрица
	{
		for (int p = n; p < 2 * n; p++)
		{
			if (k == (p - n))
				b[k][p] = 1;
			else b[k][p] = 0;
		}
	}
	for (int k = 0; k < n; k++)//заполнение массива b значениями(нужна при использовании rand)
	{
		for (int p = 0; p < n; p++)
		{
			b[k][p] = a[k][p];
		}
	}
	double l;
	for (int u = 0; u < n; u++)//прямой ход
	{
		l = b[u][u];
		for (int i = 0; i < 2 * n; i++)
		{
			b[u][i] = b[u][i] / l;
		}
		for (int i = u + 1; i < n; i++)
		{
			l = b[i][u];
			for (int p = u; p < 2 * n; p++)
			{
				if (l != 0)
					b[i][p] = b[i][p] - l*b[u][p];
			}
		}
	}
	for (int u = n - 1; u >0; u--)//обратный ход
	{
		for (int i = u - 1; i >= 0; i--)
		{
			l = b[i][u];
			for (int p = u; p < 2 * n; p++)
			{
				if (l != 0)
					b[i][p] = b[i][p] - l*b[u][p];
			}
		}
	}
	double *c = new double[2 * n];
	for (int i = 0; i < n; i++)//проверка существования обратной матрицы
	{
		if (b[i][i] != 1)
		{
			cout << "reverse matrix doesn't exist" << endl;
			system("pause");
			return 0;
		}
		
	
	}
	for (int i = 0; i < n; i++)//вывод обратной матрицы
	{
		for (int j = n; j < 2* n; j++)
		{
			c[j - n] = b[i][j];
		}
		PrintTabl(n, c, i, h);
	}
	cout << char(192) << setfill(char(196));//низ таблицы
	for (int j = 0; j<n; j++)
		cout << setw(h) << char(217);
	cout << endl;
	system("pause");
	return 0;
}



void PrintTabl(int n, double *c, int i, int h)
{
	if (i == 0)
	{
		cout << char(218) << setfill(char(196));
		for (int j = 0; j < n - 1; j++)
			cout << setw(h) << char(194);
		cout << setw(h) << char(191) << endl;
	}
	else
	{
		cout << char(195) << setfill(char(196));
		for (int j = 0; j < n - 1; j++)
			cout << setw(h) << char(197);
		cout << setw(h) << char(180) << endl;
	}
	int *size = new int[n];
	for (int j = 0; j < n - 1; j++)
		cout << setfill(' ');
	cout << char(179);
	for (int j = 0; j < n; j++)       //заполнение таблицы
	{
		cout << setw(h - 1) << fixed << setprecision(h - 7) << c[j] << char(179);
	}
	cout << endl;
}
