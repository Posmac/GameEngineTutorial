#pragma once

#ifdef RF_PLATFORM_WINDOWS

extern rfe::Application* rfe::CreateApplication();

int main(int argc, char** argv)
{
	auto app = rfe::CreateApplication();
	app->Run();
	delete app;
}

#endif