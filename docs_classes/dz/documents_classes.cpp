// dz.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "DZ_Class.h"
#include "DZ1.h"

//#include "DZLIB.cpp"


using namespace std;
//int Header::number = 0;
int main()
{
	system("chcp 1251>nul");
	int iPunkt;
	while (true)
	{
		system(" CLS ");
		cout << endl << "����  ������� ������� ����������." << endl << endl;

		cout << endl << "1.  �� - 5.1.1  �������� ��������� � ����������� " << endl;
		cout << "2.  �� - 5.1.2  �������� �������� ��� ����������  " << endl;
		cout << "3.  �� - 5.1.3  �������� �������� ��� ���������� �� ������ ������ " << endl;
		cout << "4.  �� - 5.1.4  ���� ������� ��������� " << endl;
		cout << "5.  �� - 5.1.5  ������� � ��������� ������������� ���������  " << endl;
		cout << "6.  �� - 5.1.6  ���������� ������������� ��������� " << endl;
		cout << "7.  �� - 5.1.7  ����������� �������� ������������ ��� ���������� " << endl;
		cout << "8.  �� - 5.1.8   �������� �������� ��� ���������� �� ������ ������ " << endl;
		cout << "9.  �� - 5.1.9  ���� ������� ���������" << endl;
		cout << "10. �� - 5.1.10 ���������� ���������� ��������� � ��� ������� " << endl;
		cout << "11. �� - 5.1.11 ������� ������������� ��������� " << endl;
		cout << "12. �� - 5.1.12 ��������� ������������� ��������� " << endl;
		cout << "13. �� - 5.1.13 ����������� ���� ���������� " << endl;
		cout << "14. �� - 5.1.14 ���������� ��������� � �������� " << endl;
		cout << "15. �� - 5.1.15 �������� ��������� �� ��������� " << endl;
		cout << "16. �� - 5.1.16 ���������� ��������� ������������ ��� ���������� " << endl;
		cout << "17. �� - 5.1.17 ���������� ��������� ������ ��� ���������� " << endl;
		cout << "18. �� - 5.1.18 ������� ��������� " << endl;
		cout << "19. �� - 5.1.19 ������ � ������ ��������� �� ����� " << endl;
		cout << "20. �� - 5.1.20 ��������� ����� ������" << endl;
		cout << " " << endl;
		cout << endl << "0.����� " << endl;
		cin >> iPunkt;
		switch (iPunkt)
		{
		case 1:
		{
			cout << endl << "�� - 5.1.1  �������� ��������� � ����������� " << endl;
			Document D("������ ��������",7);
			Header H1("���������� �����",1,"red",bold);
			Header H2("���� 1", 2,"black",italic);
			Header H3("���� 2", 2,"black",italic);
			Header H4("�������",1);
			D.AddTail(&H1);
			D.AddTail(&H2); 
			D.AddTail(&H3);
			D.AddTail(&H4);
			D.print(cout);
		
		};	
		system(" pause ");   
		break;
		case 2:
		{
			cout << endl << "2.  �� - 5.1.2  �������� �������� ��� ����������  " << endl;
			Header H1;
			H1.print(cout);
			Header H2("��������");
			H2.print(cout);
			Header H3("�������", 3);
			H3.print(cout);
			Header H4("�������", 2, "�����");
			H4.print(cout);
			Header H5("����", 1, "�������", underline);
			H5.print(cout);
		};
		system(" pause ");
		break;
		case 3:
		{
			cout << "3.  �� - 5.1.3  �������� �������� ��� ���������� �� ������ ������ " << endl;
			cout << "����������� �����������" << endl;
			Header H1("�������", 2, "�����",bold);
			Header H2(H1);
			H1.print(cout);
			H2.print(cout);
			cout << "�������� ����� ���������" << endl;
			Header H3("����", 1, "�������", underline);
			Header *H4;
			H4 = &H3;
			Header H5(*H4);
			H5.print(cout);
		};
		system(" pause ");
		break;
		case 4:
		{
			cout << "4.  �� - 5.1.4  ���� ������� ��������� " << endl;
			Header H1("���� ������", 2, "�������", underline);
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 5:
		{
			cout << "5.  �� - 5.1.5  ������� � ��������� ������������� ���������  " << endl;
			Header H1;
			changeHeader(H1);
			H1.chooseHT();
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 6:
		{
			cout << "6.  �� - 5.1.6  ���������� ������������� ���������  " << endl;
			Header H1("�������", 2, "�����",italic);
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 7:
		{
			cout << "7.  �� - 5.1.7  ����������� �������� ������������ ��� ���������� " << endl;
			Header H1("�������", 2, "�����");
			H1.print(cout);
			Header H2("��������");
			H2.print(cout);
			H2 = H1;
			H2.print(cout);
		};
		system(" pause ");
		break;
		case 8:
		{
			cout << "8.  �� - 5.1.8 �������� �������� ��� ���������� �� ������ ������ " << endl;
			cout << "����������� �����������" << endl;
			Document D("������ �������", 2, 3, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1(D);
			D1.print(cout);
			cout << "�������� ����� ���������" << endl;
			Document *D2;
			D2 = &D1;
			Document D3(*D2);
			D3.print(cout);
		};
		system(" pause ");
		break;
		case 9:
		{
			cout << "9.  �� - 5.1.9  ���� ������� ���������" << endl;
			Document D("������ �������",4,1,other);
			D.print(cout);
		};
		system(" pause ");
		break;
		case 10:
		{
			cout << "10. �� - 5.1.10 ���������� ���������� ��������� � �� ������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.print(cout);

		};
		system(" pause ");
		break;
		case 11:
		{
			cout << "11. �� - 5.1.11 ������� ������������� ��������� " << endl;
			Document D("������ �������", 4, 1, other);
			D.changename();
			D.editedornot();
			D.changepagesnum();
			D.chooseDT();
			D.print(cout);
		};
		system(" pause ");
		break;
		case 12:
		{
			cout << "12. �� - 5.1.12 ��������� ������������� ��������� " << endl;	
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			cout << D.className()<<endl;
			cout << "��������: " << D.getname() << endl;
			cout<<"���������� � ���������: "<<D.getnumhead()<<endl;
			cout<<"�������: "<<D.getpages()<<endl;
			cout << "��� ���������:" << D.getDT() << endl << " (0-text, 1-book, 2-report,3-other)" << endl;

		};
		system(" pause ");
		break;
		case 13:
		{
			cout << "13. �� - 5.1.13 ����������� ���� ���������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1("�����", 7, 1, report);
			Header H4("���� ������", 1, "�����");
			Header H5("�����", 1, "�����");
			Header H6("����������", 2, "�������", italic);
			D1.AddTail(&H4);
			D1.AddTail(&H5);
			D1.AddTail(&H6);
			Document D2("!", 1, 1, report);;
			D2.print(cout);
			D2 = D + D1;
			D2.print(cout);
		};
		system(" pause ");
		break;
		case 14:
		{
			cout << "14. �� - 5.1.14 ���������� ��������� � �������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.print(cout);
			D.add(&H3, tail, 1);
			cout << "� �����" << endl;
			D.print(cout);
			Header H4("�������", 1, "�������", underline);
			D.add(&H4, head, 1);
			cout << "� ������" << endl;
			D.print(cout);
			Header H5("��������", 1, "�������", regular);
			D.add(&H5, Number, 2);
			cout << "�� ������� ����� ������ 2" << endl;
			D.print(cout);
			
	
		};
		system(" pause ");
		break;
		case 15:
		{
			cout << "15. �� - 5.1.15 �������� ��������� �� ��������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			Header H4("�������", 1, "�������", underline);
			Header H5("��������", 1, "�������", regular);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.AddTail(&H4);
			D.AddTail(&H5);
			D.print(cout);
			D.del(Number, 2);
			cout << "�������� ��������� � ������� 2" << endl;
			D.print(cout);	
			D.del(tail, 1);
			cout << "�� ������" << endl;
			D.print(cout);
			D.del(head, 1);
			cout << "� �����" << endl;
			D.print(cout);
			
		};
		system(" pause ");
		break;
		case 16:
		{
			cout << "16. �� - 5.1.16 ���������� ��������� ������������ ��� ���������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1("�����", 7, 1, report);
			Header H4("���� ������", 1, "�����");
			Header H5("�����", 1, "�����");
			Header H6("����������", 2, "�������", italic);
			D1.AddTail(&H4);
			D1.AddTail(&H5);
			D1.AddTail(&H6);
			cout << "�������� D " << endl;
			D.print(cout);
			cout << "�������� D1 " << endl;
			D1.print(cout);
			cout << "����� ������������ D=D1 " << endl;
			D = D1;
			D.print(cout);
		};
		system(" pause ");
		break;
		case 17:
		{
			cout << "17. �� - 5.1.17 ���������� ��������� ������ ��� ���������� " << endl;
			Header H3("����", 1, "�������", underline);
			cout << H3 << endl;
		};
		system(" pause ");
		break;
		case 18:
		{
			cout << "18. �� - 5.1.18 ������� ��������� " << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.print(cout);
			D.Clear();
			D.print(cout);
			
		};
		system(" pause ");
		break;
		case 19:
		{
			cout << "19. �� - 5.1.19   ������ � ������ �� �����" << endl;
			Document D("������ �������", 4, 1, other);
			Header H1("�������", 3);
			Header H2("�������", 2, "�����");
			Header H3("����", 1, "�������", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.DocToFile();
			D.DocFromFile();
		};
		system(" pause ");
		break;
		case 20:
		{
			cout << "20. �� - 5.1.20 ��������� ����� ������" << endl;
			
			Header H1("�������", 3);
			cout << H1.className() << endl;
			Document D;
			cout << D.className() << endl;
		};
		system(" pause ");
		break;

	
		case 0:
		{
			cout << endl << "0.����� " << endl;
			return 0;
		};
		}
	}
	
	//	Header A("����",1);
		//	Header B("����",2);
		//	Header C("����",1);
		//	Header D("����",3);
		//	D.print(cout);
		//	changeHeader(B);
		//	B.print(cout);
		//	C = A + B;
		//	C.print(cout);
		//	Document X("������" );
		//	Document Y("����");
		//	X.AddTail(&A);
		//	X.AddTail(&B);
		//	Y.AddTail(&C);
		//	Y.AddTail(&D);
		//	cout<<endl<<X.getnumhead()<<endl;
		//	cout << endl;
		//	Document Z;
		//	//X.editedornot();
		//	//Y.editedornot();
		//	X.changepagesnum();
		//	Y.changepagesnum();
		//	//X.print(cout);
		//	//Y.print(cout);
		//	//Y = X;
		//	//Y.print(cout);
		//	Z=X+Y;
		//	Z.print(cout);
		//	Z.DocToFile();
		//	Z.DocFromFile();
		////	/*changeHeader(A);
		////	A.print(cout);*/	//A.changetext();
		////	////A.PrintHeader();
		////	//Header B("dihflisdh", 2);
		//	////B.PrintHeader();
		//	//Header C("vghjnk", 3);
		//	//C.PrintHeader();
	system("pause");
	return 0;
	
}

	
