#include "MyForm.h" // [2]�ŕt����Form��.h
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

// �O���[�o���ϐ���`

vector<ST_S1_CONTENT> g_vecS1;
vector<ST_S2_CONTENT> g_vecS2;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	// gcnew [1]�ŕt�����v���W�F�N�g��::[2]�ŕt����Form��()
	System::Windows::Forms::Application::Run(gcnew MyApp::MyForm());

	return 0;
}