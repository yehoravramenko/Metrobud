#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"

namespace AuraEngine {
const float vertices[] = {
    // positions        // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
};

const unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

const std::string vs_src = R"(
#version 460 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec2 inTexCoord;

out vec2 TexCoord;

void main() {
  gl_Position = vec4(inPos, 1.0f);
  TexCoord = inTexCoord;
}
)";

const std::string fs_src = R"(
#version 460 core
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex;

void main() {
  FragColor = texture(tex, TexCoord);
}
)";

Renderer::Renderer(const std::tuple<int, int> size)
    : m_VBO(GL_ARRAY_BUFFER), m_EBO(GL_ELEMENT_ARRAY_BUFFER),
      m_dummyShader(vs_src, fs_src),
      m_testTex("../metrobud/textures/kenney_prototype/Green/texture_01.png") {
  glViewport(0, 0, std::get<0>(size), std::get<1>(size));
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  m_VAO.Bind();

  m_VBO.Bind();
  m_VBO.Data(sizeof(vertices), vertices);

  m_EBO.Bind();
  m_EBO.Data(sizeof(indices), indices);

  OpenGL::VertexAttribPointer(0, 3, 5, 0);
  OpenGL::EnableVertexAttribArray(0);
  OpenGL::VertexAttribPointer(1, 2, 5, 3);
  OpenGL::EnableVertexAttribArray(1);
}

void Renderer::Update() {
  // TODO: update
}

void Renderer::Draw() {
  glClear(GL_COLOR_BUFFER_BIT);

  m_dummyShader.Use();
  m_VAO.Bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Renderer::~Renderer() {
  // TODO: dtor
}
} // namespace AuraEngine