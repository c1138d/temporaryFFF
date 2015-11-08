// �G�N�Z���֘A
/* �ݒ胁��
	1�FMicrosoft Excel 11.0 Object Library ���Q�Ƃɒǉ�
	2�FCLR Support �� /clr:pure
	3�Fusing namespace Microsoft::Office::Interop::Excel;
*/
#include "MyForm.h"

using namespace MyApp;
using namespace Microsoft::Office::Interop::Excel;				// Excel�g�p�̂��߁i�Q�Ƃ���E���Ă���j

// �G�N�Z���ǂݍ��݃{�^�����p�X���Z�b�g������
void MyForm::BtnExcelLoad_Click(System::Object^  sender, System::EventArgs^  e)
{
	// �G�N�Z���t�@�C���ǂݍ���
	// �J�n�f�B���N�g��
	openFileDialog1->InitialDirectory = g_sysstrDir;
	// �t�@�C�������݂��邩�ǂ���
	openFileDialog1->FileName = nullptr;
	// �g���q�ݒ�
	openFileDialog1->Filter = "�G�N�Z���t�@�C��(*.xlsx)|*.xlsx|" + "���ׂẴt�@�C��(*.*)|*.*";
	openFileDialog1->FilterIndex = 1;

	// �_�C�����O�L�����Z�������ꍇ�͉������Ȃ� ---------------------------------------------------
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	// �擾�����t�@�C�������p�X�t�H�[���֓o�^���邽�߂ɁA�O���[�o����`�Ɋi�[
	//FormPathObj->TbExcelPath->Text = openFileDialog1->FileName;
	g_sysstrExcelPath = openFileDialog1->FileName;
	// �{�^���𐉐F�ɂ���
	BtnExcelLoad->BackColor = Color::YellowGreen;
	// ���[�h�{�^�����L���ɂȂ邩���f����
	ActiveLoad();
	// �Ή�����V�[�g���Ȃ������ꍇ�̓��b�Z�[�W
	// �ǂݍ��񂾃t�@�C���̃a���N�g�������擾�������f�B���N�g���ɐݒ�
	g_sysstrDir = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
}

// -------------------------------------------------------------------------------------------

// �V�[�g�̓ǂݍ��ݔ͈͌���(�l�͌��̂��X�V�������̂ŎQ�Ɠn��)
void MyForm::ExcelLoadRange(Worksheet^ Ws1, System::String ^ sysstrQuery, int& nRow, int& nRowMax, int& nColMax)
{
	// �c�̕�
	nRowMax = Ws1->Cells->SpecialCells(Microsoft::Office::Interop::Excel::XlCellType::xlCellTypeLastCell, System::Reflection::Missing::Value)->Row+1;
	// ���[�v�ŉ����m�F --- -> �֐����ł���@�ǂݍ��ޔ͈͂̍ŏ��̒l�Ɖ��̗�̌��E���擾����
	for (; nRow < nRowMax; nRow++){
		Range^ rgnF = static_cast<Range^>(Ws1->Cells[nRow, 1]);                // ��ԍ��[�̕�����𒲂ׂ�
		String^ sysstrval = rgnF->Text->ToString();
		if (sysstrval == sysstrQuery){   // �������P��ƈ�v�����ꍇ(�V�[�g���ƂɒP���ς���)
			// �Y�����镶���񂾂����ꍇ�A���̍s�̕�����ۑ����K���Y������悤�ɂ���
			while (true){
				Range^ rgnS = static_cast<Range^>(Ws1->Cells[nRow, nColMax]);  // �Z���擾
				if (rgnS->Value2 == nullptr){        // �����񂪂Ȃ��Ȃ����烋�[�v���ʂ���
					break;
				}
				nColMax++;
			}
			break;
		}
	}
	nRow++;			// �ǂݍ��ޕ\�͎��̍s����Ȃ̂�1�s�����Ă���
}

// �V�[�g1���[�h����
void MyForm::ExcelS1Load(Worksheet^ Ws1)
{
	// �V�[�g������
	Ws1->Select(Type::Missing);

	// �V�[�g�̓ǂݍ��ޏc���͈̔͌��肷���`
	int nRow = 1;
	int nRowMax = 1;
	int nColMax = 1;

	// �ǂݍ��ޏc���͈̔͂ƊJ�n�s��ݒ肷��i�ǂݍ��ޔ͈͂̍ŏ��̒P����o�^�j
	ExcelLoadRange(Ws1, "�ԍ�", nRow, nRowMax, nColMax);					//����

	for (; nRow < nRowMax; nRow++){
		ST_S1_CONTENT st_s1content;			// �i�[�p�i1�s���ƂɃ��Z�b�g�j
		bool bNo = false;					// �i�[�t���O
		bool bCatL = false;
		for (int nCol = 1; nCol < nColMax; nCol++){
			Range^ rgntmp = static_cast<Range^>(Ws1->Cells[nRow, nCol]);                // ��ԍ��[�̕�����𒲂ׂ�
			String^ sysstrtmp = rgntmp->Text->ToString();
			switch (nCol)
			{
			case 1:
				// �ԍ����i�[�i�󔒂Ȃ�0�����j
				st_s1content.m_no = systemStringToInt(sysstrtmp);
				if (sysstrtmp == "") bNo = true;;
				break;
			case 2:
				// �J�e�S�����i�[
				st_s1content.m_strCatL = systemStringToStdString(sysstrtmp);
				if (sysstrtmp == "") bCatL = true;
				break;
			case 3:
				// �R�����g�ۑ�
				st_s1content.m_strCmt = systemStringToStdString(sysstrtmp);
				break;
			default:
				break;
			}
		}
		// �O�ӂ����󔒂Ȃ�i�[����
		if (bNo == true && bCatL == true) continue;
		// vector�ɉ�1��i�[
		g_vecS1.push_back(st_s1content);
	}
}

