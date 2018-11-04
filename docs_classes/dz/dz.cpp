// dz.cpp: определяет точку входа для консольного приложения.
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
		cout << endl << "Меню  системы классов документов." << endl << endl;

		cout << endl << "1.  ТЗ - 5.1.1  Создание документа с заголовками " << endl;
		cout << "2.  ТЗ - 5.1.2  Создание объектов для заголовков  " << endl;
		cout << "3.  ТЗ - 5.1.3  Создание объектов для заголовков на основе других " << endl;
		cout << "4.  ТЗ - 5.1.4  Учет свойств заголовка " << endl;
		cout << "5.  ТЗ - 5.1.5  Задание и получение характеристик заголовка  " << endl;
		cout << "6.  ТЗ - 5.1.6  Распечатка характеристик заголовка " << endl;
		cout << "7.  ТЗ - 5.1.7  Перегрузить оператор присваивания для заголовков " << endl;
		cout << "8.  ТЗ - 5.1.8   Создание объектов для документов на основе других " << endl;
		cout << "9.  ТЗ - 5.1.9  Учет свойств документа" << endl;
		cout << "10. ТЗ - 5.1.10 Распечатка содержания документа и его свойств " << endl;
		cout << "11. ТЗ - 5.1.11 Задание характеристик документа " << endl;
		cout << "12. ТЗ - 5.1.12 Получение характеристик документа " << endl;
		cout << "13. ТЗ - 5.1.13 Объединение двух документов " << endl;
		cout << "14. ТЗ - 5.1.14 Добавление заголовка в документ " << endl;
		cout << "15. ТЗ - 5.1.15 Удаление заголовка из документа " << endl;
		cout << "16. ТЗ - 5.1.16 Перегрузка оператора присваивания для документов " << endl;
		cout << "17. ТЗ - 5.1.17 Перегрузка оператора вывода для заголовков " << endl;
		cout << "18. ТЗ - 5.1.18 Очистка документа " << endl;
		cout << "19. ТЗ - 5.1.19 Запись и чтение документа из файла " << endl;
		cout << "20. ТЗ - 5.1.20 Получение имени класса" << endl;
		cout << " " << endl;
		cout << endl << "0.Выход " << endl;
		cin >> iPunkt;
		switch (iPunkt)
		{
		case 1:
		{
			cout << endl << "ТЗ - 5.1.1  Создание документа с заголовками " << endl;
			Document D("Первый документ",7);
			Header H1("Интересные факты",1,"red",bold);
			Header H2("Факт 1", 2,"black",italic);
			Header H3("Факт 2", 2,"black",italic);
			Header H4("История",1);
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
			cout << endl << "2.  ТЗ - 5.1.2  Создание объектов для заголовков  " << endl;
			Header H1;
			H1.print(cout);
			Header H2("Предметы");
			H2.print(cout);
			Header H3("Рассказ", 3);
			H3.print(cout);
			Header H4("Договор", 2, "синий");
			H4.print(cout);
			Header H5("План", 1, "зеленый", underline);
			H5.print(cout);
		};
		system(" pause ");
		break;
		case 3:
		{
			cout << "3.  ТЗ - 5.1.3  Создание объектов для заголовков на основе других " << endl;
			cout << "конструктор копирования" << endl;
			Header H1("Договор", 2, "синий",bold);
			Header H2(H1);
			H1.print(cout);
			H2.print(cout);
			cout << "передача через указатель" << endl;
			Header H3("План", 1, "зеленый", underline);
			Header *H4;
			H4 = &H3;
			Header H5(*H4);
			H5.print(cout);
		};
		system(" pause ");
		break;
		case 4:
		{
			cout << "4.  ТЗ - 5.1.4  Учет свойств заголовка " << endl;
			Header H1("План похода", 2, "зеленый", underline);
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 5:
		{
			cout << "5.  ТЗ - 5.1.5  Задание и получение характеристик заголовка  " << endl;
			Header H1;
			changeHeader(H1);
			H1.chooseHT();
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 6:
		{
			cout << "6.  ТЗ - 5.1.6  Распечатка характеристик заголовка  " << endl;
			Header H1("Договор", 2, "синий",italic);
			H1.print(cout);
		};
		system(" pause ");
		break;
		case 7:
		{
			cout << "7.  ТЗ - 5.1.7  Перегрузить оператор присваивания для заголовков " << endl;
			Header H1("Договор", 2, "синий");
			H1.print(cout);
			Header H2("Документ");
			H2.print(cout);
			H2 = H1;
			H2.print(cout);
		};
		system(" pause ");
		break;
		case 8:
		{
			cout << "8.  ТЗ - 5.1.8 Создание объектов для документов на основе других " << endl;
			cout << "конструктор копирования" << endl;
			Document D("Список заданий", 2, 3, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1(D);
			D1.print(cout);
			cout << "передача через указатель" << endl;
			Document *D2;
			D2 = &D1;
			Document D3(*D2);
			D3.print(cout);
		};
		system(" pause ");
		break;
		case 9:
		{
			cout << "9.  ТЗ - 5.1.9  Учет свойств документа" << endl;
			Document D("Список заданий",4,1,other);
			D.print(cout);
		};
		system(" pause ");
		break;
		case 10:
		{
			cout << "10. ТЗ - 5.1.10 Распечатка содержания документа и ее свойств " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.print(cout);

		};
		system(" pause ");
		break;
		case 11:
		{
			cout << "11. ТЗ - 5.1.11 Задание характеристик документа " << endl;
			Document D("Список заданий", 4, 1, other);
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
			cout << "12. ТЗ - 5.1.12 Получение характеристик документа " << endl;	
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			cout << D.className()<<endl;
			cout << "Название: " << D.getname() << endl;
			cout<<"Заголовков в документе: "<<D.getnumhead()<<endl;
			cout<<"Страниц: "<<D.getpages()<<endl;
			cout << "Тип документа:" << D.getDT() << endl << " (0-text, 1-book, 2-report,3-other)" << endl;

		};
		system(" pause ");
		break;
		case 13:
		{
			cout << "13. ТЗ - 5.1.13 Объединение двух документов " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1("Отчет", 7, 1, report);
			Header H4("Цель работы", 1, "синий");
			Header H5("Итоги", 1, "синий");
			Header H6("Примечания", 2, "зеленый", italic);
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
			cout << "14. ТЗ - 5.1.14 Добавление заголовка в документ " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.print(cout);
			D.add(&H3, tail, 1);
			cout << "В хвост" << endl;
			D.print(cout);
			Header H4("Финансы", 1, "зеленый", underline);
			D.add(&H4, head, 1);
			cout << "В начало" << endl;
			D.print(cout);
			Header H5("Недочёты", 1, "красный", regular);
			D.add(&H5, Number, 2);
			cout << "На позицию после номера 2" << endl;
			D.print(cout);
			
	
		};
		system(" pause ");
		break;
		case 15:
		{
			cout << "15. ТЗ - 5.1.15 Удаление заголовка из документа " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			Header H4("Финансы", 1, "зеленый", underline);
			Header H5("Недочёты", 1, "красный", regular);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			D.AddTail(&H4);
			D.AddTail(&H5);
			D.print(cout);
			D.del(Number, 2);
			cout << "Удаление заголовка с позиции 2" << endl;
			D.print(cout);	
			D.del(tail, 1);
			cout << "Из начала" << endl;
			D.print(cout);
			D.del(head, 1);
			cout << "С конца" << endl;
			D.print(cout);
			
		};
		system(" pause ");
		break;
		case 16:
		{
			cout << "16. ТЗ - 5.1.16 Перегрузка оператора присваивания для документов " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
			D.AddTail(&H1);
			D.AddTail(&H2);
			D.AddTail(&H3);
			Document D1("Отчет", 7, 1, report);
			Header H4("Цель работы", 1, "синий");
			Header H5("Итоги", 1, "синий");
			Header H6("Примечания", 2, "зеленый", italic);
			D1.AddTail(&H4);
			D1.AddTail(&H5);
			D1.AddTail(&H6);
			cout << "Документ D " << endl;
			D.print(cout);
			cout << "Документ D1 " << endl;
			D1.print(cout);
			cout << "После присваивания D=D1 " << endl;
			D = D1;
			D.print(cout);
		};
		system(" pause ");
		break;
		case 17:
		{
			cout << "17. ТЗ - 5.1.17 Перегрузка оператора вывода для заголовков " << endl;
			Header H3("План", 1, "зеленый", underline);
			cout << H3 << endl;
		};
		system(" pause ");
		break;
		case 18:
		{
			cout << "18. ТЗ - 5.1.18 Очистка документа " << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
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
			cout << "19. ТЗ - 5.1.19   Запись и чтение из файла" << endl;
			Document D("Список заданий", 4, 1, other);
			Header H1("Рассказ", 3);
			Header H2("Договор", 2, "синий");
			Header H3("План", 1, "зеленый", underline);
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
			cout << "20. ТЗ - 5.1.20 Получение имени класса" << endl;
			
			Header H1("Рассказ", 3);
			cout << H1.className() << endl;
			Document D;
			cout << D.className() << endl;
		};
		system(" pause ");
		break;

	
		case 0:
		{
			cout << endl << "0.Выход " << endl;
			return 0;
		};
		}
	}
	
	//	Header A("ЛЯЛЯ",1);
		//	Header B("ЖУЖУ",2);
		//	Header C("НОНО",1);
		//	Header D("ХАХА",3);
		//	D.print(cout);
		//	changeHeader(B);
		//	B.print(cout);
		//	C = A + B;
		//	C.print(cout);
		//	Document X("Добрый" );
		//	Document Y("день");
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

	
