#include "Client.hpp"

namespace Metrobud {
Client::Client() {
  this->size = std::tuple(800, 600);
  this->window = std::make_unique<Window>(this->size, "Metrobud");
  this->renderer = std::make_unique<Renderer>(this->size);
}

void Client::EventLoop() {
  this->window->Update();
  this->renderer->Update();
  this->renderer->Draw();
}
} // namespace Metrobud