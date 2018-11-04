// kf.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double f;
double func(double x);
double kasat(double *g);
double iter(double *g);


int i;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	double eps=0.000001;
	double a,b;
	int h=1;
	int n=0;
	cout<<"eps=0.000001"<<endl<<"���������� �������"<<endl;
	while (h>0.9)
	{
		do
		{
		cout<<"������� � �� -1 �� 1"<<endl;
		cin>>a;
		cout<<"������� b �� -1 �� 1"<<endl;
		cin>>b;
		}
		while ((abs(a)>1) || (abs(b)>1));
		double c=(a+b)/2;
		do
		{
			if ((func(a)*func(c))<0)
			{
				b=c;
				c=(a+b)/2;
				h=0;
			}
			else if ((func(c)*func(b))<0)
				{
					a=c;
					c=(a+b)/2;
					h=0;
				}
				else 
				{
					cout<<"��� ������� � ������ ����������,������� ������ � � b"<<endl;
					break;
					h=1;
				}
			n++;
		}
		while (abs(func(c))>eps);
		if (h!=1) cout<<c<<endl;
		cout<<"n="<<n<<endl;
	}
	double t[90000];

	cout<<endl<<"����� �������"<<endl<<"������� t[0]"<<endl;
	cin>>t[0];
	i=0;
	do
	{
		i++;
		kasat(t);		
	}
	while(abs(func(t[i]))>eps);
	cout<<"x="<<t[i]<<endl;
	cout<<"n="<<i<<endl;
	double p[10000];
	cout<<endl<<"������� ��������"<<endl<<"������� p[0]"<<endl;
	cin>>p[0];
	i=0;
	do
	{
		i++;
		iter(p);
	}
	while(abs(func(p[i]))>eps);
	cout<<"x="<<p[i]<<endl;
	cout<<"n="<<i<<endl;

	eps=0.00000001;
	cout<<endl<<"eps=0.00000001"<<endl<<"���������� �������"<<endl;
	h=1;
	n=0;
	while (h>0.9)
	{
		do
		{
		cout<<"������� � �� -1 �� 1"<<endl;
		cin>>a;
		cout<<"������� b �� -1 �� 1"<<endl;
		cin>>b;
		}
		while ((abs(a)>1) || (abs(b)>1));
		double c=(a+b)/2;
		do
		{
			if ((func(a)*func(c))<0)
			{
				b=c;
				c=(a+b)/2;
				h=0;
			}
			else if ((func(c)*func(b))<0)
				{
					a=c;
					c=(a+b)/2;
					h=0;
				}
				else 
				{
					cout<<"��� ������� � ������ ����������,������� ������ � � b"<<endl;
					break;
					h=1;
				}
			n++;
		}
		while (abs(func(c))>eps);
		if (h!=1) cout<<fixed<<setprecision(8)<<c<<endl;
		cout<<"n="<<n<<endl;
	}
	t[90000];
	cout<<endl<<"����� �������"<<endl<<"������� t[0]"<<endl;
	cin>>t[0];
	i=0;
	do
	{
		i++;
		kasat(t);	                            
	}
	while(abs(func(t[i]))>eps);
	cout<<"x="<<fixed<<setprecision(8)<<t[i]<<endl;
	cout<<"n="<<i<<endl;
	p[10000];
	cout<<endl<<"������� ��������"<<endl<<"������� p[0]"<<endl;
	cin>>p[0];
	i=0;
	do
	{
		i++;
		iter(p);
	}
	while(abs(func(p[i]))>eps);
	cout<<"x="<<fixed<<setprecision(8)<<p[i]<<endl;
	cout<<"n="<<i<<endl<<endl;

	system ("pause");
	return 0;
}

double func(double x)
{
	return x-cos(x);
}
double kasat(double *g)
{
	return g[i]=g[i-1]-(-cos(g[i-1])+g[i-1])/(1+sin(g[i-1]));
}
double iter(double *g)
{
	return g[i]=cos(g[i-1]);
}
