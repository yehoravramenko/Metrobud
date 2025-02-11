#pragma once
#include <utility>
#include <string>

namespace AuraEngine
{
  class UIElement
  {
  public:
    virtual void Draw() const = 0;

  protected:
    std::pair<float, float> position;
  };
}