#include "../../DX11impl/DX11Device.h"
#include "../Renderer.h"
#include "IDeviceContext.h"
#include "../../DX11impl/DX11DeviceContext.h"

IDeviceContext* IDeviceContext::Get(IDevice* device)
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11DeviceContext(static_cast<DX11Device*>(device->GetRawDeviceContext()));
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}

IDeviceContext::~IDeviceContext()
{
}
