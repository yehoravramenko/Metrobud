#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Debug/Debug.hpp"
#include <format>

namespace AuraEngine
{
  const float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  };

  const std::string vs_src = R"(
#version 460 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec2 inTexCoord;

out vec2 TexCoord;

uniform mat4 mvp;

void main() {
  vec4 inv_pos = mvp * vec4(inPos, 1.0f);
  // vec4 inv_pos = mvp * vec4(inPos.x, inPos.y, -inPos.z, 1.0f);
  gl_Position = inv_pos;
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

  int x = 0;

  Renderer::Renderer(const WindowSize windowSize) :
    VBO(GL_ARRAY_BUFFER), EBO(GL_ELEMENT_ARRAY_BUFFER),
    dummyShader(vs_src, fs_src),
    testTex("../metrobud/textures/kenney_prototype/Green/texture_01.png"),
    camera(windowSize, { 2.0f, 0.0f, -10.0f })
  {
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, windowSize.width, windowSize.height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    this->VAO.Bind();

    this->VBO.Bind();
    this->VBO.Data(sizeof(vertices), vertices);

    //this->EBO.Bind();
    //this->EBO.Data(sizeof(indices), indices);

    OpenGL::VertexAttribPointer(0, 3, 5, 0);
    OpenGL::EnableVertexAttribArray(0);
    OpenGL::VertexAttribPointer(1, 2, 5, 3);
    OpenGL::EnableVertexAttribArray(1);
  }

  void Renderer::Update()
  {
    auto model = Matrix4(1.0f);
    //model = glm::rotate(model, glm::radians(-55.0f), Vector3(1.0f, 0.0f, 0.0f));

    auto mvp = this->camera.GetViewProjectionMatrix() * model;
    this->dummyShader.Use();
    this->dummyShader.SetMat4("mvp", mvp);
  }

  void Renderer::Draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->testTex.Bind();
    this->dummyShader.Use();
    this->VAO.Bind();
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }

  Renderer::~Renderer()
  {
    // TODO: dtor
  }
} // namespace AuraEngine