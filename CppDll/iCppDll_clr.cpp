#include "stdafx.h"
#include "iCppDll_clr.h"
#include "iToUi.h"
#include "TestDlg.h"
#include "CppDll.h"

extern CCppDllApp theApp;

namespace sCppDll
{
	iCppDll_clr::iCppDll_clr()
	{

	}

	void iCppDll_clr::Handle(String^ strMsg)
	{
		iToUi::Handle(strMsg);
	}

	void iCppDll_clr::ShowWindow()
	{
		HINSTANCE save_hInstance = AfxGetResourceHandle();
		AfxSetResourceHandle(theApp.m_hInstance);

		CTestDlg dlg;
		//dlg.DoModal();

		AfxSetResourceHandle(save_hInstance);

	}

}