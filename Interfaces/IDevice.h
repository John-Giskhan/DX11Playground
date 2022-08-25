#pragma once
class IDevice
{
public:
	virtual void Create(IDevice& p_device) = 0;
	virtual void Release() = 0;
	virtual void ClearRenderTargetView(float red, float green, float blue, float alpha) = 0;
};

