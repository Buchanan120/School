namespace Euclid
{
    partial class EuclidWiz
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
            this.btnFindGCD = new System.Windows.Forms.Button();
            this.textBoxNumber1 = new System.Windows.Forms.TextBox();
            this.textBoxNumber2 = new System.Windows.Forms.TextBox();
            this.labelNumber1 = new System.Windows.Forms.Label();
            this.labelNumber2 = new System.Windows.Forms.Label();
            this.labelGCD = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnFindGCD
            // 
            this.btnFindGCD.Location = new System.Drawing.Point(197, 45);
            this.btnFindGCD.Name = "btnFindGCD";
            this.btnFindGCD.Size = new System.Drawing.Size(75, 23);
            this.btnFindGCD.TabIndex = 0;
            this.btnFindGCD.Text = "Find GCD";
            this.btnFindGCD.UseVisualStyleBackColor = true;
            this.btnFindGCD.Click += new System.EventHandler(this.btnFindGCD_Click);
            // 
            // textBoxNumber1
            // 
            this.textBoxNumber1.Location = new System.Drawing.Point(78, 12);
            this.textBoxNumber1.Name = "textBoxNumber1";
            this.textBoxNumber1.Size = new System.Drawing.Size(100, 20);
            this.textBoxNumber1.TabIndex = 1;
            // 
            // textBoxNumber2
            // 
            this.textBoxNumber2.Location = new System.Drawing.Point(78, 38);
            this.textBoxNumber2.Name = "textBoxNumber2";
            this.textBoxNumber2.Size = new System.Drawing.Size(100, 20);
            this.textBoxNumber2.TabIndex = 2;
            // 
            // labelNumber1
            // 
            this.labelNumber1.AutoSize = true;
            this.labelNumber1.Location = new System.Drawing.Point(19, 19);
            this.labelNumber1.Name = "labelNumber1";
            this.labelNumber1.Size = new System.Drawing.Size(53, 13);
            this.labelNumber1.TabIndex = 3;
            this.labelNumber1.Text = "Number 1";
            this.labelNumber1.Click += new System.EventHandler(this.label1_Click);
            // 
            // labelNumber2
            // 
            this.labelNumber2.AutoSize = true;
            this.labelNumber2.Location = new System.Drawing.Point(19, 45);
            this.labelNumber2.Name = "labelNumber2";
            this.labelNumber2.Size = new System.Drawing.Size(53, 13);
            this.labelNumber2.TabIndex = 5;
            this.labelNumber2.Text = "Number 2";
            this.labelNumber2.Click += new System.EventHandler(this.label2_Click);
            // 
            // labelGCD
            // 
            this.labelGCD.AutoSize = true;
            this.labelGCD.Location = new System.Drawing.Point(22, 79);
            this.labelGCD.Name = "labelGCD";
            this.labelGCD.Size = new System.Drawing.Size(0, 13);
            this.labelGCD.TabIndex = 6;
            this.labelGCD.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // EuclidWiz
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 104);
            this.Controls.Add(this.labelGCD);
            this.Controls.Add(this.labelNumber2);
            this.Controls.Add(this.labelNumber1);
            this.Controls.Add(this.textBoxNumber2);
            this.Controls.Add(this.textBoxNumber1);
            this.Controls.Add(this.btnFindGCD);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "EuclidWiz";
            this.Text = "Euclid\'s Algorithm Wizard";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnFindGCD;
        private System.Windows.Forms.TextBox textBoxNumber1;
        private System.Windows.Forms.TextBox textBoxNumber2;
        private System.Windows.Forms.Label labelNumber1;
        private System.Windows.Forms.Label labelNumber2;
        private System.Windows.Forms.Label labelGCD;
    }
}

