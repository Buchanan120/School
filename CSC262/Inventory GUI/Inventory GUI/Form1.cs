using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MediaDB;

namespace Inventory_GUI
{
    public partial class Form1 : Form
    {
		enum ViewType { View, Edit, Add };
		InventoryDatabase invase = new InventoryDatabase();

        public Form1()
        {
            InitializeComponent();
        }

       

		#region Menu 
		#region File
		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (openFileDialog.ShowDialog() == DialogResult.OK)
			{
				invase.LoadDatabase(openFileDialog.FileName);
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				invase.SaveDatabase(saveFileDialog.FileName);
			}
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
		}
		#endregion
		#region Tools

		private void addToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void editToolStripMenuItem1_Click(object sender, EventArgs e)
		{

		}

		private void removeToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}
		#endregion
		#endregion

		#region Lookup
		enum SearchType { Title, UPC };
		SearchType searchType = SearchType.Title;
		private void radioTitle_CheckedChanged(object sender, EventArgs e)
		{
			searchType = SearchType.Title;
		}

		private void radioUPC_CheckedChanged(object sender, EventArgs e)
		{
			searchType = SearchType.UPC;
		}

		private void buttonLookupSearch_Click(object sender, EventArgs e)
		{
			try
			{
				switch (searchType)
				{
					case SearchType.Title:
						ShowItem(invase.LookupByTitle(textLookupTitle.ToString()));
						break;
					case SearchType.UPC:
						invase.LookupByUPC(textLookupUPC.ToString());
						break;
				}
			}
			catch (System.Exception ex)
			{
				MessageBox.Show(ex.Message, "Could not open file:");
			}
		}
		#endregion

		private void ShowItem(Item item)
		{
			switch(item.GetType().ToString())
			{
				case "MediaDB.Book":
					ShowBook(item as Book);
					break;
				case "MediaDB.Movie":
					ShowMovie(item);
					break;
				case "MediaDB.Album":
					ShowAlbum(item);
					break;
				default:
					MessageBox.Show("\"Fix Me\" - The Show Item Switch Case");
					break;
			}
		}

		private void ShowAlbum(Item item)
		{
			throw new NotImplementedException();
		}

		private void ShowMovie(Item item)
		{
			throw new NotImplementedException();
		}

		private void ShowBook(Book book)
		{
			textBookAuthor.Text = book.Author;
			textBookDescription.Text = book.Description;
			textBookFormat.Text = book.Format.ToString();
			textBookGenre.Text = book.Genre.ToString();
			textBookISBN.Text = book.Genre.ToString();
			textBookPrice.Text = book.Price.ToString();
			textBookQuantity.Value = (decimal)book.Quantity;
			textBookSupplierAddress.Text = book.Supplier.Address.ToString();
			textBookSupplierContactPerson.Text = book.Supplier.ContactPerson;
			textBookSupplierName.Text = book.Supplier.Name;
			textBookSupplierPhone.Text = book.Supplier.Phone;
			textBookTitle.Text = book.Title;
			textBookUPC.Text = book.UPC;
			textBookYear.Text = book.Year.ToString();
		}

		private void maskedTextBox26_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
		{

		}

		private void numericUpDown4_ValueChanged(object sender, EventArgs e)
		{

		}

		private void maskedTextBox28_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
		{

		}

		private void maskedTextBox32_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
		{

		}

		private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
		{

		}
	}
}
