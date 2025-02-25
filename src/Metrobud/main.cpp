#include "AuraEngine/AuraEngine.hpp"
#include "Metrobud/Client/Client.hpp"
using namespace AuraEngine;

auto main() -> int {
  Engine engine{};
  Metrobud::Client CL{&engine};
  CL.OnStart();

  while (!engine.ShouldExit())
    engine.EventLoop();

  CL.OnExit();
  return 0;
}