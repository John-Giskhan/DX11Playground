#include "Graphics.h"

Graphics::Graphics(HWND hwnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[3] = { D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1 };
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createDeviceFlags,
		featureLevelArray,
		3,
		D3D11_SDK_VERSION,
		&sd,
		&p_SwapChain,
		&p_Device,
		&featureLevel,
		&p_Device_Context);

	//get the texture from the swap chain (back buffer) buffer #0
	ID3D11Resource* p_back_buffer = nullptr;
	p_SwapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&p_back_buffer));
	p_Device->CreateRenderTargetView(p_back_buffer, nullptr, &p_render_target_view);
}

void Graphics::EndFrame()
{
	p_SwapChain->Present(1u, 0u);
}

Graphics::~Graphics()
{
	if (p_render_target_view != nullptr) {
		p_render_target_view->Release();
	}
	if (p_Device_Context != nullptr) {
		p_Device_Context->Release();
	}
	if (p_SwapChain != nullptr) {
		p_SwapChain->Release();
	}
	if (p_Device != nullptr) {
		p_Device->Release();
	}
}

void Graphics::ClearRenderTargetView(float red, float green, float blue, float alpha)
{
	float color[4] = { red, green, blue, alpha };
	p_Device_Context->ClearRenderTargetView(p_render_target_view, color);
}
