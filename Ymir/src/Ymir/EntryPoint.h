#pragma once

#ifdef YM_PLATFORM_WINDOWS

extern Ymir::Application* Ymir::CreateApplication();

int main(int argc, char** argv)
{
	Ymir::Log::Init();
	YM_CORE_WARN("Initialized Log!");
	int a = 5;
	YM_INFO("Hello! Var={0}", a);

	auto app = Ymir::CreateApplication();
	app->Run();
	delete app;
}

#endif // YM_PLATFORM_WINDOWS

