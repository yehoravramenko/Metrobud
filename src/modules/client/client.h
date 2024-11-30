#pragma once

#include <common.h>

typedef struct _Client {
  vec2 windowSize;
  bool isRunning;
} _Client;

typedef _Client *Client;

Client g_Client();

void Client_Init();
void Client_Update();
void Client_Exit();