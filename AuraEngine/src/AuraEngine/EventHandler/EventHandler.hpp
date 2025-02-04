#pragma once
#include "../ExportAPI.hpp"

namespace AuraEngine
{
  class Client;

  class AE_API EventHandler
  {
  public:
    EventHandler(Client *const client);
    void PollEvents();

    ~EventHandler();

  private:

    Client *client = nullptr;
  };
}