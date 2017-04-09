// newDelete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <iostream>

using namespace std;

class Foo
{
public:
	int _id;
	long _data;
	string _str;

public:
	Foo():_id(0) {cout<<"default ctor. this=" << this << " id=" << _id << endl;}
	Foo(int i):_id(i) {cout<<"ctor. this=" << this << " id=" << _id << endl;}

	virtual
	~Foo() {cout<<"dtor. this=" << this << " id=" << _id << endl;} 

	static void* operator new(size_t size);
	static void operator delete(void* pdead, size_t size);
	static void* operator new[](size_t size);
	static void operator delete[](void* pdead, size_t size);
};

void* Foo::operator new(size_t size)
{
	Foo* p = (Foo*)malloc(size);
	cout<< "Foo::operator new(), size=" << size << "    return: " << p << endl;
	return p;
}

void Foo::operator delete(void* pdead, size_t size)
{
	cout<< "Foo::operator delete(), pdead=" << pdead << "  size=" << size <<endl;
	free(pdead);
}

void* Foo::operator new[](size_t size)
{
	Foo* p = (Foo*)malloc(size);
	cout<< "Foo::operator new[](), size=" << size << "    return: " << p << endl;
	return p;
}

void Foo::operator delete[](void* pdead, size_t size)
{
	cout<< "Foo::operator delete[](), pdead=" << pdead << "  size=" << size <<endl;
	free(pdead);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//����members�͵���golbals
	//Foo* pf = new Foo;
	//delete pf;

	//����ǿ�Ƶ���globals
	//Foo* pf2 = ::new Foo;//���õ���void* ::operator new(size_t);
	//::delete pf2;//���õ���void ::operator delete(void*);

	/*cout<< "sizeof(Foo)=" << sizeof(Foo) << endl;

	Foo *p = new Foo(7);
	delete p;

	Foo* pArray = new Foo[5];
	delete [] pArray;*/

	Foo *p = ::new Foo(7);
	::delete p;

	Foo* pArray = ::new Foo[5];
	::delete [] pArray;

	return 0;
}

