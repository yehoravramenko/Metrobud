#include "renderer.hpp"
#include "shader_src.hpp"

// float vertices[] = {
//     // positions          // texture coords
//     0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
//     0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
//     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
//     -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
// };

float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

Shader *shader;

Renderer::Renderer(vec2 &viewportSize) {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    ERR_MSG("Failed to initialize OpenGL");
  }

  this->clearColor = {0.0f, 0.0f, 0.0f, 1.0f};
  this->clearMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;

  GL::Viewport({0, 0}, viewportSize);

  this->VAO = new VertexArray();
  this->VAO->Bind();

  this->VBO = new Buffer(GL_ARRAY_BUFFER);
  this->VBO->Data(sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Shader_New(&shader, vertexShader_src, fragmentShader_src);
  shader = new Shader(vertexShader_src, fragmentShader_src);

  const unsigned int VERTEX_COORD_index = 0;
  GL::VertexAttribPointer(VERTEX_COORD_index, 3, GL_FLOAT, 3 * sizeof(float),
                          NULL);
  GL::EnableVertexAttribArray(VERTEX_COORD_index);
}

void Renderer::Update() {
}

void Renderer::Render() {
  GL::Clear(this->clearMask);

  shader->Use();
  this->VAO->Bind();
  GL::DrawArrays(GL_TRIANGLES, 0, 3);
}

Renderer::~Renderer() {
  delete shader;
  delete this->VBO;
  delete this->VAO;
}
