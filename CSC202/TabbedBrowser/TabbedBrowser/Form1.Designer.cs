namespace TabbedBrowser
{
	partial class browserWindow
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
			this.components = new System.ComponentModel.Container();
			this.tabControl1 = new System.Windows.Forms.TabControl();
			this.tabPage1 = new System.Windows.Forms.TabPage();
			this.tab1WebBrowser = new System.Windows.Forms.WebBrowser();
			this.tab1ButtonGo = new System.Windows.Forms.Button();
			this.tab1AddressBar = new System.Windows.Forms.TextBox();
			this.tabPage2 = new System.Windows.Forms.TabPage();
			this.tab2WebBrowser = new System.Windows.Forms.WebBrowser();
			this.tab2ButtonGo = new System.Windows.Forms.Button();
			this.tab2AddressBar = new System.Windows.Forms.TextBox();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
			this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.timer = new System.Windows.Forms.Timer(this.components);
			this.tabControl1.SuspendLayout();
			this.tabPage1.SuspendLayout();
			this.tabPage2.SuspendLayout();
			this.menuStrip1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
			this.SuspendLayout();
			// 
			// tabControl1
			// 
			this.tabControl1.Controls.Add(this.tabPage1);
			this.tabControl1.Controls.Add(this.tabPage2);
			this.tabControl1.Location = new System.Drawing.Point(1, 27);
			this.tabControl1.Name = "tabControl1";
			this.tabControl1.SelectedIndex = 0;
			this.tabControl1.Size = new System.Drawing.Size(778, 567);
			this.tabControl1.TabIndex = 0;
			// 
			// tabPage1
			// 
			this.tabPage1.Controls.Add(this.tab1WebBrowser);
			this.tabPage1.Controls.Add(this.tab1ButtonGo);
			this.tabPage1.Controls.Add(this.tab1AddressBar);
			this.tabPage1.Location = new System.Drawing.Point(4, 22);
			this.tabPage1.Name = "tabPage1";
			this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage1.Size = new System.Drawing.Size(770, 541);
			this.tabPage1.TabIndex = 0;
			this.tabPage1.Text = "Tab 1";
			this.tabPage1.UseVisualStyleBackColor = true;
			// 
			// tab1WebBrowser
			// 
			this.tab1WebBrowser.Location = new System.Drawing.Point(7, 35);
			this.tab1WebBrowser.MinimumSize = new System.Drawing.Size(20, 20);
			this.tab1WebBrowser.Name = "tab1WebBrowser";
			this.tab1WebBrowser.Size = new System.Drawing.Size(756, 526);
			this.tab1WebBrowser.TabIndex = 2;
			this.tab1WebBrowser.Url = new System.Uri("http://www.google.com", System.UriKind.Absolute);
			// 
			// tab1ButtonGo
			// 
			this.tab1ButtonGo.Location = new System.Drawing.Point(731, 6);
			this.tab1ButtonGo.Name = "tab1ButtonGo";
			this.tab1ButtonGo.Size = new System.Drawing.Size(33, 23);
			this.tab1ButtonGo.TabIndex = 1;
			this.tab1ButtonGo.Text = "Go";
			this.tab1ButtonGo.UseVisualStyleBackColor = true;
			this.tab1ButtonGo.Click += new System.EventHandler(this.tab1ButtonGo_Click);
			// 
			// tab1AddressBar
			// 
			this.tab1AddressBar.Location = new System.Drawing.Point(3, 9);
			this.tab1AddressBar.Name = "tab1AddressBar";
			this.tab1AddressBar.Size = new System.Drawing.Size(722, 20);
			this.tab1AddressBar.TabIndex = 0;
			this.tab1AddressBar.Text = "http://www.google.com";
			// 
			// tabPage2
			// 
			this.tabPage2.Controls.Add(this.tab2WebBrowser);
			this.tabPage2.Controls.Add(this.tab2ButtonGo);
			this.tabPage2.Controls.Add(this.tab2AddressBar);
			this.tabPage2.Location = new System.Drawing.Point(4, 22);
			this.tabPage2.Name = "tabPage2";
			this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage2.Size = new System.Drawing.Size(770, 541);
			this.tabPage2.TabIndex = 1;
			this.tabPage2.Text = "Tab 2";
			this.tabPage2.UseVisualStyleBackColor = true;
			// 
			// tab2WebBrowser
			// 
			this.tab2WebBrowser.Location = new System.Drawing.Point(9, 35);
			this.tab2WebBrowser.MinimumSize = new System.Drawing.Size(20, 20);
			this.tab2WebBrowser.Name = "tab2WebBrowser";
			this.tab2WebBrowser.Size = new System.Drawing.Size(756, 526);
			this.tab2WebBrowser.TabIndex = 5;
			this.tab2WebBrowser.Url = new System.Uri("http://www.slashdot.org", System.UriKind.Absolute);
			// 
			// tab2ButtonGo
			// 
			this.tab2ButtonGo.Location = new System.Drawing.Point(733, 6);
			this.tab2ButtonGo.Name = "tab2ButtonGo";
			this.tab2ButtonGo.Size = new System.Drawing.Size(33, 23);
			this.tab2ButtonGo.TabIndex = 4;
			this.tab2ButtonGo.Text = "Go";
			this.tab2ButtonGo.UseVisualStyleBackColor = true;
			// 
			// tab2AddressBar
			// 
			this.tab2AddressBar.Location = new System.Drawing.Point(5, 9);
			this.tab2AddressBar.Name = "tab2AddressBar";
			this.tab2AddressBar.Size = new System.Drawing.Size(722, 20);
			this.tab2AddressBar.TabIndex = 3;
			this.tab2AddressBar.Text = "http://www.slashdot.org";
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(780, 24);
			this.menuStrip1.TabIndex = 1;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.exitToolStripMenuItem});
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
			this.fileToolStripMenuItem.Text = "File";
			// 
			// openToolStripMenuItem
			// 
			this.openToolStripMenuItem.Name = "openToolStripMenuItem";
			this.openToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
			this.openToolStripMenuItem.Text = "Open...";
			this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
			this.exitToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
			this.exitToolStripMenuItem.Text = "Exit";
			this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
			// 
			// openFileDialog
			// 
			this.openFileDialog.FileName = "openFileDialog";
			this.openFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog_FileOk);
			// 
			// timer
			// 
			this.timer.Tick += new System.EventHandler(this.timer_Tick);
			// 
			// browserWindow
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(780, 596);
			this.Controls.Add(this.tabControl1);
			this.Controls.Add(this.menuStrip1);
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "browserWindow";
			this.Text = "Tabbed Browser";
			this.tabControl1.ResumeLayout(false);
			this.tabPage1.ResumeLayout(false);
			this.tabPage1.PerformLayout();
			this.tabPage2.ResumeLayout(false);
			this.tabPage2.PerformLayout();
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl tabControl1;
		private System.Windows.Forms.TabPage tabPage1;
		private System.Windows.Forms.TabPage tabPage2;
		private System.Windows.Forms.WebBrowser tab1WebBrowser;
		private System.Windows.Forms.Button tab1ButtonGo;
		private System.Windows.Forms.TextBox tab1AddressBar;
		private System.Windows.Forms.WebBrowser tab2WebBrowser;
		private System.Windows.Forms.Button tab2ButtonGo;
		private System.Windows.Forms.TextBox tab2AddressBar;
		private System.Windows.Forms.BindingSource bindingSource1;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
		private System.Windows.Forms.OpenFileDialog openFileDialog;
		private System.Windows.Forms.Timer timer;
	}
}

