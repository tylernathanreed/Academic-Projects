//* Description *//
// Title: SQL Injector Form
// Author: Tyler Reed
// Defines the Functions for the SQL Injector Form

//* Libraries *//
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

//* Namespace *//
namespace Contact_Manager_Client
{
    // SQL Injector Class
    public partial class Form_SQLInjector : Form
    {
        //* Class Variables *//
        public SqlConnection Connection;

        // Called to create the SQL Injector Form
        public Form_SQLInjector()
        {
            InitializeComponent();
        }

        // Triggered when the "Send" Button is Clicked
        private void Button_Send_Click(object sender, EventArgs e)
        {
            ExecuteSQL();
        }

        // Triggered when a Key is Pressed while the "SQL" Textbox is Active
        private void TextBox_SQL_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                ExecuteSQL();
            }
        }

        // Parses the SQL Statement
        public void ExecuteSQL()
        {
            SqlDataAdapter adapter = new SqlDataAdapter(TextBox_SQL.Text, Connection);
            DataSet data = new DataSet();
            TextBox_Error.Visible = true;

            try
            {
                adapter.Fill(data);
            }
            catch(SqlException ex)
            {
                TextBox_Error.Text = "Invalid Statement: \r\n" + ex.Message;
                return;
            }

            try
            {
                DataGrid_Output.DataSource = data.Tables[0];
                DataGrid_Output.AutoResizeColumns();
            }
            catch(IndexOutOfRangeException)
            {
                TextBox_Error.Text = "Statement Executed Successfully";
                return;
            }

            TextBox_Error.Visible = false;
        }

        // Triggered when the "Return to Switchboard" Button is Pressed
        private void Button_Return_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
