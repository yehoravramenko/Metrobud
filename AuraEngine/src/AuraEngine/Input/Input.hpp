#pragma once
#include "Keyboard/Keyboard.hpp"
#include "Keyboard/Keycode.hpp"

namespace AuraEngine
{
  class Input
  {
  public:
    AE_API bool GetKey(Keycode keycode) const;
  private:
    Keyboard keyboard;
  };
}