#include "DX11DeviceContext.h"

DX11DeviceContext::DX11DeviceContext(DX11Device* device)
{
	device_context = static_cast<ID3D11DeviceContext*>(device->GetRawDeviceContext());
}

DX11DeviceContext::~DX11DeviceContext()
{
}

void DX11DeviceContext::ClearRenderTargetView(IRenderTargetView* render_target_view, float color[])
{
	device_context->ClearRenderTargetView(
		static_cast<ID3D11RenderTargetView*>(render_target_view->GetRawRenderTargetView()), color);
}
