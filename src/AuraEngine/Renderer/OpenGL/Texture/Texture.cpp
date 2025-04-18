#include "Texture.hpp"
#include "Debug/Debug.hpp"
#include <format>
#include <stb/stb_image.h>

namespace AuraEngine::OpenGL
{
  Texture::Texture(const std::string &filename, const GLenum minFilter,
    const GLenum magFilter)
  {
    glGenTextures(1, &this->handle);
    Bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    stbi_set_flip_vertically_on_load(true);
    unsigned char *data =
      stbi_load(filename.c_str(), &this->width, &this->height, &this->nrChannels, 0);
    if(!data)
    {
      Debug::Warning(std::format("Failed to load texture {}", filename));
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB,
      GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
  }

  void Texture::Bind() const
  {
    glBindTexture(GL_TEXTURE_2D, this->handle);
  }

} // namespace AuraEngine::OpenGL