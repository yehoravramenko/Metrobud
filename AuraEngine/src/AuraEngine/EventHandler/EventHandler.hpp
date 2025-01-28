#pragma once
#include "../Renderer/Renderer.hpp"

namespace AuraEngine
{
  class EventHandler
  {
  public:
    EventHandler(Renderer *const renderer);
    void PollEvents();
    bool ShouldQuit() const;

  private:
    bool shouldQuit = false;
    Renderer *renderer = nullptr;
  };
}