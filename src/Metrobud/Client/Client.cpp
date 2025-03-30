#include "Client.hpp"
#include "Debug/Debug.hpp"
using namespace AuraEngine;

float speed = 0.1f;
float sensitivity = 100.0f;

namespace Metrobud
{
  void Client::OnStart()
  {
    Debug::Log("Client::OnStart called!");
  }

  void Client::OnUpdate()
  {
    if(Input::GetKey(KeyCode::Escape))
    {
      Application::Exit();
    }

    if(Input::GetKey(KeyCode::W))
    {
      this->mainCamera->Translate(speed * Vector3{ 0.0f, 0.0f, 1.0f });
    }
    if(Input::GetKey(KeyCode::S))
    {
      this->mainCamera->Translate(speed * Vector3{ 0.0f, 0.0f, -1.0f });
    }
    if(Input::GetKey(KeyCode::A))
    {
      this->mainCamera->Translate(speed * Vector3{ -1.0f, 0.0f, 0.0f });
    }
    if(Input::GetKey(KeyCode::D))
    {
      this->mainCamera->Translate(speed * Vector3{ 1.0f, 0.0f, 0.0f });
    }

    /*const std::tuple<float, float> &mousePosition = Input::GetCursorPosition();
    float rotationX = sensitivity * (std::get<1>(mousePosition) - std::get<1>(this->))*/
  }

  void Client::OnDraw() {}

  void Client::OnExit()
  {
    Debug::Log("Client::OnExit called!");
  }

} // namespace Metrobud