using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;           // DLLImportを使用するため
using Microsoft.Office.Interop.Excel;           // エクセル読み込み
using System.IO;

// ---------------------------------------------------------
// メイン
// ---------------------------------------------------------
namespace SectionChecker
{
    // フォームのクラス
    public partial class Form1 : Form
    {
        // --- 変数定義 ---
        string      strDirPath;         // ダイヤログ用パス保存
        int         g_nSectionRowMax    = 0;
        int         g_nExcelRowMax      = 0;
        string[]    g_strarrExCol;

        // --- DLL IMPORT Win32APIを使うため ---
        [DllImport("kernel32.dll")]
        static extern int GetPrivateProfileSectionNames(
            IntPtr  lpszReturnBuffer,
            uint    nSize,
            string  lpFileName
            );

        [DllImport("kernel32.dll")]
        static extern uint GetPrivateProfileString(
           string           lpAppName,
           string           lpKeyName,
           string           lpDefault,
           StringBuilder    lpReturnedString,
           uint             nSize,
           string           lpFileName
           );

        // --- コンストラクタ -------------------
        public Form1()
        {
            InitializeComponent();
            strDirPath = @"d:\";                    // デフォルトの開始パス
        }

        // --- 内部処理 --------------------------
        // フォームロード時処理
        private void Form1_Load(object sender, EventArgs e)
        {
            // ウィンドウの位置・サイズを復元
            Bounds = Properties.Settings.Default.Bounds;
            WindowState = Properties.Settings.Default.WindowState;
        }

        // フォーム表示
        private void Form1_Shown(object sender, EventArgs e)
        {
            // ステータス表示
            this.StatusLabel.Text = "起動完了";
        }

        // フォーム閉じるときの処理
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // ウィンドウの位置・サイズを保存
            if (WindowState == FormWindowState.Normal)
                Properties.Settings.Default.Bounds = Bounds;
            else
                Properties.Settings.Default.Bounds = RestoreBounds;

            Properties.Settings.Default.WindowState = WindowState;
            Properties.Settings.Default.Save();
        }   

        // --- メインメソッド --------------------------------------------------
        // メニュー終了
        private void MenuStFExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        // --- メニュー開く --------------------------------------------------------------------------------
        private void MenuStFOpen_Click(object sender, EventArgs e)
        {
            // ダイアログのタイトルを指定
            openFileDialog.Title                = "開く";
            // 初期フォルダを指定
            openFileDialog.InitialDirectory     = strDirPath;
            // 初期ファイル名
            openFileDialog.FileName             = string.Empty;
            // ファイルが存在するかどうかチェックする
            openFileDialog.CheckFileExists      = true;
            // 複数選択をするか否か
            openFileDialog.Multiselect          = false;
            // ファイルの種類、拡張子のフィルターを設定
            openFileDialog.Filter =
                "すべてのファイル(*.*)|*.*|" +
                "テキストファイル(*.txt)|*.txt";
            // 初期状態で選択されているフィルターは何番目か
            // インデックスは１からはじまるので注意
            openFileDialog.FilterIndex = 2;

            // 開くダイアログを表示
            DialogResult ret = openFileDialog.ShowDialog();
            if (ret == DialogResult.OK){                    // ファイル決定処理
                // ファイルの中身を調べる 引数はパス
                string  stIniPath   = System.IO.Path.ChangeExtension(openFileDialog.FileName, ".ini");  // 拡張子をiniへ変更する
                IntPtr  ptr         = Marshal.StringToHGlobalAnsi(new String('\0', 1024));              // アンマネージ文字列確保
                int     nlength     = GetPrivateProfileSectionNames(ptr, 1024, stIniPath);              // WinAPI関数

                if ( nlength > 0){
                    // リスト準備
                    listView.Columns.Clear();           // ヘッダークリア
                    listView.Items.Clear();             // リストすべてクリア
                    // 列を追加
                    listView.Columns.Add("SwitchName", 100);
                    listView.Columns.Add("ID", 80);

                    // iniファイルの中身読み込み
                    String result = Marshal.PtrToStringAnsi(ptr, nlength);
                    // セクションごとに処理を実行(セクション名を/0区切りで分離し、それに対して処理)
                    string[] strarrSec = result.Split('\0');
                    int nRowAll=0;
                    //コントロールを初期化する
                    ST_PBar.Minimum = 0;
                    ST_PBar.Maximum = strarrSec.Length-1;
                    ST_PBar.Value = 0;

                    for(int nRow=0; nRow<strarrSec.Length;nRow++){
                        StringBuilder sa = new StringBuilder(256);
                        StringBuilder sb = new StringBuilder(64);
                        // iniファイルから情報を取得する なければsb=errとなる
                        GetPrivateProfileString(strarrSec[nRow], "NAME", "err", sa, 256, stIniPath);
                        GetPrivateProfileString(strarrSec[nRow], "ID", "err", sb, 64, stIniPath);
                        // 値が取得できたらリストに表示
                        if (sa.ToString() != "err"){
                            // 取得した文字列をスペース区切りで分離（分離数も取得できる）
                            string[] strarrName = sa.ToString().Split(' ');
                            string[] strarrID = sb.ToString().Split(' ');
                            for (int i = 0; i < strarrName.Length; i++){
                                // リスト表示
                                ListViewItem item = new ListViewItem(strarrName[i]);
                                item.SubItems.Add(strarrID[i]);
                                listView.Items.Add(item);               // 行を追加
                            }
                            nRowAll += strarrName.Length;
                        }
                        ST_PBar.Value = nRow;
                    }
                    // カラムの幅を自動調整する
                    foreach (ColumnHeader ch in listView.Columns)
                    {
                        ch.Width = -2;
                    }
                    g_nSectionRowMax = nRowAll;            // →表の行数
                }
                Marshal.FreeHGlobal(ptr);           // アンマネージメモリ解放

                // パスをGUI表示
                TB_FPath.Text           = openFileDialog.FileName;
                // 読み込んだファイルのディレクトリ名取得
                strDirPath              = System.IO.Path.GetDirectoryName(openFileDialog.FileName);
                // ステータス表示
                this.StatusLabel.Text   = System.IO.Path.GetFileName(openFileDialog.FileName) + " 読み込み成功";
                this.StatusLabel.ForeColor = Color.YellowGreen;
            }
        }

