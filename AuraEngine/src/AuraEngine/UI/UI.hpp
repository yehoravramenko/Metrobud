#pragma once
#include <SDL3/SDL.h>
#include <string>
#include "UIElement/UIFrame/UIFrame.hpp"
#include "UIElement/UIText/UIText.hpp"
#include <map>


namespace AuraEngine
{
  class UI
  {
  public:
    UIFrame rootFrame;

    UI(SDL_Window *window, void *sdl_gl_context);

    //void AddElement(const std::string &name, UIElement *element);
    //UIElement *GetElement(const std::string &name);

    void ProcessSDLEvent(SDL_Event &event);
    void Update();
    void Draw();
    ~UI();

  private:
    //std::map<std::string, UIElement *> uiElements;
  };
}