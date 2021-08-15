#pragma once

#ifdef YM_PLATFORM_WINDOWS

extern Ymir::Application* Ymir::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ymir::CreateApplication();
	app->Run();
	delete app;
}

#endif // YM_PLATFORM_WINDOWS

