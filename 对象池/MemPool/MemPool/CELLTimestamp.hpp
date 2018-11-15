#ifndef _CELLTimestamp_hpp_
#define _CELLTimestamp_hpp_

#include <chrono>
//using namespace std::chrono;

class CELLTimestamp
{
public:
	CELLTimestamp()
	{
		update();
	}

	~CELLTimestamp()
	{
	}

	void update()
	{
		_begin = std::chrono::high_resolution_clock::now();
	}

	/************************************************************************/
	/* ��ȡ��ǰ��                                                           */
	/************************************************************************/
	double getElapsedSecond()
	{
		return getElapsedTimeInMicroSec() * 0.000001;
	}

	/************************************************************************/
	/* ��ȡ����                                                           */
	/************************************************************************/
	double getElapsedTimeInMilliSec()
	{
		return this->getElapsedTimeInMicroSec() * 0.001;
	}

	/************************************************************************/
	/* ��ȡ΢��                                                           */
	/************************************************************************/
	long long getElapsedTimeInMicroSec()
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
	}

protected:
	std::chrono::time_point<std::chrono::high_resolution_clock> _begin;
};

#endif