#pragma once
class ISwapChain
{
	virtual ISwapChain* Create() = 0;
	virtual void Release() = 0;
};

