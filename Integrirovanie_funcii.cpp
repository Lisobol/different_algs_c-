#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double func1(double);
double func2(double);
double func3(double);
double func4(double);
double func11(double, double);
double func22(double, double);
double func33(double, double);
double func44(double, double);
int i;
void IntRect(double a, double b, int k, int d);
struct I_print {	//данные для печати результатов интегрирования
	char* name;//название функции
	double i_sum;	//значение интегральной суммы
	double i_toch;	//точное значение интеграла
	int n;	//число разбиений области интегрирования при котором достигнута требуемая точность
}i_prn[4];
void PrintTabl(I_print i_prn[], int k);
double(*f[4])(double) = { func1,func2,func3,func4 };
double(*g[4])(double, double) = { func11,func22,func33,func44 };
void(*p)(I_print i_prn[], int);
double eps[7] = { 0.01,0.001,0.0001,0.00001,0.000001,0.0000001,0.00000001 };
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "C");
	double a, b;
	i_prn[0].name = "y=x";
	i_prn[1].name = "y=sin(22x)";
	i_prn[2].name = "y=x^4";
	i_prn[3].name = "y=arctg(x)";
	cout << "enter a" << endl;
	cin >> a;
	cout << "enter b" << endl;
	cin >> b;
	for (int d = 0; d<7; d++)
	{
		cout << "eps=" << setprecision(8)<<eps[d] << endl;
		for (int k = 0; k < 4; k++)
		{
			IntRect(a, b, k, d);
		}
		PrintTabl(i_prn, 4);
	}
	system("pause");
	return 0;
}

void IntRect(double a, double b, int k, int d)
{
	double dx, x, t =0 , s = 1e+7;
	int n = 1;
	int i;
	do
	{
		t = s;
		s = 0;
		n++;
		dx = (b-a) / n;
		for (i = 0; i<n; i++)
		{
			x = a + dx*i + dx / 2;
			s = s + f[k](x)*dx;
		}
	} while ((abs(s - t)>=eps[d]) && (n<1e+8));
	i_prn[k].i_toch = g[k](a, b);
	i_prn[k].i_sum = s;
	i_prn[k].n = n;
}
double func1(double x)
{
	return x;
}
double func11(double a, double b)
{
	return ((b*b - a*a) / 2.0);
}
double func2(double x)
{
	return sin(22.0*x);
}
double func22(double a, double b)
{
	return (cos(a*22.0) - cos(b*22.0)) / 22.0;
}
double func3(double x)
{
	return x*x*x*x;
}
double func33(double a, double b)
{
	return (b*b*b*b*b - a*a*a*a*a) / 5.0;
}
double func4(double x)
{
	return atan(x);
}
double func44(double a, double b)
{
	return b*atan(b) - a*atan(a) - (log(b*b + 1) - log(a*a + 1)) / 2.0;
}
void PrintTabl(I_print i_prn[], int k)
{
	const int m = 4;//число столбцов таблицы
	int wn[m] = { 12,18,18,10 };//ширина столбцов таблицы
	char *title[m] = { "Function","Integral","IntSum","N " };
	int size[m];
	for (int i = 0; i<m; i++)
		size[i] = strlen(title[i]);
	//шапка таблицы
	cout << char(218) << setfill(char(196));
	for (int j = 0; j<m - 1; j++)
		cout << setw(wn[j]) << char(194);
	cout << setw(wn[m - 1]) << char(191) << endl;
	cout << char(179);
	for (int j = 0; j<m; j++)
		cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
		<< setw((wn[j] - size[j]) / 2) << char(179);
	cout << endl;
	for (int i = 0; i<k; i++)
	{//заполнение таблицы
		cout << char(195) << fixed;
		for (int j = 0; j<m - 1; j++)
			cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;

		cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
			<< setw((wn[0] - strlen(i_prn[i].name)) / 2) << char(179);
		cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].i_toch << char(179)
			<< setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
			<< setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
	}
	//низ таблицы
	cout << char(192) << setfill(char(196));
	for (int j = 0; j<m - 1; j++)
		cout << setw(wn[j]) << char(193);
	cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}
