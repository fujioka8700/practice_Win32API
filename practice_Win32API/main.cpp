#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	CONST TCHAR* str1 = _T("Kitty on your lap");
	TCHAR str2[32];

	lstrcpyn(str2, str1, lstrlen(str1) + 1);
	MessageBox(NULL, str2, str2, MB_OK);

	return 0;
}