#pragma once

#include "DX11Device.h"
#include "DX11SwapChain.h"
#include "../Renderer/Interfaces/IRenderTargetView.h"

class DX11RenderTargetView final :
	public IRenderTargetView
{
public:
	DX11RenderTargetView(DX11Device* device, DX11SwapChain* swapchain);
	void* GetRawRenderTargetView() override { return render_target_view; }
	~DX11RenderTargetView() override;
private:
	IDXGISwapChain* swap_chain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11RenderTargetView* render_target_view = nullptr;
};
