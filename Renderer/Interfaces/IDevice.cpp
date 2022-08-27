#include "IDevice.h"
#include "../Renderer.h"
#include "../../DX11impl/DX11device.h"

IDevice* IDevice::Create(HWND hwnd)
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11Device(hwnd);
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}
IDevice::~IDevice()
{
}