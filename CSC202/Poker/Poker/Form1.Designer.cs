namespace Poker
{
	partial class Form1
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
			this.btnShuffle = new System.Windows.Forms.Button();
			this.btnDeal = new System.Windows.Forms.Button();
			this.grbControls = new System.Windows.Forms.GroupBox();
			this.grbResults = new System.Windows.Forms.GroupBox();
			this.lblResults = new System.Windows.Forms.Label();
			this.grbCard1 = new System.Windows.Forms.GroupBox();
			this.lblCard1Suit = new System.Windows.Forms.Label();
			this.lblCard1Num = new System.Windows.Forms.Label();
			this.grbCard2 = new System.Windows.Forms.GroupBox();
			this.lblCard2Suit = new System.Windows.Forms.Label();
			this.lblCard2Num = new System.Windows.Forms.Label();
			this.grbCard3 = new System.Windows.Forms.GroupBox();
			this.lblCard3Suit = new System.Windows.Forms.Label();
			this.lblCard3Num = new System.Windows.Forms.Label();
			this.grbCard4 = new System.Windows.Forms.GroupBox();
			this.lblCard4Suit = new System.Windows.Forms.Label();
			this.lblCard4Num = new System.Windows.Forms.Label();
			this.grbCard5 = new System.Windows.Forms.GroupBox();
			this.lblCard5Suit = new System.Windows.Forms.Label();
			this.lblCard5Num = new System.Windows.Forms.Label();
			this.grbHand = new System.Windows.Forms.GroupBox();
			this.grbControls.SuspendLayout();
			this.grbResults.SuspendLayout();
			this.grbCard1.SuspendLayout();
			this.grbCard2.SuspendLayout();
			this.grbCard3.SuspendLayout();
			this.grbCard4.SuspendLayout();
			this.grbCard5.SuspendLayout();
			this.grbHand.SuspendLayout();
			this.SuspendLayout();
			// 
			// btnShuffle
			// 
			this.btnShuffle.Location = new System.Drawing.Point(6, 13);
			this.btnShuffle.Name = "btnShuffle";
			this.btnShuffle.Size = new System.Drawing.Size(75, 23);
			this.btnShuffle.TabIndex = 0;
			this.btnShuffle.Text = "Shuffle";
			this.btnShuffle.UseVisualStyleBackColor = true;
			this.btnShuffle.Click += new System.EventHandler(this.btnShuffle_Click);
			// 
			// btnDeal
			// 
			this.btnDeal.Location = new System.Drawing.Point(6, 42);
			this.btnDeal.Name = "btnDeal";
			this.btnDeal.Size = new System.Drawing.Size(75, 23);
			this.btnDeal.TabIndex = 0;
			this.btnDeal.Text = "Deal";
			this.btnDeal.UseVisualStyleBackColor = true;
			this.btnDeal.Click += new System.EventHandler(this.btnDeal_Click);
			// 
			// grbControls
			// 
			this.grbControls.Controls.Add(this.btnDeal);
			this.grbControls.Controls.Add(this.btnShuffle);
			this.grbControls.Location = new System.Drawing.Point(309, 116);
			this.grbControls.Name = "grbControls";
			this.grbControls.Size = new System.Drawing.Size(88, 73);
			this.grbControls.TabIndex = 1;
			this.grbControls.TabStop = false;
			this.grbControls.Text = "Controls";
			// 
			// grbResults
			// 
			this.grbResults.Controls.Add(this.lblResults);
			this.grbResults.Location = new System.Drawing.Point(112, 116);
			this.grbResults.Name = "grbResults";
			this.grbResults.Size = new System.Drawing.Size(90, 49);
			this.grbResults.TabIndex = 2;
			this.grbResults.TabStop = false;
			this.grbResults.Text = "Results";
			// 
			// lblResults
			// 
			this.lblResults.AutoSize = true;
			this.lblResults.Location = new System.Drawing.Point(11, 25);
			this.lblResults.Name = "lblResults";
			this.lblResults.Size = new System.Drawing.Size(16, 13);
			this.lblResults.TabIndex = 0;
			this.lblResults.Text = "---";
			// 
			// grbCard1
			// 
			this.grbCard1.Controls.Add(this.lblCard1Suit);
			this.grbCard1.Controls.Add(this.lblCard1Num);
			this.grbCard1.Location = new System.Drawing.Point(3, 14);
			this.grbCard1.Name = "grbCard1";
			this.grbCard1.Size = new System.Drawing.Size(57, 69);
			this.grbCard1.TabIndex = 3;
			this.grbCard1.TabStop = false;
			this.grbCard1.Text = "Card 1";
			// 
			// lblCard1Suit
			// 
			this.lblCard1Suit.AutoSize = true;
			this.lblCard1Suit.Location = new System.Drawing.Point(5, 39);
			this.lblCard1Suit.Name = "lblCard1Suit";
			this.lblCard1Suit.Size = new System.Drawing.Size(25, 13);
			this.lblCard1Suit.TabIndex = 1;
			this.lblCard1Suit.Text = "Suit";
			// 
			// lblCard1Num
			// 
			this.lblCard1Num.AutoSize = true;
			this.lblCard1Num.Location = new System.Drawing.Point(5, 16);
			this.lblCard1Num.Name = "lblCard1Num";
			this.lblCard1Num.Size = new System.Drawing.Size(29, 13);
			this.lblCard1Num.TabIndex = 1;
			this.lblCard1Num.Text = "Num";
			// 
			// grbCard2
			// 
			this.grbCard2.Controls.Add(this.lblCard2Suit);
			this.grbCard2.Controls.Add(this.lblCard2Num);
			this.grbCard2.Location = new System.Drawing.Point(56, 14);
			this.grbCard2.Name = "grbCard2";
			this.grbCard2.Size = new System.Drawing.Size(57, 69);
			this.grbCard2.TabIndex = 3;
			this.grbCard2.TabStop = false;
			this.grbCard2.Text = "Card 2";
			// 
			// lblCard2Suit
			// 
			this.lblCard2Suit.AutoSize = true;
			this.lblCard2Suit.Location = new System.Drawing.Point(6, 39);
			this.lblCard2Suit.Name = "lblCard2Suit";
			this.lblCard2Suit.Size = new System.Drawing.Size(25, 13);
			this.lblCard2Suit.TabIndex = 1;
			this.lblCard2Suit.Text = "Suit";
			// 
			// lblCard2Num
			// 
			this.lblCard2Num.AutoSize = true;
			this.lblCard2Num.Location = new System.Drawing.Point(6, 16);
			this.lblCard2Num.Name = "lblCard2Num";
			this.lblCard2Num.Size = new System.Drawing.Size(29, 13);
			this.lblCard2Num.TabIndex = 1;
			this.lblCard2Num.Text = "Num";
			// 
			// grbCard3
			// 
			this.grbCard3.Controls.Add(this.lblCard3Suit);
			this.grbCard3.Controls.Add(this.lblCard3Num);
			this.grbCard3.Location = new System.Drawing.Point(109, 14);
			this.grbCard3.Name = "grbCard3";
			this.grbCard3.Size = new System.Drawing.Size(57, 69);
			this.grbCard3.TabIndex = 3;
			this.grbCard3.TabStop = false;
			this.grbCard3.Text = "Card 3";
			// 
			// lblCard3Suit
			// 
			this.lblCard3Suit.AutoSize = true;
			this.lblCard3Suit.Location = new System.Drawing.Point(6, 39);
			this.lblCard3Suit.Name = "lblCard3Suit";
			this.lblCard3Suit.Size = new System.Drawing.Size(25, 13);
			this.lblCard3Suit.TabIndex = 1;
			this.lblCard3Suit.Text = "Suit";
			// 
			// lblCard3Num
			// 
			this.lblCard3Num.AutoSize = true;
			this.lblCard3Num.Location = new System.Drawing.Point(6, 16);
			this.lblCard3Num.Name = "lblCard3Num";
			this.lblCard3Num.Size = new System.Drawing.Size(29, 13);
			this.lblCard3Num.TabIndex = 1;
			this.lblCard3Num.Text = "Num";
			// 
			// grbCard4
			// 
			this.grbCard4.Controls.Add(this.lblCard4Suit);
			this.grbCard4.Controls.Add(this.lblCard4Num);
			this.grbCard4.Location = new System.Drawing.Point(162, 14);
			this.grbCard4.Name = "grbCard4";
			this.grbCard4.Size = new System.Drawing.Size(57, 69);
			this.grbCard4.TabIndex = 3;
			this.grbCard4.TabStop = false;
			this.grbCard4.Text = "Card 4";
			// 
			// lblCard4Suit
			// 
			this.lblCard4Suit.AutoSize = true;
			this.lblCard4Suit.Location = new System.Drawing.Point(6, 39);
			this.lblCard4Suit.Name = "lblCard4Suit";
			this.lblCard4Suit.Size = new System.Drawing.Size(25, 13);
			this.lblCard4Suit.TabIndex = 1;
			this.lblCard4Suit.Text = "Suit";
			// 
			// lblCard4Num
			// 
			this.lblCard4Num.AutoSize = true;
			this.lblCard4Num.Location = new System.Drawing.Point(6, 16);
			this.lblCard4Num.Name = "lblCard4Num";
			this.lblCard4Num.Size = new System.Drawing.Size(29, 13);
			this.lblCard4Num.TabIndex = 1;
			this.lblCard4Num.Text = "Num";
			// 
			// grbCard5
			// 
			this.grbCard5.Controls.Add(this.lblCard5Suit);
			this.grbCard5.Controls.Add(this.lblCard5Num);
			this.grbCard5.Location = new System.Drawing.Point(215, 14);
			this.grbCard5.Name = "grbCard5";
			this.grbCard5.Size = new System.Drawing.Size(57, 69);
			this.grbCard5.TabIndex = 3;
			this.grbCard5.TabStop = false;
			this.grbCard5.Text = "Card 5";
			// 
			// lblCard5Suit
			// 
			this.lblCard5Suit.AutoSize = true;
			this.lblCard5Suit.Location = new System.Drawing.Point(6, 39);
			this.lblCard5Suit.Name = "lblCard5Suit";
			this.lblCard5Suit.Size = new System.Drawing.Size(25, 13);
			this.lblCard5Suit.TabIndex = 1;
			this.lblCard5Suit.Text = "Suit";
			// 
			// lblCard5Num
			// 
			this.lblCard5Num.AutoSize = true;
			this.lblCard5Num.Location = new System.Drawing.Point(6, 16);
			this.lblCard5Num.Name = "lblCard5Num";
			this.lblCard5Num.Size = new System.Drawing.Size(29, 13);
			this.lblCard5Num.TabIndex = 1;
			this.lblCard5Num.Text = "Num";
			// 
			// grbHand
			// 
			this.grbHand.Controls.Add(this.grbCard5);
			this.grbHand.Controls.Add(this.grbCard4);
			this.grbHand.Controls.Add(this.grbCard3);
			this.grbHand.Controls.Add(this.grbCard2);
			this.grbHand.Controls.Add(this.grbCard1);
			this.grbHand.Location = new System.Drawing.Point(257, 12);
			this.grbHand.Name = "grbHand";
			this.grbHand.Size = new System.Drawing.Size(279, 89);
			this.grbHand.TabIndex = 4;
			this.grbHand.TabStop = false;
			this.grbHand.Text = "Hand";
			this.grbHand.Visible = false;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.WhiteSmoke;
			this.ClientSize = new System.Drawing.Size(578, 437);
			this.Controls.Add(this.grbHand);
			this.Controls.Add(this.grbResults);
			this.Controls.Add(this.grbControls);
			this.Name = "Form1";
			this.Text = "Poker";
			this.grbControls.ResumeLayout(false);
			this.grbResults.ResumeLayout(false);
			this.grbResults.PerformLayout();
			this.grbCard1.ResumeLayout(false);
			this.grbCard1.PerformLayout();
			this.grbCard2.ResumeLayout(false);
			this.grbCard2.PerformLayout();
			this.grbCard3.ResumeLayout(false);
			this.grbCard3.PerformLayout();
			this.grbCard4.ResumeLayout(false);
			this.grbCard4.PerformLayout();
			this.grbCard5.ResumeLayout(false);
			this.grbCard5.PerformLayout();
			this.grbHand.ResumeLayout(false);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button btnShuffle;
		private System.Windows.Forms.Button btnDeal;
		private System.Windows.Forms.GroupBox grbControls;
		private System.Windows.Forms.GroupBox grbResults;
		private System.Windows.Forms.Label lblResults;
		private System.Windows.Forms.GroupBox grbCard1;
		private System.Windows.Forms.GroupBox grbCard2;
		private System.Windows.Forms.GroupBox grbCard3;
		private System.Windows.Forms.GroupBox grbCard4;
		private System.Windows.Forms.GroupBox grbCard5;
		private System.Windows.Forms.GroupBox grbHand;
		private System.Windows.Forms.Label lblCard1Num;
		private System.Windows.Forms.Label lblCard2Num;
		private System.Windows.Forms.Label lblCard3Num;
		private System.Windows.Forms.Label lblCard4Num;
		private System.Windows.Forms.Label lblCard5Num;
		private System.Windows.Forms.Label lblCard1Suit;
		private System.Windows.Forms.Label lblCard2Suit;
		private System.Windows.Forms.Label lblCard3Suit;
		private System.Windows.Forms.Label lblCard4Suit;
		private System.Windows.Forms.Label lblCard5Suit;
	}
}

