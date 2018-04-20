#pragma once
#include <string>
#include <windows.h>
using namespace std;

#include "MsgDefine.h"

class UniWndStrategy;

#ifndef _UNIVERSAL_WND_MSG_
#define _UNIVERSAL_WND_MSG_
typedef struct  tagUniversalWndMsg
{
	HWND mainHwnd;
	string strTitle;
	string strText;
	int nSeatIndex;
}UniWndMsg;
#endif

class UniWndStrategy
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg) = 0;
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg) = 0;
};

class UniWnd : public UniWndStrategy
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg);
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};

class NormalGrappleWnd : public UniWnd//��ͨ������Ϸ
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg);
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};

class NormalStageClearWnd : public UniWnd//��ͨ��������Ϸ
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg);
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};

class EliteGrappleWnd : public UniWnd//��Ӣ������Ϸ
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg);
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};

class EliteStageClearWnd : public UniWnd//��Ӣ��������Ϸ
{
public:
	virtual void WndMsg(int nCode, UniWndMsg* pUniWndMsg);
	virtual void WndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};

class EmuUniWnd
{
private:
	EmuUniWnd() {};
	virtual ~EmuUniWnd() {};
	EmuUniWnd(const EmuUniWnd& other) {};
	EmuUniWnd& operator=(const EmuUniWnd&) {};

public:
	static EmuUniWnd* GetInstance()
	{
		static EmuUniWnd sg;
		return &sg;
	}

	void DoWndMsg(int nCode, UniWndMsg* pUniWndMsg);

	void DoWndEnsure(int nCode, UniWndMsg* pUniWndMsg);
};