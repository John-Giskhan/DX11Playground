#include <d3d11.h>
#include "../Renderer/Interfaces/IDeviceContext.h"
class DX11DeviceContext :
    public IDeviceContext
{
public:
    DX11DeviceContext(DX11Device* device);
    virtual ~DX11DeviceContext();
private:
	ID3D11DeviceContext* device_context = nullptr;
};

