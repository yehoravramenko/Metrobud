#pragma once
#include "../OpenGLObject.hpp"
#include "glad/glad.h"
#include <string>

namespace AuraEngine::OpenGL {
class Texture : private OpenGLObject {
public:
  Texture(const std::string &filename,
          const GLenum minFilter = GL_LINEAR_MIPMAP_LINEAR,
          const GLenum magFilter = GL_LINEAR);
  void Bind() const;

private:
  int m_width, m_height, m_nrChannels;
};
} // namespace AuraEngine::OpenGL