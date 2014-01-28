//* Description *//
// Title: Create Contact Form
// Author: Tyler Reed
// Defines the Functions for the Create Contact Form

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
    // Create Contact Class
    public partial class Form_CreateContact : Form
    {
        //* Class Variables *//
        public SqlConnection Connection;
        public Boolean Modifying = false;
        public int ContactID = -1;

        // Called to create the Create Contact Form
        public Form_CreateContact()
        {
            InitializeComponent();
        }

        // Triggered when the "Save" Button is Pressed
        private void Button_Save_Click(object sender, EventArgs e)
        {
            // Validate the Birthdate
            try
            {
                int month = Convert.ToInt32(TextBox_Birthdate_Month.Text);
                int day = Convert.ToInt32(TextBox_Birthdate_Day.Text);
                int year = Convert.ToInt32(TextBox_Birthdate_Year.Text);

                if(!IsValidDate(month, day, year))
                {
                    MessageBox.Show("Please enter a valid Birthdate!\nReason: Impossible Date");
                    return;
                }

                // Make sure the Date is in the Past
                DateTime birthdate = new DateTime(year, month, day);

                if(birthdate > DateTime.Today)
                {
                    MessageBox.Show("Please enter a valid Birthdate!\nReason: Future Date");
                    return;
                }

                // Make sure the Year is Reasonable
                if(year < 1900)
                {
                    MessageBox.Show("Please enter a valid Birthdate!\nReason: Dates older than the 1900s are not allowed");
                    return;
                }
            }
            catch(FormatException)
            {
                // The User did not fill at least one
                // of the Birthdate fields. This is fine,
                // so the program won't do anything about it
            }

            // Initialize the SQL String
            String sql = "";

            // Determine whether or not the Contact is being Created for Modified
            if(Modifying)
            {
                sql = "UPDATE Contact SET ";

                // Check if the First Name Exists
                if(!TextBox_FirstName.Text.Equals(""))
                    sql += "first_name = '" + TextBox_FirstName.Text + "'";
                else
                {
                    MessageBox.Show("Contacts must have a First Name!");
                    return;
                }

                // Check if the Middle Name Exists
                if(!TextBox_MiddleName.Text.Equals(""))
                    sql += ", middle_name = '" + TextBox_MiddleName.Text + "'";
                else
                    sql += ", middle_name = NULL";

                // Check if the Last Name Exists
                if(!TextBox_LastName.Text.Equals(""))
                    sql += ", last_name = '" + TextBox_LastName.Text + "'";
                else
                    sql += ", last_name = NULL";

                // Check if the Gender Exists
                if(!ComboBox_Gender.SelectedText.Equals(""))
                    sql += ", gender = '" + ComboBox_Gender.SelectedText[0] + "'";
                else
                    sql += ", gender = NULL";

                // Check if the Birthdate Fields are all Filled or all Empty
                if(TextBox_Birthdate_Day.Text.Equals("") == TextBox_Birthdate_Month.Text.Equals("") &&
                   TextBox_Birthdate_Month.Text.Equals("") == TextBox_Birthdate_Year.Text.Equals(""))
                {
                    // Check if the Birthdate Exists
                    if(!TextBox_Birthdate_Day.Text.Equals(""))
                        sql += ", birthdate = '" + TextBox_Birthdate_Year.Text + "-" + TextBox_Birthdate_Month.Text + "-" + TextBox_Birthdate_Day.Text + "'";
                    else
                        sql += ", birthdate = NULL";
                }
                else // User partially filled the Birthdate Field
                {
                    MessageBox.Show("Please complete the Birthdate Field.");
                    return;
                }

                // Check if the Alias Exists
                if(!TextBox_Alias.Equals(""))
                    sql += ", alias = '" + TextBox_Alias.Text + "'";
                else
                    sql += ", alias = NULL";

                // Add the WHERE Clause
                sql += " WHERE id = " + ContactID;
            }
            else
            {
                sql = "INSERT INTO Contact " +
                      "(first_name, middle_name, last_name, gender, birthdate, alias) VALUES (";

                // Check if the First Name Exists
                if(!TextBox_FirstName.Text.Equals(""))
                    sql += "'" + TextBox_FirstName.Text + "'";
                else
                {
                    MessageBox.Show("Contacts must have a First Name!");
                    return;
                }

                // Check if the Middle Name Exists
                if(!TextBox_MiddleName.Text.Equals(""))
                    sql += ", '" + TextBox_MiddleName.Text + "'";
                else
                    sql += ", NULL";

                // Check if the Last Name Exists
                if(!TextBox_LastName.Text.Equals(""))
                    sql += ", '" + TextBox_LastName.Text + "'";
                else
                    sql += ", NULL";

                // Check if the Gender Exists
                if(!ComboBox_Gender.SelectedText.Equals(""))
                    sql += ", '" + ComboBox_Gender.SelectedItem.ToString()[0] + "'";
                else
                    sql += ", NULL";

                // Check if the Birthdate Fields are all Filled or all Empty
                if(TextBox_Birthdate_Day.Text.Equals("") == TextBox_Birthdate_Month.Text.Equals("") &&
                   TextBox_Birthdate_Month.Text.Equals("") == TextBox_Birthdate_Year.Text.Equals(""))
                {
                    // Check if the Birthdate Exists
                    if(!TextBox_Birthdate_Day.Text.Equals(""))
                        sql += ", '" + TextBox_Birthdate_Year.Text + "-" + TextBox_Birthdate_Month.Text + "-" + TextBox_Birthdate_Day.Text + "'";
                    else
                        sql += ", NULL";
                }
                else
                {
                    MessageBox.Show("Please complete the Birthdate Field.");
                    return;
                }

                // Check if the Alias Exists
                if(!TextBox_Alias.Text.Equals(""))
                    sql += ", '" + TextBox_Alias.Text + "')";
                else
                    sql += ", NULL)";
            }

            SqlDataAdapter adapter = new SqlDataAdapter(sql, Connection);
            DataSet data = new DataSet();

            // Execute the SQL Statement
            try
            {
                adapter.Fill(data);
                this.Close();
            }
            catch(SqlException ex)
            {
                MessageBox.Show("Invalid SQL Statement:\r\n" + ex);
            }
        }

        // Triggered when the "Cancel" Button is Pressed
        private void Button_Cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        // Triggered when the Form is Created
        private void Form_CreateContact_Load(object sender, EventArgs e)
        {
            ComboBox_Gender.SelectedText = "Unspecified";
        }

        //* Validation Methods *//
        public bool IsValidDate(int month, int day, int year)
        {
            // Make sure all values are Positive
            if(month <= 0)
                return false;
            else if(day <= 0)
                return false;
            else if(year <= 0)
                return false;

            // Check the Day Limit per Month
            switch(month)
            {
                case 4: // April
                case 6: // June
                case 9: // September
                case 11: // November
                    if(day > 30)
                        return false;
                    break;

                case 1: // January
                case 3: // March
                case 5: // May
                case 7: // July
                case 8: // August
                case 10: // October
                case 12: // December
                    if(day > 31)
                        return false;
                    break;

                case 2: // February
                    if(day > 29)
                        return false;
                    else if(day == 29)
                    {
                        // Check for Leap Years
                        if(year % 4 != 0)
                            return false;
                        else if(year % 100 == 0 && year % 400 != 0) // Check for Skips
                            return false;
                    }
                    break;
            }

            return true;
        }

        //* Mutator Methods *//
        // Sets the First Name of the Contact
        public void SetFirstName(string firstname)
        {
            TextBox_FirstName.Text = firstname;
        }

        // Sets the Middle Name of the Contact
        public void SetMiddleName(string middlename)
        {
            TextBox_MiddleName.Text = middlename;
        }

        // Sets the Last Name of the Contact
        public void SetLastName(string lastname)
        {
            TextBox_LastName.Text = lastname;
        }

        // Sets the Gender of the Contact
        public void SetGender(string gender)
        {
            if(gender.Length > 0)
            {
                // Use the first Gender Character
                char g = gender[0];

                // Attempt to match the Gender
                for(int i = 0; i < ComboBox_Gender.Items.Count; i++)
                    if(g == ComboBox_Gender.Items[i].ToString()[0])
                        ComboBox_Gender.SelectedIndex = i;
            }
        }

        // Sets the Birthdate of the Contact
        public void SetBirthDate(String birthdate)
        {
            char[] delimiters = {'/', ' '};
            string[] components = birthdate.Split(delimiters);

            try
            {
                TextBox_Birthdate_Month.Text = components[0];
                TextBox_Birthdate_Day.Text = components[1];
                TextBox_Birthdate_Year.Text = components[2];
            }
            catch(IndexOutOfRangeException)
            {
                // Somehow the String was improperly formatted
                // Since it wasn't properly formatted, it shouldn't be
                // loaded. The User should either re-enter the correct
                // Birthdate, or leave it blank.
            }
        }

        // Sets the Alias of the Contact
        public void SetAlias(string alias)
        {
            TextBox_Alias.Text = alias;
        }
    }
}
