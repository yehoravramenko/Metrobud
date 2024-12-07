#include "window.hpp"

const int W_WIDTH = 800;
const int W_HEIGHT = 600;

Window *window;

Window *g_Window() {
  return window;
}

void Window_Init(vec2 *windowSize) {
  if (!glfwInit()) {
    ERR_MSG("Failed to initialize GLFW");
  }

  window = calloc(1, sizeof(Window));

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window->pGLFWWindow =
      glfwCreateWindow(W_WIDTH, W_HEIGHT, "metrobud", NULL, NULL);

  if (window->pGLFWWindow == NULL) {
    glfwTerminate();
    ERR_MSG("Failed to create a window");
  }

  glfwMakeContextCurrent(window->pGLFWWindow);

  *windowSize = (vec2){W_WIDTH, W_HEIGHT};
}

void Window_Update(bool *isRunning) {
  if (glfwGetKey(window->pGLFWWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
      glfwWindowShouldClose(window->pGLFWWindow)) {
    *isRunning = false;
  }

  glfwSwapBuffers(window->pGLFWWindow);
  glfwPollEvents();
}

void Window_Exit() {
  free(window);
}
