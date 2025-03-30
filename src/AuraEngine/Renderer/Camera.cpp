#include "Camera.hpp"

namespace AuraEngine
{
  Camera::Camera(const float aspectRatio, const Vector3 position)
  {
    this->position = position;
    this->view = glm::lookAt(this->position, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });
    this->projection = glm::perspective(glm::radians(this->fieldOfView), aspectRatio, 0.1f, 100.0f);
  }

  const Matrix4 Camera::GetViewProjectionMatrix() const
  {
    return this->projection * this->view;
  }

}