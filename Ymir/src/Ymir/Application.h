#pragma once

#include "Core.h"

namespace Ymir {

	class YMIR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}
