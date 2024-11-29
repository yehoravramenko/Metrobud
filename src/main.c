#include "common.h"
#include "Client/client.h"

int main(int argc, char **argv) {
  Client_Init();
  while (Client()->isRunning) {
    Client_Update();
  }
  Client_Exit();
  return 0;
}