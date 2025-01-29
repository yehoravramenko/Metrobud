#include "Renderer.hpp"
#include "../Log/Log.hpp"
#include <glad/glad.h>
#include <format>

namespace AuraEngine {
  constexpr float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  constexpr char vert_shader[] = R"(
    #version 460 core
    layout(location=0) in vec3 inPos;

    void main()
    {
      gl_Position = vec4(inPos, 1.0);
    }
  )";

  constexpr char frag_shader[] = R"(
    #version 460 core
    out vec4 FragColor;
    
    void main()
    {
      FragColor = vec4(0.0f, 0.5f, 0.0f, 1.0f);
    }
  )";

  Renderer::Renderer()
  {
    if (!SDL_Init(SDL_INIT_VIDEO))
      Log::EngineLog.Error(std::string("Failed to initialize SDL.\nSDL_Error: ") + SDL_GetError());

    int context_flags = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG;
#ifdef AE_DEBUG
    context_flags |= SDL_GL_CONTEXT_DEBUG_FLAG;
#endif

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, context_flags);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
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

    Log::EngineLog.Info(std::format("OpenGL Version: {}.{}", GLVersion.major, GLVersion.minor));
    Log::EngineLog.Info(std::format("OpenGL Shading Language Version: {}", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION)));
    Log::EngineLog.Info(std::format("OpenGL Vendor: {}", (char *)glGetString(GL_VENDOR)));
    Log::EngineLog.Info(std::format("OpenGL Renderer: {}", (char *)glGetString(GL_RENDERER)));

    glViewport(0, 0, 800, 600);
    glClearColor(.07f, .07f, .07f, 1.f);

    this->shader = new Shader(vert_shader, frag_shader);

    this->DummyVAO = new VertexArray();
    this->DummyVAO->Bind();

    this->VBO = new VertexBuffer(GL_ARRAY_BUFFER);
    this->VBO->Bind();
    this->VBO->SetData(sizeof(vertices), vertices);

    this->DummyVAO->AddVertexAttribPointer("vertexPos", 3, GL_FLOAT, GL_FALSE, 3, 0);

    this->DummyVAO->Unbind();
  }
  void Renderer::Render()
  {
    glClear(GL_COLOR_BUFFER_BIT);

    this->shader->Use();
    this->DummyVAO->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }

  Window *const Renderer::GetWindow()
  {
    return this->window;
  }
  Renderer::~Renderer()
  {
    delete this->shader;
    delete this->DummyVAO;
    delete this->VBO;
    delete this->window;
    SDL_Quit();
  }
  void Renderer::windowResizeCallback(std::pair<int, int> newSize)
  {
    glViewport(0, 0, newSize.first, newSize.second);
  }
}
