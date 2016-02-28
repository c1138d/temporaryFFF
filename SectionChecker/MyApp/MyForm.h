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
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �ԍ�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �t�@�C����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �X�V����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �쐬����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �t�@�C���p�X;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �G���[���e;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �Y���t�@�C��;









	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->�ԍ� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�t�@�C���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�X�V���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�쐬���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�t�@�C���p�X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->�G���[���e = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�Y���t�@�C�� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
				this->�ԍ�, this->�t�@�C����,
					this->�X�V����, this->�쐬����, this->�t�@�C���p�X
			});
			this->dataGridView1->Location = System::Drawing::Point(10, 45);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(280, 215);
			this->dataGridView1->TabIndex = 2;
			// 
			// �ԍ�
			// 
			this->�ԍ�->HeaderText = L"�ԍ�";
			this->�ԍ�->Name = L"�ԍ�";
			this->�ԍ�->ReadOnly = true;
			// 
			// �t�@�C����
			// 
			this->�t�@�C����->HeaderText = L"�t�@�C����";
			this->�t�@�C����->Name = L"�t�@�C����";
			this->�t�@�C����->ReadOnly = true;
			// 
			// �X�V����
			// 
			this->�X�V����->HeaderText = L"�X�V����";
			this->�X�V����->Name = L"�X�V����";
			this->�X�V����->ReadOnly = true;
			// 
			// �쐬����
			// 
			this->�쐬����->HeaderText = L"�쐬����";
			this->�쐬����->Name = L"�쐬����";
			this->�쐬����->ReadOnly = true;
			// 
			// �t�@�C���p�X
			// 
			this->�t�@�C���p�X->HeaderText = L"�t�@�C���p�X";
			this->�t�@�C���p�X->Name = L"�t�@�C���p�X";
			this->�t�@�C���p�X->ReadOnly = true;
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
				this->�G���[���e,
					this->�Y���t�@�C��
			});
			this->dataGridView2->Location = System::Drawing::Point(355, 45);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 21;
			this->dataGridView2->Size = System::Drawing::Size(255, 215);
			this->dataGridView2->TabIndex = 4;
			// 
			// �G���[���e
			// 
			this->�G���[���e->HeaderText = L"�G���[���e";
			this->�G���[���e->Name = L"�G���[���e";
			// 
			// �Y���t�@�C��
			// 
			this->�Y���t�@�C��->HeaderText = L"�Y���t�@�C��";
			this->�Y���t�@�C��->Name = L"�Y���t�@�C��";
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
		// �ǂݍ��݃t�H���_�I���{�^��
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//̧�ق��J���_�C�A���O�̍쐬 
		FolderBrowserDialog^ dlg = gcnew FolderBrowserDialog;
		dlg->Description = "txt/log�̃t�H���_��I�����Ă�������";

		//�_�C�A���O�̕\�� �iCancel�{�^�����N���b�N���ꂽ�ꍇ�͉������Ȃ��j
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		//�擾�����t�@�C���� 
		String^ FolderName = dlg->SelectedPath;
		textBox1->Text = FolderName;

		// �\�̏����ݒ�
		dataGridView1->Rows->Clear();		// �N���A
		DataGridViewRowCollection^ rows = dataGridView1->Rows;

		// �I�������t�H���_�̃t�@�C����\������
		array<String^>^ ArrDirFileName = Directory::GetFiles(FolderName);//�t�H���_�[���̃t�@�C������z��ɓ����  
		
		for (int i = 0; i < ArrDirFileName->Length; i++){
			String^ FileName = Path::GetFileName(ArrDirFileName[i]);
			FileInfo^ fileInfo = gcnew FileInfo(ArrDirFileName[i]);
			
			rows->Add(i, FileName, fileInfo->LastWriteTime, fileInfo->CreationTime, ArrDirFileName[i] + "\r\n");
		}

		// �I�������Z���̃t�@�C�����J���āA���g��\�ɏ�������
		// �\�̏����ݒ�
		dataGridView2->Rows->Clear();		// �N���A
		DataGridViewRowCollection^ dgv2rows = dataGridView2->Rows;

		StreamReader^ din = File::OpenText(ArrDirFileName[0]);
		String^ str;
		String^ strExt;
		int count = 0;
		while ((str = din->ReadLine()) != nullptr)
		{
			// �g���q��T��
			if (str->IndexOf(".") != -1) strExt = str;
			// �i�[
			if (str->IndexOf("err") != -1) dgv2rows->Add(str, strExt);
			if (str->IndexOf("Error") != -1) dgv2rows->Add(str, strExt);
			count++;
		}
	}
	};
}
