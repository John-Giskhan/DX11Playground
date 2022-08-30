#include "App.h"
#include "MainWindows.h"
#include <Windows.h>

App::App() : main_window(L"el Window", WS_OVERLAPPEDWINDOW)
{
}

int App::Run() const
{
	// Run the message loop.

	MSG msg = {};
	bool quit = false;
	while (!quit)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) //PeekMessage return automatically if there's no messages
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg); //calls the window procedure of the window that is the target of the message
			if (msg.message == WM_QUIT)
				quit = true;
		}
		if (quit)
			break;
		NextFrame();
	}
	// Cleanup here
	return 0;
}

void App::NextFrame() const
{
	main_window.m_renderer->ClearRenderTargetView(0.0f,0.0f,0.5f,1.0f);
	main_window.m_renderer->DrawTriangle();
	main_window.m_renderer->EndFrame();
}
