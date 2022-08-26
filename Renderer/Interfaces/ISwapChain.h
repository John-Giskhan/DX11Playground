#pragma once
#include "IDevice.h"
#include <Windows.h>
class ISwapChain
{
public:
	static ISwapChain* Create(IDevice* device, HWND hwnd);

	virtual ~ISwapChain();
};