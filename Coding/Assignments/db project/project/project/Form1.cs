using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 's8ProjectDataSet.STUDENT' table. You can move, or remove it, as needed.
            


        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=DESKTOP-D8NJMO2\\SQLEXPRESS;Initial Catalog=S8Project;Integrated Security=True;");
            SqlCommand sqlcommand = new SqlCommand();
            sqlcommand.Connection = sqlConnection;
            sqlConnection.Open();
            sqlcommand.CommandText = "INSERT INTO STUDENT VALUES ("+textBox1.Text+ ", '"+textBox2.Text+"',"+textBox3.Text+ ", '"+textBox4.Text+"', '"+textBox5.Text+"', '"+textBox6.Text+"', '"+textBox7.Text+"');";
            sqlcommand.ExecuteNonQuery();
            sqlConnection.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.sTUDENTTableAdapter.Fill(this.s8ProjectDataSet.STUDENT);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=DESKTOP-D8NJMO2\\SQLEXPRESS;Initial Catalog=S8Project;Integrated Security=True;");
            SqlCommand sqlcommand = new SqlCommand();
            sqlcommand.Connection = sqlConnection;
            sqlConnection.Open();
            sqlcommand.CommandText = "update STUDENT set SNAME = '"+textBox2.Text+"' where SID = "+textBox1.Text+";";
            sqlcommand.ExecuteNonQuery();
            sqlConnection.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=DESKTOP-D8NJMO2\\SQLEXPRESS;Initial Catalog=S8Project;Integrated Security=True;");
            SqlCommand sqlcommand = new SqlCommand();
            sqlcommand.Connection = sqlConnection;
            sqlConnection.Open();
            sqlcommand.CommandText = "Delete from student where SID = " + textBox1.Text + ";";
            sqlcommand.ExecuteNonQuery();
            sqlConnection.Close();
        }
    }
}