        // --- Excelタブの開くボタン ------------------------------------------------------------------
        private void BTN_EFLoad_Click(object sender, EventArgs e)
        {
            // ダイアログのタイトルを指定
            openFileDialog.Title                = "Excelを開く";
            // 初期フォルダを指定
            openFileDialog.InitialDirectory     = strDirPath;
            // 初期ファイル名
            openFileDialog.FileName             = string.Empty;
            // ファイルが存在するかどうかチェックする
            openFileDialog.CheckFileExists      = true;
            // ファイルの種類、拡張子のフィルターを設定
            openFileDialog.Filter =
                "すべてのファイル(*.*)|*.*|" +
                "テキストファイル(*.xlsx)|*.xlsx";
            // 初期状態で選択されているフィルターは何番目か
            // インデックスは１からはじまるので注意
            openFileDialog.FilterIndex = 2;

            if (openFileDialog.ShowDialog() == DialogResult.OK){                    // ファイル決定処理
                // エクセル開く→シート名をコンボボックスへ
                string strExcelPath = openFileDialog.FileName;
                // Excelアプリケーションオブジェクトを新規作成
                Microsoft.Office.Interop.Excel.Application ExcelApp
                    = new Microsoft.Office.Interop.Excel.Application();
                // VisibleをTrueに設定した場合はExcelアプリケーションの画面が表示
                ExcelApp.Visible = false;
                // using Microsoft.Office.Interop.ExcelでWorkbook使用可能 ワークブック開く
                Workbook wb = ExcelApp.Workbooks.Open(strExcelPath);
                int nAllSt = wb.Sheets.Count;                   // ワークシートの合計数
                // 開いているワークブックのシート名すべて格納
                CB_EX_SHEET.Items.Clear();                      // 全てのリストをクリア
                for (int nShCt=1; nShCt < nAllSt; nShCt++){
                    Worksheet wsTmp = wb.Sheets[nShCt];
                    CB_EX_SHEET.Items.Add(wsTmp.Name);          // コンボボックスへ格納
                }
                CB_EX_SHEET.SelectedIndex = 0;                  // コンボボックス初期設定
                wb.Close(false, Type.Missing, Type.Missing);    // Excell終了
                ExcelApp.Quit();
                // パスをGUI表示
                TB_ExcelPath.Text = strExcelPath;
                // 読み込んだファイルのディレクトリ名取得
                strDirPath = System.IO.Path.GetDirectoryName(strExcelPath);
                // ステータス表示
                this.StatusLabel.Text = System.IO.Path.GetFileName(strExcelPath) + " パスセット完了";
                this.StatusLabel.ForeColor = Color.DodgerBlue;
            }
        }

