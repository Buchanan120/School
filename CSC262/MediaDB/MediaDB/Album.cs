using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MediaDB
{
	[Serializable]
    public class Album : Item
    {
        public enum Formats { CD, Cassette };
        public enum Genres { };

        private string artist;
        private string label;
        private Formats format;
        private Genres genre;
        private List<Song> songs;

        public Genres Genre
        {
          get { return genre; }
          set { genre = value; }
        }

        public Formats Format
        {
          get { return format; }
          set { format = value; }
        }

        public string Label
        {
          get { return label; }
          set { label = value; }
        }

        public string Artist
        {
          get { return artist; }
          set { artist = value; }
        }

        /// <summary>
        /// Adds a song to the tracklist.
        /// </summary>
        /// <param name="newSong">Song to add.</param>
        public void AddSong(Song newSong)
        {
            this.songs.Add(newSong);
        }

        /// <summary>
        /// Removes a song from the tracklist.
        /// </summary>
        /// <param name="song">Song to remove.</param>
        public void RemoveSong(Song song)
        {
            this.songs.Remove(song);
        }
    }
}