#pragma once
using namespace System;
using namespace System::Threading;
namespace sCppDll
{

	public ref class iCppDll_clr
	{
	public:
		iCppDll_clr();
	
	public: 
		static void Handle(String^ strMsg);
		static void SetCallBack(SendOrPostCallback ^callback);
		static void SendToUi(const std::string &strInfo);
		static System::Threading::SendOrPostCallback ^m_callback;
		static System::Threading::SynchronizationContext ^m_context;
		//static void ShowWindow();
	};

}

