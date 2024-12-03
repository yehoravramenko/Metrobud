#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/math/math.h"

#include "modules/engine/engine.h"

#define ERR_MSG(...)                                                           \
  printf("Error: "__VA_ARGS__);                                                \
  printf("\n");                                                                \
  exit(-1);

#ifdef DEBUG
#define DEBUG_MSG(...)                                                         \
  printf(__VA_ARGS__);                                                         \
  printf("\n");
#else
#define DEBUG_MSG(...) Engine_WriteLog(__VA_ARGS__);
#endif // DEBUG