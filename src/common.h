#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/math/math.h"

#include "modules/engine/engine.h"

#ifdef DEBUG
#define DEBUG_MSG(...)                                                         \
  printf("DEBUG MESSAGE\t"__VA_ARGS__);                                        \
  printf("\n");

#define ERR_MSG(...)                                                           \
  printf("ENGINE ERROR\t"__VA_ARGS__);                                         \
  printf("\n");                                                                \
  exit(-1);
#else
#define DEBUG_MSG(...)                                                         \
  Engine_WriteLog("DEBUG MESSAGE\t");                                          \
  Engine_WriteLog(__VA_ARGS__);                                                \
  Engine_WriteLog("\n");
#define ERR_MSG(...)                                                           \
  Engine_WriteLog("ENGINE ERROR\t");                                           \
  Engine_WriteLog(__VA_ARGS__);                                                \
  Engine_WriteLog("\n");                                                       \
  exit(-1);
#endif // DEBUG