namespace Contact_Manager_Client
{
    partial class Form_ConfirmDelete
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
            this.Label_Promp = new System.Windows.Forms.Label();
            this.Button_Yes = new System.Windows.Forms.Button();
            this.Button_No = new System.Windows.Forms.Button();
            this.CheckBox_Reminder = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // Label_Promp
            // 
            this.Label_Promp.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Label_Promp.AutoSize = true;
            this.Label_Promp.Location = new System.Drawing.Point(8, 9);
            this.Label_Promp.Name = "Label_Promp";
            this.Label_Promp.Size = new System.Drawing.Size(229, 13);
            this.Label_Promp.TabIndex = 0;
            this.Label_Promp.Text = "Are you sure you want permanently delete this?";
            // 
            // Button_Yes
            // 
            this.Button_Yes.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Yes.Location = new System.Drawing.Point(44, 54);
            this.Button_Yes.Name = "Button_Yes";
            this.Button_Yes.Size = new System.Drawing.Size(75, 23);
            this.Button_Yes.TabIndex = 1;
            this.Button_Yes.Text = "&Yes";
            this.Button_Yes.UseVisualStyleBackColor = true;
            this.Button_Yes.Click += new System.EventHandler(this.Button_Yes_Click);
            // 
            // Button_No
            // 
            this.Button_No.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_No.Location = new System.Drawing.Point(125, 54);
            this.Button_No.Name = "Button_No";
            this.Button_No.Size = new System.Drawing.Size(75, 23);
            this.Button_No.TabIndex = 2;
            this.Button_No.Text = "&No";
            this.Button_No.UseVisualStyleBackColor = true;
            this.Button_No.Click += new System.EventHandler(this.Button_No_Click);
            // 
            // CheckBox_Reminder
            // 
            this.CheckBox_Reminder.Anchor = ((System.Windows.Forms.AnchorStyles) ((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.CheckBox_Reminder.AutoSize = true;
            this.CheckBox_Reminder.Location = new System.Drawing.Point(64, 31);
            this.CheckBox_Reminder.Name = "CheckBox_Reminder";
            this.CheckBox_Reminder.Size = new System.Drawing.Size(117, 17);
            this.CheckBox_Reminder.TabIndex = 3;
            this.CheckBox_Reminder.Text = "&Don\'t ask me again";
            this.CheckBox_Reminder.UseVisualStyleBackColor = true;
            // 
            // Form_ConfirmDelete
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(245, 89);
            this.Controls.Add(this.CheckBox_Reminder);
            this.Controls.Add(this.Button_No);
            this.Controls.Add(this.Button_Yes);
            this.Controls.Add(this.Label_Promp);
            this.Name = "Form_ConfirmDelete";
            this.Text = "Delete Confirmation";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label_Promp;
        private System.Windows.Forms.Button Button_Yes;
        private System.Windows.Forms.Button Button_No;
        private System.Windows.Forms.CheckBox CheckBox_Reminder;
    }
}