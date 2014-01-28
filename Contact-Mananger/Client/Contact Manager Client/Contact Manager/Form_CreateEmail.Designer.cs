namespace Contact_Manager_Client
{
    partial class Form_CreateEmail
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
            this.DataGrid_Contacts = new System.Windows.Forms.DataGridView();
            this.Label_DataGrid = new System.Windows.Forms.Label();
            this.Label_Delimit = new System.Windows.Forms.Label();
            this.TextBox_Type = new System.Windows.Forms.TextBox();
            this.ComboBox_Type = new System.Windows.Forms.ComboBox();
            this.Label_Type = new System.Windows.Forms.Label();
            this.TextBox_PhoneNumber = new System.Windows.Forms.TextBox();
            this.Label_PhoneNumber = new System.Windows.Forms.Label();
            this.Button_Save = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).BeginInit();
            this.SuspendLayout();
            // 
            // DataGrid_Contacts
            // 
            this.DataGrid_Contacts.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Contacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contacts.Location = new System.Drawing.Point(12, 66);
            this.DataGrid_Contacts.Name = "DataGrid_Contacts";
            this.DataGrid_Contacts.Size = new System.Drawing.Size(441, 153);
            this.DataGrid_Contacts.TabIndex = 7;
            // 
            // Label_DataGrid
            // 
            this.Label_DataGrid.AutoSize = true;
            this.Label_DataGrid.Location = new System.Drawing.Point(12, 50);
            this.Label_DataGrid.Name = "Label_DataGrid";
            this.Label_DataGrid.Size = new System.Drawing.Size(121, 13);
            this.Label_DataGrid.TabIndex = 6;
            this.Label_DataGrid.Text = "Contacts with this Email:";
            // 
            // Label_Delimit
            // 
            this.Label_Delimit.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Delimit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_Delimit.Location = new System.Drawing.Point(12, 43);
            this.Label_Delimit.Name = "Label_Delimit";
            this.Label_Delimit.Size = new System.Drawing.Size(436, 2);
            this.Label_Delimit.TabIndex = 5;
            // 
            // TextBox_Type
            // 
            this.TextBox_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Type.Location = new System.Drawing.Point(348, 12);
            this.TextBox_Type.Name = "TextBox_Type";
            this.TextBox_Type.ReadOnly = true;
            this.TextBox_Type.Size = new System.Drawing.Size(100, 20);
            this.TextBox_Type.TabIndex = 4;
            // 
            // ComboBox_Type
            // 
            this.ComboBox_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ComboBox_Type.FormattingEnabled = true;
            this.ComboBox_Type.Location = new System.Drawing.Point(257, 12);
            this.ComboBox_Type.Name = "ComboBox_Type";
            this.ComboBox_Type.Size = new System.Drawing.Size(85, 21);
            this.ComboBox_Type.TabIndex = 3;
            // 
            // Label_Type
            // 
            this.Label_Type.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Type.AutoSize = true;
            this.Label_Type.Location = new System.Drawing.Point(217, 15);
            this.Label_Type.Name = "Label_Type";
            this.Label_Type.Size = new System.Drawing.Size(34, 13);
            this.Label_Type.TabIndex = 2;
            this.Label_Type.Text = "Type:";
            // 
            // TextBox_PhoneNumber
            // 
            this.TextBox_PhoneNumber.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_PhoneNumber.Location = new System.Drawing.Point(94, 12);
            this.TextBox_PhoneNumber.Name = "TextBox_PhoneNumber";
            this.TextBox_PhoneNumber.Size = new System.Drawing.Size(117, 20);
            this.TextBox_PhoneNumber.TabIndex = 1;
            // 
            // Label_PhoneNumber
            // 
            this.Label_PhoneNumber.AutoSize = true;
            this.Label_PhoneNumber.Location = new System.Drawing.Point(12, 15);
            this.Label_PhoneNumber.Name = "Label_PhoneNumber";
            this.Label_PhoneNumber.Size = new System.Drawing.Size(76, 13);
            this.Label_PhoneNumber.TabIndex = 0;
            this.Label_PhoneNumber.Text = "Email Address:";
            // 
            // Button_Save
            // 
            this.Button_Save.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Save.Location = new System.Drawing.Point(152, 225);
            this.Button_Save.Name = "Button_Save";
            this.Button_Save.Size = new System.Drawing.Size(75, 23);
            this.Button_Save.TabIndex = 8;
            this.Button_Save.Text = "&Save";
            this.Button_Save.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Cancel.Location = new System.Drawing.Point(233, 225);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 9;
            this.Button_Cancel.Text = "&Cancel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // Form_CreateEmail
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(460, 260);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Save);
            this.Controls.Add(this.DataGrid_Contacts);
            this.Controls.Add(this.Label_DataGrid);
            this.Controls.Add(this.Label_Delimit);
            this.Controls.Add(this.TextBox_Type);
            this.Controls.Add(this.ComboBox_Type);
            this.Controls.Add(this.Label_Type);
            this.Controls.Add(this.TextBox_PhoneNumber);
            this.Controls.Add(this.Label_PhoneNumber);
            this.Name = "Form_CreateEmail";
            this.Text = "New Email";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView DataGrid_Contacts;
        private System.Windows.Forms.Label Label_DataGrid;
        private System.Windows.Forms.Label Label_Delimit;
        private System.Windows.Forms.TextBox TextBox_Type;
        private System.Windows.Forms.ComboBox ComboBox_Type;
        private System.Windows.Forms.Label Label_Type;
        private System.Windows.Forms.TextBox TextBox_PhoneNumber;
        private System.Windows.Forms.Label Label_PhoneNumber;
        private System.Windows.Forms.Button Button_Save;
        private System.Windows.Forms.Button Button_Cancel;
    }
}