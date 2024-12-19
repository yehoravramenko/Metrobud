#include "renderer.hpp"

using namespace Metrobud;

Renderer::Renderer(std::array<int, 4> rect) {

  glViewport(rect[0], rect[1], rect[2], rect[3]);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  this->clearMask |= GL_DEPTH_BUFFER_BIT;
}

void Renderer::Update() {
}

void Renderer::Draw() {
  glClear(this->clearMask);
}

void Renderer::Exit() {
}