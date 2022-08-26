#pragma once
#include "../Renderer/Interfaces/IDevice.h"
#include <d3d11.h>

class DX11Device :
	public IDevice
{
public:
	DX11Device();
	virtual ~DX11Device();
	inline void* GetRawDevice() override { return device; }
	inline void* GetRawDeviceContext() override { return device_context; }
private:
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* device_context = nullptr;
};

