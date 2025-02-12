#include "Keyboard.hpp"
#include <format>
#include "../../Log/Log.hpp"

namespace AuraEngine
{
    Keyboard::Keyboard()
    {
        this->keyboardState = SDL_GetKeyboardState(nullptr);
    }

    bool Keyboard::KeyPressed(const SDL_Scancode scancode) const
    {
        return this->keyboardState[scancode];
    }

} // namespace AuraEngine
