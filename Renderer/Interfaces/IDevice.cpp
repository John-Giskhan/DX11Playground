#include "IDevice.h"
#include "../Renderer.h"
#include "../../DX11impl/DX11device.h"

IDevice* IDevice::Create()
{
	switch (Renderer::GetAPI())
	{
		case GraphicsAPI::DX11: return new DX11Device();
		case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}