#pragma once
#include <Windows.h>
#include "Interfaces/IDevice.h"
#include "Interfaces/ISwapChain.h"
#include "Interfaces/IDeviceContext.h"
#include "Interfaces/IRenderTargetView.h"
#pragma comment(lib, "d3d11.lib")

enum class GraphicsAPI
{
	None = 0,
	DX11 = 1,
};

class Renderer
{
public:
	Renderer(HWND hwnd);
	~Renderer();

	static GraphicsAPI GetAPI() { return s_GraphicsAPI; }
	static GraphicsAPI SetAPI(GraphicsAPI p_GraphicsAPI) { s_GraphicsAPI = p_GraphicsAPI; }
	void EndFrame() const;
	void ClearRenderTargetView(float red, float green, float blue, float alpha) const;

private:
	IDevice* p_Device = nullptr;
	ISwapChain* p_SwapChain = nullptr;
	IDeviceContext* p_Device_Context = nullptr;
	IRenderTargetView* p_render_target_view = nullptr;
	static GraphicsAPI s_GraphicsAPI;
};
