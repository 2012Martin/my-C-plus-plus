#include "stdafx.h"
#include "CELLTimestamp.hpp"
#include "Alloctor.h"
#include "CCELLObjectPool.hpp"

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::mutex m;
const int tCount = 4;
const int mCount = 16;
const int nCount = mCount / tCount;

class ClassA : public ObjectPoolBase<ClassA, 5>
{
public:
	ClassA()
	{
		num = 0;
		printf("ClassA\n");
	}
	~ClassA()
	{
		printf("~ClassA\n");
	}

	int num = 0;
private:

};

class ClassB : public ObjectPoolBase<ClassB, 10>
{
public:
	ClassB(int n, int m)
	{
		num = n * m;
		//printf("ClassB\n");
	}
	~ClassB()
	{
		//printf("~ClassB\n");
	}

	int num = 0;
private:

};

void workFun(int index)
{

	ClassA* data[nCount];
	for (size_t i = 0; i < nCount; i++)
	{
		data[i] = ClassA::createObject();
	}
	for (size_t i = 0; i < nCount; i++)
	{
		ClassA::deleteObject(data[i]);
	}
}


int main()
{
	/*
	std::thread t[tCount];
	for (int n = 0; n < tCount; n++)
	{
		t[n] = std::thread(workFun, n);
	}
	CELLTimestamp cTime;
	for (int n = 0; n < tCount; n++)
	{
		t[n].join();
	}

	std::cout << cTime.getElapsedTimeInMilliSec() << std::endl;
	std::cout << "Hello, main thread." << std::endl;
	*/



	/*
	ClassA* a1 = new ClassA();
	delete a1;

	ClassA* a2 = ClassA::createObject();
	ClassA::deleteObject(a2);

	ClassB* b1 = new ClassB(2, 3);
	delete b1;

	ClassB* b2 = ClassB::createObject(2, 3);
	ClassB::deleteObject(b2);
	*/


	//�ڴ�غͶ���ؽ��
	
	//�ڴ�غ�����ָ���ϡ�����أ���������new delete����������������ܽ����Ҫע��
	ClassB* b1 = new ClassB(0, 1);
	delete b1;

	ClassA* a = new ClassA();
	delete a;

	printf("---------------1---------------\n");
	{
		std::shared_ptr<ClassA> s1 = std::make_shared<ClassA>();//������ͷ��ڴ�ֱ�ӽ��뵽�ڴ�أ�û�н�������
	}

	printf("---------------2---------------\n");
	{
		std::shared_ptr<ClassA> s1(new ClassA());//�Ƚ������أ�new ClassA()�����ڽ����ڴ�أ�ClassA���������Ĺ��������
	}

	printf("---------------3---------------\n");
	ClassA* a1 = new ClassA();
	delete a1;

	printf("---------------4---------------\n");

	return 0;
}