#pragma once

class IDevice
{
public:
	static IDevice* Create();
	virtual void* GetRawDevice();
	virtual void* GetRawDeviceContext();
	virtual ~IDevice();
};