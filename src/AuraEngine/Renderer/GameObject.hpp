#pragma once
#include "AE_API.hpp"
#include "Math.hpp"

namespace AuraEngine
{
  class GameObject
  {
  public:
    GameObject(Vector3 &position);
    AE_API virtual void Translate(Vector3 &translation);
    //AE_API virtual void Rotate(const float rotX, const float rotY, const float rotZ);

    AE_API const Vector3 &GetPosition() const
    {
      return this->position;
    }

  protected:
    Vector3 position;
  };
}