#include "Renderer.h"
using namespace Microsoft;

Renderer::Renderer(HWND hwnd)
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

	// If the project is in a debug build, enable the debug layer.
	#if defined(_DEBUG)
        createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif
	D3D_FEATURE_LEVEL feature_level;

	constexpr D3D_FEATURE_LEVEL feature_level_array[3] = {
		D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1
	};
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createDeviceFlags,
		feature_level_array,
		3,
		D3D11_SDK_VERSION,
		&sd,
		&p_swap_chain,
		&p_device,
		&feature_level,
		&p_device_context);

	//get the texture from the swap chain (back buffer) buffer #0
	WRL::ComPtr<ID3D11Resource> p_back_buffer = nullptr;
	const HRESULT hr = p_swap_chain->GetBuffer(0, __uuidof(ID3D11Resource), &p_back_buffer);
	if (SUCCEEDED(hr))
		p_device->CreateRenderTargetView(p_back_buffer.Get(), nullptr, &p_render_target_view);
}

void Renderer::EndFrame() const
{
	p_swap_chain->Present(1u, 0u);
}

void Renderer::ClearRenderTargetView(const float red, const float green, const float blue, const float alpha) const
{
	const float color[4] = { red, green, blue, alpha };
	p_device_context->ClearRenderTargetView(p_render_target_view.Get(), color);
}
