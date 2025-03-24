#pragma once
#include "../AuraEngine.hpp"
#include "../Input/Input.hpp"

namespace AuraEngine {
class Application {
public:
  Application(AuraEngine::Engine *engine);

  virtual void OnStart()  = 0;
  virtual void OnUpdate() = 0;
  virtual void OnDraw()   = 0;
  virtual void OnExit()   = 0;

  virtual ~Application() = default;

private:
  AuraEngine::Engine *m_engine;

protected:
  virtual void Exit() final;
};
} // namespace AuraEngine