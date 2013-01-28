using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TabbedBrowser
{
	public partial class browserWindow : Form
	{
		public DelegateStuff doStuff;

		public browserWindow()
		{
			InitializeComponent();

			doStuff = new DelegateStuff();

			timer.Interval = 30000;
		}

		public void tab1OpenDialog()
		{
			string newUrl = openFileDialog.FileName.ToString();
			tab1WebBrowser.Navigate(newUrl);
			tab1AddressBar.Text = newUrl;
		}

		public void tab2OpenDialog()
		{
			string newUrl = openFileDialog.FileName.ToString();
			tab2WebBrowser.Navigate(newUrl);
			tab2AddressBar.Text = newUrl;
		}

		private void tab1ButtonGo_Click(object sender, EventArgs e)
		{
			tab1WebBrowser.Navigate(tab1AddressBar.Text);
			timer.Start();
		}

		private void tab2ButtonGo_Click(object sender, EventArgs e)
		{
			tab2WebBrowser.Navigate(tab2AddressBar.Text);
			timer.Start();
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			openFileDialog.ShowDialog();
		}

		private void openFileDialog_FileOk(object sender, CancelEventArgs e)
		{
			if (tabControl1.SelectedTab == tabPage1)
				doStuff.stuffNThings(tab1OpenDialog);
			else
				doStuff.stuffNThings(tab2OpenDialog);
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void timer_Tick(object sender, EventArgs e)
		{
			tab1WebBrowser.Refresh();
			tab2WebBrowser.Refresh();
		}
	}

	public class DelegateStuff
	{
		public delegate void doStuff();

		public void stuffNThings(doStuff doThis)
		{
			doThis();
		}
	}
}
