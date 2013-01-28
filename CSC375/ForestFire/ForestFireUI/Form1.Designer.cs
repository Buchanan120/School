namespace ForestFire
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
			this.components = new System.ComponentModel.Container();
			this.gridBox = new System.Windows.Forms.PictureBox();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.uiGrassToGrass = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.uiGrassToBrush = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.uiGrassToTree = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.uiGrassBurnTime = new System.Windows.Forms.NumericUpDown();
			this.uiBrushBurnTime = new System.Windows.Forms.NumericUpDown();
			this.uiTreeBurnTime = new System.Windows.Forms.NumericUpDown();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.uiBrushToGrass = new System.Windows.Forms.TextBox();
			this.label10 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.uiBrushToBrush = new System.Windows.Forms.TextBox();
			this.label12 = new System.Windows.Forms.Label();
			this.uiBrushToTree = new System.Windows.Forms.TextBox();
			this.uiTreeToGrass = new System.Windows.Forms.TextBox();
			this.label13 = new System.Windows.Forms.Label();
			this.label14 = new System.Windows.Forms.Label();
			this.uiTreeToBrush = new System.Windows.Forms.TextBox();
			this.label15 = new System.Windows.Forms.Label();
			this.uiTreeToTree = new System.Windows.Forms.TextBox();
			this.uiUpdateStyle = new System.Windows.Forms.ComboBox();
			this.label7 = new System.Windows.Forms.Label();
			this.btnInitialize = new System.Windows.Forms.Button();
			this.btnRun = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.gridBox)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.uiGrassBurnTime)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.uiBrushBurnTime)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.uiTreeBurnTime)).BeginInit();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// gridBox
			// 
			this.gridBox.Location = new System.Drawing.Point(12, 12);
			this.gridBox.Name = "gridBox";
			this.gridBox.Size = new System.Drawing.Size(800, 800);
			this.gridBox.TabIndex = 0;
			this.gridBox.TabStop = false;
			// 
			// timer1
			// 
			this.timer1.Interval = 2000;
			this.timer1.Tick += new System.EventHandler(this.stepSimulation);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(845, 36);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(85, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "Grass Burn Time";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(845, 62);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(85, 13);
			this.label2.TabIndex = 3;
			this.label2.Text = "Brush Burn Time";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(850, 91);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(80, 13);
			this.label3.TabIndex = 5;
			this.label3.Text = "Tree Burn Time";
			// 
			// uiGrassToGrass
			// 
			this.uiGrassToGrass.Location = new System.Drawing.Point(94, 19);
			this.uiGrassToGrass.Name = "uiGrassToGrass";
			this.uiGrassToGrass.Size = new System.Drawing.Size(100, 20);
			this.uiGrassToGrass.TabIndex = 8;
			this.uiGrassToGrass.Text = "0.8";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(12, 22);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(76, 13);
			this.label4.TabIndex = 7;
			this.label4.Text = "Grass to Grass";
			// 
			// uiGrassToBrush
			// 
			this.uiGrassToBrush.Location = new System.Drawing.Point(94, 45);
			this.uiGrassToBrush.Name = "uiGrassToBrush";
			this.uiGrassToBrush.Size = new System.Drawing.Size(100, 20);
			this.uiGrassToBrush.TabIndex = 10;
			this.uiGrassToBrush.Text = "0.6";
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(12, 48);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(76, 13);
			this.label5.TabIndex = 9;
			this.label5.Text = "Grass to Brush";
			// 
			// uiGrassToTree
			// 
			this.uiGrassToTree.Location = new System.Drawing.Point(94, 71);
			this.uiGrassToTree.Name = "uiGrassToTree";
			this.uiGrassToTree.Size = new System.Drawing.Size(100, 20);
			this.uiGrassToTree.TabIndex = 12;
			this.uiGrassToTree.Text = "0.1";
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(17, 74);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(71, 13);
			this.label6.TabIndex = 11;
			this.label6.Text = "Grass to Tree";
			// 
			// uiGrassBurnTime
			// 
			this.uiGrassBurnTime.Location = new System.Drawing.Point(936, 34);
			this.uiGrassBurnTime.Name = "uiGrassBurnTime";
			this.uiGrassBurnTime.Size = new System.Drawing.Size(100, 20);
			this.uiGrassBurnTime.TabIndex = 19;
			this.uiGrassBurnTime.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
			// 
			// uiBrushBurnTime
			// 
			this.uiBrushBurnTime.Location = new System.Drawing.Point(936, 60);
			this.uiBrushBurnTime.Name = "uiBrushBurnTime";
			this.uiBrushBurnTime.Size = new System.Drawing.Size(100, 20);
			this.uiBrushBurnTime.TabIndex = 20;
			this.uiBrushBurnTime.Value = new decimal(new int[] {
            6,
            0,
            0,
            0});
			// 
			// uiTreeBurnTime
			// 
			this.uiTreeBurnTime.Location = new System.Drawing.Point(936, 89);
			this.uiTreeBurnTime.Name = "uiTreeBurnTime";
			this.uiTreeBurnTime.Size = new System.Drawing.Size(100, 20);
			this.uiTreeBurnTime.TabIndex = 21;
			this.uiTreeBurnTime.Value = new decimal(new int[] {
            15,
            0,
            0,
            0});
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.uiTreeToGrass);
			this.groupBox1.Controls.Add(this.label13);
			this.groupBox1.Controls.Add(this.label14);
			this.groupBox1.Controls.Add(this.uiTreeToBrush);
			this.groupBox1.Controls.Add(this.label15);
			this.groupBox1.Controls.Add(this.uiTreeToTree);
			this.groupBox1.Controls.Add(this.uiBrushToGrass);
			this.groupBox1.Controls.Add(this.label10);
			this.groupBox1.Controls.Add(this.label11);
			this.groupBox1.Controls.Add(this.uiBrushToBrush);
			this.groupBox1.Controls.Add(this.label12);
			this.groupBox1.Controls.Add(this.uiBrushToTree);
			this.groupBox1.Controls.Add(this.uiGrassToGrass);
			this.groupBox1.Controls.Add(this.label4);
			this.groupBox1.Controls.Add(this.label5);
			this.groupBox1.Controls.Add(this.uiGrassToBrush);
			this.groupBox1.Controls.Add(this.label6);
			this.groupBox1.Controls.Add(this.uiGrassToTree);
			this.groupBox1.Location = new System.Drawing.Point(848, 115);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(200, 256);
			this.groupBox1.TabIndex = 22;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Chance to Spread";
			// 
			// uiBrushToGrass
			// 
			this.uiBrushToGrass.Location = new System.Drawing.Point(94, 97);
			this.uiBrushToGrass.Name = "uiBrushToGrass";
			this.uiBrushToGrass.Size = new System.Drawing.Size(100, 20);
			this.uiBrushToGrass.TabIndex = 14;
			this.uiBrushToGrass.Text = "0.9";
			// 
			// label10
			// 
			this.label10.AutoSize = true;
			this.label10.Location = new System.Drawing.Point(12, 100);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(76, 13);
			this.label10.TabIndex = 13;
			this.label10.Text = "Brush to Grass";
			// 
			// label11
			// 
			this.label11.AutoSize = true;
			this.label11.Location = new System.Drawing.Point(12, 126);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(76, 13);
			this.label11.TabIndex = 15;
			this.label11.Text = "Brush to Brush";
			// 
			// uiBrushToBrush
			// 
			this.uiBrushToBrush.Location = new System.Drawing.Point(94, 123);
			this.uiBrushToBrush.Name = "uiBrushToBrush";
			this.uiBrushToBrush.Size = new System.Drawing.Size(100, 20);
			this.uiBrushToBrush.TabIndex = 16;
			this.uiBrushToBrush.Text = "0.75";
			// 
			// label12
			// 
			this.label12.AutoSize = true;
			this.label12.Location = new System.Drawing.Point(17, 152);
			this.label12.Name = "label12";
			this.label12.Size = new System.Drawing.Size(71, 13);
			this.label12.TabIndex = 17;
			this.label12.Text = "Brush to Tree";
			// 
			// uiBrushToTree
			// 
			this.uiBrushToTree.Location = new System.Drawing.Point(94, 149);
			this.uiBrushToTree.Name = "uiBrushToTree";
			this.uiBrushToTree.Size = new System.Drawing.Size(100, 20);
			this.uiBrushToTree.TabIndex = 18;
			this.uiBrushToTree.Text = "0.25";
			// 
			// uiTreeToGrass
			// 
			this.uiTreeToGrass.Location = new System.Drawing.Point(94, 175);
			this.uiTreeToGrass.Name = "uiTreeToGrass";
			this.uiTreeToGrass.Size = new System.Drawing.Size(100, 20);
			this.uiTreeToGrass.TabIndex = 20;
			this.uiTreeToGrass.Text = "0.99";
			// 
			// label13
			// 
			this.label13.AutoSize = true;
			this.label13.Location = new System.Drawing.Point(12, 178);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(71, 13);
			this.label13.TabIndex = 19;
			this.label13.Text = "Tree to Grass";
			// 
			// label14
			// 
			this.label14.AutoSize = true;
			this.label14.Location = new System.Drawing.Point(12, 204);
			this.label14.Name = "label14";
			this.label14.Size = new System.Drawing.Size(71, 13);
			this.label14.TabIndex = 21;
			this.label14.Text = "Tree to Brush";
			// 
			// uiTreeToBrush
			// 
			this.uiTreeToBrush.Location = new System.Drawing.Point(94, 201);
			this.uiTreeToBrush.Name = "uiTreeToBrush";
			this.uiTreeToBrush.Size = new System.Drawing.Size(100, 20);
			this.uiTreeToBrush.TabIndex = 22;
			this.uiTreeToBrush.Text = "0.9";
			// 
			// label15
			// 
			this.label15.AutoSize = true;
			this.label15.Location = new System.Drawing.Point(17, 230);
			this.label15.Name = "label15";
			this.label15.Size = new System.Drawing.Size(66, 13);
			this.label15.TabIndex = 23;
			this.label15.Text = "Tree to Tree";
			// 
			// uiTreeToTree
			// 
			this.uiTreeToTree.Location = new System.Drawing.Point(94, 227);
			this.uiTreeToTree.Name = "uiTreeToTree";
			this.uiTreeToTree.Size = new System.Drawing.Size(100, 20);
			this.uiTreeToTree.TabIndex = 24;
			this.uiTreeToTree.Text = "0.5";
			// 
			// uiUpdateStyle
			// 
			this.uiUpdateStyle.FormattingEnabled = true;
			this.uiUpdateStyle.Items.AddRange(new object[] {
            "Synchronous",
            "Asynchronous"});
			this.uiUpdateStyle.Location = new System.Drawing.Point(915, 383);
			this.uiUpdateStyle.Name = "uiUpdateStyle";
			this.uiUpdateStyle.Size = new System.Drawing.Size(121, 21);
			this.uiUpdateStyle.TabIndex = 23;
			this.uiUpdateStyle.Text = "Synchronous";
			// 
			// label7
			// 
			this.label7.AutoSize = true;
			this.label7.Location = new System.Drawing.Point(841, 386);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(68, 13);
			this.label7.TabIndex = 25;
			this.label7.Text = "Update Style";
			// 
			// btnInitialize
			// 
			this.btnInitialize.Location = new System.Drawing.Point(880, 434);
			this.btnInitialize.Name = "btnInitialize";
			this.btnInitialize.Size = new System.Drawing.Size(75, 23);
			this.btnInitialize.TabIndex = 26;
			this.btnInitialize.Text = "Initialize";
			this.btnInitialize.UseVisualStyleBackColor = true;
			this.btnInitialize.Click += new System.EventHandler(this.btnInitialize_Click);
			// 
			// btnRun
			// 
			this.btnRun.Location = new System.Drawing.Point(961, 434);
			this.btnRun.Name = "btnRun";
			this.btnRun.Size = new System.Drawing.Size(75, 23);
			this.btnRun.TabIndex = 27;
			this.btnRun.Text = "Run";
			this.btnRun.UseVisualStyleBackColor = true;
			this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1109, 862);
			this.Controls.Add(this.btnRun);
			this.Controls.Add(this.btnInitialize);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.uiUpdateStyle);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.uiTreeBurnTime);
			this.Controls.Add(this.uiBrushBurnTime);
			this.Controls.Add(this.uiGrassBurnTime);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.gridBox);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.gridBox)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.uiGrassBurnTime)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.uiBrushBurnTime)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.uiTreeBurnTime)).EndInit();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox gridBox;
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox uiGrassToGrass;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox uiGrassToBrush;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox uiGrassToTree;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.NumericUpDown uiGrassBurnTime;
		private System.Windows.Forms.NumericUpDown uiBrushBurnTime;
		private System.Windows.Forms.NumericUpDown uiTreeBurnTime;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.TextBox uiTreeToGrass;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.Label label14;
		private System.Windows.Forms.TextBox uiTreeToBrush;
		private System.Windows.Forms.Label label15;
		private System.Windows.Forms.TextBox uiTreeToTree;
		private System.Windows.Forms.TextBox uiBrushToGrass;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.TextBox uiBrushToBrush;
		private System.Windows.Forms.Label label12;
		private System.Windows.Forms.TextBox uiBrushToTree;
		private System.Windows.Forms.ComboBox uiUpdateStyle;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.Button btnInitialize;
		private System.Windows.Forms.Button btnRun;
	}
}

