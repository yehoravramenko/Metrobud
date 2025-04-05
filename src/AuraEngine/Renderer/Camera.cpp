#include "Camera.hpp"
#include "Input/Input.hpp"

namespace AuraEngine
{
  Camera::Camera(const WindowSize windowSize, Vector3 position) : GameObject(position)
  {
    this->windowSize = windowSize;
    this->aspectRatio = static_cast<float>(this->windowSize.width) / this->windowSize.height;
    this->rotation = Quaternion(Vector3(0.0f, 0.0f, 0.0f));
  }

  void Camera::Rotate(Quaternion &rotation)
  {
    this->rotation = rotation;
  }

  void Camera::SetFOV(const float fov)
  {
    this->fieldOfView = fov;
  }

  const Matrix4 Camera::GetViewProjectionMatrix()
  {
    auto rotation = glm::toMat4(this->rotation);

    this->up = Vector3(rotation[1]);
    this->front = Vector3(rotation[2]);

    auto view = glm::lookAt(this->position, this->position + this->front, this->up);
    auto projection = glm::perspective(glm::radians(this->fieldOfView), this->aspectRatio, 0.1f, 100.0f);

    return projection * view;
  }
}