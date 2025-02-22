#pragma once
#include "Window/Window.hpp"

namespace Metrobud {
class Client
{
public:
  Client();
  ~Client();

private:
  Window* window = nullptr;
  std::tuple<int, int> size;
};
} // namespace Metrobud