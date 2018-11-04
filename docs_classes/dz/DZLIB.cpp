#include "stdafx.h"
#include <iostream>
#include "DZ_Class.h"
#include "DZ1.h"
#include "afxwin.h"
#include "fstream"
using namespace std;

Header::Header()
{ 
	text = NULL;
	//strcpy_s(text,30, "Заголовок");
	position = 1; 
	/*number++; 
	nomer = number;*/
	nomer++;
	strcpy_s(color, "чёрный");
	HT = regular;
};
Header::Header(Header &H) 
{
	text = new char[strlen(H.text) + 1];
	strcpy_s(text,strlen(H.text)+1 ,H.text); 
	position = H.position;
	//number++; 
	//nomer = number;
	nomer++;
	HT = H.HT;
	strcpy_s(color, H.color);
};
Header::Header(Header *pH) 
{
	text = new char[strlen(pH->text) + 1];
	strcpy_s(text, strlen(pH->text) + 1, pH->text);
	position = pH->position; 
	//number++;
	//nomer = number;
	nomer++;
	HT = pH->HT;
	strcpy_s(color, pH->color);
};
Header::Header(char *a)
{
	text = new char[strlen(a) + 1];
	strcpy_s(text, strlen(a) + 1, a);
	position = 1;
	/*number++;
	nomer = number;*/
	nomer++;
	strcpy_s(color, "чёрный");
	
	HT = regular;
};
Header::Header(char *a, int p) 
{
	text = new char[strlen(a) + 1];
	strcpy_s(text, strlen(a) + 1, a);
	position = p;
	/*number++;
	nomer = number;*/
	nomer++;
	strcpy_s(color, "чёрный");
	
	HT =regular;
};
Header::Header(char *a, int p, char *c) 
{
	text = new char[strlen(a) + 1];
	strcpy_s(text, strlen(a) + 1, a);
	position = p;
	strcpy_s(color, c); 
	/*number++;
	nomer = number;*/
	nomer++;
	HT = regular;
};
Header::Header(char *a, int p, char *c, HeaderType x)
{
	text = new char[strlen(a) + 1];
	strcpy_s(text, strlen(a) + 1, a);
	position = p;
	strcpy_s(color, c);
	/*number++;
	nomer = number;*/
	nomer++;
	HT = x;
};


void Header::setpos()
{

	cout << "Введите 1,2 или 3-уровень заголовка" << endl;
	cin >> position;
	cout << "уровень заголовка-" << position << endl;
}
void Header::changetext()
{
	char *a=new char[80];
	cout << "Введите новый заголовок" << endl;
	cin >> a;
	
	 text = new char[strlen(a) + 1];      	
	strcpy_s(text, strlen(a) + 1, a);
};
void Header::print(ostream &out)
{
	if (this->text != NULL) {
		switch (position)
		{
		case 1:
			cout << text << "            //цвет-" << color << ",тип- " << HT << endl;
			break;
		case 2:
			cout << "     " << text << "            //цвет-" << color << ",тип- " << HT << endl;
			break;
		case 3:
			cout << "              " << text << "            //цвет-" << color << ",тип- " << HT << endl;
			break;
		}
	}
	else out << "  Имя не задано " << endl; 
};
void Header::changecolor()
{
	char a[80];
	cout << "Введите новый цвет заголовка" << endl;
	cin >> a;
	strcpy_s(color, a);
};
void changeHeader(Header &H)
{
	H.changetext();
	H.changecolor();
	H.setpos();
};
const char* Header::gettext() 
{
	return(const char *) text;
};
void Header::chooseHT()
{
	cout << "Введите номер типа заголовка: 0- bold,1-italic,2- underline,3-regular" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 0:
		HT = bold ;
		break;
	case 1:
		HT = italic;
		break;
	case 2:
		HT = underline;
		break;
	case 3:
		HT = regular;
		break;
	}
};
Header & Header:: operator=(Header&H)
{
	text = new char[strlen(H.text) + 1];
	strcpy_s(text, strlen(H.text) + 1, H.text);
	position = H.position;
	nomer = H.nomer;
	HT = H.HT;
	strcpy_s(color, H.color);
	return *this;
};
//Header & Header:: operator +(Header & H1)
//{  
//	Header H;
//	if ((this->text != NULL)&&(H1.text != NULL))
//	{
//		H.text = new char[strlen(this->text) + strlen(H1.text) + 15];
//		strcpy_s(H.text, strlen(this->text) + 1, this->text);
//		strcat_s(H.text, strlen(this->text)+8, "  ");
//		strcat_s(H.text, strlen(this->text) + strlen(H1.text) + 15/*strlen(H1.text) + 1*/, H1.text);
//	}
//	H.nomer = this->nomer;
//	H.position = H1.position;
//	H.HT = H1.HT;
//	strcpy_s(H.color, 80,H1.color);
//	return H; 
//};
ostream & operator << (ostream &  out, Header &  obj)
{
	switch (obj.position)
	{
	case 1:
		out << obj.text <<"            //цвет-" << obj.color << ",тип- " << obj.HT << endl;
		break;
	case 2:
		out<< "      " << obj.text << "            //цвет-" << obj.color << ",тип- " << obj.HT << endl;
		break;
	case 3:
		out<<"                " <<obj.text << "            //цвет-" << obj.color << ",тип- " << obj.HT << endl;
		break;
	}
	return out;
};

