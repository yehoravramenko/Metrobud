#include "stdio.h"
#include "stdlib.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define ERR_MSG(...)                                                           \
  printf("Error: "__VA_ARGS__);                                                \
  printf("\n");                                                                \
  exit(-1);

const int W_WIDTH = 800;
const int W_HEIGHT = 600;

float vertices[] = {
    // positions          // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
};

unsigned int VAO, VBO;

int main(int argc, char **argv) {
  if (!glfwInit()) {
    ERR_MSG("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(W_WIDTH, W_HEIGHT, "metrobud", NULL, NULL);

  if (window == NULL) {
    glfwTerminate();
    ERR_MSG("Failed to create a window");
  }

  glfwMakeContextCurrent(window);
  gladLoadGL();
  glViewport(0, 0, W_WIDTH, W_HEIGHT);
  glClearColor(0.0f, 0.5f, 0.0f, 0.0f);

  while (!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, 1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  return 0;
}