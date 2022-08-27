#include "DX11Device.h"
#include "../Graphics.h"

void DX11Device::Create(IDevice& p_Device)
{
	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Device* device;
	ID3D11DeviceContext* device_Context;
	const D3D_FEATURE_LEVEL featureLevelArray[3] = { D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1 };
	D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createDeviceFlags,
		featureLevelArray,
		3,
		D3D11_SDK_VERSION,
		&device,
		&featureLevel,
		&device_Context);
}

void DX11Device::Release()
{
}

void DX11Device::ClearRenderTargetView(float red, float green, float blue, float alpha)
{
	float color[4] = { red, green, blue, alpha };
	p_Device_Context->ClearRenderTargetView(Graphics::p_render_target_view, color);
}
