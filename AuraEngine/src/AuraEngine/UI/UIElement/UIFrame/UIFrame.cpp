#include "UIFrame.hpp"

namespace AuraEngine
{
  UIFrame::UIFrame(const std::string &name, const std::pair<float, float> &position, ImGuiWindowFlags flags)
  {
    this->name = name;
    this->position = position;
    this->flags = flags;
  }

  void UIFrame::AddElement(const std::pair<std::string, UIElement *> &element)
  {
    this->elements.emplace(element);
  }

  UIElement *UIFrame::GetElement(const std::string &name)
  {
    return this->elements[name];
  }

  void UIFrame::Draw() const
  {
    ImGui::Begin(this->name.c_str(), nullptr, this->flags);
    for (const auto &[name, element] : this->elements)
    {
      element->Draw();
    }
    ImGui::End();
  }

  UIFrame::~UIFrame()
  {
    for (const auto &[name, element] : this->elements)
    {
      delete element;
    }
  }
}