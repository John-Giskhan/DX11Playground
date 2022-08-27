#pragma once
#include "../Renderer/Interfaces/ISwapChain.h"

#include "DX11Device.h"


class DX11SwapChain final :
	public ISwapChain
{
public:
	explicit DX11SwapChain(IDXGISwapChain* p_swap_chain);
	void* GetRawSwapChain() override { return swap_chain; }
	void Present() override;
	~DX11SwapChain() override;
	void* GetBackBuffer() override;
private:
	HWND m_hwnd = nullptr;
	IDXGISwapChain* swap_chain = nullptr;
};
