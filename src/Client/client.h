#pragma once
#include "../common.h"

typedef struct _AuraClient {
  GLFWwindow *window;
  bool isRunning;
} _AuraClient;

typedef _AuraClient *AuraClient;

AuraClient Client();

void Client_Init();
void Client_Update();
void Client_Exit();