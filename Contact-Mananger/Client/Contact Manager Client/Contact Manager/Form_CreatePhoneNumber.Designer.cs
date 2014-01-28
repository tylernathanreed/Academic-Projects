namespace Contact_Manager_Client
{
    partial class Form_CreatePhoneNumber
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
            this.Label_PhoneNumber = new System.Windows.Forms.Label();
            this.TextBox_PhoneNumber = new System.Windows.Forms.TextBox();
            this.Label_Type = new System.Windows.Forms.Label();
            this.ComboBox_Type = new System.Windows.Forms.ComboBox();
            this.TextBox_Type = new System.Windows.Forms.TextBox();
            this.CheckBox_International = new System.Windows.Forms.CheckBox();
            this.TextBox_Extension = new System.Windows.Forms.TextBox();
            this.TextBox_International = new System.Windows.Forms.TextBox();
            this.CheckBox_Extension = new System.Windows.Forms.CheckBox();
            this.Label_Delimit = new System.Windows.Forms.Label();
            this.Label_DataGrid = new System.Windows.Forms.Label();
            this.DataGrid_Contacts = new System.Windows.Forms.DataGridView();
            this.Button_Save = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).BeginInit();
            this.SuspendLayout();
            // 
            // Label_PhoneNumber
            // 
            this.Label_PhoneNumber.AutoSize = true;
            this.Label_PhoneNumber.Location = new System.Drawing.Point(12, 15);
            this.Label_PhoneNumber.Name = "Label_PhoneNumber";
            this.Label_PhoneNumber.Size = new System.Drawing.Size(81, 13);
            this.Label_PhoneNumber.TabIndex = 0;
            this.Label_PhoneNumber.Text = "Phone Number:";
            // 
            // TextBox_PhoneNumber
            // 
            this.TextBox_PhoneNumber.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_PhoneNumber.Location = new System.Drawing.Point(99, 12);
            this.TextBox_PhoneNumber.Name = "TextBox_PhoneNumber";
            this.TextBox_PhoneNumber.Size = new System.Drawing.Size(100, 20);
            this.TextBox_PhoneNumber.TabIndex = 1;
            // 
            // Label_Type
            // 
            this.Label_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Type.AutoSize = true;
            this.Label_Type.Location = new System.Drawing.Point(205, 15);
            this.Label_Type.Name = "Label_Type";
            this.Label_Type.Size = new System.Drawing.Size(34, 13);
            this.Label_Type.TabIndex = 2;
            this.Label_Type.Text = "Type:";
            // 
            // ComboBox_Type
            // 
            this.ComboBox_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ComboBox_Type.FormattingEnabled = true;
            this.ComboBox_Type.Location = new System.Drawing.Point(245, 12);
            this.ComboBox_Type.Name = "ComboBox_Type";
            this.ComboBox_Type.Size = new System.Drawing.Size(85, 21);
            this.ComboBox_Type.TabIndex = 3;
            // 
            // TextBox_Type
            // 
            this.TextBox_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Type.Location = new System.Drawing.Point(336, 12);
            this.TextBox_Type.Name = "TextBox_Type";
            this.TextBox_Type.ReadOnly = true;
            this.TextBox_Type.Size = new System.Drawing.Size(100, 20);
            this.TextBox_Type.TabIndex = 4;
            // 
            // CheckBox_International
            // 
            this.CheckBox_International.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.CheckBox_International.AutoSize = true;
            this.CheckBox_International.Location = new System.Drawing.Point(246, 40);
            this.CheckBox_International.Name = "CheckBox_International";
            this.CheckBox_International.Size = new System.Drawing.Size(84, 17);
            this.CheckBox_International.TabIndex = 7;
            this.CheckBox_International.Text = "International";
            this.CheckBox_International.UseVisualStyleBackColor = true;
            // 
            // TextBox_Extension
            // 
            this.TextBox_Extension.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Extension.Location = new System.Drawing.Point(99, 38);
            this.TextBox_Extension.Name = "TextBox_Extension";
            this.TextBox_Extension.ReadOnly = true;
            this.TextBox_Extension.Size = new System.Drawing.Size(100, 20);
            this.TextBox_Extension.TabIndex = 6;
            // 
            // TextBox_International
            // 
            this.TextBox_International.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_International.Location = new System.Drawing.Point(336, 38);
            this.TextBox_International.Name = "TextBox_International";
            this.TextBox_International.ReadOnly = true;
            this.TextBox_International.Size = new System.Drawing.Size(100, 20);
            this.TextBox_International.TabIndex = 8;
            // 
            // CheckBox_Extension
            // 
            this.CheckBox_Extension.AutoSize = true;
            this.CheckBox_Extension.Location = new System.Drawing.Point(21, 40);
            this.CheckBox_Extension.Name = "CheckBox_Extension";
            this.CheckBox_Extension.Size = new System.Drawing.Size(72, 17);
            this.CheckBox_Extension.TabIndex = 5;
            this.CheckBox_Extension.Text = "Extension";
            this.CheckBox_Extension.UseVisualStyleBackColor = true;
            // 
            // Label_Delimit
            // 
            this.Label_Delimit.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Delimit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_Delimit.Location = new System.Drawing.Point(12, 70);
            this.Label_Delimit.Name = "Label_Delimit";
            this.Label_Delimit.Size = new System.Drawing.Size(424, 2);
            this.Label_Delimit.TabIndex = 9;
            // 
            // Label_DataGrid
            // 
            this.Label_DataGrid.AutoSize = true;
            this.Label_DataGrid.Location = new System.Drawing.Point(15, 76);
            this.Label_DataGrid.Name = "Label_DataGrid";
            this.Label_DataGrid.Size = new System.Drawing.Size(133, 13);
            this.Label_DataGrid.TabIndex = 10;
            this.Label_DataGrid.Text = "Contacts with this Number:";
            // 
            // DataGrid_Contacts
            // 
            this.DataGrid_Contacts.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Contacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contacts.Location = new System.Drawing.Point(12, 92);
            this.DataGrid_Contacts.Name = "DataGrid_Contacts";
            this.DataGrid_Contacts.Size = new System.Drawing.Size(424, 148);
            this.DataGrid_Contacts.TabIndex = 11;
            // 
            // Button_Save
            // 
            this.Button_Save.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Save.Location = new System.Drawing.Point(143, 246);
            this.Button_Save.Name = "Button_Save";
            this.Button_Save.Size = new System.Drawing.Size(75, 23);
            this.Button_Save.TabIndex = 12;
            this.Button_Save.Text = "&Save";
            this.Button_Save.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Cancel.Location = new System.Drawing.Point(230, 246);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 13;
            this.Button_Cancel.Text = "&Cancel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // Form_CreatePhoneNumber
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(448, 279);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Save);
            this.Controls.Add(this.DataGrid_Contacts);
            this.Controls.Add(this.Label_DataGrid);
            this.Controls.Add(this.Label_Delimit);
            this.Controls.Add(this.TextBox_International);
            this.Controls.Add(this.CheckBox_Extension);
            this.Controls.Add(this.TextBox_Extension);
            this.Controls.Add(this.CheckBox_International);
            this.Controls.Add(this.TextBox_Type);
            this.Controls.Add(this.ComboBox_Type);
            this.Controls.Add(this.Label_Type);
            this.Controls.Add(this.TextBox_PhoneNumber);
            this.Controls.Add(this.Label_PhoneNumber);
            this.Name = "Form_CreatePhoneNumber";
            this.Text = "New Phone Number";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label_PhoneNumber;
        private System.Windows.Forms.TextBox TextBox_PhoneNumber;
        private System.Windows.Forms.Label Label_Type;
        private System.Windows.Forms.ComboBox ComboBox_Type;
        private System.Windows.Forms.TextBox TextBox_Type;
        private System.Windows.Forms.CheckBox CheckBox_International;
        private System.Windows.Forms.TextBox TextBox_Extension;
        private System.Windows.Forms.TextBox TextBox_International;
        private System.Windows.Forms.CheckBox CheckBox_Extension;
        private System.Windows.Forms.Label Label_Delimit;
        private System.Windows.Forms.Label Label_DataGrid;
        private System.Windows.Forms.DataGridView DataGrid_Contacts;
        private System.Windows.Forms.Button Button_Save;
        private System.Windows.Forms.Button Button_Cancel;
    }
}