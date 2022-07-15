#pragma once

#ifdef RF_PLATFORM_WINDOWS

extern rfe::Application* rfe::CreateApplication();

int main(int argc, char** argv)
{
	rfe::Log::Init();
	RF_CORE_WARN("Initialized Log!");
	RF_CLIENT_CRITICAL("Hello!");

	auto app = rfe::CreateApplication();
	app->Run();
	delete app;
}

#endif