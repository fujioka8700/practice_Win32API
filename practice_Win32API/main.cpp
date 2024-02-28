#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	TCHAR str1[128] = _T("Kitty on your lap\n");
	CONST TCHAR* str2 = _T("Tokyo mew mew");

	lstrcat(str1, str2);
	MessageBox(NULL, str1, str2, MB_OK);

	return 0;
}