Document::Document() {
	name = NULL;    
	/*strcpy_s(name, 80, "документ");*/
	DT = text;
	pagesnum = 0;
	edited = false;
	headnum =0;
};
Document::Document(char *s) {
	if (s != (char *)NULL) {
		name = new char[strlen(s) + 1]; 
		strcpy_s(name, strlen(s) + 1, s);
	}
	else { name = (char *)NULL; };
	DT = text;
	pagesnum = 0;
	edited = false;
};
Document::Document(char *s, int p)
{
	if (s != (char *)NULL)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	else { name = (char *)NULL; };
	DT = text;
	pagesnum = p;
	edited = false;
}
Document::Document(char *s, int p, bool e)
{
	if (s != (char *)NULL)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	else { name = (char *)NULL; };
	DT = text;
	pagesnum = p;
	edited = e;
};
Document::Document(char *s, int p, bool e, DocumentType D)
{
	if (s != (char *)NULL)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	else { name = (char *)NULL; };
	DT =D;
	pagesnum = p;
	edited = e;
};
Document::Document(Document &D) {
	if (D.name != (char *)NULL) 
	{
		name = new char[strlen(D.name) + 1];   
		strcpy_s(name, strlen(D.name) + 1, D.name);
	}
	else { name = (char *)NULL; };
	D.headnum = D.GetCount();
	headnum = D.headnum;
	edited =D.edited;
	pagesnum = D.pagesnum;
	DT = D.DT;
	POSITION pos = D.GetHeadPosition();
	for (int i = 0; i < headnum; i++)
	{
		AddTail(((Header *)D.GetAt(pos)));
		D.GetNext(pos);
	};

	
	/*if (D.name != (char *)NULL) {
		name = new char[strlen(D.name) + 1];     strcpy_s(name, strlen(D.name) + 1, D.name);
	}
	else { name = (char *)NULL; };
	DT = D.DT;
	D.headnum = (int)D.GetCount();
	headnum = D.headnum;
	POSITION pos = D.GetHeadPosition();
	for (int i = 0; i < headnum; i++)
	{
		AddTail(((Header *)D.GetAt(pos)));
		D.GetNext(pos);
	};
	pagesnum =D.pagesnum;
	edited = D.edited;*/
};
Document::Document(Document *pD) {
	if (pD->name != (char *)NULL)
	{
		name = new char[strlen(pD->name) + 1];   
		strcpy_s(name, strlen(pD->name) + 1, pD->name);
	}
	else { name = (char *)NULL; };
	DT = pD->DT;
	pagesnum = 0;
	edited = false;
};


