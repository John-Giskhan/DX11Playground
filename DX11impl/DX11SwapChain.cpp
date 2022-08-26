#include "DX11SwapChain.h"
#include "DX11Device.h"

DX11SwapChain::DX11SwapChain(DX11Device* device, HWND hwnd)
{
	m_hwnd = hwnd;
	DXGI_SWAP_CHAIN_DESC1 sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.Width = 0;
	sd.Height = 0;
	sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	IDXGIFactory2* dxgiFactory = nullptr;
	dxgiFactory->CreateSwapChainForHwnd(
		(ID3D11Device*)device->GetRawDevice(),
		hwnd,
		&sd,
		NULL,
		NULL,
		&swap_chain
	);
}

DX11SwapChain::~DX11SwapChain()
{
	if (swap_chain != nullptr) {
		swap_chain->Release();
	}
}
