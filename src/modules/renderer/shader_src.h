#pragma once
#define GLSL(src) "#version 460\n" #src
// clang-format off

const char *vertexShader_src = GLSL(
layout(location = 0) in vec3 inPos;

void main()
{
  gl_Position = vec4(inPos, 1.0);
}
);

const char *fragmentShader_src = GLSL(
out vec4 FragColor;

void main()
{
  FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
);