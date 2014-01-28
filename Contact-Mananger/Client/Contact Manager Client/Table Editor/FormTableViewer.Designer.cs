namespace Contact_Manager_Client.Table_Editor
{
    partial class FormTableViewer
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
            this.DataGrid_Table = new System.Windows.Forms.DataGridView();
            this.Label_DataGrid = new System.Windows.Forms.Label();
            this.Button_Return = new System.Windows.Forms.Button();
            this.Button_Create = new System.Windows.Forms.Button();
            this.Button_Edit = new System.Windows.Forms.Button();
            this.Button_Remove = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Table)).BeginInit();
            this.SuspendLayout();
            // 
            // DataGrid_Table
            // 
            this.DataGrid_Table.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Table.Location = new System.Drawing.Point(12, 25);
            this.DataGrid_Table.MultiSelect = false;
            this.DataGrid_Table.Name = "DataGrid_Table";
            this.DataGrid_Table.ReadOnly = true;
            this.DataGrid_Table.Size = new System.Drawing.Size(449, 231);
            this.DataGrid_Table.TabIndex = 0;
            // 
            // Label_DataGrid
            // 
            this.Label_DataGrid.AutoSize = true;
            this.Label_DataGrid.Location = new System.Drawing.Point(12, 9);
            this.Label_DataGrid.Name = "Label_DataGrid";
            this.Label_DataGrid.Size = new System.Drawing.Size(83, 13);
            this.Label_DataGrid.TabIndex = 1;
            this.Label_DataGrid.Text = "Table Elements:";
            // 
            // Button_Return
            // 
            this.Button_Return.Location = new System.Drawing.Point(15, 262);
            this.Button_Return.Name = "Button_Return";
            this.Button_Return.Size = new System.Drawing.Size(141, 23);
            this.Button_Return.TabIndex = 2;
            this.Button_Return.Text = "&Return to Table Editor";
            this.Button_Return.UseVisualStyleBackColor = true;
            // 
            // Button_Create
            // 
            this.Button_Create.Location = new System.Drawing.Point(224, 262);
            this.Button_Create.Name = "Button_Create";
            this.Button_Create.Size = new System.Drawing.Size(75, 23);
            this.Button_Create.TabIndex = 3;
            this.Button_Create.Text = "&Create";
            this.Button_Create.UseVisualStyleBackColor = true;
            // 
            // Button_Edit
            // 
            this.Button_Edit.Location = new System.Drawing.Point(305, 262);
            this.Button_Edit.Name = "Button_Edit";
            this.Button_Edit.Size = new System.Drawing.Size(75, 23);
            this.Button_Edit.TabIndex = 4;
            this.Button_Edit.Text = "&Edit";
            this.Button_Edit.UseVisualStyleBackColor = true;
            // 
            // Button_Remove
            // 
            this.Button_Remove.Location = new System.Drawing.Point(386, 262);
            this.Button_Remove.Name = "Button_Remove";
            this.Button_Remove.Size = new System.Drawing.Size(75, 23);
            this.Button_Remove.TabIndex = 5;
            this.Button_Remove.Text = "&Remove";
            this.Button_Remove.UseVisualStyleBackColor = true;
            // 
            // FormTableViewer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(473, 297);
            this.Controls.Add(this.Button_Remove);
            this.Controls.Add(this.Button_Edit);
            this.Controls.Add(this.Button_Create);
            this.Controls.Add(this.Button_Return);
            this.Controls.Add(this.Label_DataGrid);
            this.Controls.Add(this.DataGrid_Table);
            this.Name = "FormTableViewer";
            this.Text = "Table Viewer";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Table)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView DataGrid_Table;
        private System.Windows.Forms.Label Label_DataGrid;
        private System.Windows.Forms.Button Button_Return;
        private System.Windows.Forms.Button Button_Create;
        private System.Windows.Forms.Button Button_Edit;
        private System.Windows.Forms.Button Button_Remove;
    }
}