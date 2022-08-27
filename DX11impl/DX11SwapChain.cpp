#include "DX11SwapChain.h"

#include "DX11Buffer.h"
#include "DX11Device.h"

DX11SwapChain::DX11SwapChain(DX11Device* device)
{
	swap_chain = static_cast<IDXGISwapChain*>(device->GetRawSwapChain());
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

void* DX11SwapChain::GetBackBuffer() const
{
	ID3D11Resource* back_buffer = nullptr;
	swap_chain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&back_buffer));
	return back_buffer;
}
