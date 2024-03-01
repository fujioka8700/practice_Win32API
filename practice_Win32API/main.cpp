#include <windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	HWND hwnd = CreateWindow(
		TEXT("STATIC"), TEXT("Kitty on your lap"),
		WS_CAPTION,
		100, 100, 200, 200, NULL, NULL,
		hInstance, NULL
	);

	if (hwnd == NULL) return 0;

	ShowWindow(hwnd, SW_SHOW);
	MessageBox(NULL, TEXT("Kitty on your lap"),
		TEXT("Kitty"), MB_ICONINFORMATION);

	return 0;
}