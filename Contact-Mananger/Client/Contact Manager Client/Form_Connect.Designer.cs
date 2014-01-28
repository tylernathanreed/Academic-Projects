namespace Contact_Manager_Client
{
    partial class Form_Connect
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
            this.Button_Connect = new System.Windows.Forms.Button();
            this.Label_Server = new System.Windows.Forms.Label();
            this.TextBox_Server = new System.Windows.Forms.TextBox();
            this.TextBox_Database = new System.Windows.Forms.TextBox();
            this.Label_Database = new System.Windows.Forms.Label();
            this.TextBox_Timeout = new System.Windows.Forms.TextBox();
            this.Label_Timeout = new System.Windows.Forms.Label();
            this.Label_Trusted = new System.Windows.Forms.Label();
            this.CheckBox_Trusted = new System.Windows.Forms.CheckBox();
            this.Button_Close = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Button_Connect
            // 
            this.Button_Connect.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Connect.Location = new System.Drawing.Point(12, 99);
            this.Button_Connect.Name = "Button_Connect";
            this.Button_Connect.Size = new System.Drawing.Size(109, 23);
            this.Button_Connect.TabIndex = 9;
            this.Button_Connect.Text = "C&onnect";
            this.Button_Connect.UseVisualStyleBackColor = true;
            this.Button_Connect.Click += new System.EventHandler(this.Button_Connect_Click);
            // 
            // Label_Server
            // 
            this.Label_Server.AutoSize = true;
            this.Label_Server.Location = new System.Drawing.Point(9, 16);
            this.Label_Server.Name = "Label_Server";
            this.Label_Server.Size = new System.Drawing.Size(41, 13);
            this.Label_Server.TabIndex = 1;
            this.Label_Server.Text = "Server:";
            // 
            // TextBox_Server
            // 
            this.TextBox_Server.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Server.Location = new System.Drawing.Point(71, 13);
            this.TextBox_Server.Name = "TextBox_Server";
            this.TextBox_Server.Size = new System.Drawing.Size(165, 20);
            this.TextBox_Server.TabIndex = 2;
            this.TextBox_Server.Text = "localhost";
            this.TextBox_Server.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBox_Server_KeyDown);
            // 
            // TextBox_Database
            // 
            this.TextBox_Database.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Database.Location = new System.Drawing.Point(71, 39);
            this.TextBox_Database.Name = "TextBox_Database";
            this.TextBox_Database.Size = new System.Drawing.Size(165, 20);
            this.TextBox_Database.TabIndex = 4;
            this.TextBox_Database.Text = "Contact Manager";
            this.TextBox_Database.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBox_Database_KeyDown);
            // 
            // Label_Database
            // 
            this.Label_Database.AutoSize = true;
            this.Label_Database.Location = new System.Drawing.Point(9, 42);
            this.Label_Database.Name = "Label_Database";
            this.Label_Database.Size = new System.Drawing.Size(56, 13);
            this.Label_Database.TabIndex = 3;
            this.Label_Database.Text = "Database:";
            // 
            // TextBox_Timeout
            // 
            this.TextBox_Timeout.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBox_Timeout.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.TextBox_Timeout.Location = new System.Drawing.Point(199, 67);
            this.TextBox_Timeout.MaxLength = 4;
            this.TextBox_Timeout.Name = "TextBox_Timeout";
            this.TextBox_Timeout.Size = new System.Drawing.Size(37, 20);
            this.TextBox_Timeout.TabIndex = 8;
            this.TextBox_Timeout.Text = "30";
            this.TextBox_Timeout.WordWrap = false;
            this.TextBox_Timeout.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBox_Timeout_KeyDown);
            // 
            // Label_Timeout
            // 
            this.Label_Timeout.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Timeout.AutoSize = true;
            this.Label_Timeout.Location = new System.Drawing.Point(145, 71);
            this.Label_Timeout.Name = "Label_Timeout";
            this.Label_Timeout.Size = new System.Drawing.Size(48, 13);
            this.Label_Timeout.TabIndex = 7;
            this.Label_Timeout.Text = "Timeout:";
            // 
            // Label_Trusted
            // 
            this.Label_Trusted.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Label_Trusted.AutoSize = true;
            this.Label_Trusted.Location = new System.Drawing.Point(9, 70);
            this.Label_Trusted.Name = "Label_Trusted";
            this.Label_Trusted.Size = new System.Drawing.Size(103, 13);
            this.Label_Trusted.TabIndex = 5;
            this.Label_Trusted.Text = "Trusted Connection:";
            // 
            // CheckBox_Trusted
            // 
            this.CheckBox_Trusted.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.CheckBox_Trusted.AutoSize = true;
            this.CheckBox_Trusted.Checked = true;
            this.CheckBox_Trusted.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CheckBox_Trusted.Location = new System.Drawing.Point(118, 70);
            this.CheckBox_Trusted.Name = "CheckBox_Trusted";
            this.CheckBox_Trusted.Size = new System.Drawing.Size(15, 14);
            this.CheckBox_Trusted.TabIndex = 6;
            this.CheckBox_Trusted.UseVisualStyleBackColor = true;
            // 
            // Button_Close
            // 
            this.Button_Close.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Close.Location = new System.Drawing.Point(127, 99);
            this.Button_Close.Name = "Button_Close";
            this.Button_Close.Size = new System.Drawing.Size(109, 23);
            this.Button_Close.TabIndex = 10;
            this.Button_Close.Text = "&Close";
            this.Button_Close.UseVisualStyleBackColor = true;
            this.Button_Close.Click += new System.EventHandler(this.Button_Close_Click);
            // 
            // Form_Connect
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(248, 134);
            this.Controls.Add(this.Button_Close);
            this.Controls.Add(this.CheckBox_Trusted);
            this.Controls.Add(this.Label_Trusted);
            this.Controls.Add(this.TextBox_Timeout);
            this.Controls.Add(this.Label_Timeout);
            this.Controls.Add(this.TextBox_Database);
            this.Controls.Add(this.Label_Database);
            this.Controls.Add(this.TextBox_Server);
            this.Controls.Add(this.Label_Server);
            this.Controls.Add(this.Button_Connect);
            this.Name = "Form_Connect";
            this.Text = "Connect to Database";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Button_Connect;
        private System.Windows.Forms.Label Label_Server;
        private System.Windows.Forms.TextBox TextBox_Server;
        private System.Windows.Forms.TextBox TextBox_Database;
        private System.Windows.Forms.Label Label_Database;
        private System.Windows.Forms.TextBox TextBox_Timeout;
        private System.Windows.Forms.Label Label_Timeout;
        private System.Windows.Forms.Label Label_Trusted;
        private System.Windows.Forms.CheckBox CheckBox_Trusted;
        private System.Windows.Forms.Button Button_Close;
    }
}