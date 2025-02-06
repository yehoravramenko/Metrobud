#include "Camera.hpp"
#include "Renderer.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace AuraEngine
{
  Camera::Camera(const float &fov, const glm::vec3 &position, const Renderer *renderer)
  {
    this->fov = fov;
    this->position = position;
    this->renderer = renderer;

    //this->updateTransform();
  }

  void Camera::Move(const glm::vec3 &position)
  {
    this->position += position;
  }

  const glm::mat4 &Camera::GetTransform()
  {
    return this->transform;
  }

  void Camera::updateTransform()
  {
    glm::mat4 view = glm::translate(glm::mat4(1.0f), this->position);
    // TODO: move near and far distances to variables
    glm::mat4 proj = glm::perspective(glm::radians(this->fov), this->renderer->GetAspectRatio(), 0.1f, 100.0f);
    this->transform = proj * view;
  }
}