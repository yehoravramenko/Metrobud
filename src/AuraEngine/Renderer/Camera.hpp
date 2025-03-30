#pragma once
#include "AuraEngine/Renderer/GameObject.hpp"
#include "AuraEngine/AuraMath.hpp"

namespace AuraEngine
{
  class Camera : public GameObject
  {
  public:
    Camera(const float aspectRatio, const Vector3 position = { 0.0f, 0.0f, 0.0f });
    const Matrix4 GetViewProjectionMatrix() const;

  private:
    float fieldOfView = 60.0f;
    Matrix4 view;
    Matrix4 projection;
  };
}