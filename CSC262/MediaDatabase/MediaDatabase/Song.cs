using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Song
    {
        private string title;
        private int trackNumber;
        private TimeSpan length;

        public Song()
        {
            length = new TimeSpan();
        }

        public TimeSpan Length
        {
            get { return length; }
            set { length = value; }
        }


        public int TrackNumber
        {
            get { return trackNumber; }
            set { trackNumber = value; }
        }

        public string Title
        {
          get { return title; }
          set { title = value; }
        }
        
    }
}