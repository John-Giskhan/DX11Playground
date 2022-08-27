#pragma once
#include <d3d11.h>
#include "DX11Device.h"
#include "DX11DeviceContext.h"
#include "../Renderer/Interfaces/IDeviceContext.h"
#include "../Renderer/Interfaces/IRenderTargetView.h"
class DX11DeviceContext final :
	public IDeviceContext
{
public:
	DX11DeviceContext(DX11Device* device);
	~DX11DeviceContext() override;
	void ClearRenderTargetView(IRenderTargetView* render_target_view, float color[]) override;
private:
	ID3D11DeviceContext* device_context = nullptr;
};
