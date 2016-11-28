#include "stdafx.h"
#include "MySystem.h"
#include "iToUi.h"

MySystem* MySystem::m_instance = NULL;

MySystem::MySystem()
{
}


MySystem::~MySystem()
{
}

MySystem *MySystem::GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MySystem();
	}
	return m_instance;
}

void MySystem::DelInstance()
{
	delete m_instance;
	m_instance = NULL;
}

void MySystem::Start()
{
	m_threadSys.StartThread(this, ThreadFunc, _T(""), 0);
	m_threadTimer.StartThread(this, TimerSendThreadFunc, _T(""), 0);

}

void MySystem::End()
{
	m_threadSys.m_pWinThread->PostThreadMessage(WM_QUIT, 0, 0);
	m_threadTimer.EndThread();
	DelInstance();
}

void MySystem::RecvMsg(const std::string &strMsg)
{
	if (strMsg == "StartRun")
	{
		Start();

		std::string *strMsg1 = new std::string(strMsg);

		m_threadSys.m_pWinThread->PostThreadMessage(TALK_MESSAGE, (WPARAM)strMsg1, 0);

	}
	else if (strMsg == "EndRun")
	{
		End();
	}
	else
	{
		std::string *strMsg1 = new std::string(strMsg);

		m_threadSys.m_pWinThread->PostThreadMessage(TALK_MESSAGE, (WPARAM)strMsg1, 0);

	}

}

UINT MySystem::ThreadFunc(LPVOID lpParam)
{
	MyThread *thread = (MyThread *)lpParam;
	MySystem *handle = (MySystem *)thread->m_pHandleClass;

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (msg.message == TALK_MESSAGE)
		{
			//MessageBox(NULL, L"Hi", L"Worker Thread", MB_OK);
			std::string *strMsg = (std::string*)msg.wParam;

			handle->ExeMsg(*strMsg);

			delete strMsg;
			TRACE("%s\r\n", handle->m_recvMsg.c_str());

		}

		DispatchMessage(&msg);

	}

	//MessageBox(NULL, L"Thread will close", L"From Worker Thread", MB_OK);

	//AfxGetApp()->m_pMainWnd->PostMessageW(TALK_MESSAGE + 1, 0, 0);

	return 0;
}

void MySystem::ExeMsg(std::string &strMsg)
{
	m_recvMsg = strMsg;
	TRACE("%s\r\n", m_recvMsg.c_str());
}

UINT MySystem::TimerSendThreadFunc(LPVOID lpParam)
{
	MyThread *thread = (MyThread *)lpParam;
	MySystem *handle = (MySystem *)thread->m_pHandleClass;

	while (handle->m_threadTimer.isThreadRun())
	{
		handle->SendMsg();
		Sleep(10);
	}
	return 0;
}

void MySystem::SendMsg()
{
	if (m_recvMsg == "Stop")
		return;
	iToUi::PostMessageToUi(m_recvMsg);

}