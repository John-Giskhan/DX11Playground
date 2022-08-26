class IDeviceContext
{
public:
	static IDeviceContext* Get(IDevice* device);
	void ClearRenderTargetView();
	virtual ~IDeviceContext();
};