#include "EmuUniWnd.h"
#include "WndEnsure.h"
#include "WndEnsure2.h"
#include "emu_manager/EmuManager.h"

void NormalGrappleWnd::WndMsg(int nCode, UniWndMsg* pUniWndMsg)
{
	switch (nCode)
	{
	case 1:
	{

		return;
	}
		break;
	}
	UniWnd::WndMsg(nCode, pUniWndMsg);
}

void NormalGrappleWnd::WndEnsure(int nCode, UniWndMsg* pUniWndMsg)
{
	switch (nCode)
	{
	case UNI_CODE_ENSURE_WATCH_NORMAL:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure2* pWnd = new CWndEnsure2("��Ϊ���ں�����ʧȥ�������Ȩ");
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		if (IDOK == CWndBase::ShowModalWnd(hWnd))
		{
			EmuManager::Instance()->netStandUp();
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
		return;
	}
	break;
	case UNI_CODE_ENSURE_JOIN_NORMAL:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CDuiString strTitle;
		strTitle.Format("������Ϸ��Ҫ������%dͭ��", EmuManager::Instance()->m_pPlayerManager->getRoom().m_nSitCost);
		CWndEnsure2* pWnd = new CWndEnsure2(strTitle);
		HWND hWnd = pWnd->CreateModalWnd(pUniWndMsg->mainHwnd);
		if (IDOK == CWndBase::ShowModalWnd(hWnd))
		{
			EmuManager::Instance()->netSitDown(pMsg->nSeatIndex);
		}
		if (pMsg)
		{
			delete pMsg;
			pMsg = nullptr;
		}
		return;
	}
	break;
	}
	UniWnd::WndEnsure(nCode, pUniWndMsg);
}