#include "IRenderTargetView.h"
#include "../Renderer.h"
#include "../../DX11impl/DX11SwapChain.h"
#include "../../DX11impl/DX11RenderTargetView.h"

IRenderTargetView* IRenderTargetView::Create(IDevice* p_device, ISwapChain* p_swapchain)
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11RenderTargetView(static_cast<DX11Device*>(p_device->GetRawDevice()),
	                                                        static_cast<DX11SwapChain*>(p_swapchain->
		                                                        GetRawSwapChain()));
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}

IRenderTargetView::~IRenderTargetView()
{
}
