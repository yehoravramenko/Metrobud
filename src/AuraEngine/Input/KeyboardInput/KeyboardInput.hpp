#pragma once
#include <SDL3/SDL_scancode.h>

namespace AuraEngine
{
  enum KeyCode
  {
    Unknown = -1,

    Space = SDL_SCANCODE_SPACE,
    Apostrophe = SDL_SCANCODE_APOSTROPHE, // '
    Comma = SDL_SCANCODE_COMMA, // ,
    Minus = SDL_SCANCODE_MINUS, // -
    Period = SDL_SCANCODE_PERIOD, // .
    Slash = SDL_SCANCODE_SLASH, // /
    Key0 = SDL_SCANCODE_0,
    Key1 = SDL_SCANCODE_1,
    Key2 = SDL_SCANCODE_2,
    Key3 = SDL_SCANCODE_3,
    Key4 = SDL_SCANCODE_4,
    Key5 = SDL_SCANCODE_5,
    Key6 = SDL_SCANCODE_6,
    Key7 = SDL_SCANCODE_7,
    Key8 = SDL_SCANCODE_8,
    Key9 = SDL_SCANCODE_9,
    Semicolon = SDL_SCANCODE_SEMICOLON, // ;
    Equal = SDL_SCANCODE_EQUALS, // =
    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,
    LeftBracket = SDL_SCANCODE_LEFTBRACKET, // [
    Backslash = SDL_SCANCODE_BACKSLASH, /* \ */
    RightBracket = SDL_SCANCODE_RIGHTBRACKET, // ]
    GraveAccent = SDL_SCANCODE_GRAVE, // `

    Escape = SDL_SCANCODE_ESCAPE,
    Enter = SDL_SCANCODE_RETURN,
    Tab = SDL_SCANCODE_TAB,
    Backspace = SDL_SCANCODE_BACKSPACE,
    Insert = SDL_SCANCODE_INSERT,
    Delete = SDL_SCANCODE_DELETE,
    Right = SDL_SCANCODE_RIGHT,
    Left = SDL_SCANCODE_LEFT,
    Down = SDL_SCANCODE_DOWN,
    Up = SDL_SCANCODE_UP,
    PageUp = SDL_SCANCODE_PAGEUP,
    PageDown = SDL_SCANCODE_PAGEDOWN,
    Home = SDL_SCANCODE_HOME,
    End = SDL_SCANCODE_END,
    CapsLock = SDL_SCANCODE_CAPSLOCK,
    ScrollLock = SDL_SCANCODE_SCROLLLOCK,
    NumLock = SDL_SCANCODE_NUMLOCKCLEAR,
    PrintScreen = SDL_SCANCODE_PRINTSCREEN,
    Pause = SDL_SCANCODE_PAUSE,
    F1 = SDL_SCANCODE_F1,
    F2 = SDL_SCANCODE_F2,
    F3 = SDL_SCANCODE_F3,
    F4 = SDL_SCANCODE_F4,
    F5 = SDL_SCANCODE_F5,
    F6 = SDL_SCANCODE_F6,
    F7 = SDL_SCANCODE_F7,
    F8 = SDL_SCANCODE_F8,
    F9 = SDL_SCANCODE_F9,
    F10 = SDL_SCANCODE_F10,
    F11 = SDL_SCANCODE_F11,
    F12 = SDL_SCANCODE_F12,
    F13 = SDL_SCANCODE_F13,
    F14 = SDL_SCANCODE_F14,
    F15 = SDL_SCANCODE_F15,
    F16 = SDL_SCANCODE_F16,
    F17 = SDL_SCANCODE_F17,
    F18 = SDL_SCANCODE_F18,
    F19 = SDL_SCANCODE_F19,
    F20 = SDL_SCANCODE_F20,
    F21 = SDL_SCANCODE_F21,
    F22 = SDL_SCANCODE_F22,
    F23 = SDL_SCANCODE_F23,
    F24 = SDL_SCANCODE_F24,

    Num0 = SDL_SCANCODE_KP_1,
    Num1 = SDL_SCANCODE_KP_2,
    Num2 = SDL_SCANCODE_KP_3,
    Num3 = SDL_SCANCODE_KP_4,
    Num4 = SDL_SCANCODE_KP_5,
    Num5 = SDL_SCANCODE_KP_6,
    Num6 = SDL_SCANCODE_KP_7,
    Num7 = SDL_SCANCODE_KP_8,
    Num8 = SDL_SCANCODE_KP_9,
    Num9 = SDL_SCANCODE_KP_0,
    NumPeriod = SDL_SCANCODE_KP_PERIOD,
    NumSlash = SDL_SCANCODE_KP_DIVIDE,
    NumMultiply = SDL_SCANCODE_KP_MULTIPLY,
    NumMinus = SDL_SCANCODE_KP_MINUS,
    NumAdd = SDL_SCANCODE_KP_PLUS,
    NumEnter = SDL_SCANCODE_KP_ENTER,

    /************************************************************************/
    /*                        Check Key Modifiers                           */
    /************************************************************************/

    /*LeftShift = 340,
    LeftCtrl = 341,
    LeftAlt = 342,
    LeftWin = 343,
    RightShift = 344,
    RightCtrl = 345,
    RightAlt = 346,
    RightWin = 347,
    Menu = 348,*/
  };

  enum KeyState
  {
    Released,
    Pressed,
  };

  namespace KeyboardInput
  {
    KeyState GetKeyState(const KeyCode keycode);
  }
} // namespace AuraEngine