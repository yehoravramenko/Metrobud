#include "VertexAttribPointer.hpp"

namespace AuraEngine
{
    int VertexAttribPointer::GLOBAL_INDEX = -1;

    VertexAttribPointer::VertexAttribPointer(const int length, const GLenum type, const GLboolean normalized,
                                             const int stride, const int startOffset)
    {
        this->index = ++GLOBAL_INDEX;
        this->length = length;
        this->type = type;
        this->normalized = normalized;

        switch (this->type)
        {
        case GL_FLOAT:
        default:
            this->stride = stride * sizeof(float);
            this->startOffset = startOffset * sizeof(float);
            break;
        }

        glVertexAttribPointer(this->index, this->length, this->type, this->normalized,
                              static_cast<GLsizei>(this->stride), reinterpret_cast<void*>(this->startOffset));
    }

    void VertexAttribPointer::Enable() const
    {
        glEnableVertexAttribArray(this->index);
    }

    void VertexAttribPointer::Disable() const
    {
        glDisableVertexAttribArray(this->index);
    }
} // namespace AuraEngine
