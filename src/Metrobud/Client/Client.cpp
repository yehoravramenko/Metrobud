#include "Client.hpp"
#include "Debug/Debug.hpp"

using namespace AuraEngine;

constexpr float sensitivity = 0.15f;
Vector2 cursorCenter{};
float pitch = 0.0f;
float yaw = 180.0f;

constexpr float normalFOV = 60.0f;
constexpr float zoomFOV = 20.0f;
constexpr float zoomSpeed = 3.0f;
float zoomProgress = 0.0f;
bool camZoomed = false;

namespace Metrobud
{
  void Client::OnStart()
  {
    cursorCenter = { this->GetWindowSize().width / 2.0f, this->GetWindowSize().height / 2.0f };
    Input::SetCursorVisibility(false);
    Input::SetCursorPosition(cursorCenter);
  }

  void Client::OnUpdate()
  {
    if(Input::GetKey(KeyCode::Escape))
    {
      Application::Exit();
    }

    this->UpdateCamera();
  }

  void Client::UpdateCamera()
  {
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

    auto cursorPos = Input::GetCursorPosition();

    auto cursorDelta = (cursorPos - cursorCenter) * sensitivity;

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

    Input::SetCursorPosition(cursorCenter);

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