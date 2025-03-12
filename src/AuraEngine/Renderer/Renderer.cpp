#include "Renderer.hpp"

namespace AuraEngine {
const float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                          0.0f,  0.0f,  0.5f, 0.0f};

const std::string vs_src = R"(
#version 460 core
layout (location = 0) in vec3 inPos;

void main() {
  gl_Position = vec4(inPos, 1.0f);
}
)";

const std::string fs_src = R"(
#version 460 core
out vec4 FragColor;

void main() {
  FragColor = vec4(0.0f, 0.5f, 0.0f, 1.0f);
}
)";

Renderer::Renderer(const std::tuple<int, int> size)
    : m_dummyShader(vs_src, fs_src) {
  glViewport(0, 0, std::get<0>(size), std::get<1>(size));
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  m_VAO.Bind();

  m_VBO.Bind();
  m_VBO.Data(sizeof(vertices), vertices);

  m_VBO.VertexAttribPointer(0, 3, 3, 0);
  m_VBO.EnableVertexAttribArray(0);
}

void Renderer::Update() {
  // TODO: update
}

void Renderer::Draw() {
  glClear(GL_COLOR_BUFFER_BIT);

  m_VAO.Bind();
  m_dummyShader.Use();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

Renderer::~Renderer() {
  // TODO: dtor
}
} // namespace AuraEngine