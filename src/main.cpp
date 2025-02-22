#include "Client/Client.hpp"

auto main() -> int {
  Metrobud::Client client{};
  while (!client.ShouldExit())
    client.EventLoop();
  return 0;
}