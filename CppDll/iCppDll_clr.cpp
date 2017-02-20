#include "stdafx.h"
#include "iCppDll_clr.h"
#include "iToUi.h"
#include "TestDlg.h"
#include "CppDll.h"
#include "MySystem.h"

extern CCppDllApp theApp;

namespace sCppDll
{
	iCppDll_clr::iCppDll_clr()
	{

	}

	void iCppDll_clr::Handle(String^ strMsg)
	{
		CString strMsg1 = strMsg;
		MySystem::GetInstance()->RecvMsg((std::string)strMsg1);
		//iToUi::Handle(strMsg);
	}


	void iCppDll_clr::SetCallBack(SendOrPostCallback ^callback)
	{
		m_callback = callback;
		m_context = System::Threading::SynchronizationContext::Current;


	}


	void iCppDll_clr::SendToUi(const std::string &strInfo)
	{
		String ^strInfo1 = gcnew String(strInfo.c_str());
		m_context->Post(m_callback, strInfo1);
	}


	//void iCppDll_clr::ShowWindow()
	//{
	//	HINSTANCE save_hInstance = AfxGetResourceHandle();
	//	AfxSetResourceHandle(theApp.m_hInstance);

	//	CTestDlg dlg;
	//	//dlg.DoModal();

	//	AfxSetResourceHandle(save_hInstance);

	//}

}