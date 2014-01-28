namespace Contact_Manager_Client
{
    partial class Form_CreateAddress
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
            this.Label_Address = new System.Windows.Forms.Label();
            this.DataGrid_Address = new System.Windows.Forms.DataGridView();
            this.Button_Add = new System.Windows.Forms.Button();
            this.Button_Edit = new System.Windows.Forms.Button();
            this.Button_Remove = new System.Windows.Forms.Button();
            this.Label_Delimit = new System.Windows.Forms.Label();
            this.Label_DataGrid = new System.Windows.Forms.Label();
            this.DataGrid_Contacts = new System.Windows.Forms.DataGridView();
            this.Button_Save = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Address)).BeginInit();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).BeginInit();
            this.SuspendLayout();
            // 
            // Label_Address
            // 
            this.Label_Address.AutoSize = true;
            this.Label_Address.Location = new System.Drawing.Point(12, 9);
            this.Label_Address.Name = "Label_Address";
            this.Label_Address.Size = new System.Drawing.Size(48, 13);
            this.Label_Address.TabIndex = 0;
            this.Label_Address.Text = "Address:";
            // 
            // DataGrid_Address
            // 
            this.DataGrid_Address.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Address.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Address.Location = new System.Drawing.Point(15, 25);
            this.DataGrid_Address.Name = "DataGrid_Address";
            this.DataGrid_Address.Size = new System.Drawing.Size(297, 97);
            this.DataGrid_Address.TabIndex = 1;
            // 
            // Button_Add
            // 
            this.Button_Add.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Add.Location = new System.Drawing.Point(318, 25);
            this.Button_Add.Name = "Button_Add";
            this.Button_Add.Size = new System.Drawing.Size(75, 23);
            this.Button_Add.TabIndex = 2;
            this.Button_Add.Text = "&Add";
            this.Button_Add.UseVisualStyleBackColor = true;
            // 
            // Button_Edit
            // 
            this.Button_Edit.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Edit.Location = new System.Drawing.Point(318, 62);
            this.Button_Edit.Name = "Button_Edit";
            this.Button_Edit.Size = new System.Drawing.Size(75, 23);
            this.Button_Edit.TabIndex = 3;
            this.Button_Edit.Text = "&Edit";
            this.Button_Edit.UseVisualStyleBackColor = true;
            // 
            // Button_Remove
            // 
            this.Button_Remove.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Remove.Location = new System.Drawing.Point(318, 99);
            this.Button_Remove.Name = "Button_Remove";
            this.Button_Remove.Size = new System.Drawing.Size(75, 23);
            this.Button_Remove.TabIndex = 4;
            this.Button_Remove.Text = "&Remove";
            this.Button_Remove.UseVisualStyleBackColor = true;
            // 
            // Label_Delimit
            // 
            this.Label_Delimit.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Delimit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_Delimit.Location = new System.Drawing.Point(15, 130);
            this.Label_Delimit.Name = "Label_Delimit";
            this.Label_Delimit.Size = new System.Drawing.Size(378, 2);
            this.Label_Delimit.TabIndex = 5;
            // 
            // Label_DataGrid
            // 
            this.Label_DataGrid.AutoSize = true;
            this.Label_DataGrid.Location = new System.Drawing.Point(12, 136);
            this.Label_DataGrid.Name = "Label_DataGrid";
            this.Label_DataGrid.Size = new System.Drawing.Size(134, 13);
            this.Label_DataGrid.TabIndex = 6;
            this.Label_DataGrid.Text = "Contacts with this Address:";
            // 
            // DataGrid_Contacts
            // 
            this.DataGrid_Contacts.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Contacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contacts.Location = new System.Drawing.Point(15, 152);
            this.DataGrid_Contacts.Name = "DataGrid_Contacts";
            this.DataGrid_Contacts.Size = new System.Drawing.Size(378, 134);
            this.DataGrid_Contacts.TabIndex = 7;
            // 
            // Button_Save
            // 
            this.Button_Save.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Save.Location = new System.Drawing.Point(108, 292);
            this.Button_Save.Name = "Button_Save";
            this.Button_Save.Size = new System.Drawing.Size(75, 23);
            this.Button_Save.TabIndex = 8;
            this.Button_Save.Text = "&Save";
            this.Button_Save.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Cancel.Location = new System.Drawing.Point(221, 292);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 9;
            this.Button_Cancel.Text = "&Cancel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // Form_CreateAddress
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(405, 327);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Save);
            this.Controls.Add(this.DataGrid_Contacts);
            this.Controls.Add(this.Label_DataGrid);
            this.Controls.Add(this.Label_Delimit);
            this.Controls.Add(this.Button_Remove);
            this.Controls.Add(this.Button_Edit);
            this.Controls.Add(this.Button_Add);
            this.Controls.Add(this.DataGrid_Address);
            this.Controls.Add(this.Label_Address);
            this.Name = "Form_CreateAddress";
            this.Text = "New Address";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Address)).EndInit();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label_Address;
        private System.Windows.Forms.DataGridView DataGrid_Address;
        private System.Windows.Forms.Button Button_Add;
        private System.Windows.Forms.Button Button_Edit;
        private System.Windows.Forms.Button Button_Remove;
        private System.Windows.Forms.Label Label_Delimit;
        private System.Windows.Forms.Label Label_DataGrid;
        private System.Windows.Forms.DataGridView DataGrid_Contacts;
        private System.Windows.Forms.Button Button_Save;
        private System.Windows.Forms.Button Button_Cancel;

    }
}