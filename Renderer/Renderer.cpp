#include "Renderer.h"
#include "Interfaces/IDevice.h"
GraphicsAPI Renderer::s_GraphicsAPI = GraphicsAPI::DX11;

Renderer::Renderer(HWND hwnd)
{
	p_Device = IDevice::Create(hwnd);
	p_Device_Context = IDeviceContext::Get(p_Device);
	p_SwapChain = ISwapChain::Get(p_Device);
	p_render_target_view = IRenderTargetView::Create(p_Device, p_SwapChain);
	
	//get the texture from the swap chain (back buffer) buffer #0
}

void Renderer::EndFrame() const
{
	p_SwapChain->Present();
}

Renderer::~Renderer()
{
}

void Renderer::ClearRenderTargetView(float red, float green, float blue, float alpha) const
{
	float color[4] = {red, green, blue, alpha};
	p_Device_Context->ClearRenderTargetView(p_render_target_view, color);
}
