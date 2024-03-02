#include <windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	HWND hwnd;
	MSG msg;

	hwnd = CreateWindow(
		TEXT("BUTTON"), TEXT("Kitty on your lap"),
		WS_CAPTION | WS_VISIBLE,
		100, 100, 200, 200, NULL, NULL,
		hInstance, NULL
	);

	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg, NULL, 0, 0);
		if (msg.message == WM_LBUTTONUP) break;
		DispatchMessage(&msg);
	}
	return 0;
}