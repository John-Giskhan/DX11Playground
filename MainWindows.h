#pragma once
#include <Windows.h>
#include "Renderer/Renderer.h"
#include <memory>
class MainWindow
{

public:
	static LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	MainWindow(
		PCWSTR lpWindowName,
		DWORD dwStyle,
		DWORD dwExStyle = 0,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT,
		int nHeight = CW_USEDEFAULT,
		HWND hWndParent = 0,
		HMENU hMenu = 0
	);
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;
	HWND GetWindowHandle() const;
	PCWSTR  ClassName() const;

	std::unique_ptr<Renderer> m_Renderer;

private:
	HWND m_hwnd;
};

