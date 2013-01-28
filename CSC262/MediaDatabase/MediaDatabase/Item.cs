using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public abstract class Item
    {
        private string title;
        private string description;
        private decimal price;
        private int quantity;
        private string upc;
        private Supplier supplier;

        public string Description
        {
          get { return description; }
          set { description = value; }
        }

        public decimal Price
        {
          get { return price; }
          set { price = value; }
        }

        public int Quantity
        {
          get { return quantity; }
          set { quantity = value; }
        }

        /// <summary>
        /// Increases the quantity of the item in stock.
        /// </summary>
        /// <param name="quantity">Quantity by which to increase.</param>
        public void IncreaseQuantity(int quantity)
        {
            this.quantity += quantity;
        }

        /// <summary>
        /// Decreases the quantity of the item in stock.
        /// </summary>
        /// <param name="quantity">Quantity by which to decrease.</param>
        public void DecreaseQuantity(int quantity)
        {
            this.quantity -= quantity;
        }

        public string UPC
        {
          get { return upc; }
          set { upc = value; }
        }

        public Supplier Supplier
        {
          get { return supplier; }
          set { supplier = value; }
        }


        public string Title
        {
            get { return title; }
            set { title = value; }
        }
    }
}