void Document::changename()
{
	char a[80];
	cout << "Введите новое название" << endl;
	cin >> a;
	name = new char[80];
	strcpy_s(name,80, a);
};
void Document::print(ostream &out)
{
	
	if (name != (char *)NULL) 
	{ 
		out << "{{{******* " << endl << "Документ -  " << name << endl;
	}
	else 
	{ 
		out << "Название не задано! " << endl; 
	};    
	headnum = (int)GetCount();  
	out << "Число заголовков в списке  = " << headnum << "}" << endl;
	POSITION pos = GetHeadPosition();
	for (int i = 0; i < headnum; i++)
	{ 
		cout << i+1 << ". ";
		((Header *)(GetAt(pos)))->print(out);
		GetNext(pos); } 

	out <<"Страниц: "<< pagesnum << endl;
	if (edited) out << "Отредактировано" << endl;
	else out << "Неотредактировано" << endl;
	out <<"тип документа:( 0-text,1-book, 2-report,3-other)  "<<  DT << endl;

	out << "*******}}}" << endl;
};
void Document::add(Header *pH, TypeAddDel t, int Numb) {
	if (t == tail)
		AddTail((CObject *)pH);  
	if (t == head) 
		AddHead((CObject *)pH);
	if (t == Number) 
	{ 
		if (GetCount() < Numb)
		{
			cout << endl << "Добавление невозможно, проверьте номер!" << endl;  
			return;
		};   
		int nRazm = (int)GetCount(); 
		POSITION pos = GetHeadPosition();   
		for (int i = 0;  i <= (Numb-2); i++) 
		{ 
			GetNext(pos);
		}; 
		InsertAfter(pos, (CObject *)pH); 
	};
	headnum= (int)GetCount();
};
void Document::del(TypeAddDel t, int Numb)
{
	if (t == head) RemoveHead();
	if (t == tail) RemoveTail();
	if (t == Number) 
	{ 
		if (GetCount() < Numb) 
		{ 
			cout << endl << "Удаление невозможно, проверьте номер!" << endl; 
			return; 
		};    
		int nRazm = (int)GetCount();    
		POSITION pos = GetHeadPosition();    
		for (int i = 0;  i <(Numb-1); i++) 
		{ 
			GetNext(pos); 
		};    
		RemoveAt(pos); 
	};  
	headnum = (int)GetCount();
};
void Document::editedornot()
{ 
	cout << name<<" oтредактировано?" << endl;
	cin >> edited;
};
void Document::changepagesnum() {
	cout << "Сколько страниц в документе " << name<<"?" << endl;
	cin >> pagesnum;
};
int Document::getnumhead() 
{ 
	headnum = (int)GetCount(); 
	return headnum; 
};
char* Document:: getname()
{
	return name ;
};
int Document::getpages() 
{
	return pagesnum;
};
void Document::chooseDT()
{
	cout << "Введите номер типа документа: 0- text,1- book,2- report,3-other" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
		DT = text; 
		break;
	case 2:
		DT = book;
		break;
	case 3:
		DT = report; 
		break;
	
	case 4:
		DT = other;
		break;
	}
};
DocumentType Document::getDT() 
{
	return DT;
};
void Document::Clear()
{
	RemoveAll();
	headnum = (int)GetCount();
	pagesnum = 0;
};
void Document:: DocToFile()
{
	ofstream out("dzfile.bin", ios::binary | ios::out);
	headnum = this->headnum;
	POSITION pos = this->GetHeadPosition();
	out.write((char*)this, sizeof(*this));
	out.close();
};
void Document::DocFromFile()
{
	cout <<endl<< "Чтение документа из файла" << endl;
	ifstream in("dzfile.bin", ios::binary | ios::in);
	in.read((char*)(Document *)this, sizeof(*this));
	this->print(cout);
	cout << endl;
	in.close();
};


Document  Document:: operator +(Document &X)
{
	Document Z;
	Z.name = new char[strlen(this->name)+strlen(X.getname())+10];
	this->headnum = (int)this->GetCount();
	POSITION pos =this->GetHeadPosition();
	for (int i = 0; i < this->headnum; i++)
	{
		Z.AddTail(((Header *)this->GetAt(pos)));
		this->GetNext(pos);
	};	
	X.headnum = (int)X.GetCount();
	pos = X.GetHeadPosition(); 
	for (int i = 0; i < X.headnum; i++)
	{
		Z.AddTail(((Header *)X.GetAt(pos)));
		X.GetNext(pos);
	}
	strcpy_s(Z.name,strlen(this->name)+1, this->name);
	
	strcat_s(Z.name, strlen(this->name) + 7, "  ");
	strcat_s(Z.name, strlen(this->name) + strlen(X.getname()) + 8, X.getname());
	Z.headnum = (int)Z.GetCount();
	Z.pagesnum = X.pagesnum + this->pagesnum;
	if ((X.edited == false) || (this->edited == false)) Z.edited = false;
	else Z.edited = true;
	return Z;
};
Document & Document::operator =(Document &S)
{
	this->name = new char[strlen(S.getname())+1];
	strcpy_s(name, strlen(S.getname()) + 1, S.getname());
	this->Clear();
	S.headnum = S.GetCount();
	headnum =S.headnum;
	POSITION pos = S.GetHeadPosition();
	for (int i = 0; i < headnum; i++) 
	{
		AddTail(((Header *)S.GetAt(pos)));
		S.GetNext(pos);
	}; 
	edited = S.edited;
	pagesnum = S.pagesnum;
	DT = S.DT;
	return *this;
};

