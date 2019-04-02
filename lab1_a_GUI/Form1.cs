using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//加这一句
using System.Runtime.InteropServices;

namespace GUI2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Add(int x, int y);

        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Get_string")]
        public static extern bool Get_string(ref byte str);

        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Put_Get_string")]
        public static extern bool Put_Get_string(ref byte str_out,ref byte str_in );

        //EntryPoint = "CallString")]
        //public static extern int CallString(ref byte str);

        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Wordlist_func(
                                                    ref byte filepath,
                                                    int Nword,
                                                    char start_ch,
                                                    char end_ch,
                                                    bool longest_word,
                                                    bool longest_letter,
                                                    ref byte out_meg);//输入);


        bool start_flag = false;
        bool end_flag = false;
        bool num_flag=false;
        bool longest_flag=true;
        bool letter_flag = false;

        string a;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {
            

            int a= Add(123, 321);

        }



        private void label2_Click(object sender, EventArgs e)
        {

            byte[] s = new byte[1024];
            bool t = Get_string(ref s[0]);//用字节数组接收动态库传过来的字符串
            string strGet = System.Text.Encoding.Default.GetString(s, 0, s.Length); //将字节数组转换为字符串
            label2.Text = strGet;
        }

        private void label3_Click(object sender, EventArgs e)
        {
            byte[] s_out = new byte[1024];
            byte[] s_in = Encoding.UTF8.GetBytes("hello pjl");
            bool t = Put_Get_string(ref s_out[0],ref s_in[0]);//用字节数组接收动态库传过来的字符串//传入传出字符串都他妈要这么干，麻烦


            string strGet = System.Text.Encoding.Default.GetString(s_out, 0, s_out.Length); //将字节数组转换为字符串
            label3.Text = strGet;
        }



        private void button1_Click(object sender, EventArgs e)
        {
            


            int Nword = num_flag ? int.Parse(textBox3.Text) : 0;//
            char start_ch = start_flag ? textBox2.Text[0] : '\0';
            char end_ch = end_flag ? textBox4.Text[0] : '\0';

            byte[] out_meg = new byte[102400];
            Wordlist_func(
                ref Encoding.UTF8.GetBytes(textBox6.Text)[0],//获取文件目录
                Nword,
                start_ch,
                end_ch,
                longest_flag,
                letter_flag,
                ref out_meg[0]
                );
             a= System.Text.Encoding.ASCII.GetString(out_meg); //将字节数组转换为字符串
            textBox1.Text = "";//初始化？
            textBox1.Text = a;
            //MessageBox.Show(a);
            //textBox1_TextChanged(sender,e);
        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void label3_Click_1(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            
        }


        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            longest_flag = !longest_flag;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            start_flag = !start_flag;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            end_flag = !end_flag;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            num_flag = !num_flag;
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            letter_flag = !letter_flag;
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
/*
    C#中对dll中的字符指针传入传出的操作：
    传入：
    1，把对应的字符串转换成字符数组
    2，接口设置为Get_string(ref byte str);

    传出：
    1，接口同样Get_string(ref byte str);
    2，调用时：Get_string(ref s[0])
    3，s为一个字节数组

    总的来说，都是用字符数组来传进传出，而且是传ref s[0]
    记住字符数组跟字符串的转换函数：
    byte[] s_in = Encoding.UTF8.GetBytes("hello pjl");
    string strGet = System.Text.Encoding.Default.GetString(s, 0, s.Length);

    而在dll的接口都是char*

    更新日志：
    3.26，

 */
