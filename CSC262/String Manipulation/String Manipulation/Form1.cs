using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace String_Manipulation
{
	public partial class FormStringManipulation : Form
	{
		// Here be methods
		#region methods
		// GetLength
			// Takes a string and returns the length thereof as a string
		private static string GetLength(string current)
		{
			return current.Length.ToString();
		}

		// GetStringLeft
			// Takes a string to be manipulated and another string with the number of characters to return
			//	Returns a substring from the left
		private static string GetStringLeft(string current, string numChars)
		{
			if (IsNumeric(numChars))
			{
				int length = int.Parse(numChars);
				if (length > current.Length)
					return "Value too high (Out of range)";
				else
					return current.Substring(0, length);
			}
			else
				return "Enter a valid number";
		}

		// GetStringRight
			// Takes a string to be manipulated and another with the number of characters to return
			//	Returns a substring from the right
		private static string GetStringRight(string current, string numChars)
		{
			if (IsNumeric(numChars))
			{
				int length = current.Length;
				int start = length - int.Parse(numChars);
				if (start < 0) 
					return "Value too high (Out of range)";
				else
					return current.Substring(start, length - start);
			}
			else
				return "Enter a valid number";
		}

		// CountCharsInString
			// Takes a string to be manipulated and a string of chars
			//	Counts each instance of every char in the latter string
			//	Returns the count as a string
		private static string CountCharsInString(string current, string chars)
		{
			int count = 0;
			foreach(char c in chars)
			{
				foreach(char d in current)
				{
					if (c == d) count++;
				}
			}

			return count.ToString();
		}

		// GetStringMiddle
			// Takes a string to be manipulated, a start and length values also as strings
			//	Returns a substring of the former
			//	Will check for out of bounds errors
		private static string GetStringMiddle(string current, string start, string numChars)
		{
			if(IsNumeric(start) && IsNumeric(numChars))
			{
				int first = int.Parse(start);
				int length = int.Parse(numChars);
				if(first + length > current.Length)
				{
					return "Out of bounds";
				}
				else
				{
					return current.Substring(first, length);
				}
			}
			else
				return "Enter a valid number";
		}

		// FindStringInString
			// Takes a string to be manipulated and a search string
			//	Searches the former for the latter
			//	Returns -1 or the index found as a string
		private static string FindStringInString(string current, string search)
		{
			string notFound = "-1";
			for (int i = 0; i < current.Length; i++)
			{
				try
				{
					string test = current.Substring(i, search.Length);
					if (test == search) return i.ToString();
				}
				catch (System.Exception e)
				{
					return notFound;
				}
			} 
			return notFound;
		}

		// StringToArray
			// Takes a string argument
			//	Parses string into words
			//	Returns array of strings from parse
		private static string[] StringToArray(string current)
		{
			// Google helped with this one after I spent half an hour trying to figure it out.
			string[] returnMe = current.Split(' ');
			return returnMe;
		}

		// StringToList
			// Takes a string argument
			//	Parses string into list of words
			//	Returns string list of words
		private static string StringToList(string current)
		{
			string returnMe = "";
			current = current.ToLower();
			foreach(char c in current)
			{
				if (c < 65) returnMe += ",";
				if (c > 90 && c < 97) returnMe += ",";
				if (c > 122) returnMe += ",";
				else returnMe += c;
			}
			return returnMe;
		}

		// GetSubString
			// Takes a string to be manipulated and two strings: start and end chars
			//	Returns substring between first instance of start 
			//	and first subsequent instance of end chars
		private static string GetSubString(string current, string start, string end)
		{
			string notFound = "-1";
			for (int i = 0; i < current.Length; i++)
			{
				if (start.Length < 0 && end.Length < 0 && current[i] == start[0])
				{
					for (int j = i; j < current.Length; j++)
					{
						if (current[j] == end[0])
						{
							return current.Substring(i, i + j + 1);
						}
					}
				}
			}

			return notFound;
		}

		// Reverse
			// Takes a string and returns its reverse
			//	Uses XOR to swap characters in a single variable
		private static string Reverse(string current)
		{
			char[] temp = new char[current.Length];
			int length = current.Length - 1;

			for (int i = 0; i <= length; i++)
				temp[i] = current[length - i];

			return new string(temp);
		}

		// IsNumeric
			// Takes a string argument
			//	Checks if the string contains all numbers
			//	Returns a bool
		private static bool IsNumeric(string chkNumeric)
		{
			int intOutVal;
			bool isValidNumeric = false;
			isValidNumeric = int.TryParse(chkNumeric, out intOutVal);
			return isValidNumeric;
		}
		#endregion

		public FormStringManipulation()
		{
			InitializeComponent();
		}

		private void buttonStringLength_Click(object sender, EventArgs e)
		{
			textBoxStringLengthResult.Text = GetLength(textBoxStringLength.Text.ToString());
		}

		private void buttonStringLeft_Click(object sender, EventArgs e)
		{
			textBoxStringLeftResult.Text = GetStringLeft(textBoxStringLeft.Text.ToString(), textBoxStringLeftNumChars.Text.ToString());
		}

		private void buttonStringRight_Click(object sender, EventArgs e)
		{
			textBoxStringRightResult.Text = GetStringRight(textBoxStringRight.Text.ToString(), textBoxStringRightNumChars.Text.ToString());
		}

		private void buttonStringCount_Click(object sender, EventArgs e)
		{
			textBoxStringCountResult.Text = CountCharsInString(textBoxStringCount.Text.ToString(), textBoxStringCountChars.Text.ToString());
		}
		
		private void buttonStringMiddle_Click(object sender, EventArgs e)
		{
			textBoxStringMiddleResults.Text = GetStringMiddle(textBoxStringMiddle.Text.ToString(), 
				textBoxStringMiddleStart.Text.ToString(), textBoxStringMiddleNumChars.Text.ToString());
		}

		private void buttonStringString_Click(object sender, EventArgs e)
		{
			textBoxStringStringResults.Text =
				FindStringInString(textBoxStringString.Text.ToString(), textBoxStringStringSub.Text.ToString());
		}

		private void buttonStringToArray_Click(object sender, EventArgs e)
		{
			string[] collection = StringToArray(textBoxStringToArray.Text.ToString());
			int i = 0;
			listStringToArray.Items.Clear();
			foreach (string s in collection)
			{
				listStringToArray.Items.Add(s);
			}
		}

		private void buttonStringList_Click(object sender, EventArgs e)
		{
			textBoxStringListResults.Text = StringToList(textBoxStringList.Text.ToString());
		}

		private void buttonSubString_Click(object sender, EventArgs e)
		{
			textBoxSubStringResult.Text = GetSubString(textBoxSubString.Text.ToString(),
				textBoxSubStringStart.Text.ToString(), textBoxSubStringEnd.Text.ToString());
		}

		private void buttonReverse_Click(object sender, EventArgs e)
		{
			textBoxReverseResult.Text = Reverse(textBoxReverse.Text.ToString());
		}
	}
}
