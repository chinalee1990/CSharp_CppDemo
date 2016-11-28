#pragma once
using namespace System;

namespace sCppDll
{

	public ref class iCppDll_clr
	{
	public:
		iCppDll_clr();
	
	public: 
		static void Handle(String^ strMsg);

		static void ShowWindow();
	};

}

