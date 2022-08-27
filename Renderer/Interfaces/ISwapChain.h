#pragma once
#include "IDevice.h"
#include <Windows.h>


class ISwapChain
{
public:
	static ISwapChain* Get(IDevice* device);
	virtual void* GetRawSwapChain() = 0;
	virtual void* GetBackBuffer() const = 0;
	virtual void Present() = 0;
	virtual ~ISwapChain();
};
