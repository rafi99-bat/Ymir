#include <Ymir.h>

class Sandbox : public Ymir::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Ymir::Application* Ymir::CreateApplication()
{
	return new Sandbox();
}