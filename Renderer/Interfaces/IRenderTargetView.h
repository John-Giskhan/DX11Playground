#pragma once
#include "IDevice.h"
#include "ISwapChain.h"

class IRenderTargetView
{
public:
	static IRenderTargetView* Create(IDevice* p_device, ISwapChain* p_swapchain);
	virtual void* GetRawRenderTargetView() = 0;
	virtual ~IRenderTargetView();
};
