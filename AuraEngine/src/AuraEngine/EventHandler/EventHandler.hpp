#pragma once

namespace AuraEngine
{
  class EventHandler
  {
  public:
    void PollEvents();
    bool ShouldQuit() const;

  private:
    bool shouldQuit = false;
  };
}