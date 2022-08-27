#pragma once
#include "IDevice.h"

class ISwapChain
{
public:
	static ISwapChain* Get(IDevice* device);
	virtual void* GetRawSwapChain() = 0;
	virtual void* GetBackBuffer() = 0;
	virtual void Present() = 0;
	virtual ~ISwapChain();
};
