using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Movie : Item
    {
        public enum Formats { DVD, VHS };
        public enum Genres { };

        private int year;
        private Formats format;
        private Genres genre;
        
        public Formats Format
        {
            get { return format; }
            set { format = value; }
        }

        public Genres Genre
        {
            get { return genre; }
            set { genre = value; }
        }

        public int Year
        {
          get { return year; }
          set { year = value; }
        }
    }
}