#pragma once
#include "MyThread.h"

#define TALK_MESSAGE WM_USER+100

class MySystem
{
public:
	MySystem();
	~MySystem();

	static MySystem *GetInstance();
	static void DelInstance();

	static MySystem *m_instance;

	void Start();
	void End();

	void RecvMsg(const std::string &strMsg);

	void ExeMsg(std::string &strMsg);

	MyThread m_threadSys;

	MyThread m_threadTimer;

	static UINT ThreadFunc(LPVOID lpParam);

	static UINT TimerSendThreadFunc(LPVOID lpParam);

	void SendMsg(std::string &strMsg);
	//std::string m_recvMsg;

};

