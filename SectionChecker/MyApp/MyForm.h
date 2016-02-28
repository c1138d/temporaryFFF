#pragma once

namespace MyApp02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  番号;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ファイル名;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  更新日時;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  作成日時;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ファイルパス;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  エラー内容;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  該当ファイル;









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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->番号 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ファイル名 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->更新日時 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->作成日時 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ファイルパス = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->エラー内容 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->該当ファイル = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(210, 19);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->番号, this->ファイル名,
					this->更新日時, this->作成日時, this->ファイルパス
			});
			this->dataGridView1->Location = System::Drawing::Point(10, 45);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(280, 215);
			this->dataGridView1->TabIndex = 2;
			// 
			// 番号
			// 
			this->番号->HeaderText = L"番号";
			this->番号->Name = L"番号";
			this->番号->ReadOnly = true;
			// 
			// ファイル名
			// 
			this->ファイル名->HeaderText = L"ファイル名";
			this->ファイル名->Name = L"ファイル名";
			this->ファイル名->ReadOnly = true;
			// 
			// 更新日時
			// 
			this->更新日時->HeaderText = L"更新日時";
			this->更新日時->Name = L"更新日時";
			this->更新日時->ReadOnly = true;
			// 
			// 作成日時
			// 
			this->作成日時->HeaderText = L"作成日時";
			this->作成日時->Name = L"作成日時";
			this->作成日時->ReadOnly = true;
			// 
			// ファイルパス
			// 
			this->ファイルパス->HeaderText = L"ファイルパス";
			this->ファイルパス->Name = L"ファイルパス";
			this->ファイルパス->ReadOnly = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 285);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(625, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->エラー内容,
					this->該当ファイル
			});
			this->dataGridView2->Location = System::Drawing::Point(355, 45);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 21;
			this->dataGridView2->Size = System::Drawing::Size(255, 215);
			this->dataGridView2->TabIndex = 4;
			// 
			// エラー内容
			// 
			this->エラー内容->HeaderText = L"エラー内容";
			this->エラー内容->Name = L"エラー内容";
			// 
			// 該当ファイル
			// 
			this->該当ファイル->HeaderText = L"該当ファイル";
			this->該当ファイル->Name = L"該当ファイル";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 307);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// 読み込みフォルダ選択ボタン
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//ﾌｧｲﾙを開くダイアログの作成 
		FolderBrowserDialog^ dlg = gcnew FolderBrowserDialog;
		dlg->Description = "txt/logのフォルダを選択してください";

		//ダイアログの表示 （Cancelボタンがクリックされた場合は何もしない）
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		//取得したファイル名 
		String^ FolderName = dlg->SelectedPath;
		textBox1->Text = FolderName;

		// 表の初期設定
		dataGridView1->Rows->Clear();		// クリア
		DataGridViewRowCollection^ rows = dataGridView1->Rows;

		// 選択したフォルダのファイルを表示する
		array<String^>^ ArrDirFileName = Directory::GetFiles(FolderName);//フォルダー内のファイル名を配列に入れる  
		
		for (int i = 0; i < ArrDirFileName->Length; i++){
			String^ FileName = Path::GetFileName(ArrDirFileName[i]);
			FileInfo^ fileInfo = gcnew FileInfo(ArrDirFileName[i]);
			
			rows->Add(i, FileName, fileInfo->LastWriteTime, fileInfo->CreationTime, ArrDirFileName[i] + "\r\n");
		}

		// 選択したセルのファイルを開いて、中身を表に書きだす
		// 表の初期設定
		dataGridView2->Rows->Clear();		// クリア
		DataGridViewRowCollection^ dgv2rows = dataGridView2->Rows;

		StreamReader^ din = File::OpenText(ArrDirFileName[0]);
		String^ str;
		String^ strExt;
		int count = 0;
		while ((str = din->ReadLine()) != nullptr)
		{
			// 拡張子を探せ
			if (str->IndexOf(".") != -1) strExt = str;
			// 格納
			if (str->IndexOf("err") != -1) dgv2rows->Add(str, strExt);
			if (str->IndexOf("Error") != -1) dgv2rows->Add(str, strExt);
			count++;
		}
	}
	};
}
