#include "DX11Buffer.h"

#include "DX11SwapChain.h"

void* DX11Buffer::Create(DX11SwapChain* swap_chain)
{
	return swap_chain->GetBackBuffer();
}

DX11Buffer::~DX11Buffer()
{
}
