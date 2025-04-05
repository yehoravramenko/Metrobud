#pragma once
#include "AE_API.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>

namespace AuraEngine
{
  using Vector2 = glm::vec2;
  using Vector3 = glm::vec3;
  using Matrix4 = glm::mat4;
  using Quaternion = glm::quat;

  namespace Math
  {
    AE_API float Clamp(float &value, const float minValue, const float maxValue);
    AE_API float Lerp(const float a, const float b, const float t);

    AE_API Vector3 EulerAngles(const float xRot, const float yRot, const float zRot);
  }
}