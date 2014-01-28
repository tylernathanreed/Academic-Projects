namespace Contact_Manager_Client
{
    partial class Form_CreateGroup
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
            this.Label_Name = new System.Windows.Forms.Label();
            this.TextBox_Name = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.TextBox_Description = new System.Windows.Forms.TextBox();
            this.Label_Delimit = new System.Windows.Forms.Label();
            this.Label_Members = new System.Windows.Forms.Label();
            this.DataGrid_Members = new System.Windows.Forms.DataGridView();
            this.Button_Add = new System.Windows.Forms.Button();
            this.Button_Edit = new System.Windows.Forms.Button();
            this.Button_Remove = new System.Windows.Forms.Button();
            this.Button_Save = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Members)).BeginInit();
            this.SuspendLayout();
            // 
            // Label_Name
            // 
            this.Label_Name.AutoSize = true;
            this.Label_Name.Location = new System.Drawing.Point(12, 9);
            this.Label_Name.Name = "Label_Name";
            this.Label_Name.Size = new System.Drawing.Size(38, 13);
            this.Label_Name.TabIndex = 0;
            this.Label_Name.Text = "Name:";
            // 
            // TextBox_Name
            // 
            this.TextBox_Name.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Name.Location = new System.Drawing.Point(81, 6);
            this.TextBox_Name.Name = "TextBox_Name";
            this.TextBox_Name.Size = new System.Drawing.Size(349, 20);
            this.TextBox_Name.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Description:";
            // 
            // TextBox_Description
            // 
            this.TextBox_Description.AcceptsReturn = true;
            this.TextBox_Description.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Description.Location = new System.Drawing.Point(81, 32);
            this.TextBox_Description.Multiline = true;
            this.TextBox_Description.Name = "TextBox_Description";
            this.TextBox_Description.Size = new System.Drawing.Size(349, 65);
            this.TextBox_Description.TabIndex = 3;
            // 
            // Label_Delimit
            // 
            this.Label_Delimit.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Delimit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_Delimit.Location = new System.Drawing.Point(15, 104);
            this.Label_Delimit.Name = "Label_Delimit";
            this.Label_Delimit.Size = new System.Drawing.Size(415, 2);
            this.Label_Delimit.TabIndex = 4;
            // 
            // Label_Members
            // 
            this.Label_Members.AutoSize = true;
            this.Label_Members.Location = new System.Drawing.Point(12, 111);
            this.Label_Members.Name = "Label_Members";
            this.Label_Members.Size = new System.Drawing.Size(53, 13);
            this.Label_Members.TabIndex = 5;
            this.Label_Members.Text = "Members:";
            // 
            // DataGrid_Members
            // 
            this.DataGrid_Members.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Members.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Members.Location = new System.Drawing.Point(12, 127);
            this.DataGrid_Members.Name = "DataGrid_Members";
            this.DataGrid_Members.Size = new System.Drawing.Size(327, 130);
            this.DataGrid_Members.TabIndex = 6;
            // 
            // Button_Add
            // 
            this.Button_Add.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Add.Location = new System.Drawing.Point(355, 127);
            this.Button_Add.Name = "Button_Add";
            this.Button_Add.Size = new System.Drawing.Size(75, 23);
            this.Button_Add.TabIndex = 7;
            this.Button_Add.Text = "&Add";
            this.Button_Add.UseVisualStyleBackColor = true;
            // 
            // Button_Edit
            // 
            this.Button_Edit.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Edit.Location = new System.Drawing.Point(355, 181);
            this.Button_Edit.Name = "Button_Edit";
            this.Button_Edit.Size = new System.Drawing.Size(75, 23);
            this.Button_Edit.TabIndex = 8;
            this.Button_Edit.Text = "&Edit";
            this.Button_Edit.UseVisualStyleBackColor = true;
            // 
            // Button_Remove
            // 
            this.Button_Remove.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Remove.Location = new System.Drawing.Point(355, 235);
            this.Button_Remove.Name = "Button_Remove";
            this.Button_Remove.Size = new System.Drawing.Size(75, 23);
            this.Button_Remove.TabIndex = 9;
            this.Button_Remove.Text = "&Remove";
            this.Button_Remove.UseVisualStyleBackColor = true;
            // 
            // Button_Save
            // 
            this.Button_Save.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Save.Location = new System.Drawing.Point(97, 263);
            this.Button_Save.Name = "Button_Save";
            this.Button_Save.Size = new System.Drawing.Size(75, 23);
            this.Button_Save.TabIndex = 10;
            this.Button_Save.Text = "&Save";
            this.Button_Save.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Cancel.Location = new System.Drawing.Point(227, 263);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 11;
            this.Button_Cancel.Text = "&Cancel";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // Form_CreateGroup
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(442, 298);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Save);
            this.Controls.Add(this.Button_Remove);
            this.Controls.Add(this.Button_Edit);
            this.Controls.Add(this.Button_Add);
            this.Controls.Add(this.DataGrid_Members);
            this.Controls.Add(this.Label_Members);
            this.Controls.Add(this.Label_Delimit);
            this.Controls.Add(this.TextBox_Description);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TextBox_Name);
            this.Controls.Add(this.Label_Name);
            this.Name = "Form_CreateGroup";
            this.Text = "New Group";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Members)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label_Name;
        private System.Windows.Forms.TextBox TextBox_Name;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox TextBox_Description;
        private System.Windows.Forms.Label Label_Delimit;
        private System.Windows.Forms.Label Label_Members;
        private System.Windows.Forms.DataGridView DataGrid_Members;
        private System.Windows.Forms.Button Button_Add;
        private System.Windows.Forms.Button Button_Edit;
        private System.Windows.Forms.Button Button_Remove;
        private System.Windows.Forms.Button Button_Save;
        private System.Windows.Forms.Button Button_Cancel;
    }
}