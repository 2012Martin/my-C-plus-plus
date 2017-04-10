// newDelete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <iostream>

using namespace std;

class Bad
{
public:
	Bad(){cout << "terminate called after throwing an instance of ::Bad" << endl;}
};

class Foo
{
public:
	Foo(){cout<<"Foo::Foo()" << endl;}
	Foo(int i){cout<<"Foo::Foo(int)" << endl; throw Bad();}
	//�����������׳�expection������placement operator delete

	//1.һ���operator new()������
	void* operator new(size_t size){
		cout << "operator new(size_t size), size=" << size <<endl;
		return malloc(size);
	}
	//2.��׼�����ṩ��placement new()�����ص���ʽ��ģ��standard placement new
	void* operator new(size_t size, void* start){
		cout << "operator new(size_t size, void* start), size=" << size  << " start=" << start <<endl;
		return start;
	}
	//3.�����ո�µ�placement new
	void* operator new(size_t size, long extra){
		cout << "operator new(size_t size, long extra), size=" << size  << " extra=" << extra <<endl;
		return malloc(size+extra);
	}
	//4.������һ��placement new
	void* operator new(size_t size, long extra, char init){
		cout << "operator new(size_t size, char init), size=" << size  << " char=" << init <<endl;
		return malloc(size+extra);
	}
	//5.����д���һ��������type
	//error C2821: ��operator new���ĵ�һ���βα���Ϊ��size_t��
	/*void* operator new(long extra, char init){
		return malloc(extra);
	}*/

	//1.һ���operator delete()������
	void operator delete(void*, size_t){
		cout << "operator delete(void*, size_t)" << endl;
	}

	//2.
	void operator delete(void*, void*){
		cout << "operator delete(void*, void*)" << endl;
	}

	//3.
	void operator delete(void*, long){
		cout << "operator delete(void*, long)" << endl;
	}

	//4.
	void operator delete(void*, long, char){
		cout << "operator delete(void*, long, char)" << endl;
	}

private:
	int m_i;
};




int _tmain(int argc, _TCHAR* argv[])
{
    Foo start;
	Foo* p1 = new Foo;
	Foo* p2 = new(&start) Foo;
	Foo* p3 = new(100) Foo;
	Foo* p4 = new(100, '1') Foo;
	Foo* p5 = new(100) Foo(1);//vs2010û�е���operator delete(void*, long)

	return 0;
}

