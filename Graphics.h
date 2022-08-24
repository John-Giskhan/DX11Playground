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
	void ClearRenderTargetView(float red, float green, float blue, float alpha);
private:
	ID3D11Device* p_Device = nullptr;
	IDXGISwapChain* p_SwapChain = nullptr;
	ID3D11DeviceContext* p_Device_Context = nullptr;
	ID3D11RenderTargetView* p_render_target_view = nullptr;

};

