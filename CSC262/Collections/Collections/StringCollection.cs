using System.Windows.Forms;

namespace Collections
{
    class StringCollection : System.Collections.CollectionBase
    {
        /// <summary>
        /// Adds a string to the collection.
        /// </summary>
        /// <param name="aString">The string to be added.</param>
        public void Add(string aString)
        {
            List.Add(aString);
        }


        /// <summary>
        /// Removes a specific string from the collection. 
        /// Only the first occurance of the string will be removed.
        /// </summary>
        /// <param name="aString">The string to be removed.</param>
        public void Remove(string aString)
        {
            List.Remove(aString);
        }

        /// <summary>
        /// Removes the string at the specified index from the collection.
        /// </summary>
        /// <param name="index">Index at which to remove.</param>
        public void RemoveAt(int index)
        {
            if (index > Count - 1 || index < 0)
                MessageBox.Show("Index out of bounds.", "Error");
            else
                List.RemoveAt(index);
        }

        /// <summary>
        /// Returns the string at the specified index.
        /// </summary>
        /// <param name="index">Index of string to return.</param>
        /// <returns></returns>
        public string Item(int index)
        {
            return (string)List[index];
        }

    }
}
