namespace Contact_Manager_Client
{
    partial class Form_SQLInjector
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
            if (disposing && (components != null))
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
            this.TextBox_SQL = new System.Windows.Forms.TextBox();
            this.Label_SQL = new System.Windows.Forms.Label();
            this.Label_Output = new System.Windows.Forms.Label();
            this.Button_Send = new System.Windows.Forms.Button();
            this.DataGrid_Output = new System.Windows.Forms.DataGridView();
            this.TextBox_Error = new System.Windows.Forms.TextBox();
            this.Button_Return = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Output)).BeginInit();
            this.SuspendLayout();
            // 
            // TextBox_SQL
            // 
            this.TextBox_SQL.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_SQL.Location = new System.Drawing.Point(99, 12);
            this.TextBox_SQL.Name = "TextBox_SQL";
            this.TextBox_SQL.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.TextBox_SQL.Size = new System.Drawing.Size(242, 20);
            this.TextBox_SQL.TabIndex = 1;
            this.TextBox_SQL.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBox_SQL_KeyDown);
            // 
            // Label_SQL
            // 
            this.Label_SQL.AutoSize = true;
            this.Label_SQL.Location = new System.Drawing.Point(12, 15);
            this.Label_SQL.Name = "Label_SQL";
            this.Label_SQL.Size = new System.Drawing.Size(81, 13);
            this.Label_SQL.TabIndex = 2;
            this.Label_SQL.Text = "SQL Command:";
            // 
            // Label_Output
            // 
            this.Label_Output.AutoSize = true;
            this.Label_Output.Location = new System.Drawing.Point(12, 43);
            this.Label_Output.Name = "Label_Output";
            this.Label_Output.Size = new System.Drawing.Size(42, 13);
            this.Label_Output.TabIndex = 3;
            this.Label_Output.Text = "Output:";
            // 
            // Button_Send
            // 
            this.Button_Send.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Send.Location = new System.Drawing.Point(347, 10);
            this.Button_Send.Name = "Button_Send";
            this.Button_Send.Size = new System.Drawing.Size(75, 23);
            this.Button_Send.TabIndex = 4;
            this.Button_Send.Text = "S&end";
            this.Button_Send.UseVisualStyleBackColor = true;
            this.Button_Send.Click += new System.EventHandler(this.Button_Send_Click);
            // 
            // DataGrid_Output
            // 
            this.DataGrid_Output.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DataGrid_Output.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid_Output.Location = new System.Drawing.Point(12, 64);
            this.DataGrid_Output.Name = "DataGrid_Output";
            this.DataGrid_Output.ReadOnly = true;
            this.DataGrid_Output.Size = new System.Drawing.Size(410, 220);
            this.DataGrid_Output.TabIndex = 6;
            // 
            // TextBox_Error
            // 
            this.TextBox_Error.AcceptsReturn = true;
            this.TextBox_Error.AcceptsTab = true;
            this.TextBox_Error.ForeColor = System.Drawing.Color.Black;
            this.TextBox_Error.Location = new System.Drawing.Point(12, 64);
            this.TextBox_Error.Multiline = true;
            this.TextBox_Error.Name = "TextBox_Error";
            this.TextBox_Error.ReadOnly = true;
            this.TextBox_Error.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.TextBox_Error.Size = new System.Drawing.Size(410, 220);
            this.TextBox_Error.TabIndex = 7;
            this.TextBox_Error.Visible = false;
            // 
            // Button_Return
            // 
            this.Button_Return.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Return.Location = new System.Drawing.Point(12, 290);
            this.Button_Return.Name = "Button_Return";
            this.Button_Return.Size = new System.Drawing.Size(410, 23);
            this.Button_Return.TabIndex = 8;
            this.Button_Return.Tag = "";
            this.Button_Return.Text = "&Return to Switchboard";
            this.Button_Return.UseVisualStyleBackColor = true;
            this.Button_Return.Click += new System.EventHandler(this.Button_Return_Click);
            // 
            // Form_SQLInjector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(434, 320);
            this.Controls.Add(this.Button_Return);
            this.Controls.Add(this.TextBox_Error);
            this.Controls.Add(this.DataGrid_Output);
            this.Controls.Add(this.Button_Send);
            this.Controls.Add(this.Label_Output);
            this.Controls.Add(this.Label_SQL);
            this.Controls.Add(this.TextBox_SQL);
            this.Name = "Form_SQLInjector";
            this.Text = "SQL Injector";
            ((System.ComponentModel.ISupportInitialize) (this.DataGrid_Output)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TextBox_SQL;
        private System.Windows.Forms.Label Label_SQL;
        private System.Windows.Forms.Label Label_Output;
        private System.Windows.Forms.Button Button_Send;
        private System.Windows.Forms.DataGridView DataGrid_Output;
        private System.Windows.Forms.TextBox TextBox_Error;
        private System.Windows.Forms.Button Button_Return;
    }
}