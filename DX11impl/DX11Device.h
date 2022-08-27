#pragma once
#include "../Renderer/Interfaces/IDevice.h"
#include <d3d11.h>

class DX11Device final :
	public IDevice
{
public:
	DX11Device(HWND hwnd);
	~DX11Device() override;
	void* GetRawDevice() override { return device; }
	void* GetRawDeviceContext() override { return device_context; }
	void* GetRawSwapChain() override {return swap_chain;}
private:
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* device_context = nullptr;
	IDXGISwapChain* swap_chain = nullptr;
};
