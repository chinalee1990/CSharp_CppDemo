using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace CSharpCppDemo
{
    public partial class Form1 : Form
    {
        int m_nCount;
        public Form1()
        {
            InitializeComponent();
            this.Text = "实验仿真系统";

        }

        private void button1_Click(object sender, EventArgs e)
        {
            sCppDll.iCppDll_clr.Handle("StartRun");

            sCppDll.iCppDll_clr.Handle("Button 1 CLick");
        }


        protected override void WndProc(ref Message msg)
        {
            switch (msg.Msg)
            {
                case 0x0400+1:

                string strWParam = Marshal.PtrToStringAnsi(msg.WParam);
                string strLParam = Marshal.PtrToStringAnsi(msg.LParam);
        
                label1.Text = strWParam + "  " + strLParam;

                m_nCount++;

                label2.Text = m_nCount.ToString();

                if (m_nCount==10000)
                {
                   // GC.Collect(0);
                    m_nCount = 0;
                }
                break;
            }
            base.WndProc(ref msg);

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            //iToDll.Handle("EndRun");
            sCppDll.iCppDll_clr.Handle("EndRun");

        }

        private void button2_Click(object sender, EventArgs e)
        {
            sCppDll.iCppDll_clr.Handle("Stop");

        }

        private void button3_Click(object sender, EventArgs e)
        {
            sCppDll.iCppDll_clr.ShowWindow();
        }

    }
}
