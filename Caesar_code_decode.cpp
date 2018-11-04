#include "stdafx.h"
#include <iostream>
#include <fstream> 
using namespace std;
void key();
int kodirovka();
int raskodirovka();
void statistika();
int k[50], n;
const int len = 81;
char word[len], line[len], word1[len];
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	ifstream fin;
	fin.open("ah.txt", ios_base::in);
	if (!fin) {
		cout << "не удается открыть файл" << endl;
		return 1;
	}
	while (fin.getline(line, len))
	{
		key();
	}
	cout << "введите текст" << endl;
	cin.getline(word, len);   
	kodirovka();
	cout << endl << "закодированный текст" << endl << word << endl;
	raskodirovka();
	cout << endl << "раскодированный текст" << endl << word << endl;
	statistika();
	system("pause");
	return 0;
}

void key()
{
	int b;
	n = 0;
	cout << "блокнот:" << endl << line << endl;
	for (int i = 0; i < strlen(line); i++)
	{
		if (k[n] < -1000) k[n] = 0;
		if ((!isspace(line[i])) && (!ispunct(line[i])))
		{
			b = int(line[i]);
			k[n] += b;
		}
		else
		{
			k[n] = k[n] % 256;
			n++;
		}
	}
}
int kodirovka()
{
	n = 0;
	for (int g = 0; g < strlen(word); g++)
	{
		word[g] += k[n];
		word1[g] = word[g];
		if (n == 4)
			n = 0;
		else n++;
	}
	return n;
}
int raskodirovka()
{
	n = 0;
	for (int g = 0; g < strlen(word); g++)
	{
		word[g] -= k[n];
		if (n == 4)
			n = 0;
		else n++;
	}
	return n;
}
void statistika()
{
	int **g = new int*[len];
	for (int i = 0; i < len; i++)
		g[i] = new int[len];
	char **word4 = new char*[len];
	for (int i = 0; i < len; i++)
		word4[i] = new char[len];
	int j = 0;
	int kolvobukv = 0;
	char p;
	for (int i = 0; i < strlen(word); i++) //запись в масиив всех введенных символов
	{
		word4[i][0] = word[i];
		kolvobukv++;
	}
	for (int i = 0; i < kolvobukv; i++)  //поиск одинаковых символов
	{
		for (int k = i + 1; k < kolvobukv; k++)
		{
			if (word4[i][0] == word4[k][0])
			{
				p = word4[k][0];
				word4[k][0] = word4[kolvobukv - 1][0];
				word4[kolvobukv - 1][0] = p;
				kolvobukv--;
				k--;
			}
		}
	}
	for (int i = 0; i < kolvobukv; i++)     //поиск кодов одинаковых букв
	{
		j = 1;

		for (int k = 0; k < strlen(word); k++)
		{
			if (word4[i][0] == word[k])
			{
				word4[i][j] = word1[k];
				j++;
			}
		}
		for (int k = 1; k < j; k++)                  //поиск одинаковых кодов
		{
			g[i][k] = 1;
			for (int z = k + 1; z <= j; z++)
			{
				if (word4[i][k] == word4[i][z])
				{
					p = word4[i][j];
					word4[i][j] = word4[i][z];
					word4[i][z] = p;
					j--;
					g[i][k]++;
				}
			}
		}
	}
	for (int u = 0; u < kolvobukv; u++)
	{
		cout << word4[u][0] << endl;
		int o = 1;
		while (g[u][o]>-257)
		{
			cout << "код: " << word4[u][o] << " " << g[u][o] << "раз(а)" << endl;
			o++;
		}
		cout << endl;
	}
}
