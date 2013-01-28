namespace GetTicks
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
            this.label1 = new System.Windows.Forms.Label();
            this.labelMinutes = new System.Windows.Forms.Label();
            this.labelSeconds = new System.Windows.Forms.Label();
            this.labelTicks = new System.Windows.Forms.Label();
            this.textHours = new System.Windows.Forms.TextBox();
            this.textMinutes = new System.Windows.Forms.TextBox();
            this.textSeconds = new System.Windows.Forms.TextBox();
            this.textTicks = new System.Windows.Forms.TextBox();
            this.buttonCalculate = new System.Windows.Forms.Button();
            this.textResult = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Hours";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // labelMinutes
            // 
            this.labelMinutes.AutoSize = true;
            this.labelMinutes.Location = new System.Drawing.Point(24, 56);
            this.labelMinutes.Name = "labelMinutes";
            this.labelMinutes.Size = new System.Drawing.Size(44, 13);
            this.labelMinutes.TabIndex = 1;
            this.labelMinutes.Text = "Minutes";
            this.labelMinutes.Click += new System.EventHandler(this.labelMinutes_Click);
            // 
            // labelSeconds
            // 
            this.labelSeconds.AutoSize = true;
            this.labelSeconds.Location = new System.Drawing.Point(24, 83);
            this.labelSeconds.Name = "labelSeconds";
            this.labelSeconds.Size = new System.Drawing.Size(49, 13);
            this.labelSeconds.TabIndex = 2;
            this.labelSeconds.Text = "Seconds";
            this.labelSeconds.Click += new System.EventHandler(this.labelSeconds_Click);
            // 
            // labelTicks
            // 
            this.labelTicks.AutoSize = true;
            this.labelTicks.Location = new System.Drawing.Point(24, 110);
            this.labelTicks.Name = "labelTicks";
            this.labelTicks.Size = new System.Drawing.Size(33, 13);
            this.labelTicks.TabIndex = 3;
            this.labelTicks.Text = "Ticks";
            this.labelTicks.Click += new System.EventHandler(this.labelTicks_Click);
            // 
            // textHours
            // 
            this.textHours.Location = new System.Drawing.Point(76, 29);
            this.textHours.Name = "textHours";
            this.textHours.Size = new System.Drawing.Size(100, 20);
            this.textHours.TabIndex = 4;
            this.textHours.Text = "0";
            this.textHours.TextChanged += new System.EventHandler(this.textHours_TextChanged);
            // 
            // textMinutes
            // 
            this.textMinutes.Location = new System.Drawing.Point(77, 56);
            this.textMinutes.Name = "textMinutes";
            this.textMinutes.Size = new System.Drawing.Size(100, 20);
            this.textMinutes.TabIndex = 5;
            this.textMinutes.Text = "0";
            this.textMinutes.TextChanged += new System.EventHandler(this.textMinutes_TextChanged);
            // 
            // textSeconds
            // 
            this.textSeconds.Location = new System.Drawing.Point(77, 83);
            this.textSeconds.Name = "textSeconds";
            this.textSeconds.Size = new System.Drawing.Size(100, 20);
            this.textSeconds.TabIndex = 6;
            this.textSeconds.Text = "0";
            this.textSeconds.TextChanged += new System.EventHandler(this.textSeconds_TextChanged);
            // 
            // textTicks
            // 
            this.textTicks.Location = new System.Drawing.Point(77, 110);
            this.textTicks.Name = "textTicks";
            this.textTicks.Size = new System.Drawing.Size(100, 20);
            this.textTicks.TabIndex = 7;
            this.textTicks.Text = "0";
            this.textTicks.TextChanged += new System.EventHandler(this.textTicks_TextChanged);
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Location = new System.Drawing.Point(182, 137);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(75, 23);
            this.buttonCalculate.TabIndex = 8;
            this.buttonCalculate.Text = "Calculate!";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // textResult
            // 
            this.textResult.Location = new System.Drawing.Point(76, 137);
            this.textResult.Name = "textResult";
            this.textResult.Size = new System.Drawing.Size(100, 20);
            this.textResult.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(272, 167);
            this.Controls.Add(this.textResult);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.textTicks);
            this.Controls.Add(this.textSeconds);
            this.Controls.Add(this.textMinutes);
            this.Controls.Add(this.textHours);
            this.Controls.Add(this.labelTicks);
            this.Controls.Add(this.labelSeconds);
            this.Controls.Add(this.labelMinutes);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Ticks Calculator";
            this.Load += new System.EventHandler(this.labelHours_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelMinutes;
        private System.Windows.Forms.Label labelSeconds;
        private System.Windows.Forms.Label labelTicks;
        private System.Windows.Forms.TextBox textHours;
        private System.Windows.Forms.TextBox textMinutes;
        private System.Windows.Forms.TextBox textSeconds;
        private System.Windows.Forms.TextBox textTicks;
        private System.Windows.Forms.Button buttonCalculate;
        private System.Windows.Forms.TextBox textResult;
    }
}

