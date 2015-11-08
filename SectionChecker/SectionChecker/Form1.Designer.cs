// Desingerで使う関数

namespace SectionChecker
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem(new string[] {
            "Name"}, -1, System.Drawing.Color.Empty, System.Drawing.Color.Empty, new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128))));
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("ID");
            this.MenuSt = new System.Windows.Forms.MenuStrip();
            this.MenuStFile = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuStFOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuStFExit = new System.Windows.Forms.ToolStripMenuItem();
            this.ヘルプHToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.まにゅあるToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.バージョン情報ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.TB_FPath = new System.Windows.Forms.TextBox();
            this.listView = new System.Windows.Forms.ListView();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.StatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.BTN_SFLoad = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.CB_EX_SHEET = new System.Windows.Forms.ComboBox();
            this.TB_EX_SERACH = new System.Windows.Forms.TextBox();
            this.BTN_EFLoadTo = new System.Windows.Forms.Button();
            this.LV_InExl = new System.Windows.Forms.ListView();
            this.BTN_EFLoad = new System.Windows.Forms.Button();
            this.TB_ExcelPath = new System.Windows.Forms.TextBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.CB_EX_COLNAME = new System.Windows.Forms.ComboBox();
            this.BTN_MG_OutEXL = new System.Windows.Forms.Button();
            this.BTN_MG_RESULT = new System.Windows.Forms.Button();
            this.LV_MR = new System.Windows.Forms.ListView();
            this.BTN_MG_OutCSV = new System.Windows.Forms.Button();
            this.toolTip = new System.Windows.Forms.ToolTip(this.components);
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.ST_PBar = new System.Windows.Forms.ToolStripProgressBar();
            this.MenuSt.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // MenuSt
            // 
            this.MenuSt.BackColor = System.Drawing.Color.Maroon;
            this.MenuSt.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuStFile,
            this.ヘルプHToolStripMenuItem});
            this.MenuSt.Location = new System.Drawing.Point(0, 0);
            this.MenuSt.Name = "MenuSt";
            this.MenuSt.Size = new System.Drawing.Size(344, 26);
            this.MenuSt.TabIndex = 0;
            this.MenuSt.Text = "menuStrip1";
            // 
            // MenuStFile
            // 
            this.MenuStFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuStFOpen,
            this.MenuStFExit});
            this.MenuStFile.Name = "MenuStFile";
            this.MenuStFile.Size = new System.Drawing.Size(85, 22);
            this.MenuStFile.Text = "ファイル(&F)";
            // 
            // MenuStFOpen
            // 
            this.MenuStFOpen.Name = "MenuStFOpen";
            this.MenuStFOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.MenuStFOpen.Size = new System.Drawing.Size(242, 22);
            this.MenuStFOpen.Text = "SectionFileを開く(&O)";
            this.MenuStFOpen.Click += new System.EventHandler(this.MenuStFOpen_Click);
            // 
            // MenuStFExit
            // 
            this.MenuStFExit.Name = "MenuStFExit";
            this.MenuStFExit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.MenuStFExit.Size = new System.Drawing.Size(242, 22);
            this.MenuStFExit.Text = "終了(&X)";
            this.MenuStFExit.Click += new System.EventHandler(this.MenuStFExit_Click);
            // 
            // ヘルプHToolStripMenuItem
            // 
            this.ヘルプHToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.まにゅあるToolStripMenuItem,
            this.バージョン情報ToolStripMenuItem});
            this.ヘルプHToolStripMenuItem.Name = "ヘルプHToolStripMenuItem";
            this.ヘルプHToolStripMenuItem.Size = new System.Drawing.Size(75, 22);
            this.ヘルプHToolStripMenuItem.Text = "ヘルプ(&H)";
            // 
            // まにゅあるToolStripMenuItem
            // 
            this.まにゅあるToolStripMenuItem.Name = "まにゅあるToolStripMenuItem";
            this.まにゅあるToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.まにゅあるToolStripMenuItem.Text = "まにゅある";
            // 
            // バージョン情報ToolStripMenuItem
            // 
            this.バージョン情報ToolStripMenuItem.Name = "バージョン情報ToolStripMenuItem";
            this.バージョン情報ToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.バージョン情報ToolStripMenuItem.Text = "バージョン情報";
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog";
            this.openFileDialog.RestoreDirectory = true;
            // 
            // TB_FPath
            // 
            this.TB_FPath.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.TB_FPath.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_FPath.Location = new System.Drawing.Point(5, 5);
            this.TB_FPath.Name = "TB_FPath";
            this.TB_FPath.Size = new System.Drawing.Size(275, 24);
            this.TB_FPath.TabIndex = 2;
            this.TB_FPath.Text = " --- File Path ---";
            // 
            // listView
            // 
            this.listView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listView.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.listView.FullRowSelect = true;
            this.listView.Location = new System.Drawing.Point(5, 30);
            this.listView.Name = "listView";
            this.listView.Size = new System.Drawing.Size(320, 237);
            this.listView.TabIndex = 3;
            this.listView.UseCompatibleStateImageBehavior = false;
            this.listView.View = System.Windows.Forms.View.Details;
            // 
            // statusStrip
            // 
            this.statusStrip.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.statusStrip.GripStyle = System.Windows.Forms.ToolStripGripStyle.Visible;
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabel,
            this.ST_PBar});
            this.statusStrip.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.statusStrip.Location = new System.Drawing.Point(0, 336);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(344, 22);
            this.statusStrip.TabIndex = 4;
            this.statusStrip.Text = "statusStrip";
            // 
            // StatusLabel
            // 
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(23, 17);
            this.StatusLabel.Text = "---";
            // 
            // tabControl1
            // 
            this.tabControl1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.tabControl1.Location = new System.Drawing.Point(5, 30);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(335, 302);
            this.tabControl1.TabIndex = 5;
            this.toolTip.SetToolTip(this.tabControl1, "SectionFile/Excel/Merge");
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.BTN_SFLoad);
            this.tabPage1.Controls.Add(this.TB_FPath);
            this.tabPage1.Controls.Add(this.listView);
            this.tabPage1.Location = new System.Drawing.Point(4, 26);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(327, 272);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "SectionFile";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // BTN_SFLoad
            // 
            this.BTN_SFLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_SFLoad.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.BTN_SFLoad.Location = new System.Drawing.Point(280, 5);
            this.BTN_SFLoad.Name = "BTN_SFLoad";
            this.BTN_SFLoad.Size = new System.Drawing.Size(45, 25);
            this.BTN_SFLoad.TabIndex = 4;
            this.BTN_SFLoad.Text = "Open";
            this.BTN_SFLoad.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.CB_EX_SHEET);
            this.tabPage2.Controls.Add(this.TB_EX_SERACH);
            this.tabPage2.Controls.Add(this.BTN_EFLoadTo);
            this.tabPage2.Controls.Add(this.LV_InExl);
            this.tabPage2.Controls.Add(this.BTN_EFLoad);
            this.tabPage2.Controls.Add(this.TB_ExcelPath);
            this.tabPage2.Location = new System.Drawing.Point(4, 26);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(327, 272);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Excel";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // CB_EX_SHEET
            // 
            this.CB_EX_SHEET.FormattingEnabled = true;
            this.CB_EX_SHEET.Location = new System.Drawing.Point(5, 30);
            this.CB_EX_SHEET.Name = "CB_EX_SHEET";
            this.CB_EX_SHEET.Size = new System.Drawing.Size(145, 25);
            this.CB_EX_SHEET.TabIndex = 6;
            this.CB_EX_SHEET.Text = "Sheet Name";
            this.toolTip.SetToolTip(this.CB_EX_SHEET, "シート名");
            // 
            // TB_EX_SERACH
            // 
            this.TB_EX_SERACH.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.TB_EX_SERACH.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_EX_SERACH.Location = new System.Drawing.Point(150, 30);
            this.TB_EX_SERACH.Name = "TB_EX_SERACH";
            this.TB_EX_SERACH.Size = new System.Drawing.Size(130, 24);
            this.TB_EX_SERACH.TabIndex = 5;
            this.TB_EX_SERACH.Text = "Seach";
            this.TB_EX_SERACH.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip.SetToolTip(this.TB_EX_SERACH, "左端検索単語");
            // 
            // BTN_EFLoadTo
            // 
            this.BTN_EFLoadTo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_EFLoadTo.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.BTN_EFLoadTo.Location = new System.Drawing.Point(280, 30);
            this.BTN_EFLoadTo.Name = "BTN_EFLoadTo";
            this.BTN_EFLoadTo.Size = new System.Drawing.Size(45, 25);
            this.BTN_EFLoadTo.TabIndex = 4;
            this.BTN_EFLoadTo.Text = "Load";
            this.toolTip.SetToolTip(this.BTN_EFLoadTo, "Excelロード");
            this.BTN_EFLoadTo.UseVisualStyleBackColor = true;
            this.BTN_EFLoadTo.Click += new System.EventHandler(this.BTN_EFLoadTo_Click);
            // 
            // LV_InExl
            // 
            this.LV_InExl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.LV_InExl.FullRowSelect = true;
            this.LV_InExl.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem5,
            listViewItem6});
            this.LV_InExl.Location = new System.Drawing.Point(5, 55);
            this.LV_InExl.Name = "LV_InExl";
            this.LV_InExl.Size = new System.Drawing.Size(320, 212);
            this.LV_InExl.TabIndex = 2;
            this.LV_InExl.UseCompatibleStateImageBehavior = false;
            this.LV_InExl.View = System.Windows.Forms.View.Details;
            // 
            // BTN_EFLoad
            // 
            this.BTN_EFLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_EFLoad.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.BTN_EFLoad.Location = new System.Drawing.Point(280, 5);
            this.BTN_EFLoad.Name = "BTN_EFLoad";
            this.BTN_EFLoad.Size = new System.Drawing.Size(45, 25);
            this.BTN_EFLoad.TabIndex = 1;
            this.BTN_EFLoad.Text = "Open";
            this.toolTip.SetToolTip(this.BTN_EFLoad, "Excelのパスをセット\r\nシート名更新");
            this.BTN_EFLoad.UseVisualStyleBackColor = true;
            this.BTN_EFLoad.Click += new System.EventHandler(this.BTN_EFLoad_Click);
            // 
            // TB_ExcelPath
            // 
            this.TB_ExcelPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.TB_ExcelPath.Font = new System.Drawing.Font("メイリオ", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_ExcelPath.Location = new System.Drawing.Point(5, 5);
            this.TB_ExcelPath.Name = "TB_ExcelPath";
            this.TB_ExcelPath.Size = new System.Drawing.Size(275, 24);
            this.TB_ExcelPath.TabIndex = 0;
            this.TB_ExcelPath.Text = " --- File Path ---";
            this.toolTip.SetToolTip(this.TB_ExcelPath, "Excelファイルパス");
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.CB_EX_COLNAME);
            this.tabPage3.Controls.Add(this.BTN_MG_OutEXL);
            this.tabPage3.Controls.Add(this.BTN_MG_RESULT);
            this.tabPage3.Controls.Add(this.LV_MR);
            this.tabPage3.Controls.Add(this.BTN_MG_OutCSV);
            this.tabPage3.Location = new System.Drawing.Point(4, 26);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(327, 272);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Merge";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // CB_EX_COLNAME
            // 
            this.CB_EX_COLNAME.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.CB_EX_COLNAME.FormattingEnabled = true;
            this.CB_EX_COLNAME.Location = new System.Drawing.Point(5, 240);
            this.CB_EX_COLNAME.Name = "CB_EX_COLNAME";
            this.CB_EX_COLNAME.Size = new System.Drawing.Size(95, 25);
            this.CB_EX_COLNAME.TabIndex = 4;
            this.toolTip.SetToolTip(this.CB_EX_COLNAME, "Excelの項目名");
            // 
            // BTN_MG_OutEXL
            // 
            this.BTN_MG_OutEXL.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_MG_OutEXL.Location = new System.Drawing.Point(160, 240);
            this.BTN_MG_OutEXL.Name = "BTN_MG_OutEXL";
            this.BTN_MG_OutEXL.Size = new System.Drawing.Size(85, 25);
            this.BTN_MG_OutEXL.TabIndex = 3;
            this.BTN_MG_OutEXL.Text = "Save EXLS";
            this.toolTip.SetToolTip(this.BTN_MG_OutEXL, "表の内容を.xlsx形式で保存");
            this.BTN_MG_OutEXL.UseVisualStyleBackColor = true;
            this.BTN_MG_OutEXL.Click += new System.EventHandler(this.BTN_MG_OutEXL_Click);
            // 
            // BTN_MG_RESULT
            // 
            this.BTN_MG_RESULT.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_MG_RESULT.Location = new System.Drawing.Point(100, 240);
            this.BTN_MG_RESULT.Name = "BTN_MG_RESULT";
            this.BTN_MG_RESULT.Size = new System.Drawing.Size(60, 25);
            this.BTN_MG_RESULT.TabIndex = 2;
            this.BTN_MG_RESULT.Text = "MERGE";
            this.toolTip.SetToolTip(this.BTN_MG_RESULT, "SectionFileの内容をExcelと比較");
            this.BTN_MG_RESULT.UseVisualStyleBackColor = true;
            this.BTN_MG_RESULT.Click += new System.EventHandler(this.BTN_MG_RESULT_Click);
            // 
            // LV_MR
            // 
            this.LV_MR.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.LV_MR.FullRowSelect = true;
            this.LV_MR.GridLines = true;
            this.LV_MR.Location = new System.Drawing.Point(5, 5);
            this.LV_MR.Name = "LV_MR";
            this.LV_MR.Size = new System.Drawing.Size(315, 235);
            this.LV_MR.TabIndex = 1;
            this.LV_MR.UseCompatibleStateImageBehavior = false;
            this.LV_MR.View = System.Windows.Forms.View.Details;
            // 
            // BTN_MG_OutCSV
            // 
            this.BTN_MG_OutCSV.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BTN_MG_OutCSV.Location = new System.Drawing.Point(245, 240);
            this.BTN_MG_OutCSV.Name = "BTN_MG_OutCSV";
            this.BTN_MG_OutCSV.Size = new System.Drawing.Size(75, 25);
            this.BTN_MG_OutCSV.TabIndex = 0;
            this.BTN_MG_OutCSV.Text = "Save CSV";
            this.BTN_MG_OutCSV.UseVisualStyleBackColor = true;
            // 
            // toolTip
            // 
            this.toolTip.IsBalloon = true;
            // 
            // ST_PBar
            // 
            this.ST_PBar.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.ST_PBar.Name = "ST_PBar";
            this.ST_PBar.Size = new System.Drawing.Size(100, 16);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 358);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.MenuSt);
            this.MainMenuStrip = this.MenuSt;
            this.Name = "Form1";
            this.Text = "SectionChecker";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Shown += new System.EventHandler(this.Form1_Shown);
            this.MenuSt.ResumeLayout(false);
            this.MenuSt.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip MenuSt;
        private System.Windows.Forms.ToolStripMenuItem MenuStFile;
        private System.Windows.Forms.ToolStripMenuItem MenuStFOpen;        
        private System.Windows.Forms.ToolStripMenuItem MenuStFExit;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.TextBox TB_FPath;
        private System.Windows.Forms.ListView listView;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabel;
        private System.Windows.Forms.ToolStripMenuItem ヘルプHToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem まにゅあるToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem バージョン情報ToolStripMenuItem;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button BTN_SFLoad;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.ListView LV_InExl;
        private System.Windows.Forms.Button BTN_EFLoad;
        private System.Windows.Forms.TextBox TB_ExcelPath;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Button BTN_MG_OutCSV;
        private System.Windows.Forms.ToolTip toolTip;
        private System.Windows.Forms.Button BTN_MG_RESULT;
        private System.Windows.Forms.ListView LV_MR;
        private System.Windows.Forms.TextBox TB_EX_SERACH;
        private System.Windows.Forms.Button BTN_EFLoadTo;
        private System.Windows.Forms.Button BTN_MG_OutEXL;
        private System.Windows.Forms.ComboBox CB_EX_SHEET;
        private System.Windows.Forms.ComboBox CB_EX_COLNAME;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.ToolStripProgressBar ST_PBar;
    }
}

