namespace Collections
{
    partial class Collections
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.buttonAL = new System.Windows.Forms.Button();
            this.buttonCustom = new System.Windows.Forms.Button();
            this.buttonRemove = new System.Windows.Forms.Button();
            this.listCustomCollection = new System.Windows.Forms.ListBox();
            this.listArrayList = new System.Windows.Forms.ListBox();
            this.textBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "String Name";
            // 
            // buttonAL
            // 
            this.buttonAL.Location = new System.Drawing.Point(122, 27);
            this.buttonAL.Name = "buttonAL";
            this.buttonAL.Size = new System.Drawing.Size(143, 23);
            this.buttonAL.TabIndex = 2;
            this.buttonAL.Text = "Add to ArrayList";
            this.buttonAL.UseVisualStyleBackColor = true;
            this.buttonAL.Click += new System.EventHandler(this.buttonAL_Click);
            // 
            // buttonCustom
            // 
            this.buttonCustom.Location = new System.Drawing.Point(122, 56);
            this.buttonCustom.Name = "buttonCustom";
            this.buttonCustom.Size = new System.Drawing.Size(143, 23);
            this.buttonCustom.TabIndex = 3;
            this.buttonCustom.Text = "Add to Custom Collection";
            this.buttonCustom.UseVisualStyleBackColor = true;
            this.buttonCustom.Click += new System.EventHandler(this.buttonCustom_Click);
            // 
            // buttonRemove
            // 
            this.buttonRemove.Location = new System.Drawing.Point(108, 300);
            this.buttonRemove.Name = "buttonRemove";
            this.buttonRemove.Size = new System.Drawing.Size(143, 23);
            this.buttonRemove.TabIndex = 4;
            this.buttonRemove.Text = "Remove Selected";
            this.buttonRemove.UseVisualStyleBackColor = true;
            this.buttonRemove.Click += new System.EventHandler(this.buttonRemove_Click);
            // 
            // listCustomCollection
            // 
            this.listCustomCollection.FormattingEnabled = true;
            this.listCustomCollection.Location = new System.Drawing.Point(13, 108);
            this.listCustomCollection.Name = "listCustomCollection";
            this.listCustomCollection.Size = new System.Drawing.Size(155, 186);
            this.listCustomCollection.TabIndex = 5;
            // 
            // listArrayList
            // 
            this.listArrayList.FormattingEnabled = true;
            this.listArrayList.Location = new System.Drawing.Point(190, 108);
            this.listArrayList.Name = "listArrayList";
            this.listArrayList.Size = new System.Drawing.Size(155, 186);
            this.listArrayList.TabIndex = 6;
            // 
            // textBox
            // 
            this.textBox.Location = new System.Drawing.Point(16, 30);
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(100, 20);
            this.textBox.TabIndex = 7;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(91, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Custom Collection";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(187, 89);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "ArrayList";
            // 
            // Collections
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(359, 336);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.listArrayList);
            this.Controls.Add(this.listCustomCollection);
            this.Controls.Add(this.buttonRemove);
            this.Controls.Add(this.buttonCustom);
            this.Controls.Add(this.buttonAL);
            this.Controls.Add(this.label1);
            this.Name = "Collections";
            this.Text = "Collections";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonAL;
        private System.Windows.Forms.Button buttonCustom;
        private System.Windows.Forms.Button buttonRemove;
        private System.Windows.Forms.ListBox listCustomCollection;
        private System.Windows.Forms.ListBox listArrayList;
        private System.Windows.Forms.TextBox textBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

