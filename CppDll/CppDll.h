// CppDll.h : CppDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCppDllApp
// �йش���ʵ�ֵ���Ϣ������� CppDll.cpp
//

class CCppDllApp : public CWinApp
{
public:
	CCppDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};