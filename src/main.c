#include <modules/client/client.h>

int main(int argc, char **argv) {
  Client_Init();
  while (g_Client()->isRunning) {
    Client_Update();
  }
  Client_Exit();
  return 0;
}