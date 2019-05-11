#include "MyForm.h"

using namespace Carat;

[STAThreadAttribute]

void ShowForm() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}