        // --- エクセルロード→表 -------------------------------------------------------------------
        private void BTN_EFLoadTo_Click(object sender, EventArgs e)
        {
            string strExcelPath = TB_ExcelPath.Text;                // ToStringでは無理
            if (!System.IO.File.Exists(strExcelPath)) {
                this.StatusLabel.Text = "ファイルが存在しない";
                this.StatusLabel.ForeColor = Color.Crimson;
                return;
            }
            //コントロールを初期化する
            ST_PBar.Minimum = 0;
            ST_PBar.Maximum = 7;
            ST_PBar.Value = 0;

            // Excelアプリケーションオブジェクトを新規作成
            Microsoft.Office.Interop.Excel.Application ExcelApp
                = new Microsoft.Office.Interop.Excel.Application();
            // VisibleをTrueに設定した場合はExcelアプリケーションの画面が表示
            ExcelApp.Visible = false;
            ST_PBar.Value = 1;

            // using Microsoft.Office.Interop.ExcelでWorkbook使用可能 ワークブック開く
            Workbook wb = ExcelApp.Workbooks.Open(strExcelPath);
            int nAllSt = wb.Sheets.Count;                    // ワークシートの合計数
            ST_PBar.Value = 2;

            // 開いているワークブックのシート名を検索
            int nShCt = 1;
            for (; nShCt < nAllSt; nShCt++) {
                Worksheet wsTmp = wb.Sheets[nShCt];
                if (wsTmp.Name == CB_EX_SHEET.Text) break;  // 選択中のコンボボックスのシート名を使用
            }
            Worksheet ws1 = wb.Sheets[nShCt];               // シート名決定
            ws1.Select(Type.Missing);
            ST_PBar.Value = 3;

            // --- 縦横の範囲を決定する
            int nRow = 1;
            int nColMax = 1;
            bool bEnd = false;
            while (nRow < 1000)
            {                                   // 1000行以降はループ抜ける（改善の余地）
                Range rgnF = ws1.Cells[nRow, 1];                // 一番左端の文字列を調べる
                dynamic val = rgnF.Value2;
                if (Convert.ToString(val) == TB_EX_SERACH.Text)   // 左検索単語と一致した場合
                {               // 該当する文字列だった場合、この行の文字列保存※必ず該当するようにする
                    while (true)
                    {
                        Range rgnS = ws1.Cells[nRow, nColMax];  // セル取得
                        val = rgnS.Value2;
                        if (Convert.ToString(val) == null)
                        {        // 文字列がなくなったらループをぬける
                            nColMax--;
                            break;
                        }
                        nColMax++;
                    }
                    break;
                }
                nRow++;
            }
            ST_PBar.Value = 4;

            // リスト準備
            LV_InExl.Columns.Clear();           // ヘッダーすべてクリア
            LV_InExl.Items.Clear();             // リストすべてクリア
            CB_EX_COLNAME.Items.Clear();        // 項目名コンボボックスクリア
            // --- 横の列分追加する
            g_strarrExCol = new string[nColMax];
            for (int nColID = 0; nColID < nColMax; nColID++){
                Range rgnVal = ws1.Cells[nRow, nColID + 1];               // セルの値取得
                dynamic valIN = rgnVal.Value2;
                // stringに変換
                g_strarrExCol[nColID] = Convert.ToString(valIN);            // グローバルに値格納
                LV_InExl.Columns.Add(g_strarrExCol[nColID], 100);           // へっだーに追加
                CB_EX_COLNAME.Items.Add(g_strarrExCol[nColID]);             // コンボボックスに格納
            }
            CB_EX_COLNAME.SelectedIndex = 0;    // コンボボックスの初期設定
            nRow++;
            int nRowIdF = nRow;                 // IDまでの行数を格納
            ST_PBar.Value = 5;

            // --- 値をリストに表示
            while (true)
            {
                string[] strarr = new string[nColMax];
                for (int nCol = 0; nCol < nColMax; nCol++)
                {
                    Range rgnVal = ws1.Cells[nRow, nCol + 1];               // セルの値取得
                    dynamic valIN = rgnVal.Value2;
                    // stringに変換
                    strarr[nCol] = Convert.ToString(valIN);
                    if (nCol == 0 && strarr[0] == null) bEnd = true;
                }
                if (bEnd) break;
                LV_InExl.Items.Add(new ListViewItem(strarr));               // リストに表示
                nRow++;
            }
            ST_PBar.Value = 6;

            // カラムの幅を自動調整する
            foreach (ColumnHeader ch in LV_InExl.Columns)
            {
                ch.Width = -2;
            } 
            g_nExcelRowMax = nRow - nRowIdF;                                // 最大行取得(マージ処理に利用)

            wb.Close(false, Type.Missing, Type.Missing);                    // wb終了
            ExcelApp.Quit();                                                // エクセル終了
            ST_PBar.Value = 7;

            // ステータス表示
            this.StatusLabel.Text = System.IO.Path.GetFileName(strExcelPath) + " 読み込み成功";
            this.StatusLabel.ForeColor = Color.YellowGreen;
        }

