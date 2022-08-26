#pragma once
#include "../Renderer/Interfaces/IDevice.h"
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
class DX11Device :
    public IDevice
{
    // Inherited via Device
     IDevice* Create();
     virtual ~DX11Device();
private:
    ID3D11Device* device;
    ID3D11DeviceContext* device_Context;
};

