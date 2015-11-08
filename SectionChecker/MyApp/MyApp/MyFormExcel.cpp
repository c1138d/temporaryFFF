// エクセル関連
/* 設定メモ
	1：Microsoft Excel 11.0 Object Library を参照に追加
	2：CLR Support → /clr:pure
	3：using namespace Microsoft::Office::Interop::Excel;
*/
#include "MyForm.h"

using namespace MyApp;
using namespace Microsoft::Office::Interop::Excel;				// Excel使用のため（参照から拾ってくる）

// エクセル読み込みボタン→パスをセットすつだけ
void MyForm::BtnExcelLoad_Click(System::Object^  sender, System::EventArgs^  e)
{
	// エクセルファイル読み込み
	// 開始ディレクトリ
	openFileDialog1->InitialDirectory = g_sysstrDir;
	// ファイルが存在するかどうか
	openFileDialog1->FileName = nullptr;
	// 拡張子設定
	openFileDialog1->Filter = "エクセルファイル(*.xlsx)|*.xlsx|" + "すべてのファイル(*.*)|*.*";
	openFileDialog1->FilterIndex = 1;

	// ダイヤログキャンセルした場合は何もしない ---------------------------------------------------
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	// 取得したファイル名をパスフォームへ登録するために、グローバル定義に格納
	//FormPathObj->TbExcelPath->Text = openFileDialog1->FileName;
	g_sysstrExcelPath = openFileDialog1->FileName;
	// ボタンを翠色にする
	BtnExcelLoad->BackColor = Color::YellowGreen;
	// ロードボタンが有効になるか判断する
	ActiveLoad();
	// 対応するシートがなかった場合はメッセージ
	// 読み込んだファイルのヂレクトリ名を取得→初期ディレクトリに設定
	g_sysstrDir = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
}

// -------------------------------------------------------------------------------------------

// シートの読み込み範囲決定(値は元のを更新したいので参照渡し)
void MyForm::ExcelLoadRange(Worksheet^ Ws1, System::String ^ sysstrQuery, int& nRow, int& nRowMax, int& nColMax)
{
	// 縦の幅
	nRowMax = Ws1->Cells->SpecialCells(Microsoft::Office::Interop::Excel::XlCellType::xlCellTypeLastCell, System::Reflection::Missing::Value)->Row+1;
	// ループで横幅確認 --- -> 関数化できる　読み込む範囲の最初の値と横の列の限界を取得する
	for (; nRow < nRowMax; nRow++){
		Range^ rgnF = static_cast<Range^>(Ws1->Cells[nRow, 1]);                // 一番左端の文字列を調べる
		String^ sysstrval = rgnF->Text->ToString();
		if (sysstrval == sysstrQuery){   // 左検索単語と一致した場合(シートごとに単語を変える)
			// 該当する文字列だった場合、この行の文字列保存※必ず該当するようにする
			while (true){
				Range^ rgnS = static_cast<Range^>(Ws1->Cells[nRow, nColMax]);  // セル取得
				if (rgnS->Value2 == nullptr){        // 文字列がなくなったらループをぬける
					break;
				}
				nColMax++;
			}
			break;
		}
	}
	nRow++;			// 読み込む表は次の行からなので1行足しておく
}

// シート1ロード処理
void MyForm::ExcelS1Load(Worksheet^ Ws1)
{
	// シート名決定
	Ws1->Select(Type::Missing);

	// シートの読み込む縦横の範囲決定する定義
	int nRow = 1;
	int nRowMax = 1;
	int nColMax = 1;

	// 読み込む縦横の範囲と開始行を設定する（読み込む範囲の最初の単語も登録）
	ExcelLoadRange(Ws1, "番号", nRow, nRowMax, nColMax);					//→↑

	for (; nRow < nRowMax; nRow++){
		ST_S1_CONTENT st_s1content;			// 格納用（1行ごとにリセット）
		bool bNo = false;					// 格納フラグ
		bool bCatL = false;
		for (int nCol = 1; nCol < nColMax; nCol++){
			Range^ rgntmp = static_cast<Range^>(Ws1->Cells[nRow, nCol]);                // 一番左端の文字列を調べる
			String^ sysstrtmp = rgntmp->Text->ToString();
			switch (nCol)
			{
			case 1:
				// 番号を格納（空白なら0を代入）
				st_s1content.m_no = systemStringToInt(sysstrtmp);
				if (sysstrtmp == "") bNo = true;;
				break;
			case 2:
				// カテゴリを格納
				st_s1content.m_strCatL = systemStringToStdString(sysstrtmp);
				if (sysstrtmp == "") bCatL = true;
				break;
			case 3:
				// コメント保存
				st_s1content.m_strCmt = systemStringToStdString(sysstrtmp);
				break;
			default:
				break;
			}
		}
		// 前ふたつが空白なら格納せず
		if (bNo == true && bCatL == true) continue;
		// vectorに横1列格納
		g_vecS1.push_back(st_s1content);
	}
}

