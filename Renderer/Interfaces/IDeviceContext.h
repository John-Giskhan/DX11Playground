#pragma once
#include "IRenderTargetView.h"

class IDeviceContext
{
public:
	static IDeviceContext* Get(IDevice* device);

	virtual void ClearRenderTargetView(IRenderTargetView* render_target_view, float color[]) = 0;
	virtual ~IDeviceContext();
};
