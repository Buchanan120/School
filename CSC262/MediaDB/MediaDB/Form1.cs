using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MediaDB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

			InventoryDatabase id = new InventoryDatabase();

			//id.LoadDataBase();

			//Book b = new Book();
			//b.Author = "Neil Stevenson";
			//b.Format = Book.Formats.paperback;
			//b.Genre = Book.Genres.science_fiction;
			//b.ISBN = "123456576";
			//b.Price = 19.95m;
			//b.Quantity = 500;
			//Supplier s = new Supplier();
			//Address a = new Address();
			//a.City = "New York";
			//a.State = "New York";
			//a.State = "123 Main St";
			//a.Zip = "12345";
			//s.Address = a;
			//s.ContactPerson = "Bob Wallace";
			//s.Name = "Random House";
			//s.Phone = "1-800-123-4567";
			//b.Supplier = s;
			//b.Title = "Diamond Age";
			//b.Year = 1989;
			//b.UPC = "6984945";
			//id.AddItem(b);
			//id.SaveDatabase();

        }
    }
}
