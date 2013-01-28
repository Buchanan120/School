using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Address
    {
        private string street;
        private string city;
        private string state;
        private string zip;

        public string Street
        {
          get { return street; }
          set { street = value; }
        }
        public string City
        {
          get { return city; }
          set { city = value; }
        }
        public string State
        {
          get { return state; }
          set { state = value; }
        }
        public string Zip
        {
          get { return zip; }
          set { zip = value; }
        }
    }
}
