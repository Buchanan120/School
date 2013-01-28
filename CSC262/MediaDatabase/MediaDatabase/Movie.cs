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
        public enum Genres { Historical, Biography, Historical_Fiction, Adventure, Action, Science_Fiction, Fantasy, Romance, Crime_Fiction, Comedy, Documentary, Horror, Thriller, Animated, Serial, Game_Show, Reality_Show, Sitcom, Docudrama, Soap_Opera, Police_Procedural };

        private int year;
        private Formats format;
        private Genres genre;

        public Movie()
        {
        }

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