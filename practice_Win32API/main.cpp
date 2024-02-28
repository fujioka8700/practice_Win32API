#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	TCHAR tchStr[128];

	wsprintf(tchStr, _T("インスタンスハンドル : %d"), 100);

	MessageBox(NULL, tchStr, TEXT("Kitty on your lap"), MB_OK);

	return 0;
}