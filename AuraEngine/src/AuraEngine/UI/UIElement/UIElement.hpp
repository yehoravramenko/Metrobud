#pragma once
#include <utility>
#include <string>

namespace AuraEngine
{
  //enum class UIType
  //{
  //  Default = 0,
  //  DebugInfo,
  //};

  class UIElement
  {
  public:
    virtual void Draw() const = 0;

  protected:
    std::pair<float, float> position;
  };
}