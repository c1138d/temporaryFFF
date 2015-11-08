#ifndef INCLUDED_MYFORM
#define INCLUDED_MYFORM
#pragma once
#include "Main.h"
#include "MyFormPath.h"				// パス用 →hに新フォームを追加

// グローバル定義
extern vector<ST_S1_CONTENT> g_vecS1;
extern vector<ST_S2_CONTENT> g_vecS2;

namespace MyApp {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Office::Interop::Excel;				// Excel使用のため（参照から拾ってくる）


	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  No;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CatL;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Comment;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  開くToolStripMenuItem;
	private: System::Windows::Forms::Button^  BtnExcelLoad;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
			 System::String^	g_sysstrDir;									// ダイヤログパス
			 System::String^	g_sysstrExcelPath;									// エクセルのパス
	private: System::Windows::Forms::Button^  BtnANLoad;
	private: System::Windows::Forms::Button^  BtnSWLoad;
	private: System::Windows::Forms::Label^  LbExlLoad;
	private: System::Windows::Forms::Label^  LbCsvLoad;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  LbDBLoad;
	private: System::Windows::Forms::Button^  BtnLoad;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuFPathForm;

			 MyFormPath^ FormPathObj;			// パス用フォーム定義
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  番号が飛ぶ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  カテゴリ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  コメ;

	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->No = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CatL = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Comment = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->開くToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->MenuFPathForm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BtnExcelLoad = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->BtnANLoad = (gcnew System::Windows::Forms::Button());
			this->BtnSWLoad = (gcnew System::Windows::Forms::Button());
			this->LbExlLoad = (gcnew System::Windows::Forms::Label());
			this->LbCsvLoad = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->BtnLoad = (gcnew System::Windows::Forms::Button());
			this->LbDBLoad = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->番号が飛ぶ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->カテゴリ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->コメ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->No, this->CatL,
					this->Comment
			});
			this->dataGridView1->Location = System::Drawing::Point(5, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(358, 169);
			this->dataGridView1->TabIndex = 0;
			// 
			// No
			// 
			this->No->HeaderText = L"No";
			this->No->Name = L"No";
			// 
			// CatL
			// 
			this->CatL->HeaderText = L"CatL";
			this->CatL->Name = L"CatL";
			// 
			// Comment
			// 
			this->Comment->HeaderText = L"Comment";
			this->Comment->Name = L"Comment";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Indigo;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(388, 26);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->開くToolStripMenuItem,
					this->toolStripSeparator1, this->MenuFPathForm
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(40, 22);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// 開くToolStripMenuItem
			// 
			this->開くToolStripMenuItem->Name = L"開くToolStripMenuItem";
			this->開くToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->開くToolStripMenuItem->Text = L"エクセル開く";
			this->開くToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::開くToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(169, 6);
			// 
			// MenuFPathForm
			// 
			this->MenuFPathForm->Name = L"MenuFPathForm";
			this->MenuFPathForm->Size = System::Drawing::Size(172, 22);
			this->MenuFPathForm->Text = L"読み込みパス一覧";
			this->MenuFPathForm->Click += gcnew System::EventHandler(this, &MyForm::MenuFPathForm_Click);
			// 
			// BtnExcelLoad
			// 
			this->BtnExcelLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnExcelLoad->Location = System::Drawing::Point(70, 0);
			this->BtnExcelLoad->Name = L"BtnExcelLoad";
			this->BtnExcelLoad->Size = System::Drawing::Size(130, 23);
			this->BtnExcelLoad->TabIndex = 2;
			this->BtnExcelLoad->Text = L"Excel";
			this->BtnExcelLoad->UseVisualStyleBackColor = true;
			this->BtnExcelLoad->Click += gcnew System::EventHandler(this, &MyForm::BtnExcelLoad_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// BtnANLoad
			// 
			this->BtnANLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnANLoad->Location = System::Drawing::Point(70, 25);
			this->BtnANLoad->Name = L"BtnANLoad";
			this->BtnANLoad->Size = System::Drawing::Size(50, 25);
			this->BtnANLoad->TabIndex = 3;
			this->BtnANLoad->Text = L"AN";
			this->BtnANLoad->UseVisualStyleBackColor = true;
			// 
			// BtnSWLoad
			// 
			this->BtnSWLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnSWLoad->Location = System::Drawing::Point(120, 25);
			this->BtnSWLoad->Name = L"BtnSWLoad";
			this->BtnSWLoad->Size = System::Drawing::Size(50, 25);
			this->BtnSWLoad->TabIndex = 4;
			this->BtnSWLoad->Text = L"SW";
			this->BtnSWLoad->UseVisualStyleBackColor = true;
			this->BtnSWLoad->Click += gcnew System::EventHandler(this, &MyForm::BtnSWLoad_Click);
			// 
			// LbExlLoad
			// 
			this->LbExlLoad->AutoSize = true;
			this->LbExlLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->LbExlLoad->Location = System::Drawing::Point(5, 5);
			this->LbExlLoad->Name = L"LbExlLoad";
			this->LbExlLoad->Size = System::Drawing::Size(62, 17);
			this->LbExlLoad->TabIndex = 5;
			this->LbExlLoad->Text = L"Excel-SET";
			// 
			// LbCsvLoad
			// 
			this->LbCsvLoad->AutoSize = true;
			this->LbCsvLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->LbCsvLoad->Location = System::Drawing::Point(5, 30);
			this->LbCsvLoad->Name = L"LbCsvLoad";
			this->LbCsvLoad->Size = System::Drawing::Size(56, 17);
			this->LbCsvLoad->TabIndex = 6;
			this->LbCsvLoad->Text = L"CSV-SET";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->BtnLoad);
			this->panel1->Controls->Add(this->LbDBLoad);
			this->panel1->Controls->Add(this->LbCsvLoad);
			this->panel1->Controls->Add(this->BtnExcelLoad);
			this->panel1->Controls->Add(this->LbExlLoad);
			this->panel1->Controls->Add(this->BtnSWLoad);
			this->panel1->Controls->Add(this->BtnANLoad);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(383, 78);
			this->panel1->TabIndex = 7;
			// 
			// BtnLoad
			// 
			this->BtnLoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BtnLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnLoad->Location = System::Drawing::Point(298, 0);
			this->BtnLoad->Name = L"BtnLoad";
			this->BtnLoad->Size = System::Drawing::Size(80, 75);
			this->BtnLoad->TabIndex = 8;
			this->BtnLoad->Text = L"Load";
			this->BtnLoad->UseVisualStyleBackColor = true;
			this->BtnLoad->Click += gcnew System::EventHandler(this, &MyForm::BtnLoad_Click);
			// 
			// LbDBLoad
			// 
			this->LbDBLoad->AutoSize = true;
			this->LbDBLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->LbDBLoad->Location = System::Drawing::Point(5, 55);
			this->LbDBLoad->Name = L"LbDBLoad";
			this->LbDBLoad->Size = System::Drawing::Size(49, 17);
			this->LbDBLoad->TabIndex = 7;
			this->LbDBLoad->Text = L"DB-SET";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(383, 209);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(375, 183);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(375, 183);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(0, 30);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(385, 295);
			this->splitContainer1->SplitterDistance = 80;
			this->splitContainer1->TabIndex = 9;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->番号が飛ぶ,
					this->カテゴリ, this->コメ
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(3, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 21;
			this->dataGridView2->Size = System::Drawing::Size(369, 177);
			this->dataGridView2->TabIndex = 0;
			// 
			// 番号が飛ぶ
			// 
			this->番号が飛ぶ->HeaderText = L"No2";
			this->番号が飛ぶ->Name = L"番号が飛ぶ";
			// 
			// カテゴリ
			// 
			this->カテゴリ->HeaderText = L"CatL2";
			this->カテゴリ->Name = L"カテゴリ";
			// 
			// コメ
			// 
			this->コメ->HeaderText = L"Cmt2";
			this->コメ->Name = L"コメ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 325);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// 関数定義
	private: 

		// 共通処理
		
		// 内部処理
		// System::String → char*
		const char* systemStringToChar(System::String^ systemStr);
		// System::String→std::string
		std::string systemStringToStdString(System::String ^ s);
		// System::String→int
		int systemStringToInt(System::String^ systemStr);

		// ロードボタンを翠にする判断
		void ActiveLoad();

		// メニューからの処理
		System::Void 開くToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void MenuFPathForm_Click(System::Object^  sender, System::EventArgs^  e);
		// エクセル読み込みボタン
		System::Void BtnExcelLoad_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void BtnSWLoad_Click(System::Object^  sender, System::EventArgs^  e);
		// 全部読み込むボタン
		System::Void BtnLoad_Click(System::Object^  sender, System::EventArgs^  e);

		// メインロード時
		System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);

		// エクセル処理箇所 --------------------------------------------------
		System::Void ExcelLoadRange(Worksheet^ WsTmp, System::String ^ sysstrQuery, int& nBeginRow, int& nRowMax, int& nColMax);
		System::Void ExcelS1Load(Worksheet^ WsTmp);
		System::Void ExcelS2Load(Worksheet^ WsTmp);
		System::Void ExcelLoad(System::String^ sysstrFPath);
};
}

#endif