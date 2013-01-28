using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Supplier
    {
        private string name;
        private Address address;
        private string contactPerson;
        private string phone;

        public string Phone
        {
          get { return phone; }
          set { phone = value; }
        }

        public string ContactPerson
        {
          get { return contactPerson; }
          set { contactPerson = value; }
        }

        internal Address Address
        {
          get { return address; }
          set { address = value; }
        }

        public string Name
        {
          get { return name; }
          set { name = value; }
        }
    }
}