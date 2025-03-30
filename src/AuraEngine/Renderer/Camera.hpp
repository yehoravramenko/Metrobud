#pragma once
#include "Renderer/GameObject.hpp"
#include "AuraMath.hpp"

#include <tuple>

namespace AuraEngine
{
  class Camera : public GameObject
  {
  public:
    Camera(const std::tuple<int, int> &size, const Vector3 position = { 0.0f, 0.0f, 0.0f });

    const Matrix4 GetViewProjectionMatrix();

  private:
    std::tuple<int, int> screenSize;
    float aspectRatio;
    float fieldOfView = 60.0f;

    Vector3 orientation{ 0.0f, 0.0f, -1.0f };
    Vector3 up{ 0.0f, 1.0f, 0.0f };

    Matrix4 view;
    Matrix4 projection;
  };
}