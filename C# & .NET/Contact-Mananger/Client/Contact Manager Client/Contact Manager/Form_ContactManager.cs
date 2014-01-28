//* Description *//
// Title: Contact Manager Form
// Author: Tyler Reed
// Defines the Functions for the Contact Manager Form

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
    // Contact Manager Class
    public partial class Form_ContactManager : Form
    {
        //* Class Variables *//
        public SqlConnection Connection;
        public Boolean ConfirmDelete = true;

        // Called to create the Contact Manager Form
        public Form_ContactManager()
        {
            InitializeComponent();
        }

        // Triggered when the "Return to Switchboard" Button is Pressed
        private void Button_Return_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        // Triggered when the "Create" Button is Pressed
        private void Button_Create_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            Form_CreateContact form_createContact = new Form_CreateContact();
            form_createContact.Connection = Connection;
            form_createContact.ShowDialog();
            this.Visible = true;
        }

        // Triggered when the "Edit" Button is Pressed
        private void Button_Edit_Click(object sender, EventArgs e)
        {
            // Make sure that a Row is Selected
            if(DataGrid_Contacts.SelectedRows.Count > 0)
            {
                DataGridViewCellCollection selectedRow = DataGrid_Contacts.SelectedRows[0].Cells;

                Form_CreateContact form_createContact = new Form_CreateContact();
                form_createContact.Connection = Connection;

                form_createContact.Modifying = true;
                form_createContact.ContactID = Convert.ToInt32(selectedRow[0].Value.ToString());
                form_createContact.Text = "Edit Contact";

                form_createContact.SetFirstName(selectedRow[1].Value.ToString());
                form_createContact.SetMiddleName(selectedRow[2].Value.ToString());
                form_createContact.SetLastName(selectedRow[3].Value.ToString());
                form_createContact.SetGender(selectedRow[4].Value.ToString());
                form_createContact.SetBirthDate(selectedRow[5].Value.ToString());
                form_createContact.SetAlias(selectedRow[6].Value.ToString());

                this.Visible = false;
                form_createContact.ShowDialog();
                this.Visible = true;
            }
            else
                MessageBox.Show("You must select a Contact to Edit!");
        }

        // Triggered when the "Delete" Button is Pressed
        private void Button_Delete_Click(object sender, EventArgs e)
        {
            // Make sure that a Row is Selected
            if(DataGrid_Contacts.SelectedRows.Count > 0)
            {
                // Make sure that the User really wants to Delete the selected Contact
                if(ConfirmDelete)
                {
                    int returnValue = ConfirmDeleteDialog.Show();

                    // Check if the User wanted to not see this Dialog again
                    if((returnValue & ConfirmDeleteDialog.OPTION_REMINDER) > 0)
                        ConfirmDelete = false;

                    // Check if the User responded No
                    if((returnValue & ConfirmDeleteDialog.OPTION_YES) == 0)
                        return;
                }

                string sql = "DELETE FROM Contact WHERE id = ";
                sql += DataGrid_Contacts.SelectedRows[0].Cells[0].Value;

                SqlDataAdapter adapter = new SqlDataAdapter(sql, Connection);
                DataSet data = new DataSet();
                adapter.Fill(data);

                PopulateContactList();
            }
            else
                MessageBox.Show("You must select a Contact to Delete!");
        }

        // Triggered when the Visibility of the Form is Changed
        private void Form_ContactManager_VisibleChanged(object sender, EventArgs e)
        {
            PopulateContactList();
        }

        // Triggered when the Form is Created
        private void Form_ContactManager_Load(object sender, EventArgs e)
        {
            PopulateContactList();
        }

        // Populates the Contact List with Contacts from the Database Connection
        public void PopulateContactList()
        {
            String sql = "SELECT id AS 'ID'," +
                         "first_name AS 'First Name'," +
                         "middle_name AS 'Middle Name'," +
                         "last_name AS 'Last Name'," +
                         "gender AS 'Gender'," +
                         "birthdate AS 'Birthdate'," +
                         "alias AS 'Alias' FROM Contact";

            SqlDataAdapter adapter = new SqlDataAdapter(sql, Connection);
            DataSet data = new DataSet();

            try
            {
                adapter.Fill(data);
            }
            catch(SqlException ex)
            {
                MessageBox.Show("Invalid SQL Statement:\r\n" + ex);
            }

            DataGrid_Contacts.DataSource = data.Tables[0];
            DataGrid_Contacts.AutoResizeColumns();
        }
    }
}