// シート2ロード処理
void MyForm::ExcelS2Load(Worksheet^ Ws1)
{
	// シート名決定
	Ws1->Select(Type::Missing);

	// シートの読み込む縦横の範囲決定する定義
	int nRow = 1;
	int nRowMax = 1;
	int nColMax = 1;

	// 読み込む縦横の範囲と開始行を設定する（読み込む範囲の最初の単語も登録）
	ExcelLoadRange(Ws1, "番号が飛ぶとび", nRow, nRowMax, nColMax);					//→↑

	for (; nRow < nRowMax; nRow++){
		ST_S2_CONTENT st_s2content;			// 格納用（1行ごとにリセット）
		for (int nCol = 1; nCol < nColMax; nCol++){
			Range^ rgntmp = static_cast<Range^>(Ws1->Cells[nRow, nCol]);                // 一番左端の文字列を調べる
			String^ sysstrtmp = rgntmp->Text->ToString();
			switch (nCol)
			{
			case 1:
				// 番号を格納（空白なら0を代入）
				st_s2content.m_no = systemStringToInt(sysstrtmp);
				break;
			case 2:
				// カテゴリを格納
				st_s2content.m_strCatL = systemStringToStdString(sysstrtmp);
				break;
			case 3:
				// コメント保存
				st_s2content.m_strCmt = systemStringToStdString(sysstrtmp);
				break;
			default:
				break;
			}
		}
		// vectorに横1列格納
		g_vecS2.push_back(st_s2content);
	}
}



// エクセルロード処理Main　引数　エクセルファイルパス --------------------------- |
void MyForm::ExcelLoad(System::String^ sysstrFPath)
{
	// Excelオブジェクトを新規作成
	Microsoft::Office::Interop::Excel::Application^ ExlApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
	// Excel起動するかどうか
	ExlApp->Visible = false;
	// ワークブック開く
	Workbook^ wb = ExlApp->Workbooks->Open(sysstrFPath,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value
		);
	int nSumWs = wb->Sheets->Count;			// ワークシートの数
	// ワークブックの中の特定のシート名を見つける
	int nNumWs = 1;
	for (; nNumWs < nSumWs; nNumWs++) {
		Worksheet^ WsTmp = static_cast<Worksheet^>(wb->Sheets[nNumWs]);
		if (WsTmp->Name == "通常") ExcelS1Load(WsTmp);  // シートを見つけたらループを抜ける？または関数呼ぶ？
		else if (WsTmp->Name == "特殊") ExcelS2Load(WsTmp);
	}
	//
	wb->Close(false, Type::Missing, Type::Missing);    // Excell終了
	ExlApp->Quit();
	return;
}



	/*
	// 新規ワークブック作成
	Microsoft::Office::Interop::Excel::Application^ xlApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
	Workbook^ wb = xlApp->Workbooks->Add(Type::Missing);

	// ワークシート削除
	static_cast<Worksheet^>(xlApp->ActiveWorkbook->Sheets->Item[3])->Delete();
	static_cast<Worksheet^>(xlApp->ActiveWorkbook->Sheets->Item[2])->Delete();

	// 現在のシートを指定
	Worksheet^ ws = static_cast<Worksheet^>(xlApp->ActiveSheet);

	// 書き込み
	ws->Name = "Charts";
	ws->Cells[1, 1] = "Hello World!";

	// アプリケーションをアクティブに起動
	xlApp->Visible = true;
	*/