// �V�[�g2���[�h����
void MyForm::ExcelS2Load(Worksheet^ Ws1)
{
	// �V�[�g������
	Ws1->Select(Type::Missing);

	// �V�[�g�̓ǂݍ��ޏc���͈̔͌��肷���`
	int nRow = 1;
	int nRowMax = 1;
	int nColMax = 1;

	// �ǂݍ��ޏc���͈̔͂ƊJ�n�s��ݒ肷��i�ǂݍ��ޔ͈͂̍ŏ��̒P����o�^�j
	ExcelLoadRange(Ws1, "�ԍ�����ԂƂ�", nRow, nRowMax, nColMax);					//����

	for (; nRow < nRowMax; nRow++){
		ST_S2_CONTENT st_s2content;			// �i�[�p�i1�s���ƂɃ��Z�b�g�j
		for (int nCol = 1; nCol < nColMax; nCol++){
			Range^ rgntmp = static_cast<Range^>(Ws1->Cells[nRow, nCol]);                // ��ԍ��[�̕�����𒲂ׂ�
			String^ sysstrtmp = rgntmp->Text->ToString();
			switch (nCol)
			{
			case 1:
				// �ԍ����i�[�i�󔒂Ȃ�0�����j
				st_s2content.m_no = systemStringToInt(sysstrtmp);
				break;
			case 2:
				// �J�e�S�����i�[
				st_s2content.m_strCatL = systemStringToStdString(sysstrtmp);
				break;
			case 3:
				// �R�����g�ۑ�
				st_s2content.m_strCmt = systemStringToStdString(sysstrtmp);
				break;
			default:
				break;
			}
		}
		// vector�ɉ�1��i�[
		g_vecS2.push_back(st_s2content);
	}
}



// �G�N�Z�����[�h����Main�@�����@�G�N�Z���t�@�C���p�X --------------------------- |
void MyForm::ExcelLoad(System::String^ sysstrFPath)
{
	// Excel�I�u�W�F�N�g��V�K�쐬
	Microsoft::Office::Interop::Excel::Application^ ExlApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
	// Excel�N�����邩�ǂ���
	ExlApp->Visible = false;
	// ���[�N�u�b�N�J��
	Workbook^ wb = ExlApp->Workbooks->Open(sysstrFPath,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value,
		System::Reflection::Missing::Value, System::Reflection::Missing::Value
		);
	int nSumWs = wb->Sheets->Count;			// ���[�N�V�[�g�̐�
	// ���[�N�u�b�N�̒��̓���̃V�[�g����������
	int nNumWs = 1;
	for (; nNumWs < nSumWs; nNumWs++) {
		Worksheet^ WsTmp = static_cast<Worksheet^>(wb->Sheets[nNumWs]);
		if (WsTmp->Name == "�ʏ�") ExcelS1Load(WsTmp);  // �V�[�g���������烋�[�v�𔲂���H�܂��͊֐��ĂԁH
		else if (WsTmp->Name == "����") ExcelS2Load(WsTmp);
	}
	//
	wb->Close(false, Type::Missing, Type::Missing);    // Excell�I��
	ExlApp->Quit();
	return;
}



	/*
	// �V�K���[�N�u�b�N�쐬
	Microsoft::Office::Interop::Excel::Application^ xlApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
	Workbook^ wb = xlApp->Workbooks->Add(Type::Missing);

	// ���[�N�V�[�g�폜
	static_cast<Worksheet^>(xlApp->ActiveWorkbook->Sheets->Item[3])->Delete();
	static_cast<Worksheet^>(xlApp->ActiveWorkbook->Sheets->Item[2])->Delete();

	// ���݂̃V�[�g���w��
	Worksheet^ ws = static_cast<Worksheet^>(xlApp->ActiveSheet);

	// ��������
	ws->Name = "Charts";
	ws->Cells[1, 1] = "Hello World!";

	// �A�v���P�[�V�������A�N�e�B�u�ɋN��
	xlApp->Visible = true;
	*/


