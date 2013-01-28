using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace War_of_the_Ants
{
	class Anthill
	{
        private Rectangle location;

        public Rectangle Location
        {
            get { return location; }
            set { location = value; }
        }

		public Anthill(Rectangle l)
		{
			location = l;
		}
	}
}
