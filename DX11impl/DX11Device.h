#pragma once
#include "../Interfaces/IDevice.h"
class DX11Device :
    public IDevice
{
    // Inherited via Device
     void Create(IDevice& p_device) override;
     void Release() override;
     void ClearRenderTargetView(float red, float green, float blue, float alpha) override;
};

