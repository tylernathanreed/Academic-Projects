//* Description *//
// Title: Switchboard Form
// Author: Tyler Reed
// Defines the Functions for the Switchboard Form

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
    // Switchboard Class
    public partial class Form_Switchboard : Form
    {
        //* Class Variables *//
        public SqlConnection Connection;
        public Form_Connect Parent_Form;

        // Called to create the Form
        public Form_Switchboard()
        {
            InitializeComponent();
        }

        // Triggered when the "Contact Manager" Button is Pressed
        private void Button_ContactManager_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            Form_ContactManager form_contactManager = new Form_ContactManager();
            form_contactManager.Connection = Connection;
            form_contactManager.ShowDialog();
            this.Visible = true;
        }

        // Triggered when the "Event Planner" Button is Pressed
        private void Button_EventPlanner_Click(object sender, EventArgs e)
        {

        }

        // Triggered when the "Table Editor" Button is Pressed
        private void Button_TableEditor_Click(object sender, EventArgs e)
        {

        }

        // Triggered when the "SQL Injector" Button is Pressed
        private void Button_SQLInjector_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            Form_SQLInjector form_SQLInjector = new Form_SQLInjector();
            form_SQLInjector.Connection = Connection;
            form_SQLInjector.ShowDialog();
            this.Visible = true;
        }

        // Triggered when the "Change Connection" Button is Pressed
        private void Button_Connection_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        // Triggered when the "Close Connection" Button is Pressed
        private void Button_Close_Click(object sender, EventArgs e)
        {
            Parent_Form.Close();
            this.Close();
        }

        // Triggered when the Form is Closing
        private void Form_Switchboard_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                Parent_Form.Visible = true;
            }
            catch(ObjectDisposedException)
            {
                // Do Nothing
            }
        }
    }
}
