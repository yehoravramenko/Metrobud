#pragma once
#include "../DllCore.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <utility>

namespace AuraEngine {
class AE_API Window {
public:
  Window();
  
  void Update();
  void SetSize(const std::pair<int, int> &size);
  void SetTitle(const std::string &title);
  bool ShouldClose();
  
  ~Window();
private:
  GLFWwindow* window=nullptr;
};
} // namespace AuraEngine