#pragma once
#include "../UIElement.hpp"
#include <imgui.h>
#include <string>
#include <map>

namespace AuraEngine
{
  class UIFrame : public UIElement
  {
  public:
    UIFrame(const std::string &name, const std::pair<float, float> &position, ImGuiWindowFlags flags);
    void AddElement(const std::pair<std::string, UIElement *> &element);
    UIElement *GetElement(const std::string &name);

    virtual void Draw() const override;

    ~UIFrame();

  private:
    std::string name;
    std::map<std::string, UIElement *> elements;
    ImGuiWindowFlags flags;
  };
}