#pragma once

#include <common.hpp>

typedef struct Client {
  vec2 windowSize;
  bool isRunning;
} Client;

Client *g_Client();

void Client_Init();
void Client_Update();
void Client_Exit();