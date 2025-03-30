#include "Camera.hpp"

namespace AuraEngine
{
  Camera::Camera(const std::tuple<int, int> &size, const Vector3 position) : GameObject(position)
  {
    this->screenSize = size;
    this->aspectRatio = static_cast<float>(std::get<0>(size)) / std::get<1>(size);
    this->view = Matrix4(1.0f);
    this->projection = Matrix4(1.0f);
  }

  const Matrix4 Camera::GetViewProjectionMatrix()
  {
    this->view = glm::lookAt(this->position, this->position + this->orientation, this->up);
    this->projection = glm::perspective(glm::radians(this->fieldOfView), this->aspectRatio, 0.1f, 100.0f);

    return this->projection * this->view;
  }

}