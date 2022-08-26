#include "Graphics.h"

Graphics::Graphics(HWND hwnd)
{

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
	if (p_SwapChain != nullptr) {
		p_SwapChain->Release();
	}
}

void Graphics::ClearRenderTargetView(float red, float green, float blue, float alpha)
{
	float color[4] = { red, green, blue, alpha };
	p_Device_Context->ClearRenderTargetView(p_render_target_view, color);
}
