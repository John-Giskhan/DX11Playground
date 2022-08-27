#pragma once
#include "../Renderer/Interfaces/ISwapChain.h"

#include "DX11Device.h"


class DX11SwapChain final :
	public ISwapChain
{
public:
	DX11SwapChain(DX11Device* device);
	void* GetRawSwapChain() override { return swap_chain; }
	void Present() override;
	~DX11SwapChain() override;
	void* GetBackBuffer() const override;
private:
	HWND m_hwnd = nullptr;
	IDXGISwapChain* swap_chain = nullptr;
};
