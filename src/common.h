#pragma once

#include "stdio.h"
#include "stdlib.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define ERR_MSG(...)                                                           \
  printf("Error: "__VA_ARGS__);                                                \
  printf("\n");                                                                \
  exit(-1);

#ifdef DEBUG
#define DEBUG_MSG(...)                                                         \
  printf("Log: "__VA_ARGS__);                                                  \
  printf("\n");
#endif // DEBUG