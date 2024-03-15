#include <windows.h>

#define TM_COUNT1 1
#define TM_COUNT2 2

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
		HDC hdc;
		PAINTSTRUCT ps;
		RECT rctSize;
		static int iCount1 = 0, iCount2 = 0;
		static TCHAR strCount[64];

		switch (msg) {
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			case WM_CREATE:
				SetTimer(hwnd, TM_COUNT1, 100, NULL);
				SetTimer(hwnd, TM_COUNT2, 500, NULL);
				return 0;
			case WM_TIMER:
				switch (wp) {
					case TM_COUNT1:
						iCount1++;
						break;
					case TM_COUNT2:
						iCount2++;
						break;
				}
				InvalidateRect(hwnd, NULL, TRUE);
				return 0;
			case WM_PAINT:
				hdc = BeginPaint(hwnd, &ps);

				wsprintf(strCount, "TM_COUNT1 = %d\nTM_COUNT2 = %d",
					iCount1, iCount2
				);
				GetClientRect(hwnd, &rctSize);
				DrawText(hdc, strCount, -1, &rctSize, DT_LEFT);
				EndPaint(hwnd, &ps);
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

	while (GetMessage(&msg, NULL, 0, 0)) DispatchMessage(&msg);

	return (int)msg.wParam;
}