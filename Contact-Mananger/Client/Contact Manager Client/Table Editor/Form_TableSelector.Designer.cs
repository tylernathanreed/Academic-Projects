namespace Contact_Manager_Client
{
    partial class Form_TableSelector
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
            this.Button_Contact = new System.Windows.Forms.Button();
            this.Button_Address = new System.Windows.Forms.Button();
            this.Button_Email = new System.Windows.Forms.Button();
            this.Button_PhoneNumber = new System.Windows.Forms.Button();
            this.Button_Group = new System.Windows.Forms.Button();
            this.Button_Member = new System.Windows.Forms.Button();
            this.Button_Return = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Button_Contact
            // 
            this.Button_Contact.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Contact.Location = new System.Drawing.Point(12, 12);
            this.Button_Contact.Name = "Button_Contact";
            this.Button_Contact.Size = new System.Drawing.Size(260, 23);
            this.Button_Contact.TabIndex = 0;
            this.Button_Contact.Text = "&Contact";
            this.Button_Contact.UseVisualStyleBackColor = true;
            // 
            // Button_Address
            // 
            this.Button_Address.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Address.Location = new System.Drawing.Point(12, 70);
            this.Button_Address.Name = "Button_Address";
            this.Button_Address.Size = new System.Drawing.Size(260, 23);
            this.Button_Address.TabIndex = 1;
            this.Button_Address.Text = "&Address";
            this.Button_Address.UseVisualStyleBackColor = true;
            // 
            // Button_Email
            // 
            this.Button_Email.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Email.Location = new System.Drawing.Point(12, 99);
            this.Button_Email.Name = "Button_Email";
            this.Button_Email.Size = new System.Drawing.Size(260, 23);
            this.Button_Email.TabIndex = 2;
            this.Button_Email.Text = "&Email Address";
            this.Button_Email.UseVisualStyleBackColor = true;
            // 
            // Button_PhoneNumber
            // 
            this.Button_PhoneNumber.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_PhoneNumber.Location = new System.Drawing.Point(12, 41);
            this.Button_PhoneNumber.Name = "Button_PhoneNumber";
            this.Button_PhoneNumber.Size = new System.Drawing.Size(260, 23);
            this.Button_PhoneNumber.TabIndex = 3;
            this.Button_PhoneNumber.Text = "&Phone Number";
            this.Button_PhoneNumber.UseVisualStyleBackColor = true;
            // 
            // Button_Group
            // 
            this.Button_Group.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Group.Location = new System.Drawing.Point(12, 128);
            this.Button_Group.Name = "Button_Group";
            this.Button_Group.Size = new System.Drawing.Size(260, 23);
            this.Button_Group.TabIndex = 4;
            this.Button_Group.Text = "&Group";
            this.Button_Group.UseVisualStyleBackColor = true;
            // 
            // Button_Member
            // 
            this.Button_Member.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Member.Location = new System.Drawing.Point(12, 157);
            this.Button_Member.Name = "Button_Member";
            this.Button_Member.Size = new System.Drawing.Size(260, 23);
            this.Button_Member.TabIndex = 5;
            this.Button_Member.Text = "&Member";
            this.Button_Member.UseVisualStyleBackColor = true;
            // 
            // Button_Return
            // 
            this.Button_Return.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Return.Location = new System.Drawing.Point(12, 207);
            this.Button_Return.Name = "Button_Return";
            this.Button_Return.Size = new System.Drawing.Size(260, 23);
            this.Button_Return.TabIndex = 6;
            this.Button_Return.Text = "&Return to Switchboard";
            this.Button_Return.UseVisualStyleBackColor = true;
            // 
            // Form_TableSelector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 242);
            this.Controls.Add(this.Button_Return);
            this.Controls.Add(this.Button_Member);
            this.Controls.Add(this.Button_Group);
            this.Controls.Add(this.Button_PhoneNumber);
            this.Controls.Add(this.Button_Email);
            this.Controls.Add(this.Button_Address);
            this.Controls.Add(this.Button_Contact);
            this.Name = "Form_TableSelector";
            this.Text = "Table Editor";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Button_Contact;
        private System.Windows.Forms.Button Button_Address;
        private System.Windows.Forms.Button Button_Email;
        private System.Windows.Forms.Button Button_PhoneNumber;
        private System.Windows.Forms.Button Button_Group;
        private System.Windows.Forms.Button Button_Member;
        private System.Windows.Forms.Button Button_Return;
    }
}