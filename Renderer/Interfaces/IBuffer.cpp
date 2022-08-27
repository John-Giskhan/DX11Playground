#include "../Renderer.h"

#include "IBuffer.h"
#include "../../DX11impl/DX11Buffer.h"

IBuffer* IBuffer::Create()
{
	switch (Renderer::GetAPI())
	{
	case GraphicsAPI::DX11: return new DX11Buffer();
	case GraphicsAPI::None: return nullptr;
	default:
		return nullptr;
	}
}

IBuffer::~IBuffer()
{
}
