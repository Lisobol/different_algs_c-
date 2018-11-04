// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
const int len = 81;

int main()
{
	setlocale(0, "Russian");
	char **word = new char*[len];//массив слов
	for (int i = 0; i < len; i++)
		word[i] = new char[len];
	int kolvobukv[len];//кол-во букв в слове
	cout << "введите текст" << endl;
	int  k = 0, y = 0;
	int o = 0;//o-переменная,которая нужна в случае идущих подряд нескольких пробелов,запятых итд
	char s;
	int r;
	do //ввод текста,поиск слов в тексте
	{
		s = _getch();
		r = int(s);
		if ((r<123) && (r>96))
		{
			word[y][k] = s;//запись буквы в массив
			cout << s;
			k++;
			o = 0;
		}
		else if (o == 0)
		{
			if (((r>31) &&(r<47)) ||((r>57)&&(r<64)))
			{
				cout << s;
				kolvobukv[y] = k;
				y++;
				k = 0;
				o++;//увеличиваем о на случай идущего следом знака препинания,пробела итп
			}
		}
	} while (r != 46);
	cout << endl;
	char **word2 = new char*[len]; //массив для записи слов,отличающихся от последнего
	for (int i = 0; i < len; i++)
		word2[i] = new char[len];
	int n = 0;
	int p = 0;
	for (int g = 0; g < y-1; g++)//сравнение кол-ва букв слова с кол-вом в последнем слове
	{
		p = 0;
		if (kolvobukv[g] != (kolvobukv[y-1]))//если кол-ва букв не равны
		{
			for (int l = 0; l < kolvobukv[g]; l++)
				word2[n][l] = word[g][l]; //запись слова,отличающегося от последнего в массив
			kolvobukv[n] = kolvobukv[g];
			n++;
		}
		else for (int l = 0; l < kolvobukv[g]; l++)//если кол-во букв в последнем и данном слове равны
		{
			if (word[g][l] != word[y-1][l])//совпадают ли все буквы слова или нет
			{
				p++;
			}
		}
		if (p > 0) //если не совпадают
		{
			for (int l = 0; l < kolvobukv[g]; l++)
				word2[n][l] = word[g][l];//запись слова,отличающегося от последнего в массив
			kolvobukv[n] = kolvobukv[g];
			n++;
		}
	}
	int max = 0;
	for (int g = 0; g < n; g++) //поиск максимальной длины слова
	{
		if (max <= kolvobukv[g])
			max = kolvobukv[g];
	}
	for (int g = 0; g < n; g++) //вывод слов максимальной длины
	{
		if (kolvobukv[g] == max)
		{
			for (int l = 0; l < kolvobukv[g]; l++)
				cout << word2[g][l];
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

