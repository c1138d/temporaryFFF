// 共通処理部分
#include "MyForm.h"

using namespace MyApp;

// 文字列変換処理 ---------------
// System::String → char*
const char* MyForm::systemStringToChar(System::String^ systemStr)
{
	using namespace System;
	using namespace System::Runtime::InteropServices;

	// 文字コードは、環境に合わせる(普通はUTF-8)
	int len = System::Text::Encoding::GetEncoding("UTF-8")->GetByteCount(systemStr);
	if (len > 0){
		char* rtnSts = new char[len + 1];
		memset(rtnSts, 0x00, sizeof(char)*len + 1);
		const char* buf = static_cast<const char*>((Marshal::StringToHGlobalAnsi(systemStr)).ToPointer());
		// 取得した文字列をコピー
		strncpy_s(rtnSts, len + 1, buf, _TRUNCATE);
		// メモリ開放
		Marshal::FreeHGlobal(IntPtr((void*)buf));
		return rtnSts;
	}
	return NULL;
}
// System::String→std::string
std::string MyForm::systemStringToStdString(System::String ^ s) 
{
	using namespace System::Runtime::InteropServices;

	IntPtr hString = Marshal::StringToHGlobalAnsi(s);
	if (hString == System::IntPtr::Zero) return "";

	std::string rtnSts = (const char *)hString.ToPointer();
	Marshal::FreeHGlobal(hString);
	return rtnSts;
}

// System::String→int
int MyForm::systemStringToInt(System::String^ systemStr)
{
	using namespace System;
	using namespace System::Runtime::InteropServices;
	const char* chars = systemStringToChar(systemStr);
	// NULLだったら0を返す
	int rtnSts = 0;
	if (chars != NULL){
		rtnSts = atoi(chars);
	}
	delete chars;
	return rtnSts;
}

// ロードボタンを有効にするかの処理
void MyForm::ActiveLoad()
{
	if (BtnExcelLoad->BackColor == Color::YellowGreen) BtnLoad->BackColor = Color::YellowGreen;
}


// メインフォームロード時
void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//
	FormPathObj = gcnew MyFormPath();
}

// メニューからの処理 ------------------------------------------------------------------------------
// メニューから開く
void MyForm::開くToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{

}
// 読み込みパスフォーム表示
void MyForm::MenuFPathForm_Click(System::Object^  sender, System::EventArgs^  e)
{
	// すでに開いていた場合に開かない
	if (FormPathObj->Visible) return;
	FormPathObj->Show();		// モードレス
}

// ボタン処理 ------------------------------------------------------------------------------------
// SW開くボタン
void MyForm::BtnSWLoad_Click(System::Object^  sender, System::EventArgs^  e)
{

}

// 全部読み込むボタン
void MyForm::BtnLoad_Click(System::Object^  sender, System::EventArgs^  e)
{
	// エクセル読み込み処理(ボタンが翠なら実行する)
	if (BtnLoad->BackColor != Color::YellowGreen) return;
	//
	// エクセルロード
	ExcelLoad(g_sysstrExcelPath);
	//
	// gridview1に表示
	this->dataGridView1->Rows->Clear();
	for (unsigned int i = 0; i < g_vecS1.size(); i++){
		// std::string->system stringに変換
		String^	sysstrNo = Convert::ToString(g_vecS1[i].m_no);
		String^	sysstrCatL = gcnew String(g_vecS1[i].m_strCatL.c_str());
		String^	sysstrCmt = gcnew String(g_vecS1[i].m_strCmt.c_str());
		this->dataGridView1->Rows->Add(sysstrNo, sysstrCatL, sysstrCmt);
	}
	// gridview2に表示
	this->dataGridView2->Rows->Clear();
	for (unsigned int i = 0; i < g_vecS2.size(); i++){
		// std::string->system stringに変換
		String^	sysstrNo = Convert::ToString(g_vecS2[i].m_no);
		String^	sysstrCatL = gcnew String(g_vecS2[i].m_strCatL.c_str());
		String^	sysstrCmt = gcnew String(g_vecS2[i].m_strCmt.c_str());
		this->dataGridView2->Rows->Add(sysstrNo, sysstrCatL, sysstrCmt);
	}

}

