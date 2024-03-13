#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static TCHAR strLocation[128];
	static unsigned short int x = 0, y = 0;

	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_NCLBUTTONDOWN:
			x = LOWORD(lp);
			y = HIWORD(lp);
			wsprintf(strLocation, "x���W = %d\ny���W = %d\nHITTEST = %d", x, y, wp);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);

			GetClientRect(hwnd, &rect);
			DrawText(hdc, strLocation, -1, &rect, DT_LEFT);

			EndPaint(hwnd, &ps);
			return 0;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	HWND hwnd;
	WNDCLASS winc;
	MSG msg;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("KITTY");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
		TEXT("KITTY"), TEXT("Kitty on your lap"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		400, 200,
		NULL, NULL, hInstance, NULL
	);

	if (hwnd == NULL) return -1;

	while (GetMessage(&msg, NULL, 0, 0)) {
		// TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}