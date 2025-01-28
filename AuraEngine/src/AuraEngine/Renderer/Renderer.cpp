#include "Renderer.hpp"
#include "../Log/Log.hpp"
#include <glad/glad.h>

namespace AuraEngine {
  Renderer::Renderer()
  {
    if (!SDL_Init(SDL_INIT_EVENTS))
      Log::EngineLog.Error(std::string("Failed to initialize SDL.\nSDL_Error: ") + SDL_GetError());

    int context_flags = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG;
#ifdef AE_DEBUG
    context_flags |= SDL_GL_CONTEXT_DEBUG_FLAG;
#endif

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, context_flags);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    this->window = new Window();

    this->gl_context = SDL_GL_CreateContext(this->window->GetSDLWindow());
    if (!this->gl_context)
      Log::EngineLog.Error(std::string("Failed to create GL context.\nSDL_Error: ") + SDL_GetError());

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
      Log::EngineLog.Error("Failed to intitialize GLAD.");
  }
  void Renderer::Render()
  {
  }

  Window *const Renderer::GetWindow()
  {
    return this->window;
  }
  Renderer::~Renderer()
  {
    delete this->window;
    SDL_Quit();
  }
}
