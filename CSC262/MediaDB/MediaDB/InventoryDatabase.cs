using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;
using System.Windows.Forms;

namespace MediaDB
{
	[Serializable]
    public class InventoryDatabase
    {
        private List<Item> items;
		private bool saved = false;

		public InventoryDatabase()
		{
			items = new List<Item>();
		}

        public void AddItem(Item newItem)
        {
			saved = false;
			if (items.Count > 0)
			{
				foreach (Item item in items)
					if (item.UPC == newItem.UPC)
						throw new Exception("Item already exists");
			}
            items.Add(newItem);
        }

		public void RemoveItem(Item item)
        {
			saved = false;
            items.Remove(item);
		}

        public void RemoveItem(string upc)
        {
			saved = false;
            foreach (Item item in items)
            {
                if (item.UPC == upc)
                    items.Remove(item);
            }
        }

        Item LookupByUPC(string UPC)
        {
			saved = false;
            foreach (Item item in items)
                if (item.UPC == UPC)
                    return item;

            throw new Exception("Item does not exist");
        }

        Item LookupByTitle(string title)
        {
			saved = false;
            foreach (Item item in items)
                if (item.Title == title)
                    return item;

            throw new Exception("Item does not exist");
        }

		public void SaveDatabase()
		{
			SaveDatabase(@".\media_database.awesome");
		}

		public void SaveDatabase(string path)
		{
			try
			{
				BinaryFormatter serializer = new BinaryFormatter();
				FileStream stream = File.OpenWrite(path);
				serializer.Serialize(stream, items);
				saved = true;
				stream.Close();
			}
			catch (System.Exception ex)
			{
				MessageBox.Show("Something went wrong with the save.\nPlease try again.");
			}
		}

		public void LoadDataBase()
		{
			LoadDataBase(@".\media_database.awesome");
		}

		private void LoadDataBase(string path)
		{
			try
			{
				BinaryFormatter deserializer = new BinaryFormatter();
				FileStream stream = File.OpenRead(path);
				items = deserializer.Deserialize(stream) as List<Item>;
				saved = true;
				stream.Close();
			}
			catch (System.Exception ex)
			{
				MessageBox.Show("Something went wrong with the load.\nPlease try again.");
			}
			
		}
    }
}
