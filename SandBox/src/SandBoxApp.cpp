#include <Refra.h>

class SandBox : public rfe::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{
		
	}
};

rfe::Application* rfe::CreateApplication()
{
	return new SandBox();
}