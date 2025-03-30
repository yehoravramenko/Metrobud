#pragma once
#include "AE_API.hpp"
#include "OpenGL/Buffer/Buffer.hpp"
#include "OpenGL/Shader/Shader.hpp"
#include "OpenGL/Texture/Texture.hpp"
#include "OpenGL/VertexArray/VertexArray.hpp"

#include "Camera.hpp"

#include <tuple>

namespace AuraEngine
{
  class Engine;

  class Renderer
  {
  public:
    Renderer(const std::tuple<int, int> size);
    void Update();
    void Draw();
    AE_API ~Renderer();

    Camera *GetMainCamera()
    {
      return &camera;
    }

  private:
    OpenGL::VertexArray VAO;
    OpenGL::Buffer VBO;
    OpenGL::Buffer EBO;
    OpenGL::Shader dummyShader;
    OpenGL::Texture testTex;

    Camera camera;
  };
} // namespace AuraEngine