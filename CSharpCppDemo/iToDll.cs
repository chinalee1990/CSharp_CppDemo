using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.InteropServices;

namespace CSharpCppDemo
{


    class iToDll
    {
        [DllImport("CppDll.dll")]
        public static extern void Handle(string strInfo);


    }
}
