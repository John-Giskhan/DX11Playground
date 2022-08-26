#pragma once
class IDevice
{
public:
	static IDevice* Create();
	virtual ~IDevice();
};

