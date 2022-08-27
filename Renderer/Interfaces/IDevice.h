#pragma once
#include <Windows.h>
class IDevice
{
public:
	static IDevice* Create(HWND hwnd);
	virtual void* GetRawDevice() = 0;
	virtual void* GetRawDeviceContext() = 0;
	virtual	void* GetRawSwapChain() = 0;
	virtual ~IDevice();
};
