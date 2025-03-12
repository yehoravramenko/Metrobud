#pragma once

namespace AuraEngine::GL {
class VertexArray {
public:
  VertexArray();
  void Bind() const;
  ~VertexArray();

private:
  unsigned m_handle;
};
} // namespace AuraEngine::GL