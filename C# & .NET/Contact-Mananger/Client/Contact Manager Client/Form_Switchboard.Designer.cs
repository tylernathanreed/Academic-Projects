namespace Contact_Manager_Client
{
    partial class Form_Switchboard
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
            this.Button_ContactManager = new System.Windows.Forms.Button();
            this.Button_EventPlanner = new System.Windows.Forms.Button();
            this.Button_TableEditor = new System.Windows.Forms.Button();
            this.Button_SQLInjector = new System.Windows.Forms.Button();
            this.Button_Connection = new System.Windows.Forms.Button();
            this.Button_Close = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Button_ContactManager
            // 
            this.Button_ContactManager.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_ContactManager.Location = new System.Drawing.Point(12, 12);
            this.Button_ContactManager.Name = "Button_ContactManager";
            this.Button_ContactManager.Size = new System.Drawing.Size(260, 23);
            this.Button_ContactManager.TabIndex = 0;
            this.Button_ContactManager.Text = "&Contact Manager";
            this.Button_ContactManager.UseVisualStyleBackColor = true;
            this.Button_ContactManager.Click += new System.EventHandler(this.Button_ContactManager_Click);
            // 
            // Button_EventPlanner
            // 
            this.Button_EventPlanner.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_EventPlanner.Location = new System.Drawing.Point(12, 41);
            this.Button_EventPlanner.Name = "Button_EventPlanner";
            this.Button_EventPlanner.Size = new System.Drawing.Size(260, 23);
            this.Button_EventPlanner.TabIndex = 1;
            this.Button_EventPlanner.Text = "&Event Planner";
            this.Button_EventPlanner.UseVisualStyleBackColor = true;
            this.Button_EventPlanner.Click += new System.EventHandler(this.Button_EventPlanner_Click);
            // 
            // Button_TableEditor
            // 
            this.Button_TableEditor.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_TableEditor.Location = new System.Drawing.Point(12, 70);
            this.Button_TableEditor.Name = "Button_TableEditor";
            this.Button_TableEditor.Size = new System.Drawing.Size(260, 23);
            this.Button_TableEditor.TabIndex = 2;
            this.Button_TableEditor.Text = "&Table Editor";
            this.Button_TableEditor.UseVisualStyleBackColor = true;
            this.Button_TableEditor.Click += new System.EventHandler(this.Button_TableEditor_Click);
            // 
            // Button_SQLInjector
            // 
            this.Button_SQLInjector.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_SQLInjector.Location = new System.Drawing.Point(12, 99);
            this.Button_SQLInjector.Name = "Button_SQLInjector";
            this.Button_SQLInjector.Size = new System.Drawing.Size(260, 23);
            this.Button_SQLInjector.TabIndex = 3;
            this.Button_SQLInjector.Text = "&SQL Injector";
            this.Button_SQLInjector.UseVisualStyleBackColor = true;
            this.Button_SQLInjector.Click += new System.EventHandler(this.Button_SQLInjector_Click);
            // 
            // Button_Connection
            // 
            this.Button_Connection.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Button_Connection.Location = new System.Drawing.Point(12, 145);
            this.Button_Connection.Name = "Button_Connection";
            this.Button_Connection.Size = new System.Drawing.Size(127, 23);
            this.Button_Connection.TabIndex = 4;
            this.Button_Connection.Text = "Ch&ange Connection";
            this.Button_Connection.UseVisualStyleBackColor = true;
            this.Button_Connection.Click += new System.EventHandler(this.Button_Connection_Click);
            // 
            // Button_Close
            // 
            this.Button_Close.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Button_Close.Location = new System.Drawing.Point(145, 145);
            this.Button_Close.Name = "Button_Close";
            this.Button_Close.Size = new System.Drawing.Size(127, 23);
            this.Button_Close.TabIndex = 5;
            this.Button_Close.Text = "Cl&ose Connection";
            this.Button_Close.UseVisualStyleBackColor = true;
            this.Button_Close.Click += new System.EventHandler(this.Button_Close_Click);
            // 
            // Form_Switchboard
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 180);
            this.Controls.Add(this.Button_Close);
            this.Controls.Add(this.Button_Connection);
            this.Controls.Add(this.Button_SQLInjector);
            this.Controls.Add(this.Button_TableEditor);
            this.Controls.Add(this.Button_EventPlanner);
            this.Controls.Add(this.Button_ContactManager);
            this.Name = "Form_Switchboard";
            this.Text = "Switchboard";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form_Switchboard_FormClosing);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Button_ContactManager;
        private System.Windows.Forms.Button Button_EventPlanner;
        private System.Windows.Forms.Button Button_TableEditor;
        private System.Windows.Forms.Button Button_SQLInjector;
        private System.Windows.Forms.Button Button_Connection;
        private System.Windows.Forms.Button Button_Close;
    }
}