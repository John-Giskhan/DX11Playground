#pragma once

#include <d3d11.h>

#include "DX11SwapChain.h"
#include "../Renderer/Interfaces/IBuffer.h"


class DX11Buffer final : public IBuffer
{
public:
	static void* Create(DX11SwapChain* swap_chain);
	~DX11Buffer() override;
private:
	ID3D11Resource* buffer = nullptr;
};
