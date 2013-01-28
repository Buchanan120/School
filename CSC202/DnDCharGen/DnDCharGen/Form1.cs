using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DnDCharGen
{
	public partial class Form1 : Form
	{

		Character myCharacter = new Character();
		public Form1()
		{
			InitializeComponent();
		}

		private void spinnerLevel_ValueChanged(object sender, EventArgs e)
		{
			myCharacter.SetLevel((int)spinnerLevel.Value);
		}

		private void textBoxCharacterName_TextChanged(object sender, EventArgs e)
		{
			myCharacter.SetCharacterName(textBoxCharacterName.Text);
		}

		private void wikiToolStripMenuItem_Click(object sender, EventArgs e)
		{
			myCharacter.ExportToMediawiki();
		}

		private void textBoxPlayer_TextChanged(object sender, EventArgs e)
		{
			myCharacter.SetPlayerName(textBoxPlayer.Text);
		}

		private void comboBoxClass_SelectedIndexChanged(object sender, EventArgs e)
		{
			myCharacter.SetClass(comboBoxClass.Text);
		}

		private void comboBoxRace_SelectedIndexChanged(object sender, EventArgs e)
		{
			myCharacter.SetRace(comboBoxRace.Text);
		}

		private void spinnerAge_ValueChanged(object sender, EventArgs e)
		{
			myCharacter.SetAge((int)spinnerAge.Value);
		}

		private void comboBoxGender_SelectedIndexChanged(object sender, EventArgs e)
		{
			myCharacter.SetGender(comboBoxGender.Text);
		}

		private void textBoxHeight_TextChanged(object sender, EventArgs e)
		{
			try
			{
				myCharacter.SetHeight(int.Parse(textBoxHeight.Text));
			}
			catch (Exception exception)
			{
				if(textBoxHeight.Text != "")
					MessageBox.Show(exception.Message);
				textBoxHeight.Text = "";
			}
		}

		private void textBoxWeight_TextChanged(object sender, EventArgs e)
		{
			try
			{
				myCharacter.SetWeight(int.Parse(textBoxWeight.Text));
			}
			catch (Exception exception)
			{
				if (textBoxWeight.Text != "")
					MessageBox.Show(exception.Message);
				textBoxWeight.Text = "";
			}
		}

		private void textBoxEyes_TextChanged(object sender, EventArgs e)
		{
			myCharacter.SetEyeColor(textBoxEyes.Text);
		}

		private void textBoxHair_TextChanged(object sender, EventArgs e)
		{
			myCharacter.SetHairColor(textBoxHair.Text);
		}

		private void textBoxSkin_TextChanged(object sender, EventArgs e)
		{
			myCharacter.SetSkinColor(textBoxSkin.Text);
		}

        private void spinnerSTR_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }

        private void spinnerDEX_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }

        private void spinnerCON_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }

        private void spinnerINT_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }

        private void spinnerWIS_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }

        private void spinnerCHA_ValueChanged(object sender, EventArgs e)
        {
            myCharacter.SetAbilities;
        }
	}
	public class Character
	{
		// Remember: every time you want to talk to the enum,
		// you have to explictly cast it as an int.
		private enum AbilityNames { STR, DEX, CON, INT, WIS, CHA };
		private string _characterName;
		private string _playerName;
		private string _characterClass;
		private int _level;
		private string _race;
		private int _age;
		private string _gender;
		private int _heightInInches;
		private int _weight;
		private string _eyeColor;
		private string _hairColor;
		private string _skinColor;
		private string[] _languages;
		private int[] _abilities;

		public Character()
		{
	        _abilities = new int[6];
			_level = 1;
            for (int i = 0; i < 6; i++)
            {
                _abilities[i] = 8;
            }
		}

		public int UpdatePointBuy()
		{
			// Return the number of points spent on this setup

			int total = 0;
			// For each ability score...
				// Add the cost of that score to the total

			return total;
		}

		public void SetCharacterName(string newName)
		{
			_characterName = newName;
		}

		public void SetPlayerName(string newName)
		{
			_playerName = newName;
		}

		public void SetLevel(int newLevel)
		{
			_level = newLevel;
		}

		public void SetRace(string newRace)
		{
			_race = newRace;
		}

		public void SetClass(string newClass)
		{
			_characterClass = newClass;
		}

		public void SetAge(int newAge)
		{
			_age = newAge;
		}

		public void SetGender(string newGender)
		{
			_gender = newGender;
		}

		public void SetHeight(int newHeight)
		{
			_heightInInches = newHeight;
		}

		public void SetWeight(int newWeight)
		{
			_weight = newWeight;
		}

		public void SetEyeColor(string newEyeColor)
		{
			_eyeColor = newEyeColor;
		}

		public void SetHairColor(string newHairColor)
		{
			_hairColor = newHairColor;
		}

		public void SetSkinColor(string newSkinColor)
		{
			_skinColor = newSkinColor;
		}

        public void SetAbilities()
        {
            _abilities = { spinnerSTR.value, spinnerDEX.value, spinnerCON, spinnerINT, spinnerWIS, spinnerCHA };
        }
		public void ExportToMediawiki()
		{
			// create a writer and open the file
			TextWriter tw = new StreamWriter("characterSheet.txt");

			//// write a line of text to the file
			tw.WriteLine("{{Infobox DnDCharacter");
			tw.WriteLine("|name        = " + _characterName);
			tw.WriteLine("|player      = " + _playerName);
			tw.WriteLine("|image       = ");
			tw.WriteLine("|caption     = ");
			tw.WriteLine("|level       = " + _level);
			tw.WriteLine("|race        = " + _race);
			tw.WriteLine("|class       = " + _characterClass);
			tw.WriteLine("|age         = " + _age);
			tw.WriteLine("|gender      = " + _gender);
			tw.WriteLine("|height      = " + _heightInInches / 12 + "'"
			            + _heightInInches % 12 + '"');
			tw.WriteLine("|weight      = " + _weight);
			tw.WriteLine("|hair_color  = " + _hairColor);
			tw.WriteLine("|skin_color  = " + _skinColor);
			tw.WriteLine("|eye_color   = " + _eyeColor);
            tw.WriteLine("|STR         = " + _abilities[(int)AbilityNames.STR]);
            tw.WriteLine("|DEX         = " + _abilities[(int)AbilityNames.DEX]);
            tw.WriteLine("|CON         = " + _abilities[(int)AbilityNames.CON]);
            tw.WriteLine("|INT         = " + _abilities[(int)AbilityNames.INT]);
            tw.WriteLine("|WIS         = " + _abilities[(int)AbilityNames.WIS]);
            tw.WriteLine("|CHA         = " + _abilities[(int)AbilityNames.CHA]);
			tw.WriteLine("}}");

			// close the stream
			tw.Close();
		}
	}
}
