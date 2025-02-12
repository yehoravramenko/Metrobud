#pragma once
#include <SDL3/SDL.h>
#include "../../ExportAPI.hpp"

namespace AuraEngine
{
    class Keyboard
    {
    public:
        Keyboard();
        [[nodiscard]] AE_API bool KeyPressed(SDL_Scancode scancode) const;

    private:
        const bool* keyboardState;
    };
} // namespace AuraEngine
