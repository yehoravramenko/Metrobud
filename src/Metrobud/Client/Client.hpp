#pragma once
#include "Application/Application.hpp"

namespace Metrobud
{
  class Client : public AuraEngine::Application
  {
  public:
    Client(AuraEngine::Engine *engine) : AuraEngine::Application(engine) {};

    void OnStart() override;
    void OnUpdate() override;
    void OnDraw() override;
    void OnExit() override;

  private:
    void UpdateCamera();
  };
} // namespace Metrobud