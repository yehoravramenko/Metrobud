#include "Client.hpp"
#include "Debug/Debug.hpp"

using namespace AuraEngine;

constexpr float sensitivity = 0.1f;
bool firstClick = true;
Vector2 prevCursorPos{ 0, 0 };
float yaw = 0.0f;
float pitch = 0.0f;

constexpr float normalFOV = 60.0f;
constexpr float zoomFOV = 20.0f;
constexpr float zoomSpeed = 4.0f;
float zoomProgress = 0.0f;
bool camZoomed = false;

namespace Metrobud
{
  void Client::OnStart()
  {
  }

  void Client::OnUpdate()
  {
    if(Input::GetKey(KeyCode::Escape))
    {
      Application::Exit();
    }

    auto direction = Vector3(0.0f);
    auto &camFront = this->mainCamera->GetFront();
    auto &camUp = this->mainCamera->GetUp();
    auto &camPos = this->mainCamera->GetPosition();

    auto camSpeed = 5.0f * GetDeltaTime();

    if(Input::GetKey(KeyCode::W))
    {
      direction += camFront * camSpeed;
    }
    if(Input::GetKey(KeyCode::S))
    {
      direction += camSpeed * -camFront;
    }
    if(Input::GetKey(KeyCode::A))
    {
      direction += camSpeed * -glm::normalize(glm::cross(camFront, camUp));
    }
    if(Input::GetKey(KeyCode::D))
    {
      direction += camSpeed * glm::normalize(glm::cross(camFront, camUp));
    }

    this->mainCamera->Translate(direction);

    if(Input::GetMouseButton(MouseButton::Right))
    {
      auto cursorPos = Input::GetCursorPosition();

      if(firstClick)
      {
        Input::SetCursorVisibility(false);
        prevCursorPos = cursorPos;
        firstClick = false;
      }

      auto cursorDelta = (cursorPos - prevCursorPos) * sensitivity;

      yaw -= cursorDelta.x;
      pitch += cursorDelta.y;

      pitch = Math::Clamp(pitch, -89.0f, 89.0f);

      if(yaw >= 360)
      {
        yaw -= 360;
      }
      else if(yaw <= -360)
      {
        yaw += 360;
      }

      Quaternion rotation{ Math::EulerAngles(pitch, yaw, 0.0f) };
      this->mainCamera->Rotate(rotation);

      prevCursorPos = cursorPos;
    }
    else
    {
      Input::SetCursorVisibility(true);
      firstClick = true;
    }

    if(Input::GetKey(KeyCode::B) && !camZoomed)
    {
      zoomProgress += zoomSpeed * GetDeltaTime();
      this->mainCamera->SetFOV(Math::Lerp(normalFOV, zoomFOV, zoomProgress));
      if(zoomProgress >= 1.0f)
      {
        zoomProgress = 0.0f;
        camZoomed = true;
      }
    }
    else if(Input::GetKeyUp(KeyCode::B) && camZoomed)
    {
      zoomProgress += zoomSpeed * GetDeltaTime();
      this->mainCamera->SetFOV(Math::Lerp(zoomFOV, normalFOV, zoomProgress));
      if(zoomProgress >= 1.0f)
      {
        zoomProgress = 0.0f;
        camZoomed = false;
      }
    }
    else if(Input::GetKeyUp(KeyCode::B) && !camZoomed && zoomProgress != 0.0f)
    {
      camZoomed = true;
      zoomProgress = 1.0f - zoomProgress;
    }
  }

  void Client::OnDraw() {}

  void Client::OnExit()
  {
  }

} // namespace Metrobud