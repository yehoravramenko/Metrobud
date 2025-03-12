#pragma once
#include "GL/Buffer/Buffer.hpp"
#include "GL/Shader/Shader.hpp"
#include "GL/VertexArray/VertexArray.hpp"
#include <tuple>

namespace AuraEngine {
class Renderer {
public:
  Renderer(const std::tuple<int, int> size);
  Renderer();
  void Update();
  void Draw();
  ~Renderer();

private:
  GL::VertexArray m_VAO;
  GL::Buffer m_VBO{GL_ARRAY_BUFFER};
  GL::Shader m_dummyShader;
};
} // namespace AuraEngine