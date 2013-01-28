using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Book : Item
    {
        public enum Formats { paperback, hardcover };
        public enum Genres { historical, biography, historical_fiction, adventure, action, science_fiction, fantasy, romance, crime_fiction };

        private int year;
        private string author;
        private string isbn;
        private Formats format;
        private Genres genre;

        public Genres Genre
        {
            get { return genre; }
            set { genre = value; }
        }

        public string ISBN
        {
            get { return isbn; }
            set { isbn = value; }
        }

        public string Author
        {
            get { return author; }
            set { author = value; }
        }

        public int Year
        {
            get { return year; }
            set { year = value; }
        }

        public Formats Format
        {
            get { return format; }
            set { format = value; }
        }
    }
}