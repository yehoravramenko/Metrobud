#include <modules/client/client.hpp>

int main(int argc, char **argv) {
  Client_Init();
  while (g_Client()->isRunning) {
    Client_Update();
  }
  Client_Exit();
  return 0;
}