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

public:		LPVOID m_pHandleClass;													//�����̺߳�������
public:		CString m_strHandleObj;													//�̴߳����Ķ���
public:		int m_nThreadType;														//�߳����ͣ����û���������
public:		int m_nThreadWorkState;													//�̹߳���״̬ 0:ֹͣ >0:���������û�����>0��״̬�������߳�ʱ���Զ�Ϊ1��

public:		void SetEvent();
public:		void WaitEvent();

public:		CEvent m_event;
public:		CString m_strThreadName;


};