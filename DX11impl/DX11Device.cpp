#include "DX11Device.h"

DX11Device::DX11Device()
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
		&device_context);

	////get the texture from the swap chain (back buffer) buffer #0
	//ID3D11Resource* p_back_buffer = nullptr;
	//swap_Chain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&p_back_buffer));
	//device->CreateRenderTargetView(p_back_buffer, nullptr, &render_target_view);
}

DX11Device::~DX11Device()
{
	if (device_context != nullptr) {
		device_context->Release();
	}
	if (device != nullptr) {
		device->Release();
	}
}
