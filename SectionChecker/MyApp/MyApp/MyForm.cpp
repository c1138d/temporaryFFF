// ���ʏ�������
#include "MyForm.h"

using namespace MyApp;

// ������ϊ����� ---------------
// System::String �� char*
const char* MyForm::systemStringToChar(System::String^ systemStr)
{
	using namespace System;
	using namespace System::Runtime::InteropServices;

	// �����R�[�h�́A���ɍ��킹��(���ʂ�UTF-8)
	int len = System::Text::Encoding::GetEncoding("UTF-8")->GetByteCount(systemStr);
	if (len > 0){
		char* rtnSts = new char[len + 1];
		memset(rtnSts, 0x00, sizeof(char)*len + 1);
		const char* buf = static_cast<const char*>((Marshal::StringToHGlobalAnsi(systemStr)).ToPointer());
		// �擾������������R�s�[
		strncpy_s(rtnSts, len + 1, buf, _TRUNCATE);
		// �������J��
		Marshal::FreeHGlobal(IntPtr((void*)buf));
		return rtnSts;
	}
	return NULL;
}
// System::String��std::string
std::string MyForm::systemStringToStdString(System::String ^ s) 
{
	using namespace System::Runtime::InteropServices;

	IntPtr hString = Marshal::StringToHGlobalAnsi(s);
	if (hString == System::IntPtr::Zero) return "";

	std::string rtnSts = (const char *)hString.ToPointer();
	Marshal::FreeHGlobal(hString);
	return rtnSts;
}

// System::String��int
int MyForm::systemStringToInt(System::String^ systemStr)
{
	using namespace System;
	using namespace System::Runtime::InteropServices;
	const char* chars = systemStringToChar(systemStr);
	// NULL��������0��Ԃ�
	int rtnSts = 0;
	if (chars != NULL){
		rtnSts = atoi(chars);
	}
	delete chars;
	return rtnSts;
}

// ���[�h�{�^����L���ɂ��邩�̏���
void MyForm::ActiveLoad()
{
	if (BtnExcelLoad->BackColor == Color::YellowGreen) BtnLoad->BackColor = Color::YellowGreen;
}


// ���C���t�H�[�����[�h��
void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//
	FormPathObj = gcnew MyFormPath();
}

// ���j���[����̏��� ------------------------------------------------------------------------------
// ���j���[����J��
void MyForm::�J��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{

}
// �ǂݍ��݃p�X�t�H�[���\��
void MyForm::MenuFPathForm_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ���łɊJ���Ă����ꍇ�ɊJ���Ȃ�
	if (FormPathObj->Visible) return;
	FormPathObj->Show();		// ���[�h���X
}

// �{�^������ ------------------------------------------------------------------------------------
// SW�J���{�^��
void MyForm::BtnSWLoad_Click(System::Object^  sender, System::EventArgs^  e)
{

}

// �S���ǂݍ��ރ{�^��
void MyForm::BtnLoad_Click(System::Object^  sender, System::EventArgs^  e)
{
	// �G�N�Z���ǂݍ��ݏ���(�{�^�������Ȃ���s����)
	if (BtnLoad->BackColor != Color::YellowGreen) return;
	//
	// �G�N�Z�����[�h
	ExcelLoad(g_sysstrExcelPath);
	//
	// gridview1�ɕ\��
	this->dataGridView1->Rows->Clear();
	for (unsigned int i = 0; i < g_vecS1.size(); i++){
		// std::string->system string�ɕϊ�
		String^	sysstrNo = Convert::ToString(g_vecS1[i].m_no);
		String^	sysstrCatL = gcnew String(g_vecS1[i].m_strCatL.c_str());
		String^	sysstrCmt = gcnew String(g_vecS1[i].m_strCmt.c_str());
		this->dataGridView1->Rows->Add(sysstrNo, sysstrCatL, sysstrCmt);
	}
	// gridview2�ɕ\��
	this->dataGridView2->Rows->Clear();
	for (unsigned int i = 0; i < g_vecS2.size(); i++){
		// std::string->system string�ɕϊ�
		String^	sysstrNo = Convert::ToString(g_vecS2[i].m_no);
		String^	sysstrCatL = gcnew String(g_vecS2[i].m_strCatL.c_str());
		String^	sysstrCmt = gcnew String(g_vecS2[i].m_strCmt.c_str());
		this->dataGridView2->Rows->Add(sysstrNo, sysstrCatL, sysstrCmt);
	}

}

