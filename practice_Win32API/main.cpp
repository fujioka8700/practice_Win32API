#define STRICT
#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	MessageBox(NULL, _T("�����͐������܂����B"), _T("���"), MB_OK | MB_ICONINFORMATION);

	return 0;
}