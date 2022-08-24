#pragma once
#include <Windows.h>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

class Graphics
{
public:
	Graphics(HWND hwnd);
	void EndFrame();
	~Graphics();
private:
	ID3D11Device* p_Device = nullptr;
	IDXGISwapChain* p_SwapChain = nullptr;
	ID3D11DeviceContext* p_Device_Context = nullptr;
};

