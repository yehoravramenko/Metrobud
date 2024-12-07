#pragma once

#ifdef AURA_MATH_USE_DOUBLE
#define FLOAT double
#else
#define FLOAT float
#endif

typedef struct vec2 {
  FLOAT x, y;
} vec2;

typedef struct vec3 {
  FLOAT x, y, z;
} vec3;

typedef struct vec4 {
  FLOAT x, y, z, w;
} vec4;