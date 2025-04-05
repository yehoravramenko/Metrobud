#pragma once
#include "AE_API.hpp"
#include "Window/Window.hpp"
#include "Renderer/GameObject.hpp"
#include "Math.hpp"

namespace AuraEngine
{
  class Camera : public GameObject
  {
  public:
    Camera(const WindowSize windowSize, Vector3 position = { 0.0f, 0.0f, 0.0f });

    AE_API void Rotate(Quaternion &rotation);
    AE_API void SetFOV(const float fov);

    const Matrix4 GetViewProjectionMatrix();
    auto GetFront() -> const Vector3 & { return this->front; };
    auto GetUp() -> const Vector3 & { return this->up; };
    auto GetFOV() -> const float & { return this->fieldOfView; }

  private:
    float aspectRatio;
    float fieldOfView = 60.0f;

    WindowSize windowSize;

    Vector3 front{ 0.0f, 0.0f, -1.0f };
    Vector3 up{ 0.0f, 1.0f, 0.0f };

    Quaternion rotation;
  };
}