#include "Client.hpp"

namespace Metrobud {
Client::Client() {
  this->size = std::tuple(800, 600);
  this->window = new Window(this->size, "Metrobud");
  this->renderer = new Renderer(this->size);
}

void Client::EventLoop() {
  this->window->Update();
  this->renderer->Update();
  this->renderer->Draw();
}

Client::~Client() {
  delete this->renderer;
  delete this->window;
}

} // namespace Metrobud