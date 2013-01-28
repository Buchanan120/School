namespace Ant_Pheromone_Trails
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
			this.picture = new System.Windows.Forms.PictureBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.textNumAnts = new System.Windows.Forms.TextBox();
			this.textNumFood = new System.Windows.Forms.TextBox();
			this.textFoodPerPile = new System.Windows.Forms.TextBox();
			this.buttonRun = new System.Windows.Forms.Button();
			this.buttonInitialize = new System.Windows.Forms.Button();
			this.buttonStop = new System.Windows.Forms.Button();
			this.graph = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.picture)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.graph)).BeginInit();
			this.SuspendLayout();
			// 
			// picture
			// 
			this.picture.InitialImage = null;
			this.picture.Location = new System.Drawing.Point(12, 12);
			this.picture.Name = "picture";
			this.picture.Size = new System.Drawing.Size(500, 505);
			this.picture.TabIndex = 0;
			this.picture.TabStop = false;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(518, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(80, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "Number of Ants";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(518, 53);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(108, 13);
			this.label2.TabIndex = 2;
			this.label2.Text = "Number of Food Piles";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(518, 99);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(70, 13);
			this.label3.TabIndex = 3;
			this.label3.Text = "Food Per Pile";
			// 
			// textNumAnts
			// 
			this.textNumAnts.Location = new System.Drawing.Point(521, 29);
			this.textNumAnts.Name = "textNumAnts";
			this.textNumAnts.Size = new System.Drawing.Size(97, 20);
			this.textNumAnts.TabIndex = 7;
			this.textNumAnts.Text = "100";
			// 
			// textNumFood
			// 
			this.textNumFood.Location = new System.Drawing.Point(521, 69);
			this.textNumFood.Name = "textNumFood";
			this.textNumFood.Size = new System.Drawing.Size(97, 20);
			this.textNumFood.TabIndex = 8;
			this.textNumFood.Text = "3";
			// 
			// textFoodPerPile
			// 
			this.textFoodPerPile.Location = new System.Drawing.Point(521, 115);
			this.textFoodPerPile.Name = "textFoodPerPile";
			this.textFoodPerPile.Size = new System.Drawing.Size(97, 20);
			this.textFoodPerPile.TabIndex = 9;
			this.textFoodPerPile.Text = "50";
			// 
			// buttonRun
			// 
			this.buttonRun.Location = new System.Drawing.Point(525, 250);
			this.buttonRun.Name = "buttonRun";
			this.buttonRun.Size = new System.Drawing.Size(93, 47);
			this.buttonRun.TabIndex = 12;
			this.buttonRun.Text = "Run";
			this.buttonRun.UseVisualStyleBackColor = true;
			this.buttonRun.Click += new System.EventHandler(this.buttonRun_Click);
			// 
			// buttonInitialize
			// 
			this.buttonInitialize.Location = new System.Drawing.Point(525, 182);
			this.buttonInitialize.Name = "buttonInitialize";
			this.buttonInitialize.Size = new System.Drawing.Size(93, 23);
			this.buttonInitialize.TabIndex = 13;
			this.buttonInitialize.Text = "Initialize";
			this.buttonInitialize.UseVisualStyleBackColor = true;
			this.buttonInitialize.Click += new System.EventHandler(this.buttonInitialize_Click);
			// 
			// buttonStop
			// 
			this.buttonStop.Location = new System.Drawing.Point(525, 303);
			this.buttonStop.Name = "buttonStop";
			this.buttonStop.Size = new System.Drawing.Size(93, 23);
			this.buttonStop.TabIndex = 14;
			this.buttonStop.Text = "Stop";
			this.buttonStop.UseVisualStyleBackColor = true;
			this.buttonStop.Visible = false;
			this.buttonStop.Click += new System.EventHandler(this.buttonStop_Click);
			// 
			// graph
			// 
			this.graph.InitialImage = null;
			this.graph.Location = new System.Drawing.Point(525, 365);
			this.graph.Name = "graph";
			this.graph.Size = new System.Drawing.Size(275, 152);
			this.graph.TabIndex = 15;
			this.graph.TabStop = false;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(812, 530);
			this.Controls.Add(this.graph);
			this.Controls.Add(this.buttonStop);
			this.Controls.Add(this.buttonInitialize);
			this.Controls.Add(this.buttonRun);
			this.Controls.Add(this.textFoodPerPile);
			this.Controls.Add(this.textNumFood);
			this.Controls.Add(this.textNumAnts);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.picture);
			this.Name = "Form1";
			this.Text = "Pheremone Trails";
			((System.ComponentModel.ISupportInitialize)(this.picture)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.graph)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox picture;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox textNumAnts;
		private System.Windows.Forms.TextBox textNumFood;
		private System.Windows.Forms.TextBox textFoodPerPile;
		private System.Windows.Forms.Button buttonRun;
		private System.Windows.Forms.Button buttonInitialize;
		private System.Windows.Forms.Button buttonStop;
		private System.Windows.Forms.PictureBox graph;
	}
}

