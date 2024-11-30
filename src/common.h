#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/math/math.h"

#define ERR_MSG(...)                                                           \
  printf("Error: "__VA_ARGS__);                                                \
  printf("\n");                                                                \
  exit(-1);

#ifdef DEBUG
#define DEBUG_MSG(...)                                                         \
  printf(__VA_ARGS__);                                                         \
  printf("\n");
#else
#define DEBUG_MSG(...)
#endif // DEBUG