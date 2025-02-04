#pragma once
#include "../Client/Client.hpp"
namespace AuraEngine
{
  class EventHandler
  {
  public:
    EventHandler(Client *const client);
    void PollEvents();

    ~EventHandler();

  private:

    Client *client = nullptr;
  };
}