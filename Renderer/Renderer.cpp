#include "Renderer.h"

GraphicsAPI Renderer::s_GraphicsAPI = GraphicsAPI::DX11;

void Renderer::ClearRenderTargetView(float red, float green, float blue, float alpha)
{
		float color[4] = { red, green, blue, alpha };
		//device_Context->ClearRenderTargetView(Graphics::p_render_target_view, color);	
}
