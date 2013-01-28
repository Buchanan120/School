namespace Genetic_Algorithm
{
    partial class GA
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
			this.textTargetValue = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.textNumCoins = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.textPopulationSize = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.textMutationRate = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.textElitism = new System.Windows.Forms.TextBox();
			this.checkPennies = new System.Windows.Forms.CheckBox();
			this.checkNickels = new System.Windows.Forms.CheckBox();
			this.checkDimes = new System.Windows.Forms.CheckBox();
			this.checkQuarters = new System.Windows.Forms.CheckBox();
			this.checkHalfDollars = new System.Windows.Forms.CheckBox();
			this.checkDollars = new System.Windows.Forms.CheckBox();
			this.buttonInitialize = new System.Windows.Forms.Button();
			this.buttonRun = new System.Windows.Forms.Button();
			this.label6 = new System.Windows.Forms.Label();
			this.textNumGenerations = new System.Windows.Forms.TextBox();
			this.checkStopAtTarget = new System.Windows.Forms.CheckBox();
			this.textOutput = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// textTargetValue
			// 
			this.textTargetValue.Location = new System.Drawing.Point(599, 12);
			this.textTargetValue.Name = "textTargetValue";
			this.textTargetValue.Size = new System.Drawing.Size(100, 20);
			this.textTargetValue.TabIndex = 1;
			this.textTargetValue.Text = "500";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(705, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(68, 13);
			this.label1.TabIndex = 2;
			this.label1.Text = "Target Value";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(705, 38);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(85, 13);
			this.label2.TabIndex = 4;
			this.label2.Text = "Number of Coins";
			// 
			// textNumCoins
			// 
			this.textNumCoins.Location = new System.Drawing.Point(599, 38);
			this.textNumCoins.Name = "textNumCoins";
			this.textNumCoins.Size = new System.Drawing.Size(100, 20);
			this.textNumCoins.TabIndex = 3;
			this.textNumCoins.Text = "100";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(705, 64);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(80, 13);
			this.label3.TabIndex = 6;
			this.label3.Text = "Population Size";
			// 
			// textPopulationSize
			// 
			this.textPopulationSize.Location = new System.Drawing.Point(599, 64);
			this.textPopulationSize.Name = "textPopulationSize";
			this.textPopulationSize.Size = new System.Drawing.Size(100, 20);
			this.textPopulationSize.TabIndex = 5;
			this.textPopulationSize.Text = "50";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(705, 90);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(74, 13);
			this.label4.TabIndex = 8;
			this.label4.Text = "Mutation Rate";
			// 
			// textMutationRate
			// 
			this.textMutationRate.Location = new System.Drawing.Point(599, 90);
			this.textMutationRate.Name = "textMutationRate";
			this.textMutationRate.Size = new System.Drawing.Size(100, 20);
			this.textMutationRate.TabIndex = 7;
			this.textMutationRate.Text = "0.02";
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(705, 116);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(36, 13);
			this.label5.TabIndex = 10;
			this.label5.Text = "Elitism";
			// 
			// textElitism
			// 
			this.textElitism.Location = new System.Drawing.Point(599, 116);
			this.textElitism.Name = "textElitism";
			this.textElitism.Size = new System.Drawing.Size(100, 20);
			this.textElitism.TabIndex = 9;
			this.textElitism.Text = "0.1";
			// 
			// checkPennies
			// 
			this.checkPennies.AutoSize = true;
			this.checkPennies.Checked = true;
			this.checkPennies.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkPennies.Location = new System.Drawing.Point(686, 142);
			this.checkPennies.Name = "checkPennies";
			this.checkPennies.Size = new System.Drawing.Size(63, 17);
			this.checkPennies.TabIndex = 11;
			this.checkPennies.Text = "pennies";
			this.checkPennies.UseVisualStyleBackColor = true;
			// 
			// checkNickels
			// 
			this.checkNickels.AutoSize = true;
			this.checkNickels.Location = new System.Drawing.Point(686, 165);
			this.checkNickels.Name = "checkNickels";
			this.checkNickels.Size = new System.Drawing.Size(59, 17);
			this.checkNickels.TabIndex = 12;
			this.checkNickels.Text = "nickels";
			this.checkNickels.UseVisualStyleBackColor = true;
			// 
			// checkDimes
			// 
			this.checkDimes.AutoSize = true;
			this.checkDimes.Checked = true;
			this.checkDimes.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkDimes.Location = new System.Drawing.Point(686, 188);
			this.checkDimes.Name = "checkDimes";
			this.checkDimes.Size = new System.Drawing.Size(53, 17);
			this.checkDimes.TabIndex = 13;
			this.checkDimes.Text = "dimes";
			this.checkDimes.UseVisualStyleBackColor = true;
			// 
			// checkQuarters
			// 
			this.checkQuarters.AutoSize = true;
			this.checkQuarters.Checked = true;
			this.checkQuarters.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkQuarters.Location = new System.Drawing.Point(686, 211);
			this.checkQuarters.Name = "checkQuarters";
			this.checkQuarters.Size = new System.Drawing.Size(64, 17);
			this.checkQuarters.TabIndex = 14;
			this.checkQuarters.Text = "quarters";
			this.checkQuarters.UseVisualStyleBackColor = true;
			// 
			// checkHalfDollars
			// 
			this.checkHalfDollars.AutoSize = true;
			this.checkHalfDollars.Checked = true;
			this.checkHalfDollars.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkHalfDollars.Location = new System.Drawing.Point(686, 234);
			this.checkHalfDollars.Name = "checkHalfDollars";
			this.checkHalfDollars.Size = new System.Drawing.Size(76, 17);
			this.checkHalfDollars.TabIndex = 15;
			this.checkHalfDollars.Text = "half dollars";
			this.checkHalfDollars.UseVisualStyleBackColor = true;
			// 
			// checkDollars
			// 
			this.checkDollars.AutoSize = true;
			this.checkDollars.Checked = true;
			this.checkDollars.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkDollars.Location = new System.Drawing.Point(686, 257);
			this.checkDollars.Name = "checkDollars";
			this.checkDollars.Size = new System.Drawing.Size(56, 17);
			this.checkDollars.TabIndex = 16;
			this.checkDollars.Text = "dollars";
			this.checkDollars.UseVisualStyleBackColor = true;
			// 
			// buttonInitialize
			// 
			this.buttonInitialize.Location = new System.Drawing.Point(724, 362);
			this.buttonInitialize.Name = "buttonInitialize";
			this.buttonInitialize.Size = new System.Drawing.Size(119, 23);
			this.buttonInitialize.TabIndex = 17;
			this.buttonInitialize.Text = "Clear and Initialize";
			this.buttonInitialize.UseVisualStyleBackColor = true;
			this.buttonInitialize.Click += new System.EventHandler(this.buttonInitialize_Click);
			// 
			// buttonRun
			// 
			this.buttonRun.Location = new System.Drawing.Point(599, 362);
			this.buttonRun.Name = "buttonRun";
			this.buttonRun.Size = new System.Drawing.Size(119, 23);
			this.buttonRun.TabIndex = 19;
			this.buttonRun.Text = "Run";
			this.buttonRun.UseVisualStyleBackColor = true;
			this.buttonRun.Click += new System.EventHandler(this.buttonRun_Click);
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(705, 315);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(116, 13);
			this.label6.TabIndex = 21;
			this.label6.Text = "Number of Generations";
			// 
			// textNumGenerations
			// 
			this.textNumGenerations.Location = new System.Drawing.Point(599, 315);
			this.textNumGenerations.Name = "textNumGenerations";
			this.textNumGenerations.Size = new System.Drawing.Size(100, 20);
			this.textNumGenerations.TabIndex = 20;
			this.textNumGenerations.Text = "100";
			// 
			// checkStopAtTarget
			// 
			this.checkStopAtTarget.AutoSize = true;
			this.checkStopAtTarget.Checked = true;
			this.checkStopAtTarget.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkStopAtTarget.Location = new System.Drawing.Point(686, 341);
			this.checkStopAtTarget.Name = "checkStopAtTarget";
			this.checkStopAtTarget.Size = new System.Drawing.Size(161, 17);
			this.checkStopAtTarget.TabIndex = 22;
			this.checkStopAtTarget.Text = "Stop When Target Reached";
			this.checkStopAtTarget.UseVisualStyleBackColor = true;
			// 
			// textOutput
			// 
			this.textOutput.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.textOutput.Location = new System.Drawing.Point(12, 12);
			this.textOutput.Multiline = true;
			this.textOutput.Name = "textOutput";
			this.textOutput.Size = new System.Drawing.Size(581, 723);
			this.textOutput.TabIndex = 24;
			// 
			// GA
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(855, 747);
			this.Controls.Add(this.textOutput);
			this.Controls.Add(this.checkStopAtTarget);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.textNumGenerations);
			this.Controls.Add(this.buttonRun);
			this.Controls.Add(this.buttonInitialize);
			this.Controls.Add(this.checkDollars);
			this.Controls.Add(this.checkHalfDollars);
			this.Controls.Add(this.checkQuarters);
			this.Controls.Add(this.checkDimes);
			this.Controls.Add(this.checkNickels);
			this.Controls.Add(this.checkPennies);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.textElitism);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.textMutationRate);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.textPopulationSize);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.textNumCoins);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.textTargetValue);
			this.Name = "GA";
			this.Text = "Coins Genetic Algorithm";
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textTargetValue;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textNumCoins;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textPopulationSize;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textMutationRate;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textElitism;
        private System.Windows.Forms.CheckBox checkPennies;
        private System.Windows.Forms.CheckBox checkNickels;
        private System.Windows.Forms.CheckBox checkDimes;
        private System.Windows.Forms.CheckBox checkQuarters;
        private System.Windows.Forms.CheckBox checkHalfDollars;
        private System.Windows.Forms.CheckBox checkDollars;
        private System.Windows.Forms.Button buttonInitialize;
        private System.Windows.Forms.Button buttonRun;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textNumGenerations;
        private System.Windows.Forms.CheckBox checkStopAtTarget;
		private System.Windows.Forms.TextBox textOutput;
    }
}

