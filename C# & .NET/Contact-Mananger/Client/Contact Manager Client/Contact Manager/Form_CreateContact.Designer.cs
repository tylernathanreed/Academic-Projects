namespace Contact_Manager_Client
{
    partial class Form_CreateContact
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if(disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Button_Save = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            this.DataGrid_Contact = new System.Windows.Forms.DataGridView();
            this.Label_DataGrid = new System.Windows.Forms.Label();
            this.RadioButton_PhoneNumbers = new System.Windows.Forms.RadioButton();
            this.RadioButton_Addresses = new System.Windows.Forms.RadioButton();
            this.RadioButton_Groups = new System.Windows.Forms.RadioButton();
            this.Label_FirstName = new System.Windows.Forms.Label();
            this.TextBox_FirstName = new System.Windows.Forms.TextBox();
            this.Form_MiddleName = new System.Windows.Forms.Label();
            this.TextBox_MiddleName = new System.Windows.Forms.TextBox();
            this.Label_LastName = new System.Windows.Forms.Label();
            this.TextBox_LastName = new System.Windows.Forms.TextBox();
            this.Label_Gender = new System.Windows.Forms.Label();
            this.ComboBox_Gender = new System.Windows.Forms.ComboBox();
            this.Label_Birthdate_Year = new System.Windows.Forms.Label();
            this.Label_Birthdate = new System.Windows.Forms.Label();
            this.TextBox_Birthdate_Year = new System.Windows.Forms.TextBox();
            this.TextBox_Birthdate_Month = new System.Windows.Forms.TextBox();
            this.Label_Delimit9 = new System.Windows.Forms.Label();
            this.Label_Delimit8 = new System.Windows.Forms.Label();
            this.Label_Birthdate_Day = new System.Windows.Forms.Label();
            this.TextBox_Birthdate_Day = new System.Windows.Forms.TextBox();
            this.Label_Birthdate_Month = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Button_Create = new System.Windows.Forms.Button();
            this.Button_Edit = new System.Windows.Forms.Button();
            this.Button_Delete = new System.Windows.Forms.Button();
            this.TextBox_Alias = new System.Windows.Forms.TextBox();
            this.Label_Alias = new System.Windows.Forms.Label();
            this.Button_Add = new System.Windows.Forms.Button();
            this.RadioButton_Emails = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contact)).BeginInit();
            this.SuspendLayout();
            // 
            // Button_Save
            // 
            this.Button_Save.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Save.Location = new System.Drawing.Point(437, 206);
            this.Button_Save.Name = "Button_Save";
            this.Button_Save.Size = new System.Drawing.Size(100, 23);
            this.Button_Save.TabIndex = 30;
            this.Button_Save.Text = "&Save";
            this.Button_Save.UseVisualStyleBackColor = true;
            this.Button_Save.Click += new System.EventHandler(this.Button_Save_Click);
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Cancel.Location = new System.Drawing.Point(437, 235);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(100, 23);
            this.Button_Cancel.TabIndex = 31;
            this.Button_Cancel.Text = "Ca&ncel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            this.Button_Cancel.Click += new System.EventHandler(this.Button_Cancel_Click);
            // 
            // DataGrid_Contact
            // 
            this.DataGrid_Contact.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.DataGrid_Contact.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contact.Location = new System.Drawing.Point(12, 98);
            this.DataGrid_Contact.Name = "DataGrid_Contact";
            this.DataGrid_Contact.Size = new System.Drawing.Size(407, 160);
            this.DataGrid_Contact.TabIndex = 29;
            // 
            // Label_DataGrid
            // 
            this.Label_DataGrid.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.Label_DataGrid.AutoSize = true;
            this.Label_DataGrid.Location = new System.Drawing.Point(12, 82);
            this.Label_DataGrid.Name = "Label_DataGrid";
            this.Label_DataGrid.Size = new System.Drawing.Size(86, 13);
            this.Label_DataGrid.TabIndex = 28;
            this.Label_DataGrid.Text = "Phone Numbers:";
            // 
            // RadioButton_PhoneNumbers
            // 
            this.RadioButton_PhoneNumbers.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.RadioButton_PhoneNumbers.AutoSize = true;
            this.RadioButton_PhoneNumbers.Checked = true;
            this.RadioButton_PhoneNumbers.Location = new System.Drawing.Point(434, 98);
            this.RadioButton_PhoneNumbers.Name = "RadioButton_PhoneNumbers";
            this.RadioButton_PhoneNumbers.Size = new System.Drawing.Size(101, 17);
            this.RadioButton_PhoneNumbers.TabIndex = 24;
            this.RadioButton_PhoneNumbers.TabStop = true;
            this.RadioButton_PhoneNumbers.Text = "&Phone Numbers";
            this.RadioButton_PhoneNumbers.UseVisualStyleBackColor = true;
            // 
            // RadioButton_Addresses
            // 
            this.RadioButton_Addresses.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.RadioButton_Addresses.AutoSize = true;
            this.RadioButton_Addresses.Location = new System.Drawing.Point(434, 121);
            this.RadioButton_Addresses.Name = "RadioButton_Addresses";
            this.RadioButton_Addresses.Size = new System.Drawing.Size(74, 17);
            this.RadioButton_Addresses.TabIndex = 25;
            this.RadioButton_Addresses.Text = "A&ddresses";
            this.RadioButton_Addresses.UseVisualStyleBackColor = true;
            // 
            // RadioButton_Groups
            // 
            this.RadioButton_Groups.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.RadioButton_Groups.AutoSize = true;
            this.RadioButton_Groups.Location = new System.Drawing.Point(434, 167);
            this.RadioButton_Groups.Name = "RadioButton_Groups";
            this.RadioButton_Groups.Size = new System.Drawing.Size(59, 17);
            this.RadioButton_Groups.TabIndex = 27;
            this.RadioButton_Groups.Text = "&Groups";
            this.RadioButton_Groups.UseVisualStyleBackColor = true;
            // 
            // Label_FirstName
            // 
            this.Label_FirstName.AutoSize = true;
            this.Label_FirstName.Location = new System.Drawing.Point(12, 9);
            this.Label_FirstName.Name = "Label_FirstName";
            this.Label_FirstName.Size = new System.Drawing.Size(60, 13);
            this.Label_FirstName.TabIndex = 1;
            this.Label_FirstName.Text = "First Name:";
            // 
            // TextBox_FirstName
            // 
            this.TextBox_FirstName.Location = new System.Drawing.Point(78, 6);
            this.TextBox_FirstName.MaxLength = 32;
            this.TextBox_FirstName.Name = "TextBox_FirstName";
            this.TextBox_FirstName.Size = new System.Drawing.Size(100, 20);
            this.TextBox_FirstName.TabIndex = 2;
            // 
            // Form_MiddleName
            // 
            this.Form_MiddleName.AutoSize = true;
            this.Form_MiddleName.Location = new System.Drawing.Point(184, 9);
            this.Form_MiddleName.Name = "Form_MiddleName";
            this.Form_MiddleName.Size = new System.Drawing.Size(72, 13);
            this.Form_MiddleName.TabIndex = 3;
            this.Form_MiddleName.Text = "Middle Name:";
            // 
            // TextBox_MiddleName
            // 
            this.TextBox_MiddleName.Location = new System.Drawing.Point(262, 6);
            this.TextBox_MiddleName.MaxLength = 32;
            this.TextBox_MiddleName.Name = "TextBox_MiddleName";
            this.TextBox_MiddleName.Size = new System.Drawing.Size(100, 20);
            this.TextBox_MiddleName.TabIndex = 4;
            // 
            // Label_LastName
            // 
            this.Label_LastName.AutoSize = true;
            this.Label_LastName.Location = new System.Drawing.Point(368, 9);
            this.Label_LastName.Name = "Label_LastName";
            this.Label_LastName.Size = new System.Drawing.Size(61, 13);
            this.Label_LastName.TabIndex = 5;
            this.Label_LastName.Text = "Last Name:";
            // 
            // TextBox_LastName
            // 
            this.TextBox_LastName.Location = new System.Drawing.Point(435, 6);
            this.TextBox_LastName.MaxLength = 32;
            this.TextBox_LastName.Name = "TextBox_LastName";
            this.TextBox_LastName.Size = new System.Drawing.Size(100, 20);
            this.TextBox_LastName.TabIndex = 6;
            // 
            // Label_Gender
            // 
            this.Label_Gender.AutoSize = true;
            this.Label_Gender.Location = new System.Drawing.Point(27, 35);
            this.Label_Gender.Name = "Label_Gender";
            this.Label_Gender.Size = new System.Drawing.Size(45, 13);
            this.Label_Gender.TabIndex = 7;
            this.Label_Gender.Text = "Gender:";
            // 
            // ComboBox_Gender
            // 
            this.ComboBox_Gender.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBox_Gender.FormattingEnabled = true;
            this.ComboBox_Gender.Items.AddRange(new object[] {
            "Male",
            "Female",
            "Unspecified",
            "Other"});
            this.ComboBox_Gender.Location = new System.Drawing.Point(78, 32);
            this.ComboBox_Gender.MaxDropDownItems = 4;
            this.ComboBox_Gender.Name = "ComboBox_Gender";
            this.ComboBox_Gender.Size = new System.Drawing.Size(100, 21);
            this.ComboBox_Gender.TabIndex = 8;
            // 
            // Label_Birthdate_Year
            // 
            this.Label_Birthdate_Year.AutoSize = true;
            this.Label_Birthdate_Year.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.Label_Birthdate_Year.Location = new System.Drawing.Point(334, 55);
            this.Label_Birthdate_Year.Name = "Label_Birthdate_Year";
            this.Label_Birthdate_Year.Size = new System.Drawing.Size(25, 12);
            this.Label_Birthdate_Year.TabIndex = 16;
            this.Label_Birthdate_Year.Text = "YYYY";
            // 
            // Label_Birthdate
            // 
            this.Label_Birthdate.AutoSize = true;
            this.Label_Birthdate.Location = new System.Drawing.Point(184, 35);
            this.Label_Birthdate.Name = "Label_Birthdate";
            this.Label_Birthdate.Size = new System.Drawing.Size(52, 13);
            this.Label_Birthdate.TabIndex = 9;
            this.Label_Birthdate.Text = "Birthdate:";
            // 
            // TextBox_Birthdate_Year
            // 
            this.TextBox_Birthdate_Year.Location = new System.Drawing.Point(324, 32);
            this.TextBox_Birthdate_Year.MaxLength = 4;
            this.TextBox_Birthdate_Year.Name = "TextBox_Birthdate_Year";
            this.TextBox_Birthdate_Year.Size = new System.Drawing.Size(46, 20);
            this.TextBox_Birthdate_Year.TabIndex = 17;
            // 
            // TextBox_Birthdate_Month
            // 
            this.TextBox_Birthdate_Month.Location = new System.Drawing.Point(242, 32);
            this.TextBox_Birthdate_Month.MaxLength = 2;
            this.TextBox_Birthdate_Month.Name = "TextBox_Birthdate_Month";
            this.TextBox_Birthdate_Month.Size = new System.Drawing.Size(29, 20);
            this.TextBox_Birthdate_Month.TabIndex = 11;
            // 
            // Label_Delimit9
            // 
            this.Label_Delimit9.AutoSize = true;
            this.Label_Delimit9.Location = new System.Drawing.Point(313, 35);
            this.Label_Delimit9.Name = "Label_Delimit9";
            this.Label_Delimit9.Size = new System.Drawing.Size(12, 13);
            this.Label_Delimit9.TabIndex = 15;
            this.Label_Delimit9.Text = "/";
            // 
            // Label_Delimit8
            // 
            this.Label_Delimit8.AutoSize = true;
            this.Label_Delimit8.Location = new System.Drawing.Point(271, 35);
            this.Label_Delimit8.Name = "Label_Delimit8";
            this.Label_Delimit8.Size = new System.Drawing.Size(12, 13);
            this.Label_Delimit8.TabIndex = 12;
            this.Label_Delimit8.Text = "/";
            // 
            // Label_Birthdate_Day
            // 
            this.Label_Birthdate_Day.AutoSize = true;
            this.Label_Birthdate_Day.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.Label_Birthdate_Day.Location = new System.Drawing.Point(289, 55);
            this.Label_Birthdate_Day.Name = "Label_Birthdate_Day";
            this.Label_Birthdate_Day.Size = new System.Drawing.Size(19, 12);
            this.Label_Birthdate_Day.TabIndex = 13;
            this.Label_Birthdate_Day.Text = "DD";
            // 
            // TextBox_Birthdate_Day
            // 
            this.TextBox_Birthdate_Day.Location = new System.Drawing.Point(283, 32);
            this.TextBox_Birthdate_Day.MaxLength = 2;
            this.TextBox_Birthdate_Day.Name = "TextBox_Birthdate_Day";
            this.TextBox_Birthdate_Day.Size = new System.Drawing.Size(29, 20);
            this.TextBox_Birthdate_Day.TabIndex = 14;
            // 
            // Label_Birthdate_Month
            // 
            this.Label_Birthdate_Month.AutoSize = true;
            this.Label_Birthdate_Month.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.Label_Birthdate_Month.Location = new System.Drawing.Point(244, 55);
            this.Label_Birthdate_Month.Name = "Label_Birthdate_Month";
            this.Label_Birthdate_Month.Size = new System.Drawing.Size(23, 12);
            this.Label_Birthdate_Month.TabIndex = 10;
            this.Label_Birthdate_Month.Text = "MM";
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label1.Location = new System.Drawing.Point(12, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(525, 2);
            this.label1.TabIndex = 84;
            // 
            // Button_Create
            // 
            this.Button_Create.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Create.Location = new System.Drawing.Point(127, 264);
            this.Button_Create.Name = "Button_Create";
            this.Button_Create.Size = new System.Drawing.Size(75, 23);
            this.Button_Create.TabIndex = 21;
            this.Button_Create.Text = "&Create";
            this.Button_Create.UseVisualStyleBackColor = true;
            // 
            // Button_Edit
            // 
            this.Button_Edit.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Edit.Location = new System.Drawing.Point(229, 264);
            this.Button_Edit.Name = "Button_Edit";
            this.Button_Edit.Size = new System.Drawing.Size(75, 23);
            this.Button_Edit.TabIndex = 22;
            this.Button_Edit.Text = "&Edit";
            this.Button_Edit.UseVisualStyleBackColor = true;
            // 
            // Button_Delete
            // 
            this.Button_Delete.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Delete.Location = new System.Drawing.Point(331, 264);
            this.Button_Delete.Name = "Button_Delete";
            this.Button_Delete.Size = new System.Drawing.Size(75, 23);
            this.Button_Delete.TabIndex = 23;
            this.Button_Delete.Text = "&Delete";
            this.Button_Delete.UseVisualStyleBackColor = true;
            // 
            // TextBox_Alias
            // 
            this.TextBox_Alias.Location = new System.Drawing.Point(434, 32);
            this.TextBox_Alias.MaxLength = 32;
            this.TextBox_Alias.Name = "TextBox_Alias";
            this.TextBox_Alias.Size = new System.Drawing.Size(100, 20);
            this.TextBox_Alias.TabIndex = 19;
            // 
            // Label_Alias
            // 
            this.Label_Alias.AutoSize = true;
            this.Label_Alias.Location = new System.Drawing.Point(396, 35);
            this.Label_Alias.Name = "Label_Alias";
            this.Label_Alias.Size = new System.Drawing.Size(32, 13);
            this.Label_Alias.TabIndex = 18;
            this.Label_Alias.Text = "Alias:";
            // 
            // Button_Add
            // 
            this.Button_Add.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Add.Location = new System.Drawing.Point(25, 264);
            this.Button_Add.Name = "Button_Add";
            this.Button_Add.Size = new System.Drawing.Size(75, 23);
            this.Button_Add.TabIndex = 20;
            this.Button_Add.Text = "&Add";
            this.Button_Add.UseVisualStyleBackColor = true;
            // 
            // RadioButton_Emails
            // 
            this.RadioButton_Emails.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.RadioButton_Emails.AutoSize = true;
            this.RadioButton_Emails.Location = new System.Drawing.Point(434, 144);
            this.RadioButton_Emails.Name = "RadioButton_Emails";
            this.RadioButton_Emails.Size = new System.Drawing.Size(102, 17);
            this.RadioButton_Emails.TabIndex = 26;
            this.RadioButton_Emails.Text = "E&mail Addresses";
            this.RadioButton_Emails.UseVisualStyleBackColor = true;
            // 
            // Form_CreateContact
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(549, 299);
            this.Controls.Add(this.RadioButton_Emails);
            this.Controls.Add(this.Button_Add);
            this.Controls.Add(this.Label_Alias);
            this.Controls.Add(this.TextBox_Alias);
            this.Controls.Add(this.Button_Delete);
            this.Controls.Add(this.Button_Edit);
            this.Controls.Add(this.Button_Create);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Label_FirstName);
            this.Controls.Add(this.TextBox_FirstName);
            this.Controls.Add(this.Form_MiddleName);
            this.Controls.Add(this.TextBox_MiddleName);
            this.Controls.Add(this.Label_LastName);
            this.Controls.Add(this.TextBox_LastName);
            this.Controls.Add(this.Label_Gender);
            this.Controls.Add(this.ComboBox_Gender);
            this.Controls.Add(this.Label_Birthdate_Year);
            this.Controls.Add(this.Label_Birthdate);
            this.Controls.Add(this.TextBox_Birthdate_Year);
            this.Controls.Add(this.TextBox_Birthdate_Month);
            this.Controls.Add(this.Label_Delimit9);
            this.Controls.Add(this.Label_Delimit8);
            this.Controls.Add(this.Label_Birthdate_Day);
            this.Controls.Add(this.TextBox_Birthdate_Day);
            this.Controls.Add(this.Label_Birthdate_Month);
            this.Controls.Add(this.RadioButton_Groups);
            this.Controls.Add(this.RadioButton_Addresses);
            this.Controls.Add(this.RadioButton_PhoneNumbers);
            this.Controls.Add(this.Label_DataGrid);
            this.Controls.Add(this.DataGrid_Contact);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Save);
            this.Name = "Form_CreateContact";
            this.Text = "New Contact";
            this.Load += new System.EventHandler(this.Form_CreateContact_Load);
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contact)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Button_Save;
        private System.Windows.Forms.Button Button_Cancel;
        private System.Windows.Forms.DataGridView DataGrid_Contact;
        private System.Windows.Forms.Label Label_DataGrid;
        private System.Windows.Forms.RadioButton RadioButton_PhoneNumbers;
        private System.Windows.Forms.RadioButton RadioButton_Addresses;
        private System.Windows.Forms.RadioButton RadioButton_Groups;
        private System.Windows.Forms.Label Label_FirstName;
        private System.Windows.Forms.TextBox TextBox_FirstName;
        private System.Windows.Forms.Label Form_MiddleName;
        private System.Windows.Forms.TextBox TextBox_MiddleName;
        private System.Windows.Forms.Label Label_LastName;
        private System.Windows.Forms.TextBox TextBox_LastName;
        private System.Windows.Forms.Label Label_Gender;
        private System.Windows.Forms.ComboBox ComboBox_Gender;
        private System.Windows.Forms.Label Label_Birthdate_Year;
        private System.Windows.Forms.Label Label_Birthdate;
        private System.Windows.Forms.TextBox TextBox_Birthdate_Year;
        private System.Windows.Forms.TextBox TextBox_Birthdate_Month;
        private System.Windows.Forms.Label Label_Delimit9;
        private System.Windows.Forms.Label Label_Delimit8;
        private System.Windows.Forms.Label Label_Birthdate_Day;
        private System.Windows.Forms.TextBox TextBox_Birthdate_Day;
        private System.Windows.Forms.Label Label_Birthdate_Month;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Button_Create;
        private System.Windows.Forms.Button Button_Edit;
        private System.Windows.Forms.Button Button_Delete;
        private System.Windows.Forms.TextBox TextBox_Alias;
        private System.Windows.Forms.Label Label_Alias;
        private System.Windows.Forms.Button Button_Add;
        private System.Windows.Forms.RadioButton RadioButton_Emails;

    }
}