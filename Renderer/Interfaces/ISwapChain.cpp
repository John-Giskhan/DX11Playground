#include "ISwapChain.h"
#include "../Renderer.h"
#include "../../DX11impl/DX11SwapChain.h"

ISwapChain* ISwapChain::Get(IDevice* device)
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11SwapChain(static_cast<DX11Device*>(device->GetRawDevice()));
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}

ISwapChain::~ISwapChain()
{
}
