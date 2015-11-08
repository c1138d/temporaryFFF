#include "MyForm.h" // [2]で付けたForm名.h
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

// グローバル変数定義

vector<ST_S1_CONTENT> g_vecS1;
vector<ST_S2_CONTENT> g_vecS2;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	// gcnew [1]で付けたプロジェクト名::[2]で付けたForm名()
	System::Windows::Forms::Application::Run(gcnew MyApp::MyForm());

	return 0;
}