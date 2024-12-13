#include <RGFW/RGFW.h>
#include <print>

int main(int argc, char **argv) {
  std::println("metrobud?");

  RGFW_window *window = RGFW_createWindow("metrobud", RGFW_RECT(0, 0, 800, 600),
                                          (u16)(RGFW_CENTER | RGFW_NO_RESIZE));

  while (RGFW_window_shouldClose(window) == RGFW_FALSE) {
    RGFW_window_checkEvents(window, 0);
    RGFW_window_swapBuffers(window);
  }

  RGFW_window_close(window);

  return 0;
}