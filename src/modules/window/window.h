#pragma once

#include <common.h>

typedef struct Window {
  GLFWwindow *pWindow;
} Window;

Window *g_Window();

void Window_Init(vec2 *windowSize);
void Window_Update(bool *isRunning);
void Window_Exit();