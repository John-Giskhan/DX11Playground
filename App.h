#pragma once
#include "MainWindows.h"

class App
{
public:
	App();
	int Run() const;

private:
	MainWindow main_window;
	void NextFrame() const;
};
