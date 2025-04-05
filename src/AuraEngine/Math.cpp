#include "Math.hpp"

namespace AuraEngine::Math
{
  float Clamp(float &value, const float minValue, const float maxValue)
  {
    return (value < minValue) ? minValue : (value > maxValue) ? maxValue : value;
  }

  Vector3 EulerAngles(const float xRot, const float yRot, const float zRot)
  {
    return { glm::radians(xRot), glm::radians(yRot), glm::radians(zRot) };
  }

  float Lerp(const float a, const float b, const float t)
  {
    // lerp = a + (b - a) * t
    return a + (b - a) * t;
  }
}