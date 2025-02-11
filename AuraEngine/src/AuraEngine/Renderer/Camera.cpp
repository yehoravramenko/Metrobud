#include "Camera.hpp"
#include "Renderer.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "../Log/Log.hpp"

namespace AuraEngine
{
  Camera::Camera(const float &fov, const glm::vec3 &position, const Renderer *renderer)
  {
    this->fov = fov;
    this->position = position;
    this->renderer = renderer;
  }

  void Camera::Translate(const glm::vec3 &translation)
  {
    this->position.x += translation.x;
    this->position.y += translation.y;
    this->position.z -= translation.z;
  }

  const glm::mat4 &Camera::GetTransform()
  {
    return this->transform;
  }

  void Camera::updateTransform()
  {
    glm::mat4 view = glm::lookAt(this->position, this->position + Camera::GLOBAL_FRONT, Camera::GLOBAL_UP);
    // TODO: move near and far distances to variables
    glm::mat4 proj = glm::perspective(glm::radians(this->fov), this->renderer->GetAspectRatio(), 0.1f, 100.0f);
    this->transform = proj * view;
  }
}