#pragma once
#include <Windows.h>
#include  <d3d11.h>
#pragma comment (lib,"d3d11.lib")
#include <wrl.h>
class Renderer
{
public:
	Renderer(HWND hwnd);
	Renderer( const Renderer& ) = delete;
	Renderer& operator=( const Renderer&) = delete;
	~Renderer() = default;
	void ClearRenderTargetView(float red, float green, float blue, float alpha) const;
	void EndFrame() const;
private:
	Microsoft::WRL::ComPtr<ID3D11Device> p_device = nullptr;
	Microsoft::WRL::ComPtr<IDXGISwapChain> p_swap_chain = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> p_device_context = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> p_render_target_view = nullptr;
};
