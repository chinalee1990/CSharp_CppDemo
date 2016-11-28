#include "StdAfx.h"
#include "MyThread.h"


MyThread::MyThread(void)
{
	m_nThreadWorkState = false;
}

MyThread::~MyThread(void)
{
}

void MyThread::StartThread(LPVOID pHandleClass, AFX_THREADPROC pProcFun,const CString &strHandleObj,const int &nThreadType)
{
	m_pHandleClass = pHandleClass;
	m_strHandleObj = strHandleObj;
	m_nThreadType = nThreadType;
	m_nThreadWorkState = 1;
	m_pWinThread = AfxBeginThread(pProcFun,this);
}

void MyThread::EndThread(bool bWait)
{
	
	if (m_nThreadWorkState>0)
	{	
		m_nThreadWorkState = 0;
		if(bWait==true)
			WaitForSingleObject(m_pWinThread->m_hThread,INFINITE);
	}
}

bool MyThread::isThreadRun()
{
	return m_nThreadWorkState>0?true:false;
}

void MyThread::SetEvent()
{
	m_event.SetEvent();
}

void MyThread::WaitEvent()
{
	::WaitForSingleObject(m_event.m_hObject, 3000);
}

