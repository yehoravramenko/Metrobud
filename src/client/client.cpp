#include "client.hpp"

using namespace Metrobud;

Client::Client(int &argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    this->argv.push_back(argv[i]);
  }

  this->window = std::make_unique<Window>();
  this->renderer = std::make_unique<Renderer>(this->window->getRect());
}

void Client::Update() {
  this->window->Update();
  this->renderer->Update();
  this->renderer->Draw();
}

void Client::Exit(int &ret_code) {
  this->renderer->Exit();
  this->window->Exit();
  ret_code = 0;
}

bool Client::shouldClose() {
  return this->window->shouldClose();
}