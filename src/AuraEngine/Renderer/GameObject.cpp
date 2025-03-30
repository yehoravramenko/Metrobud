#include "GameObject.hpp"

namespace AuraEngine
{
  GameObject::GameObject(const Vector3 position)
  {
    this->position = position;
  }

  void GameObject::Translate(Vector3 translation)
  {
    translation.z = -translation.z;
    this->position += translation;
  }
}