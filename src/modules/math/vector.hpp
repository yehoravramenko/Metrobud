#pragma once

#ifdef AURA_MATH_USE_DOUBLE
#define FLOAT double
#else
#define FLOAT float
#endif

struct vec2 {
  FLOAT x, y;
};

struct vec3 {
  FLOAT x, y, z;
};

struct vec4 {
  FLOAT x, y, z, w;
};