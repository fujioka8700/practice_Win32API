#include <windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	MessageBox(NULL, TEXT("Kitty on your lap"), TEXT("メッセージボックス"), MB_OK | MB_ICONINFORMATION);

	return 0;
}