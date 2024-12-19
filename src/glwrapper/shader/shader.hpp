#pragma once
#include <common.hpp>

namespace GL {
class Shader {
public:
  Shader(const std::string &vert_shader_src,
         const std::string &frag_shader_src);

private:
  unsigned int id = 0;

  void compileShader(unsigned int &shader_id, const char *src);
};
} // namespace GL