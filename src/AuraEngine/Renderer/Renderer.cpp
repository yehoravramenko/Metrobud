#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"

#include <tiny_obj_loader.h>

#include "Debug/Debug.hpp"
#include <format>
#include <vector>


namespace AuraEngine
{
  std::vector<Vertex> vertices;

  const std::string vs_src = R"(
#version 460 core
layout (location = 0) in vec3 inPos;
//layout (location = 1) in vec3 inNormal;
layout (location = 1) in vec2 inTexCoord;

out vec2 TexCoord;

uniform mat4 mvp;

void main() {
  vec4 inv_pos = mvp * vec4(inPos, 1.0f);
  // vec4 inv_pos = mvp * vec4(inPos.x, inPos.y, -inPos.z, 1.0f);
  gl_Position = inv_pos;
  TexCoord = inTexCoord;
}
)";

  const std::string fs_src = R"(
#version 460 core
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex;

void main() {
  FragColor = texture(tex, TexCoord);
}
)";

  Renderer::Renderer(const WindowSize &windowSize) :
    VBO(GL_ARRAY_BUFFER), EBO(GL_ELEMENT_ARRAY_BUFFER),
    dummyShader(vs_src, fs_src),
    testTex("../metrobud/textures/kenney_prototype/Dark/texture_01.png"),
    camera(windowSize, { 0.0f, 0.0f, 10.0f })
  {
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, windowSize.width, windowSize.height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials; // currently unused
    std::string errors, warns;

    auto model_path = "../metrobud/models/717.obj";
    //auto mtl_path = "../metrobud/models";

    auto loadSuccess = tinyobj::LoadObj(&attrib, &shapes, &materials, &errors, &warns,
      model_path);

    if(!errors.empty())
    {
      Debug::Warning(errors);
    }

    if(!loadSuccess)
    {
      Debug::Error("Failed to load model");
    }

    for(auto i = 0; i < shapes.size(); ++i)
    {
      auto &shape = shapes[i];
      auto &mesh = shape.mesh;

      for(auto j = 0; j < mesh.indices.size(); ++j)
      {
        tinyobj::index_t ind = mesh.indices[j];
        auto position = Vector3
        {
          attrib.vertices[ind.vertex_index * 3],
          attrib.vertices[ind.vertex_index * 3 + 1],
          attrib.vertices[ind.vertex_index * 3 + 2],
        };

        //auto normal = Vector3
        //{
        //  attrib.vertices[ind.normal_index * 3],
        //  attrib.vertices[ind.normal_index * 3 + 1],
        //  attrib.vertices[ind.normal_index * 3 + 2],
        //};

        auto texCoord = Vector2
        {
          attrib.texcoords[ind.texcoord_index * 2],
          attrib.texcoords[ind.texcoord_index * 2 + 1],
        };

        auto vert = Vertex{ position, texCoord };
        vertices.push_back(vert);
      }
    }

    this->VAO.Bind();

    this->VBO.Bind();
    this->VBO.Data(sizeof(Vertex) * vertices.size(), &vertices[0]);

    //this->EBO.Bind();
    //this->EBO.Data(sizeof(indices), indices);

    OpenGL::VertexAttribPointer(0, 3, 5, 0);
    OpenGL::EnableVertexAttribArray(0);
    OpenGL::VertexAttribPointer(1, 2, 5, 3);
    OpenGL::EnableVertexAttribArray(1);
    //OpenGL::VertexAttribPointer(2, 2, 8, 6);
    //OpenGL::EnableVertexAttribArray(2);
  }

  void Renderer::Update()
  {
    auto model = Matrix4(1.0f);
    model = glm::rotate(model, glm::radians(-90.0f), Vector3(1.0f, 0.0f, 0.0f));

    auto mvp = this->camera.GetViewProjectionMatrix() * model;
    this->dummyShader.Use();
    this->dummyShader.SetMat4("mvp", mvp);
  }

  void Renderer::Draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->testTex.Bind();
    this->dummyShader.Use();
    this->VAO.Bind();
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
  }

  Renderer::~Renderer()
  {
    // TODO: dtor
  }
} // namespace AuraEngine