#pragma once

enum class GraphicsAPI
{
	None = 0,
	DX11 = 1,
};

class Renderer
{
public:
	inline static GraphicsAPI GetAPI() { return s_GraphicsAPI; }
	inline static GraphicsAPI SetAPI(GraphicsAPI p_GraphicsAPI) { s_GraphicsAPI = p_GraphicsAPI; }
	void ClearRenderTargetView(float red, float green, float blue, float alpha);

private:
	static GraphicsAPI s_GraphicsAPI;
};

