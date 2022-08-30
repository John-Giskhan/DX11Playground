#include "Renderer.h"
#include <d3dcompiler.h>
#include <xutility>

#pragma comment (lib,"d3d11.lib")
#pragma comment (lib, "D3DCompiler.lib")

using namespace Microsoft;

Renderer::Renderer(HWND hwnd)
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
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	// If the project is in a debug build, enable the debug layer.
#if defined(_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL feature_level;

	constexpr D3D_FEATURE_LEVEL feature_level_array[3] = {
		D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1
	};
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createDeviceFlags,
		feature_level_array,
		3,
		D3D11_SDK_VERSION,
		&sd,
		&p_swap_chain,
		&p_device,
		&feature_level,
		&p_device_context);

	//get the texture from the swap chain (back buffer) buffer #0
	WRL::ComPtr<ID3D11Resource> p_back_buffer = nullptr;
	const HRESULT hr = p_swap_chain->GetBuffer(0, __uuidof(ID3D11Resource), &p_back_buffer);
	if (SUCCEEDED(hr))
		p_device->CreateRenderTargetView(p_back_buffer.Get(), nullptr, &p_render_target_view);
}

void Renderer::EndFrame() const
{
	p_swap_chain->Present(1u, 0u);
}

void Renderer::DrawTriangle()
{
	struct Vertex
	{
		float x;
		float y;
	};

	constexpr Vertex vertices[] =
	{
		{0.0f, 0.5f},
		{0.5f, 0.5f},
		{-0.5f, -0.5f}
	};
	WRL::ComPtr<ID3D11Buffer> p_vertex_buffer;
	D3D11_BUFFER_DESC bd{};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(vertices);
	bd.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = vertices;
	const HRESULT hr = p_device.Get()->CreateBuffer(&bd, &sd, &p_vertex_buffer);
	if (SUCCEEDED(hr))
	{
		//Bind vertex buffer to pipeline
		constexpr UINT stride = sizeof(Vertex);
		constexpr UINT offset = 0u;
		p_device_context->IASetVertexBuffers(0u, 1u, p_vertex_buffer.GetAddressOf(), &stride, &offset);

		//Load vertex shader as blob
		WRL::ComPtr<ID3DBlob> p_blob;
		const HRESULT read_vertex_file_hr = D3DReadFileToBlob(L"VertexShader.cso", &p_blob);

		if (SUCCEEDED(read_vertex_file_hr))
		{
			//Create vertex shader
			WRL::ComPtr<ID3D11VertexShader> p_vertex_shader;
			p_device->CreateVertexShader(p_blob->GetBufferPointer(), p_blob->GetBufferSize(), nullptr,
			&p_vertex_shader);

			//Bind vertex shader
				p_device_context->VSSetShader(p_vertex_shader.Get(), nullptr, 0);

			//Create input layout of the vertices
			constexpr D3D11_INPUT_ELEMENT_DESC ied[] = {
				{"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
			};
			WRL::ComPtr<ID3D11InputLayout> p_input_layout;
			const HRESULT layout_hr = p_device->CreateInputLayout(ied, std::size(ied), p_blob->GetBufferPointer(),
			p_blob->GetBufferSize(), &p_input_layout);
			if (SUCCEEDED(layout_hr))
			{
				//Bind input layout
				p_device_context->IASetInputLayout(p_input_layout.Get());

				//Create pixel shader
				WRL::ComPtr<ID3D11PixelShader> p_pixel_shader;
				const HRESULT read_pixel_file_hr = D3DReadFileToBlob(L"PixelShader.cso", &p_blob);
				if (SUCCEEDED(read_pixel_file_hr))
				{
					p_device->CreatePixelShader(p_blob->GetBufferPointer(), p_blob->GetBufferSize(), nullptr,
					                            &p_pixel_shader);

					//Bind pixel shader
					p_device_context->PSSetShader(p_pixel_shader.Get(), nullptr, 0u);

					//Bind render target
					p_device_context->OMSetRenderTargets(1u, p_render_target_view.GetAddressOf(), nullptr);

					// Set primitive topology that is the most efficient for just one trianglej
					p_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


					//Config viewport
					D3D11_VIEWPORT vp{};
					vp.Width = 800;
					vp.Height = 600;
					vp.MinDepth = 0;
					vp.MaxDepth = 1;
					vp.TopLeftX = 0;
					vp.TopLeftY = 0;
					p_device_context->RSSetViewports(1u, &vp);
				}
				p_device_context->Draw(std::size(vertices), 0u);
			}
		}
	}
}

void Renderer::ClearRenderTargetView(const float red, const float green, const float blue, const float alpha) const
{
	const float color[4] = {red, green, blue, alpha};
	p_device_context->ClearRenderTargetView(p_render_target_view.Get(), color);
}
