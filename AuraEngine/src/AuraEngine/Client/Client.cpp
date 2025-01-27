#include "Client.hpp"
#include "../Log/Log.hpp"
#include "GLFW/glfw3.h"

namespace AuraEngine {
	Client::Client() {
		Log::EngineLog.Info("Client called");
	}

	void Client::MainLoop()
	{
		this->OnStart();
		while (!this->window.ShouldClose())
		{
			window.Update();
			this->OnUpdate();
			// Rendering
			this->OnRender();
		}
		this->OnExit();
	}
} // namespace AuraEngine