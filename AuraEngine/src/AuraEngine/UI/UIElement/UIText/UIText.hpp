#pragma once
#include "../UIElement.hpp"
#include <string>

namespace AuraEngine
{
  class UIText : public UIElement
  {
  public:
    UIText(const std::pair<float, float> &position, const std::string &text);
    virtual void Draw() const override;

    void SetText(const std::string &text);

  private:
    std::string text;
  };
}