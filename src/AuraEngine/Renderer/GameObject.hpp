#pragma once
#include "AE_API.hpp"
#include "AuraMath.hpp"

namespace AuraEngine
{
  class GameObject
  {
  public:
    GameObject(const Vector3 position);
    AE_API void Translate(Vector3 translation);
    AE_API const Vector3 &GetPosition() const
    {
      return this->position;
    }

  protected:
    Vector3 position;
  };
}