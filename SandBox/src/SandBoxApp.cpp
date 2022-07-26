#include <RefraEngine.h>

class ExampleLayer : public rfe::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		RF_CLIENT_INFO("Example layer::Update");
	}

	void OnEvent(rfe::Event& e) override
	{
		RF_CLIENT_TRACE("{0}", e);
	}
};

class SandBox : public rfe::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new rfe::ImGuiLayer());
	}

	~SandBox()
	{
		
	}
};

rfe::Application* rfe::CreateApplication()
{
	return new SandBox();
}