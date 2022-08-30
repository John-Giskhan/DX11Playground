#pragma once
#include <Windows.h>
#include "Renderer/Renderer.h"
#include <memory>

class MainWindow
{
public:
	static LRESULT WindowProc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param);
	LRESULT HandleMessage(UINT u_msg, WPARAM w_param, LPARAM l_param) const;
	MainWindow(
		PCWSTR lp_window_name,
		DWORD dw_style,
		DWORD dw_ex_style = 0,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		int width = 800,
		int height = 600,
		HWND h_wnd_parent = nullptr,
		HMENU h_menu = nullptr
	);
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;
	HWND GetWindowHandle() const;
	static PCWSTR ClassName();

	std::unique_ptr<Renderer> m_renderer;

private:
	HWND m_hwnd;
};
