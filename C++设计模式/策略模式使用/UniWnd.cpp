#include "EmuUniWnd.h"
#include "WndEnsure.h"
#include "MsgDefine.h"
#include "WndEnsure2.h"

void UniWnd::WndMsg(int nCode, UniWndMsg* pUniWndMsg)
{
	switch (nCode)
	{
	case 0:
	{

	}
	break;
	}
}

void UniWnd::WndEnsure(int nCode, UniWndMsg* pUniWndMsg)
{
	switch (nCode)
	{
	case UNI_CODE_ENSURE_DEL_CHEAT:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure2* pWnd;
		pWnd = new CWndEnsure2("ȷ��ɾ������");
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		if (IDOK == CWndBase::ShowModalWnd(hWnd))
		{
			::PostMessage(pUniWndMsg->mainHwnd, WM_ENUMWND_MSG_DEL_CHEAT, 0, 0);
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
	}
	break;
	case UNI_CODE_ENSURE_TUTRIAL:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure2* pWnd;
		pWnd = new CWndEnsure2("ȷ��������ϰģʽ");
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		if (IDOK == CWndBase::ShowModalWnd(hWnd))
		{
			::PostMessage(pUniWndMsg->mainHwnd, WM_ENUMWND_MSG_TUTRIAL, 0, 0);
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
	}
	break;
	case UNI_CODE_ENSURE_EXIT:
	case UNI_CODE_ENSURE_EXIT_RANKING:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure2* pWnd;
		if (nCode == UNI_CODE_ENSURE_EXIT_RANKING)
			pWnd = new CWndEnsure2("��������˳���Ϸ����Ϊ��������ؼ�¼��ȷ��Ҫ�˳���");
		else
			pWnd = new CWndEnsure2("�Ƿ��˳���ǰ��Ϸ");
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		if (IDOK == CWndBase::ShowModalWnd(hWnd))
		{
			::PostMessage(pUniWndMsg->mainHwnd, WM_CLOSE, 0, 0);
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
	}
	break;
	case UNI_CODE_ENSURE_EXIT_ELITE:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure* pWnd = new CWndEnsure("��;�˳������۳�������ս��", " *������Ϸʱ���۳�");
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		pWnd->UpdateBtnText("������Ϸ", "�˳�");
		if (IDCANCEL == CWndBase::ShowModalWnd(hWnd))
		{
			::PostMessage(pUniWndMsg->mainHwnd, WM_CLOSE, 0, 0);
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
	}
	break;
	}
}