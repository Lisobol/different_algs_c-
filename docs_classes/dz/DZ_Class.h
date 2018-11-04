#pragma once
#include <iostream>
#include "afxwin.h"
#include "DZ1.h"
using namespace std;
class  AbstrHeader : public CObject{
	
public:
	virtual char *className() = 0; 
	virtual void print(ostream &out) = 0;
	//char *text;
	AbstrHeader() {/* text = (char *)NULL;*/ };
	~AbstrHeader()
	{
		/*if (text != (char *)NULL)       
			delete[] text; */
	}; 
	  
};
class Header :public AbstrHeader{
	int position;//уровни заголовков
	char* text/*[80]*/;//текст заголовка
	char color[80];
	int nomer;
	HeaderType HT;
	void changetext();
	void changecolor();
	void setpos();
public:
	//static int number ;//порядковый номер заголовка в документе

	Header();
	Header(Header &H);
	Header(Header *pH);
	Header(char *a, int p,char *c);
	Header(char *a);
	Header(char *a,int p);
	Header(char *a, int p, char *c, HeaderType x);



	
	friend void changeHeader(Header &H) ;
	const char* gettext();
	void chooseHT();
	virtual char *className() { return "Header"; };
	virtual void print(ostream &out);
	Header & operator =(Header &  H);
	/*Header & operator +(Header & H1);*/
	friend ostream & operator << (ostream &  out, Header &  obj);
	 
	~Header() { nomer--; };
};
class Document : public CObList {
	char* name;
	int headnum;
	bool edited;
	int pagesnum;
	DocumentType DT;
public:
	Document(); 
	Document(char *s); 
	Document(char *s, int p);
	Document(char *s, int p, bool e);
	Document(char *s,int p,bool e,DocumentType D);
	Document(Document &D);
	Document(Document *pD);
	~Document() {};

	void changename();
	void editedornot();
	void changepagesnum();
	void add(Header *pH, TypeAddDel t, int Numb);
	void del(TypeAddDel t, int Numb);
	int getnumhead();
	int getpages();
	char* getname();
	void chooseDT();
	DocumentType getDT();
	void Clear();

	virtual char *className() { return "Document"; };
	virtual void print(ostream & out);
	Document  operator +(Document &X);
	Document & operator =(Document &S);
	void DocToFile();
	void DocFromFile();
	

};
//
//class Obj:public AbstrHeader {
//public:
//	Obj() {};
//	virtual char *className() { return "Obj"; };
//	virtual void print(ostream &out) { cout << "Наследник от AbstrHeader" << endl; };
//	~Obj(){};
//};