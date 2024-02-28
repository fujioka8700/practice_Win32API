#include <windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	int on_button;

	on_button = MessageBox(NULL, TEXT("Do you like Nekomimi?"),
		TEXT("質問しています"), MB_YESNO | MB_ICONQUESTION);

	if (on_button == IDYES) {
		MessageBox(NULL, TEXT("You are nice!"),
			TEXT("メッセージボックス"), MB_OK);
	}
	
	if (on_button == IDNO) {
		MessageBox(NULL, TEXT("Be Killed!"),
			TEXT("メッセージボックス"), MB_OK);
	}

	return 0;
}