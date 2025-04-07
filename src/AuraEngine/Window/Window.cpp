#include "Window.hpp"
#include "Debug/Debug.hpp"
#include <stdio.h>
#include "Input/Input.hpp"

#include <SDL3/SDL.h>
#include "glad/glad.h"

namespace AuraEngine
{
  SDL_Window *InputNativeAPI::NativeWindow;

  Window::Window(std::string_view title, WindowSize size)
  {
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
      Debug::Error("Failed to initialize SDL");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    auto dm = SDL_GetCurrentDisplayMode(1); // TODO: It's hardcoded first display, maybe it should be fixed . . .
    this->size.width = dm->w;
    this->size.height = dm->h;

    // TODO: Implement window mode if size != {0, 0}

    unsigned int windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS;
    this->handle = SDL_CreateWindow(title.data(), this->size.width, this->size.height, windowFlags);
    if(this->handle == nullptr)
    {
      Debug::Error("Failed to create window");
    }

    SDL_SetWindowPosition(this->handle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    this->glContext = SDL_GL_CreateContext(this->handle);
    if(this->glContext == nullptr)
    {
      Debug::Error("Failed to initialize OpenGL context");
    }

    SDL_GL_MakeCurrent(this->handle, this->glContext);
    SDL_GL_SetSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
      Debug::Error("Failed to load GLAD");
    }

    InputNativeAPI::NativeWindow = this->handle;
  }

  void Window::Update()
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_EVENT_QUIT)
      {
        this->shouldExit = true;
      }
    }
    SDL_GL_SwapWindow(this->handle);
  }

  bool Window::ShouldExit() const
  {
    return this->shouldExit;
  }

  Window::~Window()
  {
    SDL_GL_DestroyContext(this->glContext);
    SDL_DestroyWindow(this->handle);
    SDL_Quit();
  }

  const WindowSize &Window::GetSize() const
  {
    return this->size;
  }
} // namespace AuraEngine