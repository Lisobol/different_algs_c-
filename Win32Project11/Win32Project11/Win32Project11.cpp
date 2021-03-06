// Win32Project11.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "Win32Project11.h"

#define MAX_LOADSTRING 100
#include<windows.h>
#include<math.h>

#define pi 3.14

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//��������� ��������� �����
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2);

char szProgName[] = "��� ���������";

int i, xView, yView;
double y;
char Buf[2];
int a = 0.2, b = 6, c = 1;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w;

	w.lpszClassName = _T("��� ���������");
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = 0;
	w.lpszMenuName = 0;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//���� �� ������� ���������������� ����� ���� - �������
	if (!RegisterClass(&w))
		return 0;

	//�������� ���� � ������, �������� ��������� CreateWindow
	hWnd = CreateWindow(_T("��� ���������"),
		_T("������ �������"),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		500,
		400,
		(HWND)NULL,
		(HMENU)NULL,
		(HINSTANCE)hInstance,
		(HINSTANCE)NULL);

	//������� ���� �� ������ �� �����
	ShowWindow(hWnd, nCmdShow);
	//������� ���������� ����
	UpdateWindow(hWnd);

	//���� ��������� ���������

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //�������� ��������� �� �������
		TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
		DispatchMessage(&lpMsg); //������� ��������� ��������������� ������� ����
	}
	return(lpMsg.wParam);
}

//������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc; //������ �������� ����������
	PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������
	HPEN hPen; //������ ����
			   //���� ��������� ���������
	switch (messg)
	{

	case WM_SIZE:
		xView = LOWORD(lParam);
		yView = HIWORD(lParam);

		break;


		//��������� ���������
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetMapMode(hdc, MM_ISOTROPIC); //���������� ������� ����������, ��� ����������
		SetWindowExtEx(hdc, 500, 500, NULL); //����� ����
		SetViewportExtEx(hdc, xView, -yView, NULL); //���������� ������ ������
		SetViewportOrgEx(hdc, xView / 6, yView / 2, NULL); //������ ���������

														   //������ ��� ���������
		Line(hdc, 0, 220, 0, -220);//��� �
		Line(hdc, -100, 0, 500, 0);//��� �
		MoveToEx(hdc, 0, 0, NULL); //������������ � ������ ���������

								   //�������� �������� ����
		hPen = CreatePen(1, 1, RGB(255, 25, 0));
		SelectObject(hdc, hPen);

		//���������
		for (i = 0; i<450; i=i++) {
			y = a*i*i + b*i + c;
			LineTo(hdc, i, int(y));
		}

		//������ ���� ����� ������
		hPen = CreatePen(1, 1, RGB(0, 0, 0));
		SelectObject(hdc, hPen);

		//������� �������
		for (i = -100; i<500; i += 100)
		{
			Line(hdc, i, 3, i, -3);
			Line(hdc, -3, i, 3, i);
			_itoa_s(i, Buf, 10);
		TextOut(hdc, i - 5, -5, LPCWSTR(Buf), strlen(Buf));
			TextOut(hdc, -5, i, LPCWSTR(Buf), strlen(Buf));
		}

		ValidateRect(hWnd, NULL); //��������� �����
		EndPaint(hWnd, &ps);
		break;

		//��������� ������ - ���������� ����
	case WM_DESTROY:
//	DeleteObject(hPen); //�� �������� ���������� �����
		PostQuitMessage(0); //�������� ��������� ������ � ����� 0 - ���������� ����������
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //����������� ������� ���������� �� �������������
	}
	return 0;
}

//������� ��������� �����
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //������� �������� ���������� x1, y1
	return LineTo(hdc, x2, y2); //���������� �����
}