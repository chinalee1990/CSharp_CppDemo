#pragma once



//extern "C" 
//{
//	_declspec(dllimport) void Handle(CString strMsg);
//
//};
#define WM_USER_MYMSG		WM_USER+1




class iToUi
{
public:
	iToUi();
	~iToUi();

	static void Handle(CString strInfo);

	static void PostMessageToUiThread(const CString &strMsg);
	static void PostMessageToUi(const std::string &strMsg);

};

