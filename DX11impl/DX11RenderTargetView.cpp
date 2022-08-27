#include "DX11RenderTargetView.h"


DX11RenderTargetView::DX11RenderTargetView(DX11Device* p_device, DX11SwapChain* p_swapchain)
{
	////get the texture from the swap chain (back buffer) buffer #0
	auto p_back_buffer = static_cast<ID3D11Resource*>(p_swapchain->GetBackBuffer());
	device->CreateRenderTargetView(p_back_buffer, nullptr, &render_target_view);
}

DX11RenderTargetView::~DX11RenderTargetView()
{
}
