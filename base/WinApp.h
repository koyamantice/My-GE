#pragma once
#include<Windows.h>

class WinApp {
private:
	WNDCLASSEX w{};
	HWND hwnd = nullptr;
public:
	static const int window_width = 1080;//����
	static const int window_height = 720;//�c��

	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparm, LPARAM lparam);
	//getter
	HWND GetHwnd() { return hwnd; }
	HINSTANCE GetHInstance() { return w.hInstance; }
public:
	int SetWinCenter();
	void Initialize();
	void Update();
	bool ProcessMessage();
	void Finalize();
};

