using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Contact_Manager_Client
{
    public partial class Form_Connect : Form
    {
        // Attempts to Connect to the Database
        public bool TestConnection()
        {
            SqlConnection connection = new SqlConnection("Server=" + TextBox_Server.Text + ";" +
                                             "Database=" + TextBox_Database.Text + ";" +
                                             "Trusted_Connection=" + (CheckBox_Trusted.Checked ? "yes;" : "no;") +
                                             "Connection Timeout=" + TextBox_Timeout.Text + ";");
            // Open the Connection
            try
            {
                connection.Open();
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Connection is Invalid:\n" + ex.Message);
                return false;
            }

            // Transition to the Switchboard Form
            this.Visible = false;
            Form_Switchboard form_switchboard = new Form_Switchboard();
            form_switchboard.Connection = connection;
            form_switchboard.Parent_Form = this;
            form_switchboard.ShowDialog();
            return true;
        }

        // Called to create the Connect Form
        public Form_Connect()
        {
            InitializeComponent();
        }

        // Forces Digit constrait on TextBox
        private void TextBox_Timeout_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!char.IsControl(e.KeyChar) && char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        // Triggered when the "Connect" Button is Pressed
        private void Button_Connect_Click(object sender, EventArgs e)
        {
            TestConnection();
        }

        // Triggered when a Key is Pressed while the "Server" Textbox is Active
        private void TextBox_Server_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                TestConnection();
            }
        }

        // Triggered when a Key is Pressed while the "Database" Textbox is Active
        private void TextBox_Database_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                TestConnection();
            }
        }

        // Triggered when a Key is Pressed while the "Timeout" Textbox is Active
        private void TextBox_Timeout_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                TestConnection();
            }
        }

        // Triggered when the "Close" Button is Pressed
        private void Button_Close_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
