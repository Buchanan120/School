using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace TextViewEdit
{
	public partial class TextViewEdit : Form
	{
		public TextViewEdit()
		{
			InitializeComponent();
		}

		private void textEditor_TextChanged(object sender, EventArgs e)
		{
			toolStripCharNumber.Text = textEditor.Text.Length.ToString();
			toolStripLineNumber.Text = textEditor.Lines.Length.ToString();
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			OpenFile();
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			SaveFile();
		}

		#region Methods
		void SaveFile()
		{
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				// The stream writer seems like it is the best option since it
				//	allows manipulation of a file stream
				StreamWriter writer = new StreamWriter(saveFileDialog.OpenFile());
				writer.Write(textEditor.Text);
				writer.Close();
			}
		}

		void OpenFile()
		{
			if (openFileDialog.ShowDialog() == DialogResult.OK)
			{
				// Stream and Stream Reader were also likely candidates.  
				//	They allow opening of existing files, as well as read access from them.
				Stream file = openFileDialog.OpenFile();
				StreamReader reader = new StreamReader(file);
				char[] text = new char[file.Length];
				reader.ReadBlock(text, 0, (int)file.Length);
				textEditor.Text = new String(text);
				reader.Close();
			}
		}
		#endregion
	}
}
