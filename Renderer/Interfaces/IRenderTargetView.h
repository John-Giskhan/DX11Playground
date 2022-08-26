#pragma once
class IRenderTargetView
{
public:
	static IRenderTargetView* Create();

	virtual ~IRenderTargetView();
};