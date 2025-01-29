#pragma once
#include <string>

namespace AuraEngine {
  class Texture
  {
  public:
    Texture(const std::string &filename);
    void Bind() const;

  private:
    unsigned int Id = 0;
  };
}