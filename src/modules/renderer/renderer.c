#include "renderer.h"

#define GLSL(src) "#version 460\n" #src

// float vertices[] = {
//     // positions          // texture coords
//     0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
//     0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
//     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
//     -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
// };

float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

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

// clang-format on

Renderer *renderer;
Shader shader;

Renderer *g_Renderer() {
  return renderer;
}

void Renderer_SetClearMask(unsigned int mask) {
  renderer->clearMask = mask;
}

bool Renderer_Init(vec2 viewportSize) {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    ERR_MSG("Failed to initialize OpenGL");
  }

  renderer = calloc(1, sizeof(Renderer));
  GL_SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  Renderer_SetClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GL_Viewport((vec2){0, 0}, viewportSize);

  VertexArray_New(&renderer->VAO);
  VertexArray_Bind(&renderer->VAO);

  Buffer_New(&renderer->VBO, GL_ARRAY_BUFFER);
  Buffer_Data(&renderer->VBO, sizeof(vertices), vertices, GL_STATIC_DRAW);

  Shader_New(&shader, vertexShader_src, fragmentShader_src);

  const unsigned int VERTEX_COORD_index = 0;
  GL_VertexAttribPointer(VERTEX_COORD_index, 3, GL_FLOAT, 3 * sizeof(float),
                         NULL);
  GL_EnableVertexAttribArray(VERTEX_COORD_index);

  VertexArray_Bind(0);

  return true;
}

void Renderer_Update() {
}

void Renderer_Render() {
  GL_Clear(renderer->clearMask);

  Shader_Use(&shader);
  VertexArray_Bind(&renderer->VAO);
  GL_DrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer_Exit() {
  Shader_Delete(&shader);
  Buffer_Free(&renderer->VBO);
  VertexArray_Free(&renderer->VAO);
  free(renderer);
}
