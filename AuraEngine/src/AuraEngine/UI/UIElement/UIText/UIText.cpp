#include "UIText.hpp"
#include <imgui.h>

AuraEngine::UIText::UIText(const std::pair<float, float> &position, const std::string &text)
{
  this->position = position;
  this->text = text;
}

void AuraEngine::UIText::Draw() const
{
  ImGui::Text(this->text.c_str());
}

void AuraEngine::UIText::SetText(const std::string &text)
{
  this->text = text;
}
