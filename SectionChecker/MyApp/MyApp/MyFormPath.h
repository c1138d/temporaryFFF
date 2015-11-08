#pragma once

namespace MyApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyFormPath の概要
	/// </summary>
	public ref class MyFormPath : public System::Windows::Forms::Form
	{
	public:
		MyFormPath(void)
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
		~MyFormPath()
		{
			if (components)
			{
				delete components;
			}
		}
	public: 
		System::Windows::Forms::TextBox^  TbExcelPath;			// メインフォームから表示するため
		
	private: 
		System::Windows::Forms::Button^  BtnPathExcelLoad;
	protected:

	protected:

	private: System::Windows::Forms::Label^  LbExcelPath;


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
			this->TbExcelPath = (gcnew System::Windows::Forms::TextBox());
			this->BtnPathExcelLoad = (gcnew System::Windows::Forms::Button());
			this->LbExcelPath = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TbExcelPath
			// 
			this->TbExcelPath->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->TbExcelPath->Location = System::Drawing::Point(50, 5);
			this->TbExcelPath->Name = L"TbExcelPath";
			this->TbExcelPath->Size = System::Drawing::Size(285, 24);
			this->TbExcelPath->TabIndex = 0;
			// 
			// BtnPathExcelLoad
			// 
			this->BtnPathExcelLoad->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnPathExcelLoad->Location = System::Drawing::Point(335, 5);
			this->BtnPathExcelLoad->Name = L"BtnPathExcelLoad";
			this->BtnPathExcelLoad->Size = System::Drawing::Size(35, 25);
			this->BtnPathExcelLoad->TabIndex = 1;
			this->BtnPathExcelLoad->Text = L"...";
			this->BtnPathExcelLoad->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BtnPathExcelLoad->UseVisualStyleBackColor = true;
			// 
			// LbExcelPath
			// 
			this->LbExcelPath->AutoSize = true;
			this->LbExcelPath->Font = (gcnew System::Drawing::Font(L"メイリオ", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->LbExcelPath->Location = System::Drawing::Point(5, 5);
			this->LbExcelPath->Name = L"LbExcelPath";
			this->LbExcelPath->Size = System::Drawing::Size(36, 17);
			this->LbExcelPath->TabIndex = 2;
			this->LbExcelPath->Text = L"Excel";
			// 
			// MyFormPath
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 110);
			this->Controls->Add(this->LbExcelPath);
			this->Controls->Add(this->BtnPathExcelLoad);
			this->Controls->Add(this->TbExcelPath);
			this->Name = L"MyFormPath";
			this->Text = L"MyFormPath";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
