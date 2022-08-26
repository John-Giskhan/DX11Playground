#include "DX11Device.h"
#include "../Graphics.h"

IDevice* DX11Device::Create()
{
	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
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

DX11Device::~DX11Device()
{
	if (device_Context != nullptr) {
		device_Context->Release();
	}
	if (device != nullptr) {
		device->Release();
	}
}
