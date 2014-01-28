namespace Contact_Manager_Client
{
    partial class Form_ContactManager
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
            this.Label_Contacts = new System.Windows.Forms.Label();
            this.Button_Delete = new System.Windows.Forms.Button();
            this.Button_Edit = new System.Windows.Forms.Button();
            this.Button_Create = new System.Windows.Forms.Button();
            this.Button_Return = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).BeginInit();
            this.SuspendLayout();
            // 
            // DataGrid_Contacts
            // 
            this.DataGrid_Contacts.AllowUserToAddRows = false;
            this.DataGrid_Contacts.AllowUserToDeleteRows = false;
            this.DataGrid_Contacts.AllowUserToResizeRows = false;
            this.DataGrid_Contacts.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Contacts.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.DataGrid_Contacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Contacts.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnEnter;
            this.DataGrid_Contacts.Location = new System.Drawing.Point(12, 32);
            this.DataGrid_Contacts.MultiSelect = false;
            this.DataGrid_Contacts.Name = "DataGrid_Contacts";
            this.DataGrid_Contacts.ReadOnly = true;
            this.DataGrid_Contacts.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.DataGrid_Contacts.ShowCellErrors = false;
            this.DataGrid_Contacts.ShowCellToolTips = false;
            this.DataGrid_Contacts.ShowEditingIcon = false;
            this.DataGrid_Contacts.ShowRowErrors = false;
            this.DataGrid_Contacts.Size = new System.Drawing.Size(454, 211);
            this.DataGrid_Contacts.TabIndex = 0;
            // 
            // Label_Contacts
            // 
            this.Label_Contacts.AutoSize = true;
            this.Label_Contacts.Location = new System.Drawing.Point(13, 13);
            this.Label_Contacts.Name = "Label_Contacts";
            this.Label_Contacts.Size = new System.Drawing.Size(52, 13);
            this.Label_Contacts.TabIndex = 1;
            this.Label_Contacts.Text = "Contacts:";
            // 
            // Button_Delete
            // 
            this.Button_Delete.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Delete.Location = new System.Drawing.Point(391, 249);
            this.Button_Delete.Name = "Button_Delete";
            this.Button_Delete.Size = new System.Drawing.Size(75, 23);
            this.Button_Delete.TabIndex = 2;
            this.Button_Delete.Text = "&Delete";
            this.Button_Delete.UseVisualStyleBackColor = true;
            this.Button_Delete.Click += new System.EventHandler(this.Button_Delete_Click);
            // 
            // Button_Edit
            // 
            this.Button_Edit.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Edit.Location = new System.Drawing.Point(310, 249);
            this.Button_Edit.Name = "Button_Edit";
            this.Button_Edit.Size = new System.Drawing.Size(75, 23);
            this.Button_Edit.TabIndex = 3;
            this.Button_Edit.Text = "&Edit";
            this.Button_Edit.UseVisualStyleBackColor = true;
            this.Button_Edit.Click += new System.EventHandler(this.Button_Edit_Click);
            // 
            // Button_Create
            // 
            this.Button_Create.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Create.Location = new System.Drawing.Point(229, 249);
            this.Button_Create.Name = "Button_Create";
            this.Button_Create.Size = new System.Drawing.Size(75, 23);
            this.Button_Create.TabIndex = 4;
            this.Button_Create.Text = "&Create";
            this.Button_Create.UseVisualStyleBackColor = true;
            this.Button_Create.Click += new System.EventHandler(this.Button_Create_Click);
            // 
            // Button_Return
            // 
            this.Button_Return.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Return.Location = new System.Drawing.Point(12, 249);
            this.Button_Return.Name = "Button_Return";
            this.Button_Return.Size = new System.Drawing.Size(123, 23);
            this.Button_Return.TabIndex = 5;
            this.Button_Return.Text = "&Return to Switchboard";
            this.Button_Return.UseVisualStyleBackColor = true;
            this.Button_Return.Click += new System.EventHandler(this.Button_Return_Click);
            // 
            // Form_ContactManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(478, 284);
            this.Controls.Add(this.Button_Return);
            this.Controls.Add(this.Button_Create);
            this.Controls.Add(this.Button_Edit);
            this.Controls.Add(this.Button_Delete);
            this.Controls.Add(this.Label_Contacts);
            this.Controls.Add(this.DataGrid_Contacts);
            this.Name = "Form_ContactManager";
            this.Text = "Contact Manager";
            this.Load += new System.EventHandler(this.Form_ContactManager_Load);
            this.VisibleChanged += new System.EventHandler(this.Form_ContactManager_VisibleChanged);
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Contacts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView DataGrid_Contacts;
        private System.Windows.Forms.Label Label_Contacts;
        private System.Windows.Forms.Button Button_Delete;
        private System.Windows.Forms.Button Button_Edit;
        private System.Windows.Forms.Button Button_Create;
        private System.Windows.Forms.Button Button_Return;
    }
}