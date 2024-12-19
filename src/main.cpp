#include <client/client.hpp>

int ret_code = 0;

int main(int argc, char **argv) {
  auto Client = std::make_unique<Metrobud::Client>(argc, argv);
  while (!Client->shouldClose()) {
    Client->Update();
  }
  Client->Exit(ret_code);

  return ret_code;
}