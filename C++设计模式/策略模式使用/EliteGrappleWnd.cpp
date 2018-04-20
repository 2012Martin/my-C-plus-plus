#include "EmuUniWnd.h"
#include "WndEnsure.h"
#include "WndEnsure2.h"
#include "emu_manager/EmuManager.h"

void EliteGrappleWnd::WndMsg(int nCode, UniWndMsg* pUniWndMsg)
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

void EliteGrappleWnd::WndEnsure(int nCode, UniWndMsg* pUniWndMsg)
{
	switch (nCode)
	{
	case UNI_CODE_ENSURE_WATCH_ELITE:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CWndEnsure2* pWnd = new CWndEnsure2("��ս���㽫����ⳡ������ͭ��");
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
	case UNI_CODE_ENSURE_JOIN_GRAPPLE_ELITE:
	{
		UniWndMsg* pMsg = pUniWndMsg;
		CDuiString strTitle;
		strTitle.Format("ÿ�����������󣬻�ʤһ�������%d��ս��", EmuManager::Instance()->m_pPlayerManager->getRoom().m_nChallengeMoney);
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