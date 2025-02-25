#include "Client.hpp"
#include "AuraEngine/Debug/Debug.hpp"
using namespace AuraEngine;

namespace Metrobud {
void Client::OnStart() {
  Debug::Log("Client::OnStart called!");
}

void Client::OnUpdate() {
  if (Input::GetKey(KeyCode::Escape)) {
    Application::Exit();
  }
}

void Client::OnDraw() {}

void Client::OnExit() {
  Debug::Log("Client::OnExit called!");
}
} // namespace Metrobud