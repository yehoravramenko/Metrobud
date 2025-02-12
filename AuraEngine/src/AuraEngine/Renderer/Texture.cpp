#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <format>
#include <glad/glad.h>
#include <stb_image.h>
#include "../Log/Log.hpp"

namespace AuraEngine
{
    Texture::Texture(const std::string& filename)
    {
        stbi_set_flip_vertically_on_load(true);
        int w, h, nrChannels;
        unsigned char* data = stbi_load(filename.c_str(), &w, &h, &nrChannels, 0);
        if (!data)
        {
            Log::EngineLog.Warn(std::format("Failed to load a texture ({})", filename));
            return;
        }

        glGenTextures(1, &this->Id);
        this->Bind();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    void Texture::Bind() const
    {
        glBindTexture(GL_TEXTURE_2D, this->Id);
    }
} // namespace AuraEngine
