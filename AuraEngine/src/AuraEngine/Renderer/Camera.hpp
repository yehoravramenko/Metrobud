#pragma once
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

namespace AuraEngine
{
  class Renderer;
  class Camera
  {
  public:
    Camera(const float &fov, const glm::vec3 &position, const Renderer *renderer);

    void Move(const glm::vec3 &position);
    const glm::mat4 &GetTransform();

    friend Renderer;

  private:
    float fov = 45.0f;
    glm::vec3 position{};
    glm::mat4 transform{};
    const Renderer *renderer;

    void updateTransform();
  };
}