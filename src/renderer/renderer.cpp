#include "renderer.hpp"

using namespace Metrobud;

// clang-format off

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

// clang-format on

const std::string vert_shader_src = R"(
#version 460 core
layout (location = 0) in vec3 inPos;

void main()
{
    gl_Position = vec4(inPos, 1.0);
}
)";

const std::string frag_shader_src = R"(
#version 460 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(0.0f, 0.5f, 0.0f, 1.0f);
} 
)";

Renderer::Renderer(std::array<int, 4> rect) {

  glViewport(rect[0], rect[1], rect[2], rect[3]);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  this->clearMask |= GL_DEPTH_BUFFER_BIT;

  this->VBO = std::make_unique<GL::Buffer>(GL_ARRAY_BUFFER);
  this->VBO->Data(sizeof(vertices), vertices, GL_STATIC_DRAW);

  this->Shader = std::make_unique<GL::Shader>(vert_shader_src, frag_shader_src);
}

void Renderer::Update() {
}

void Renderer::Draw() {
  glClear(this->clearMask);
}

void Renderer::Exit() {
}