#include "DX11Device.h"
#include "DX11DeviceContext.h"


DX11DeviceContext::DX11DeviceContext(DX11Device* device)
{
	device_context = (ID3D11DeviceContext*)device->GetRawDeviceContext();
	////get the texture from the swap chain (back buffer) buffer #0
	//ID3D11Resource* p_back_buffer = nullptr;
	//swap_Chain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&p_back_buffer));
	//device->CreateRenderTargetView(p_back_buffer, nullptr, &render_target_view);
}

DX11DeviceContext::~DX11DeviceContext()
{
}
