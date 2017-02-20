#include "stdafx.h"
#include "iToUi.h"
//#include "comutil.h"
#include "MySystem.h"



iToUi::iToUi()
{
}


iToUi::~iToUi()
{
}


void iToUi::Handle(CString strInfo)
{
	//std::string strInfo1 = strInfo;
	//TRACE(_T("%s\r\n"), strInfo);

	//iToUi::PostMessageToUiThread(_T("infoUi"));
	std::string strmsg = strInfo;
	TRACE("%s\r\n", strmsg.c_str());
	MySystem::GetInstance()->RecvMsg(strmsg);

}


void iToUi::PostMessageToUiThread(const CString &strMsg)
{
	

	HWND hWnd = FindWindow(NULL, _T("实验仿真系统"));
	TRACE(_T("%d\r\n"), hWnd);


	char *info = "post";
	char *info1 = _T("info1 ");

	PostMessage(hWnd, WM_USER_MYMSG, (WPARAM)info, (LPARAM)info1);

}

void iToUi::PostMessageToUi(const std::string &strMsg)
{
	HWND hWnd = FindWindow(NULL, _T("实验仿真系统"));
	//char *info = new char[];
	//CString strInfo = strMsg.c_str();

	char *info = const_cast<char*>(strMsg.c_str());
	//char *info = strInfo;


	//CString strInfo = strMsg.c_str();
	//String ^str = gcnew String(strInfo);

	SendMessage(hWnd, WM_USER_MYMSG, (WPARAM)info, 0);
	//PostMessage(hWnd, WM_USER_MYMSG, (WPARAM)info, (LPARAM)info1);

	//PostMessage(hWnd, WM_USER_MYMSG, (WPARAM)info, (LPARAM)&"/SendMessage(hWnd, WM_USER_MYMSG, (WHWND hWnd = FindWindow(NULL, _T(\"实验仿真系统\"));\"PARAM)&str, 0\void iToUi::PostMessageToUi(const std::string &strMsg)");
	//delete info;
}
