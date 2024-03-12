#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	HDC hdc;
	PAINTSTRUCT ps;
	HRGN hrgn;

	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_KEYDOWN:
			hdc = GetDC(hwnd);
			hrgn = CreateEllipticRgn(50, 10, 200, 150);

			SelectObject(hdc, GetStockObject(WHITE_PEN));
			Rectangle(hdc, 10, 10, 400, 200);
			
			InvalidateRect(hwnd, NULL, TRUE);
			ValidateRgn(hwnd, hrgn);

			DeleteObject(hrgn);
			ReleaseDC(hwnd, hdc);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);

			SelectObject(hdc, GetStockObject(BLACK_BRUSH));
			Rectangle(hdc, 10, 10, 400, 200);

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
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL
	);

	if (hwnd == NULL) return -1;

	while (GetMessage(&msg, NULL, 0, 0)) {
		// TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}