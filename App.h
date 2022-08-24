#pragma once
#include "MainWindows.h"

class App
{
public:
	App();
	int Run();

private:
	MainWindow main_window;
	void MakeNextFrame();
};

