using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using FridgeScript;

namespace FSCS
{
    public partial class Form1 : Form
    {
        Context Context;

        public Form1()
        {
            InitializeComponent();
            Context = new Context();
            Context.Programs.Add("a=1;");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Context.Programs[0].Script = textBox1.Text;
            Context.Programs[0].Execute();
            label1.Text = "a = " + Context.Programs[0].GetVariable("a").Value.ToString()
                            + ",b = " + Context.Programs[0].GetVariable("b").Value.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
