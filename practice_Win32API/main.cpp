#define STRICT
#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	MessageBox(NULL, _T("ˆ—‚Í¬Œ÷‚µ‚Ü‚µ‚½B"), _T("î•ñ"), MB_OK | MB_ICONINFORMATION);

	return 0;
}