        // --- Mergeボタン -------------------------------------------------------------------------
        private void BTN_MG_RESULT_Click(object sender, EventArgs e)
        {
            // SectionとExcelタブの表にデータがない場合はretrun
            if (g_nSectionRowMax == 0 || g_nExcelRowMax == 0){
                // ステータス表示
                this.StatusLabel.Text = "表が読み込まれていません";
                this.StatusLabel.ForeColor = Color.Crimson;
                return;
            }
            // リスト準備
            LV_MR.Columns.Clear();           // へっだーすべてクリア
            LV_MR.Items.Clear();             // リストすべてクリア
            // 横ヘッダー追加(Excelタブをコピーする)   特定の行だけを抜き出す
            LV_MR.Columns.Add("名前", 100);
            LV_MR.Columns.Add(CB_EX_COLNAME.Text, 100);
            //コントロールを初期化する
            ST_PBar.Minimum = 0;
            ST_PBar.Maximum = g_nExcelRowMax-1;
            ST_PBar.Value   = 0;
            
            // Excelタブの名前列データを基準にし、表に格納
            for (int nRow = 0; nRow < g_nExcelRowMax; nRow++)
            {
                bool bFlgCor        = false;    // ID一致フラグ
                bool bFlgRe         = false;    // 数値更新フラグ
                string strEXName    = LV_InExl.Items[nRow].SubItems[0].Text;      // 名前欄を取得
                string[] strarr     = new string[g_strarrExCol.Length];           // 表示用(横幅は考え中)
                strarr[0]           = strEXName;                                  // 名前を表示に格納
                string strEXID      = LV_InExl.Items[nRow].SubItems[CB_EX_COLNAME.SelectedIndex].Text;      // ExcelからID取得
                // netID:を削除する←Excelの書式を整えておく
                string strExRe      = strEXID.Replace("netID:", "");                   // netID:を削除し数値だけにする
                // 数値をスペースで分割して(複数の数値が登録されている場合に対応)
                string[] strarrDevEXID = strExRe.ToString().Split(' ');
                // --- 格納するIDをSectionから探し格納
                for (int nRowSF = 0; nRowSF < g_nSectionRowMax; nRowSF++)         // sectionでループ
                {
                    bool bFlgOver = false;
                    string strSFName = listView.Items[nRowSF].SubItems[0].Text;   // sectionから名前取得
                    if (strSFName == strEXName)                                   // Excelの名前がsectionと一致したら
                    {
                        if (bFlgCor) strarr[1] += " ";                  // 数値が複数のIDである場合はスペースを入れる
                        string strSFID = listView.Items[nRowSF].SubItems[1].Text; // sectionからID取得
                        // Excelの値と比較し違っていたら表の背景色変更し、net:数値にして新しい値入力
                        for (int nDev = 0; nDev < strarrDevEXID.Length; nDev++)
                        {
                            if (bFlgCor) {
                                string[] strarrDevTmp = strarr[1].ToString().Split(' ');        // 複数値がある場合同盟数値を削除する
                                for (int nSpTmp = 0; nSpTmp < strarrDevTmp.Length; nSpTmp++)
                                {
                                    if (strSFID == strarrDevTmp[nSpTmp])        // 格納するsec数値が既に登録されていた場合
                                        bFlgOver = true;   // 同盟数値が見つかった
                                }
                            }
                            bFlgCor = true;         // 同盟が見つかった
                            // 同盟数値以外以下実行
                            if (!bFlgOver)
                            {
                                if (nDev >= 1) strarr[1] += " ";            // 数値が複数ある場合はスペースを入れる
                                if (strSFID != strarrDevEXID[nDev])
                                {
                                    bFlgRe = true;                          // IDが一致しない（数値が更新されたことを確認）
                                    strarr[1] += strSFID;                   // スペースをつける
                                }
                                else
                                {
                                    strarr[1] += strarrDevEXID[nDev];           // IDが同じ場合はそのままにしておく
                                }
                            }
                        }
                    }
                }
                
                if (bFlgCor)     strarr[1] = "netID:" + strarr[1];      // 同盟スイッチがある場合
                else             strarr[1] = "該当なし";                // 同盟スイッチがない場合

                ListViewItem item           = new ListViewItem(strarr);     // 中身格納
                if (bFlgRe)
                {
                    // サブアイテムのスタイルはアイテムのそれを引き継がないことを指定
                    item.UseItemStyleForSubItems    = false;
                    item.SubItems[1].ForeColor      = Color.Yellow;
                    item.SubItems[1].BackColor      = Color.Red;
                }
                LV_MR.Items.Add(item);                                       // リストに格納
                ST_PBar.Value = nRow;
            }
            // カラムの幅を自動調整する
            foreach (ColumnHeader ch in LV_MR.Columns)
            {
                ch.Width = -2;
            }
            // ステータス表示
            this.StatusLabel.Text = "マージ成功";
            this.StatusLabel.ForeColor = Color.YellowGreen;
        }

