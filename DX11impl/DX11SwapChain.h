#pragma once
#include "../Renderer/Interfaces/ISwapChain.h"
#include <d3d11.h>
#include <dxgi1_2.h>
#include "DX11Device.h"

class DX11SwapChain :
    public ISwapChain
{
public:
    DX11SwapChain(DX11Device* device, HWND hwnd);
    virtual ~DX11SwapChain();
private:
	HWND m_hwnd = nullptr;
	IDXGISwapChain1* swap_chain = nullptr;
};

