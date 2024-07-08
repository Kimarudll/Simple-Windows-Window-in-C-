#include <Windows.h>


LRESULT WINAPI WindowProc(_In_ HWND hWnd, _In_ UINT msg, _In_opt_ WPARAM wP, _In_opt_ LPARAM lP) {

	switch (msg) {

		case WM_CLOSE: {

			DestroyWindow(hWnd);

		}break;

		case WM_DESTROY: {

			PostQuitMessage(0);

		}break;

	}

	return DefWindowProc(hWnd, msg, wP, lP);

}

bool WINAPI createWindow(_In_ LPCWSTR wndName, _In_ HINSTANCE hInst, _In_ int cmdShow) {

	HWND hWnd{};
	WNDCLASSEX wc{};

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hInst;
	wc.lpszClassName = wndName;
	wc.lpfnWndProc = WindowProc;

	RegisterClassEx(&wc);

	const HWND Window = CreateWindowEx(0, wndName, wndName, WS_CAPTION, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, hWnd, NULL, hInst, NULL);

	if (Window == NULL) return false;

	ShowWindow(Window, cmdShow);
	UpdateWindow(Window);

	MSG msg;

	while (GetMessage(&msg, Window, NULL, NULL)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return true;

}

int WINAPI wWinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE prevInst, _In_ LPWSTR cmdLine, _In_ int cmdShow) {

	createWindow(L"My Window", hInst, cmdShow);

	return 0;

}