        // --- Excell形式で保存する ------------------------------------------------------------------------
        private void BTN_MG_OutEXL_Click(object sender, EventArgs e)
        {
            // SectionとExcelタブの表にデータがない場合はretrun
            if (LV_MR.Items.Count<3)
            {
                // ステータス表示
                this.StatusLabel.Text = "表が読み込まれていません";
                this.StatusLabel.ForeColor = Color.Crimson;
                return;
            }
            // ダイアログのタイトルを指定
            saveFileDialog.Title = "Merge結果をxlsxで保存";
            // 初期フォルダを指定
            saveFileDialog.InitialDirectory = strDirPath;
            // 初期ファイル名
            saveFileDialog.FileName = string.Empty;
            // 拡張子が入力されなければ自動で付与するか否か
            saveFileDialog.AddExtension = true;
            // ファイルの種類、拡張子のフィルターを設定
            saveFileDialog.Filter =
                "すべてのファイル(*.*)|*.*|" +
                "Excel2010ファイル(*.xlsx)|*.xlsx|"+
                "Excelファイル(*.xls)|*.xls";
            saveFileDialog.FilterIndex = 2;

            // 【保存】ボタンで閉じられていれば選択されているファイル名を表示
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                Microsoft.Office.Interop.Excel.Application ExcelApp
                    = new Microsoft.Office.Interop.Excel.Application();
                ExcelApp.Visible = false;                                   // Excel非表示
                Workbook wb = ExcelApp.Workbooks.Add();                     // ワークブック追加

                Worksheet ws1 = wb.Sheets[1];                               // ワークブックの１枚目のシートを選択
                ws1.Select(Type.Missing);

                // 値保存
                for (int nRow = 0; nRow < LV_MR.Items.Count; nRow++)
                {
                    for (int nCol = 0; nCol < LV_MR.Columns.Count; nCol++)
                    {
                        Range rgn = ws1.Cells[nRow+1, nCol+1];
                        rgn.Value2 = LV_MR.Items[nRow].SubItems[nCol].Text;
                    }
                }

                wb.SaveAs(saveFileDialog.FileName);                         // 指定したファイル名でExcel保存
                wb.Close(false);
                ExcelApp.Quit();
                // ステータス表示
                this.StatusLabel.Text = "保存成功";
                this.StatusLabel.ForeColor = Color.YellowGreen;
            }
        }
    }
    //
}
