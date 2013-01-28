using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace MediaDB
{
	[Serializable]
    public class InventoryDatabase
    {
        private List<Item> items;

		public List<Item> Items
		{
			get { return items; }
			set { items = value; }
		}
		public InventoryDatabase()
		{
			items = new List<Item>();
		}

        public void AddItem(Item newItem)
        {
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
            items.Remove(item);
		}

        public void RemoveItem(string upc)
        {
            foreach (Item item in items)
            {
                if (item.UPC == upc)
                    items.Remove(item);
            }
        }

        public Item LookupByUPC(string UPC)
        {
            foreach (Item item in items)
                if (item.UPC == UPC)
                    return item;

            throw new Exception("Item does not exist");
        }

        public Item LookupByTitle(string title)
        {
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
				stream.Close();
			}
			catch (System.Exception ex)
			{
				throw new Exception("Something went wrong with the save.\nPlease try again.");
			}
		}

		public void LoadDatabase()
		{
			LoadDatabase(@".\media_database.awesome");
		}

		public void LoadDatabase(string path)
		{
			try
			{
				BinaryFormatter deserializer = new BinaryFormatter();
				FileStream stream = File.OpenRead(path);
				items = deserializer.Deserialize(stream) as List<Item>;
				stream.Close();
			}
			catch (System.Exception ex)
			{
                throw new Exception("Something went wrong with the load.\nPlease try again.");
			}
			
		}
    }
}
