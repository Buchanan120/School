using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Book : Item
    {
        public enum Formats { Paperback, Hardcover };
        public enum Genres { Historical, Biography, Historical_Fiction, Adventure, Action, Science_Fiction, Fantasy, Romance, Crime_Fiction };

        private int year;
        private string author;
        private string isbn;
        private Formats format;
        private Genres genre;

        public Book()
        {
        }

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