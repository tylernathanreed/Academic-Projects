//* Description *//
// Title: Confirm Delete
// Author: Tyler Reed
// Prompts the User for Delete Confirmation

//* Libraries *//
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

//* Namespace *//
namespace Contact_Manager_Client
{
    // Confirm Delete Class
    public partial class Form_ConfirmDelete : Form
    {
        //* Class Variables *//
        private int returnValue = 0;

        // Called to Create the Confirm Delete Form
        public Form_ConfirmDelete()
        {
            InitializeComponent();
        }

        // Called to Show the Dialog
        public int ReturnDialog()
        {
            this.ShowDialog();
            return returnValue;
        }

        // Triggered when the "Yes" Button is Pressed
        private void Button_Yes_Click(object sender, EventArgs e)
        {
            returnValue = ConfirmDeleteDialog.OPTION_YES + (CheckBox_Reminder.Checked ? ConfirmDeleteDialog.OPTION_REMINDER : 0);
            this.Close();
        }

        // Triggered when the "No" Button is Pressed
        private void Button_No_Click(object sender, EventArgs e)
        {
            returnValue = CheckBox_Reminder.Checked ? ConfirmDeleteDialog.OPTION_REMINDER : 0;
            this.Close();
        }
    }
}
