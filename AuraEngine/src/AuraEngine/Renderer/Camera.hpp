#pragma once
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "../ExportAPI.hpp"

namespace AuraEngine
{
  class Renderer;
  class Camera
  {
  public:
    Camera(const float &fov, const glm::vec3 &position, const Renderer *renderer);

    AE_API void Translate(const glm::vec3 &translation);
    const glm::mat4 &GetTransform();

    friend Renderer;

  private:
    static constexpr glm::vec3 GLOBAL_UP{ 0.0f, 1.0f, 0.0f };
    static constexpr glm::vec3 GLOBAL_FRONT{ 0.0f, 0.0f, -1.0f };

    float fov = 45.0f;
    glm::vec3 position{};
    glm::vec3 target{ 0.0f, 0.0f, 0.0f };
    glm::mat4 transform{};
    const Renderer *renderer;

    void updateTransform();
  };
}