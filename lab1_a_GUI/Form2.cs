using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WordString
{
    public partial class Form1 : Form
    {
        string Nword = null;
        char start_ch = '\0';
        char end_ch = '\0';
        bool longest_word = false;
        bool longest_letter = false;
        bool flag_Nword = false;
        bool flag_start = false;
        bool flag_end = false;
        //char[] filepath = new char[100];
        string filepath;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox3.Text.Length > 0)
                start_ch = textBox3.Text[0];
            if (textBox2.Text.Length > 0)
                end_ch = textBox2.Text[0];
            Nword = textBox4.Text;
            filepath = textBox1.Text;
            string input = "Wordlist.exe";
            if (flag_start)
                input += " -h " + start_ch;
            if (flag_end)
                input += " -t " + end_ch;
            if (flag_Nword)
                input += " -n " + Nword;
            if (longest_letter)
                input += " -c ";
            if (longest_word)
                input += " -w ";
            input += ' ' + filepath;
            textBox5.Text = input;
        }

        

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            longest_word = true;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            longest_letter = true;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            flag_start = !flag_start;
        }

        private void checkBox5_CheckedChanged_1(object sender, EventArgs e)
        {
            flag_end = !flag_end;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            flag_Nword = !flag_Nword;
        }
    }
}
