#include "App.h"
#include "MainWindows.h"
#include <Windows.h>

App::App() : main_window(L"el Window", WS_OVERLAPPEDWINDOW)
{}
int App::Run()
{
	// Run the message loop.

	MSG msg = { };
	bool quit = false;
	while (!quit)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) //PeekMessage return automatically if there's no messages
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);	//calls the window procedure of the window that is the target of the message
			if (msg.message == WM_QUIT)
				quit = true;
		}
		if (quit)
			break;
		MakeNextFrame();
	}
	// Cleanup here
	return 0;
}

void App::MakeNextFrame()
{
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	main_window.m_Graphics->ClearRenderTargetView(r, 0.0f, 0.0f, 1.0f);
	main_window.m_Graphics->EndFrame();
}
