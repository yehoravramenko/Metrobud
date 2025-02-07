#include "Renderer.hpp"
#include "../Log/Log.hpp"
#include "../Client/Client.hpp"
#include <glad/glad.h>
#include <format>

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

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

    uniform mat4 model;
    uniform mat4 viewProj; // view * projection

    void main()
    {
      gl_Position = viewProj * model * vec4(inPos, 1.0);
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

  Renderer::Renderer(Client *client)
  {
    this->client = client;

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

    this->window = std::make_unique<Window>();

    this->gl_context = SDL_GL_CreateContext(this->window->GetSDLWindow());
    if (!this->gl_context)
      Log::EngineLog.Error(std::string("Failed to create GL context.\nSDL_Error: ") + SDL_GetError());

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
      Log::EngineLog.Error("Failed to intitialize GLAD.");

    Log::EngineLog.Info(std::format("OpenGL Version: {}.{}", GLVersion.major, GLVersion.minor));
    Log::EngineLog.Info(std::format("OpenGL Shading Language Version: {}", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION)));
    Log::EngineLog.Info(std::format("OpenGL Vendor: {}", (char *)glGetString(GL_VENDOR)));
    Log::EngineLog.Info(std::format("OpenGL Renderer: {}", (char *)glGetString(GL_RENDERER)));

    this->ui = std::make_unique<UI>(this->window->GetSDLWindow(), this->gl_context);
    this->ui->rootFrame.AddElement({ "deltaTimeText", new UIText{ {0.0f, 0.0f}, "test!" } });

    glViewport(0, 0, 800, 600);
    glClearColor(.07f, .07f, .07f, 1.f);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);                   // x texture coordinate
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);                   // y texture coordinate
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // downscaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               // upscaling

    this->texture1 = std::make_unique<Texture>(R"(E:\aura\Metrobud\resources\kenney_prototype-textures\PNG\Green\texture_01.png)");

    this->shader = std::make_unique<Shader>(vert_shader, frag_shader);
    this->shader->SetInt("tex1", 0);

    this->DummyVAO = std::make_unique<VertexArray>();
    this->DummyVAO->Bind();

    this->VBO = std::make_unique<Buffer>(GL_ARRAY_BUFFER);
    this->VBO->Bind();
    this->VBO->SetData(sizeof(vertices), vertices);

    this->EBO = std::make_unique<Buffer>(GL_ELEMENT_ARRAY_BUFFER);
    this->EBO->Bind();
    this->EBO->SetData(sizeof(indices), indices);

    this->DummyVAO->AddVertexAttribPointer("vertexPos", 3, GL_FLOAT, GL_FALSE, 5, 0);
    this->DummyVAO->AddVertexAttribPointer("texturePos", 2, GL_FLOAT, GL_FALSE, 5, 3);

    this->DummyVAO->Unbind();

    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    this->camera = std::make_unique<Camera>(60.0f, glm::vec3{ 0.0f, 0.0f, 1.0f }, this);
  }

  void Renderer::Update()const
  {
    this->window->Update();
    this->camera->updateTransform();

    dynamic_cast<UIText *>(this->ui->rootFrame.GetElement("deltaTimeText"))->SetText(std::format("deltaTime: {}ms", this->client->GetDeltaTime()));
  }

  void Renderer::Render()const
  {
    glClear(GL_COLOR_BUFFER_BIT);
    this->ui->Update();

    this->shader->Use();
    this->shader->SetMat4("model", model);
    this->shader->SetMat4("viewProj", this->camera->GetTransform());
    this->texture1->Bind();
    this->DummyVAO->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    this->ui->Draw();
  }

  const float Renderer::GetAspectRatio() const
  {
    const std::pair<int, int> &windowSize = this->window->GetSize();
    return static_cast<float>(windowSize.first) / windowSize.second;
  }

  Camera *const Renderer::GetCamera() const
  {
    return this->camera.get();
  }

  Renderer::~Renderer()
  {
    SDL_Quit();
  }
  void Renderer::windowResizeCallback(std::pair<int, int> newSize) const
  {
    glViewport(0, 0, newSize.first, newSize.second);
  }
}
