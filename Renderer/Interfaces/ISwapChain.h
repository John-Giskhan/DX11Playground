#pragma once
class ISwapChain
{
	static ISwapChain* Create();
	virtual ~ISwapChain();
};

