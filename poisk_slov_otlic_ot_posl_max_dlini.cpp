// ConsoleApplication4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
const int len = 81;

int main()
{
	setlocale(0, "Russian");
	char **word = new char*[len];//������ ����
	for (int i = 0; i < len; i++)
		word[i] = new char[len];
	int kolvobukv[len];//���-�� ���� � �����
	cout << "������� �����" << endl;
	int  k = 0, y = 0;
	int o = 0;//o-����������,������� ����� � ������ ������ ������ ���������� ��������,������� ���
	char s;
	int r;
	do //���� ������,����� ���� � ������
	{
		s = _getch();
		r = int(s);
		if ((r<123) && (r>96))
		{
			word[y][k] = s;//������ ����� � ������
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
				o++;//����������� � �� ������ ������� ������ ����� ����������,������� ���
			}
		}
	} while (r != 46);
	cout << endl;
	char **word2 = new char*[len]; //������ ��� ������ ����,������������ �� ����������
	for (int i = 0; i < len; i++)
		word2[i] = new char[len];
	int n = 0;
	int p = 0;
	for (int g = 0; g < y-1; g++)//��������� ���-�� ���� ����� � ���-��� � ��������� �����
	{
		p = 0;
		if (kolvobukv[g] != (kolvobukv[y-1]))//���� ���-�� ���� �� �����
		{
			for (int l = 0; l < kolvobukv[g]; l++)
				word2[n][l] = word[g][l]; //������ �����,������������� �� ���������� � ������
			kolvobukv[n] = kolvobukv[g];
			n++;
		}
		else for (int l = 0; l < kolvobukv[g]; l++)//���� ���-�� ���� � ��������� � ������ ����� �����
		{
			if (word[g][l] != word[y-1][l])//��������� �� ��� ����� ����� ��� ���
			{
				p++;
			}
		}
		if (p > 0) //���� �� ���������
		{
			for (int l = 0; l < kolvobukv[g]; l++)
				word2[n][l] = word[g][l];//������ �����,������������� �� ���������� � ������
			kolvobukv[n] = kolvobukv[g];
			n++;
		}
	}
	int max = 0;
	for (int g = 0; g < n; g++) //����� ������������ ����� �����
	{
		if (max <= kolvobukv[g])
			max = kolvobukv[g];
	}
	for (int g = 0; g < n; g++) //����� ���� ������������ �����
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

