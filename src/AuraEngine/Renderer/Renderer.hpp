#pragma once
#include "AuraEngine/AE_API.hpp"
#include "OpenGL/Buffer/Buffer.hpp"
#include "OpenGL/Shader/Shader.hpp"
#include "OpenGL/Texture/Texture.hpp"
#include "OpenGL/VertexArray/VertexArray.hpp"
#include <tuple>

namespace AuraEngine
{
  class Renderer
  {
  public:
    Renderer(const std::tuple<int, int> size);
    void Update();
    void Draw();
    AE_API ~Renderer();

  private:
    OpenGL::VertexArray m_VAO;
    OpenGL::Buffer m_VBO;
    OpenGL::Buffer m_EBO;
    OpenGL::Shader m_dummyShader;
    OpenGL::Texture m_testTex;
  };
} // namespace AuraEngine