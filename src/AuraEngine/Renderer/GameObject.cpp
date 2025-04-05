#include "GameObject.hpp"

namespace AuraEngine
{
  GameObject::GameObject(Vector3 &position)
  {
    this->position = position;
  }

  void GameObject::Translate(Vector3 &translation)
  {
    this->position += translation;
  }
}