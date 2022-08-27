#include "DX11SwapChain.h"

#include "DX11Buffer.h"

DX11SwapChain::DX11SwapChain(IDXGISwapChain* p_swap_chain)
{
	swap_chain = p_swap_chain;
}

void DX11SwapChain::Present()
{
	swap_chain->Present(1u, 0u);
}

DX11SwapChain::~DX11SwapChain()
{
	if (swap_chain != nullptr)
	{
		swap_chain->Release();
	}
}

void* DX11SwapChain::GetBackBuffer()
{
	ID3D11Resource* back_buffer = nullptr;
	swap_chain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&back_buffer));
	return back_buffer;
}
