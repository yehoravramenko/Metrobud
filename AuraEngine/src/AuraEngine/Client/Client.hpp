#pragma once
#include "../DllCore.hpp"
#include "../Window/Window.hpp"
#include "../Renderer/Renderer.hpp"

namespace AuraEngine {
class AE_API Client {
public:
  Client();

  void MainLoop();

  virtual void OnStart()=0;
  virtual void OnUpdate()=0;
  virtual void OnRender()=0;
  virtual void OnExit()=0;
  //~Client();

protected:
  Window window;
  Renderer renderer;
};
} // namespace AuraEngine