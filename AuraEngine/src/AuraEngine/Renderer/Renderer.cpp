#include "Renderer.hpp"
#include "../Log/Log.hpp"
#include <glad/glad.h>
#include <format>

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace AuraEngine {
  constexpr float vertices[] = {
    // positions        // texture coords
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f, 0.0f, 1.0f    // top left 
  };

  constexpr unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
  };

  constexpr char vert_shader[] = R"(
    #version 460 core
    layout(location=0) in vec3 inPos;
    layout(location=1) in vec2 inTexCoord;

    out vec2 TexCoord;

    uniform mat4 mvp;

    void main()
    {
      gl_Position = mvp * vec4(inPos, 1.0);
      TexCoord = inTexCoord;  
    }
  )";

  constexpr char frag_shader[] = R"(
    #version 460 core
    out vec4 FragColor;
    
    in vec2 TexCoord;
    
    uniform sampler2D tex1;

    void main()
    {
      FragColor = texture(tex1, TexCoord);
    }
  )";

  glm::mat4 model;

  Renderer::Renderer()
  {
    if (!SDL_Init(SDL_INIT_VIDEO))
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

    Log::EngineLog.Info(std::format("OpenGL Version: {}.{}", GLVersion.major, GLVersion.minor));
    Log::EngineLog.Info(std::format("OpenGL Shading Language Version: {}", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION)));
    Log::EngineLog.Info(std::format("OpenGL Vendor: {}", (char *)glGetString(GL_VENDOR)));
    Log::EngineLog.Info(std::format("OpenGL Renderer: {}", (char *)glGetString(GL_RENDERER)));

    glViewport(0, 0, 800, 600);
    glClearColor(.07f, .07f, .07f, 1.f);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);                   // x texture coordinate
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);                   // y texture coordinate
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // downscaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               // upscaling

    this->texture1 = new Texture(R"(E:\aura\Metrobud\resources\kenney_prototype-textures\PNG\Orange\texture_01.png)");

    this->shader = new Shader(vert_shader, frag_shader);
    this->shader->SetInt("tex1", 0);

    this->DummyVAO = new VertexArray();
    this->DummyVAO->Bind();

    this->VBO = new Buffer(GL_ARRAY_BUFFER);
    this->VBO->Bind();
    this->VBO->SetData(sizeof(vertices), vertices);

    this->EBO = new Buffer(GL_ELEMENT_ARRAY_BUFFER);
    this->EBO->Bind();
    this->EBO->SetData(sizeof(indices), indices);

    this->DummyVAO->AddVertexAttribPointer("vertexPos", 3, GL_FLOAT, GL_FALSE, 5, 0);
    this->DummyVAO->AddVertexAttribPointer("texturePos", 2, GL_FLOAT, GL_FALSE, 5, 3);

    this->DummyVAO->Unbind();

    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  }
  void Renderer::Render()
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));

    const std::pair<int, int> &windowSize = this->window->GetSize();
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(60.0f), static_cast<float>(windowSize.first) / windowSize.second, 0.1f, 100.0f);

    glm::mat4 mvp = projection * view * model;

    this->shader->Use();
    this->shader->SetMat4(this->shader->GetUniformLocation("mvp"), glm::value_ptr(mvp));

    this->texture1->Bind();
    this->DummyVAO->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
