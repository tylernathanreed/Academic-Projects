namespace Contact_Manager_Client
{
    partial class Form_CreateMember
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
            this.Label_Contacts = new System.Windows.Forms.Label();
            this.DataGrid_Contacts = new System.Windows.Forms.DataGridView();
            this.Label_Position = new System.Windows.Forms.Label();
            this.TextBox_Position = new System.Windows.Forms.TextBox();
            this.Button_Add = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).BeginInit();
            this.SuspendLayout();
            // 
            // Label_Contacts
            // 
            this.Label_Contacts.AutoSize = true;
            this.Label_Contacts.Location = new System.Drawing.Point(12, 9);
            this.Label_Contacts.Name = "Label_Contacts";
            this.Label_Contacts.Size = new System.Drawing.Size(180, 13);
            this.Label_Contacts.TabIndex = 0;
            this.Label_Contacts.Text = "Select one of the following Contacts:";
            // 
            // DataGrid_Contacts
            // 
            this.DataGrid_Contacts.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Contacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contacts.Location = new System.Drawing.Point(15, 25);
            this.DataGrid_Contacts.Name = "DataGrid_Contacts";
            this.DataGrid_Contacts.Size = new System.Drawing.Size(411, 169);
            this.DataGrid_Contacts.TabIndex = 1;
            // 
            // Label_Position
            // 
            this.Label_Position.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Label_Position.AutoSize = true;
            this.Label_Position.Location = new System.Drawing.Point(12, 203);
            this.Label_Position.Name = "Label_Position";
            this.Label_Position.Size = new System.Drawing.Size(47, 13);
            this.Label_Position.TabIndex = 2;
            this.Label_Position.Text = "Position:";
            // 
            // TextBox_Position
            // 
            this.TextBox_Position.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Position.Location = new System.Drawing.Point(65, 200);
            this.TextBox_Position.Name = "TextBox_Position";
            this.TextBox_Position.Size = new System.Drawing.Size(361, 20);
            this.TextBox_Position.TabIndex = 3;
            // 
            // Button_Add
            // 
            this.Button_Add.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Add.Location = new System.Drawing.Point(123, 226);
            this.Button_Add.Name = "Button_Add";
            this.Button_Add.Size = new System.Drawing.Size(75, 23);
            this.Button_Add.TabIndex = 4;
            this.Button_Add.Text = "&Add";
            this.Button_Add.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Cancel.Location = new System.Drawing.Point(240, 226);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 5;
            this.Button_Cancel.Text = "&Cancel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // Form_CreateMember
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(438, 261);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Add);
            this.Controls.Add(this.TextBox_Position);
            this.Controls.Add(this.Label_Position);
            this.Controls.Add(this.DataGrid_Contacts);
            this.Controls.Add(this.Label_Contacts);
            this.Name = "Form_CreateMember";
            this.Text = "Add Member";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label_Contacts;
        private System.Windows.Forms.DataGridView DataGrid_Contacts;
        private System.Windows.Forms.Label Label_Position;
        private System.Windows.Forms.TextBox TextBox_Position;
        private System.Windows.Forms.Button Button_Add;
        private System.Windows.Forms.Button Button_Cancel;
    }
}