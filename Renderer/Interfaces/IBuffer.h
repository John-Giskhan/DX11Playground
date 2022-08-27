#pragma once

class IBuffer
{
public:
	static IBuffer* Create();
	virtual ~IBuffer();
};
