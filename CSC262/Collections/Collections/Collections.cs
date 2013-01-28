using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;

namespace Collections
{
    public partial class Collections : Form
    {
         ArrayList myAL = new ArrayList();
         StringCollection mySC = new StringCollection();
        public Collections()
        {
            InitializeComponent();
        }

        private void buttonAL_Click(object sender, EventArgs e)
        {
            myAL.Add(textBox.Text.ToString());
            updateArrayList();
        }

        private void updateArrayList()
        {
            listArrayList.Items.Clear();
            for (int i = 0; i < myAL.Count; i++)
            {
                listArrayList.Items.Add(myAL[i]);
            }
        }

        private void buttonCustom_Click(object sender, EventArgs e)
        {
            mySC.Add(textBox.Text.ToString());
            updateStringCollection();
        }

        private void updateStringCollection()
        {
            listCustomCollection.Items.Clear();
            for (int i = 0; i < mySC.Count; i++)
            {
                listCustomCollection.Items.Add(mySC.Item(i));
            }

        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < listCustomCollection.Items.Count; i++)
                if (listCustomCollection.GetSelected(i))
                {
                    mySC.RemoveAt(i);
                    updateStringCollection();
                }
            for (int i = 0; i < listArrayList.Items.Count; i++)
                if (listArrayList.GetSelected(i))
                {
                    myAL.RemoveAt(i);
                    updateStringCollection();
                }
            updateStringCollection();
            updateArrayList();
        }
    }
}
