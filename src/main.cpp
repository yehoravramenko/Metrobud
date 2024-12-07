#include <modules/client/client.hpp>

int main(int argc, char **argv) {
  Client client;
  client.Init();
  while (client.isRunning) {
    client.Update();
  }
  client.Exit();
  return 0;
}