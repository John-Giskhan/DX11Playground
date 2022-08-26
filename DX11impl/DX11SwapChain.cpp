#include "DX11SwapChain.h"
#include <d3d11.h>
DX11SwapChain::DX11SwapChain()
{
	
DXGI_SWAP_CHAIN_DESC sd;
ZeroMemory(&sd, sizeof(sd));
sd.BufferCount = 1;
sd.BufferDesc.Width = 0;
sd.BufferDesc.Height = 0;
sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
sd.BufferDesc.RefreshRate.Numerator = 0;
sd.BufferDesc.RefreshRate.Denominator = 0;
sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
sd.OutputWindow = m_hwnd;
sd.SampleDesc.Count = 1;
sd.SampleDesc.Quality = 0;
sd.Windowed = TRUE;
sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

D3D11CreateSwapChain(
	p_Device,
	&sd,
	NULL,
	&p_SwapChain,
	&p_Device_Context);

}