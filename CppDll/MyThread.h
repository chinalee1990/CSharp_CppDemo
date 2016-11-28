#pragma once

#include "afxmt.h"

class MyThread
{
public:
	MyThread(void);
	~MyThread(void);

	virtual void StartThread(LPVOID pHandleClass, AFX_THREADPROC pProcFun,const CString &strHandleObj,const int &nThreadType);
	void EndThread(bool bWait=true);

public:		bool isThreadRun();

public:		CWinThread	*m_pWinThread;
public:		CCriticalSection m_critSec;

public:		LPVOID m_pHandleClass;													//运行线程函数的类
public:		CString m_strHandleObj;													//线程处理的对象
public:		int m_nThreadType;														//线程类型，由用户定义类型
public:		int m_nThreadWorkState;													//线程工作状态 0:停止 >0:工作（由用户定义>0的状态，开启线程时，自动为1）

public:		void SetEvent();
public:		void WaitEvent();

public:		CEvent m_event;
public:		CString m_strThreadName;


};
