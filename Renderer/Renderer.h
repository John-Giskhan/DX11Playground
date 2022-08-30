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
	void DrawTriangle() const
	{
		struct Vertex
		{
			float x;
			float y;
		};

		constexpr Vertex vertices[] = 
		{
			{0.0f,0.5f},
			{0.5f,0.5f},
			{-0.5f,-0.5f}
		};
		Microsoft::WRL::ComPtr<ID3D11Buffer> p_vertex_buffer;
		D3D11_BUFFER_DESC bd{};
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.CPUAccessFlags = 0u;
		bd.MiscFlags = 0u;
		bd.ByteWidth = sizeof(vertices);
		bd.StructureByteStride = sizeof(Vertex);
		D3D11_SUBRESOURCE_DATA sd = {};
		sd.pSysMem = vertices;
		const HRESULT hr = p_device.Get()->CreateBuffer(&bd,&sd,&p_vertex_buffer);
		if(SUCCEEDED(hr))
		{
			constexpr UINT stride = sizeof( Vertex );
			constexpr UINT offset = 0u;
			p_device_context->IASetVertexBuffers(0u, 1u, &p_vertex_buffer, &stride, &offset);
			p_device_context->Draw(3u,0);
			
		}
	}
private:
	Microsoft::WRL::ComPtr<ID3D11Device> p_device = nullptr;
	Microsoft::WRL::ComPtr<IDXGISwapChain> p_swap_chain = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> p_device_context = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> p_render_target_view = nullptr;
};
