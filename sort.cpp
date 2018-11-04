#include "stdafx.h"
#include <iostream>
using namespace std;

void bubblesort(int *c,int n);
void perestanovka (int *c, int n);
void maximum(int *c, int n);
void massiv(int *c, int *a,int *b);
int _tmain(int argc, _TCHAR* argv[])
{  
	setlocale(LC_ALL, "Russian");
	int a[40],b[40],c[40];
	int i=0;
	int n=0;
	for (i=0;i<40;i++)  //ввод массива
	{
		a[i]=rand()%1000;
		c[i]=a[i]; //второй массив-для второго способа сортировки
		b[i]=a[i]; 
		cout<<a[i]<<"; ";
	}
	cout<<endl<<endl;
	for (n;n<41;n++)                //счетчик для количества значений массива, которые надо отсортировать
	{
		if ((n==10)||(n==20)||(n==40))
		{   
			massiv(c,a,b);
			cout<<"для n="<<n<<endl;
			bubblesort(a,n);
			bubblesort(a,n);
			perestanovka (a, n);
			bubblesort(a,n);
			maximum(b, n);
			maximum(b, n);
			perestanovka (b, n);
			maximum(b, n);
			
}
}
system("pause");
return 0;
}
void bubblesort(int *c,int n)
{
	int t, z,g, i, p;
	z=0;
	g=0;
	for (p=0;p<n;p++)             
	{
		for (i=1;i<n-p;i++)
		{
			g++;                    
			if (c[i]<c[i-1]) 
			{
				t=c[i];
				c[i]=c[i-1];
				c[i-1]=t;
				z++;
			}
		}
		if (z==0) break;
	}
	for (i=0;i<n;i++)
	{
		cout<<c[i]<<"  ";
	}
	cout<<endl<<"количество перестановок="<<z;
	cout<<endl<<"количество сравнений="<<g<<endl<<endl;
		
}
void perestanovka (int *c, int n)   //переворачивает массив
{
	int i;
	int t;
	for(i=0;i<=(n-2)/2;i++)
		{
			t=c[i];
			c[i]=c[n-(i+1)];
			c[n-(i+1)]=t;
		}
}
void maximum(int *c, int n)
{
	int z=0;
	int g=0;
	int max=c[0];
	int t=0;
	int k,p,i;
	for (p=0;p<n;p++)         
			{
				max=c[0];
				t=0;
				for (i=1;i<n-p;i++)
				{
					g++;
					if (max<(c[i]))
					{
							t=i;
							max=c[i];
					}
				}
				if (t!=(n-1-p)) 
				{
					k=c[n-1-p];
					c[n-1-p]=max;
					c[t]=k;
					z++;
				}
				if (z==0) break;
			
			}
	for (i=0;i<n;i++)
	{		
		cout<<c[i]<<"; ";
	}
	cout<<endl<<"количество перестановок="<<z;
	cout<<endl<<"количество сравнений="<<g<<endl<<endl;					  						
}
void massiv(int *c,int *a,int *b)
{
	int i;
	for (i=0;i<40;i++)  
			{
				*b=*c;              //второй массив-для второго способа сортировки, третий-для получения начальных значений массива при проверке на 10,20,40 элем
				*a=*c;              
			}
}
