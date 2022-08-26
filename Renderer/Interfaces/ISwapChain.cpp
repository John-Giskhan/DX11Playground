#include "ISwapChain.h"
#include "../Renderer.h"
#include "../../DX11impl/DX11SwapChain.h"

ISwapChain* ISwapChain::Create(IDevice* device, HWND hwnd)
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11SwapChain((DX11Device*)device->GetRawDevice(), hwnd);
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}

ISwapChain::~ISwapChain()
{
}
