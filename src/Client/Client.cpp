#include "Client.hpp"

namespace Metrobud {
Client::Client()
{
  this->size = std::tuple(800, 600);
  this->window = new Window(this->size, "Metrobud");
}

Client::~Client()
{
  delete this->window;
}
}