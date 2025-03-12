#include "Renderer.hpp"

namespace AuraEngine {
const float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                          0.0f,  0.0f,  0.5f, 0.0f};

Renderer::Renderer(const std::tuple<int, int> size) {
  glViewport(0, 0, std::get<0>(size), std::get<1>(size));
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  this->VBO.Data(sizeof(vertices), vertices);
}

void Renderer::Update() {
  // TODO: update
}

void Renderer::Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
}

Renderer::~Renderer() {
  // TODO: dtor
}
} // namespace AuraEngine