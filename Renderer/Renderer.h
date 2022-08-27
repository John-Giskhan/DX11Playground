#pragma once
#include <Windows.h>
#include  <d3d11.h>
#pragma comment (lib,"d3d11.lib")

class Renderer
{
public:
	Renderer(HWND hwnd);
	~Renderer();
	void ClearRenderTargetView(float red, float green, float blue, float alpha) const;
	void EndFrame() const;
private:
	ID3D11Device* p_device = nullptr;
	IDXGISwapChain* p_swap_chain = nullptr;
	ID3D11DeviceContext* p_device_context = nullptr;
	ID3D11RenderTargetView* p_render_target_view = nullptr;
};
